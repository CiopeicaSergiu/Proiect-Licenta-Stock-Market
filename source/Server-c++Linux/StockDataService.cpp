#include "StockDataService.h"
#include "../converter/TimeConverter.h"
#include "../data/StockData.h"
#include "../formatter/DataFormater.h"
#include "../formatter/parsing.h"
#include "../request/RequestStockData.h"
#include <ctime>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <iomanip>
#include <restbed>
#include <sstream>

#include <iostream>

void StockDataService::setEventGetStockData(
    std::shared_ptr<restbed::Resource> &resource)
{
    resource->set_path("/{stockName: .*}");
    resource->set_method_handler(
        "GET", [this](std::shared_ptr<restbed::Session> session)
        { eventGetStockData(session); });
}

void StockDataService::sendResponseAndCloseSession( std::shared_ptr<restbed::Session>& session, const std::string& result)
{
        session->close(restbed::OK, result,
                   {{"Content-Length", std::to_string(result.size()).c_str()},
                    {"Connection", "close"}});
}

void StockDataService::eventGetStockData(
    std::shared_ptr<restbed::Session> session)
{

    const auto request = session->get_request();

    const auto stockName = request->get_path_parameter("stockName");
    const auto startTime = request->get_query_parameter("startTime");
    const auto endTime = request->get_query_parameter("endTime");

    curlpp::Cleanup myCleanup;
    RequestStockData requestGoogle(stockName);

    // const uint64_t start = 1641059569;
    // const uint64_t stop = 1641579977;
    const auto startTimeUnix = converter::dateTime::dateToUnixTime(startTime);
    const auto endTimeUnix = converter::dateTime::dateToUnixTime(endTime);

    auto data = requestGoogle.requestStockData(startTimeUnix, endTimeUnix, "1d");

    auto stocksData = parsing::parseStockData(data);

    auto formater = DataFormater();
    const std::string result = formater.formatData(stocksData, formatingType::table);

    sendResponseAndCloseSession(session, result);
}

void StockDataService::setEndpoints() { setEventGetStockData(resource); }
