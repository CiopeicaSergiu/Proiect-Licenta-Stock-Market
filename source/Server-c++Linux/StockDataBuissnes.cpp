#include "StockDataBuissnes.h"
#include "SqlExecutor.h"
#include "SqlGenerator.h"
#include "model/BidAskPrice.h"
#include "model/Credentials.h"
#include <string>

constexpr std::uint64_t UNSIGNED_LONG_NULL = 0xFFFFFFFFFFFFFFFF;

const utils::Credentials credentialsDataBase{"licenta", "password"};

const utils::ConnectionSettings connectionSettingsDataBase{"localhost", 3306,
                                                           "licenta"};

using namespace stockService;

enum AccountsEntry { id_user, fund_name, funds, last_transaction };

double getAccountBalanceByUserId(const std::uint64_t userId) {
  utils::SqlExecutor sqlExecutor(credentialsDataBase,
                                 connectionSettingsDataBase);

  utils::SqlGenerator sqlGeneratorAccounts("./database_licenta/account.txt");

  utils::SubTable queryAccounts{
      {"id_user", "fund_name", "funds", "last_transaction"}};

  sqlExecutor.executeStatement(
      sqlGeneratorAccounts.prepareStatement<utils::Operations::select>(userId),
      queryAccounts);

  return std::stod(queryAccounts.entries[AccountsEntry::funds]);
}

void updateAccountBalanceByUserId(const std::uint64_t userId,
                                  const double newAccountBalance) {

  if (newAccountBalance < 0) {
    return;
  }

  utils::SqlExecutor sqlExecutor(credentialsDataBase,
                                 connectionSettingsDataBase);

  utils::SqlGenerator sqlGeneratorAccounts("./database_licenta/account.txt");

  sqlExecutor.executeStatement(
      sqlGeneratorAccounts.prepareStatement<utils::Operations::update>(
          newAccountBalance, userId));
}

void insertOwnedStock(const std::uint64_t userId, BidAskPrice newAquiredStock) {

  utils::SqlExecutor sqlExecutor(credentialsDataBase,
                                 connectionSettingsDataBase);

  utils::SqlGenerator sqlGeneratorAskPrice("./database_licenta/owned.txt");

  sqlExecutor.executeStatement(
      sqlGeneratorAskPrice.prepareStatement<utils::Operations::insert>(
          userId, newAquiredStock.stockName, newAquiredStock.quantity,
          newAquiredStock.price));
}

void deleteBuyCommandByCommandId(const std::uint64_t buyCommandId) {
  utils::SqlExecutor sqlExecutor(credentialsDataBase,
                                 connectionSettingsDataBase);

  utils::SqlGenerator sqlGeneratorBuy("./database_licenta/buy.txt");

  sqlExecutor.executeStatement(
      sqlGeneratorBuy.prepareStatement<utils::Operations::deletion>(
          buyCommandId));
}

void deleteAskPriceEntryByAskPriceId(const std::uint64_t askPriceId) {
  utils::SqlExecutor sqlExecutor(credentialsDataBase,
                                 connectionSettingsDataBase);

  utils::SqlGenerator sqlGeneratorBuy("./database_licenta/askPrice.txt");

  sqlExecutor.executeStatement(
      sqlGeneratorBuy.prepareStatement<utils::Operations::deletion>(
          askPriceId));
}

STATUS buyStock(const BidAskPrice &bidPrice, const BidAskPrice &askPrice) {

  utils::SqlExecutor sqlExecutor(credentialsDataBase,
                                 connectionSettingsDataBase);

  utils::SqlGenerator sqlGeneratorAskPrice("./database_licenta/buy.txt");

  utils::SubTable queryResultAsk{
      {"id_user", "id", "stockName", "quantity", "price"}};

  sqlExecutor.executeStatement(
      sqlGeneratorAskPrice.prepareStatement<utils::Operations::select>(
          bidPrice.id),
      queryResultAsk);

  const auto userId = std::stol(queryResultAsk.entries.front());

  const auto accountBalance = getAccountBalanceByUserId(userId);

  if (accountBalance < askPrice.price) {
    return STATUS::INSUFICENT_FUNDS;
  }

  updateAccountBalanceByUserId(userId, accountBalance - askPrice.price);
  insertOwnedStock(userId, askPrice);
  deleteBuyCommandByCommandId(bidPrice.id);
  deleteAskPriceEntryByAskPriceId(askPrice.id);

  return STATUS::SUCCESS;
}

std::uint64_t getUserIdByOwnedId(const std::uint64_t ownedId) {
  utils::SqlExecutor sqlExecutor(credentialsDataBase,
                                 connectionSettingsDataBase);

  utils::SqlGenerator sqlGeneratorOwned("./database_licenta/buy.txt");

  utils::SubTable queryResultOwned{
      {"id", "id_user", "stockName", "quantity", "price", "buy_date"}};

  sqlExecutor.executeStatement(
      sqlGeneratorOwned.prepareStatement<utils::Operations::select>(ownedId),
      queryResultOwned);

  if (queryResultOwned.entries.empty()) {
    return UNSIGNED_LONG_NULL;
  }

  return std::stol(queryResultOwned.entries[1]);
}

void sellStock(const std::uint64_t ownedId, const BidAskPrice &bidPrice) {
  utils::SqlExecutor sqlExecutor(credentialsDataBase,
                                 connectionSettingsDataBase);

  utils::SqlGenerator sqlGeneratorOwned("./database_licenta/owned.txt");

  sqlExecutor.executeStatement(
      sqlGeneratorOwned.prepareStatement<utils::Operations::deletion>(ownedId));

  const auto userId = getUserIdByOwnedId(ownedId);
  updateAccountBalanceByUserId(userId, getAccountBalanceByUserId(userId) +
                                           bidPrice.price);
}