#pragma once
#include <string>
#include <vector>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

namespace utils {
struct Credentials {
  std::string username;
  std::string password;
};

struct Response {
  const std::vector<std::string> columnsName;
  std::vector<std::string> results;

  explicit Response(const std::vector<std::string> &columnNamePassed);
};

class SqlExecutor {
public:
  SqlExecutor(const Credentials &credentials, const std::string &host,
              const unsigned int port);

  ~SqlExecutor();

  void executeStatement(const std::string &statement);

private:
  std::unique_ptr<sql::Driver> driver = nullptr;
  std::unique_ptr<sql::Connection> con = nullptr;
  std::unique_ptr<sql::Statement> stmt = nullptr;
  std::unique_ptr<sql::ResultSet> res = nullptr;
};
} // namespace utils