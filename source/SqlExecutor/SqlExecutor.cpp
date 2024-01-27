#include "SqlExecutor.h"

#include "model/BidAskPrice.h"
#include <algorithm>
#include <fmt/format.h>
#include <iterator>

namespace utils {

SubTable::SubTable(const std::vector<std::string> &columnNamePassed) {
  columnsName.reserve(columnNamePassed.size());
  std::copy(columnNamePassed.begin(), columnNamePassed.end(),
            std::back_inserter(columnsName));
}

SqlExecutor::SqlExecutor(const Credentials &credentials,
                         const ConnectionSettings &connectionSettings) {

  driver = get_driver_instance();
  con.reset(driver->connect(fmt::format("{}:{}/{}", connectionSettings.host,
                                        std::to_string(connectionSettings.port),
                                        connectionSettings.database),
                            credentials.username, credentials.password));
  stmt.reset(con->createStatement());
}

// Populeaza un subtable, un subtable este format din toate intrarile selectate
// la executia unui query
void SqlExecutor::executeStatement(const std::string &statement,
                                   SubTable &subTable) {

  res.reset(stmt->executeQuery(statement));

  while (res and res->next()) {
    for (const auto &columnName : subTable.columnsName)
      subTable.entries.emplace_back(res->getString(columnName));
  }
}

// pentru sql queries care nu returneaza nimic
void SqlExecutor::executeStatement(const std::string &statement) {

  stmt->execute(statement);
}

std::vector<stockService::BidAskPrice>
toBidAskPrices(const SubTable &queryResult) {

  if (queryResult.columnsName.size() != 4) {
    return {};
  }

  std::vector<stockService::BidAskPrice> bidAskPrices;
  bidAskPrices.reserve(queryResult.entries.size() / 4);

  for (size_t i = 0; i < queryResult.entries.size(); i += 4) {
    bidAskPrices.push_back(stockService::BidAskPrice{
        std::stoul(queryResult.entries.at(i)), queryResult.entries.at(i + 1),
        (std::uint32_t)std::stoul(queryResult.entries.at(i + 2)),
        std::stod(queryResult.entries.at(i + 3))});
  }

  return bidAskPrices;
}

} // namespace utils