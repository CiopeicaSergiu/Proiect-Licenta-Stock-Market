#include "SqlExecutor.h"
#include "SqlGenerator.h"
#include <catch2/catch_test_macros.hpp>
#include <fmt/format.h>

std::string subTableToUsersTable(const utils::SubTable &subTable) {
  fmt::memory_buffer buffer;
  fmt::format_to(std::back_inserter(buffer),
                 "----------------------------------\n| {:^8} | {:^8} | {:^8} "
                 "|\n----------------------------------\n",
                 subTable.columnsName[0], subTable.columnsName[1],
                 subTable.columnsName[2]);

  for (size_t i = 0; i < subTable.entries.size(); i += 3) {
    fmt::format_to(std::back_inserter(buffer),
                   "| {:^8} | {:^8} | {:^8} "
                   "|\n----------------------------------\n",
                   subTable.entries[i + 0], subTable.entries[i + 1],
                   subTable.entries[i + 2]);
  }
  return fmt::to_string(buffer); // pointer to the formatted data
}

TEST_CASE("select") {
  utils::SqlExecutor sqlExecutor({"licenta", "password"},
                                 {"localhost", 3306, "licenta"});
  utils::SubTable queryTable({"id", "username", "pass"});
  sqlExecutor.executeStatement("select * from users;", queryTable);

  const std::string userTable{
      "----------------------------------\n|    id    | username |   pass   "
      "|\n----------------------------------\n|    1     |  sergiu  |  123456  "
      "|\n----------------------------------\n"};
  REQUIRE(userTable == subTableToUsersTable(queryTable));
}

TEST_CASE("insert") {

  utils::SqlGenerator generatorUserTable("./database_licenta/users.txt");
  utils::SqlExecutor sqlExecutor({"licenta", "password"},
                                 {"localhost", 3306, "licenta"});

  const auto sqlStatement =
      generatorUserTable.prepareStatement<utils::Operations::insert>("Andrei",
                                                                     "Andrei");
  std::cout << sqlStatement << "\n";
  sqlExecutor.executeStatement(sqlStatement);
  sqlExecutor.executeStatement("commit;");
}

TEST_CASE("delete") {

  utils::SqlGenerator generatorUserTable("./database_licenta/users.txt");
  utils::SqlExecutor sqlExecutor({"licenta", "password"},
                                 {"localhost", 3306, "licenta"});

  const auto sqlStatement =
      generatorUserTable.prepareStatement<utils::Operations::deletion>(
          "Andrei");
  std::cout << sqlStatement << "\n";
  sqlExecutor.executeStatement(sqlStatement);
  sqlExecutor.executeStatement("commit;");
}

TEST_CASE("select_specific") {
  utils::SqlGenerator generatorUserTable("./database_licenta/users.txt");
  utils::SqlExecutor sqlExecutor({"licenta", "password"},
                                 {"localhost", 3306, "licenta"});

  const auto sqlStatement =
      generatorUserTable.prepareStatement<utils::Operations::select>("Andrei");
  std::cout << sqlStatement << "\n";
  utils::SubTable result({"username", "pass"});
  sqlExecutor.executeStatement(sqlStatement, result);
  std::cout << subTableToUsersTable(result);
}