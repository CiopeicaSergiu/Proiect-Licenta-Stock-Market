#include "SqlExecutor.h"
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

TEST_CASE("simple select") {
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
  const std::string insertStatement{
      "insert into users(username, pass) values (\"{}\", \"{}\");"};
  utils::SqlExecutor sqlExecutor({"licenta", "password"},
                                 {"localhost", 3306, "licenta"});

  utils::SubTable queryTable;
  sqlExecutor.executeStatement(fmt::format(insertStatement, "ana", "123"),
                               queryTable);
  std::cout << "HelloWorld!!\n";

  sqlExecutor.executeStatement("commit;", queryTable);
}