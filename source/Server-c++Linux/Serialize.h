#pragma once

#include <boost/json/value_from.hpp>
#include <boost/json/value_to.hpp>

namespace stockService {

struct Credentials;
struct BidAskPrice;

namespace Json = boost::json;

void tag_invoke(boost::json::value_from_tag, boost::json::value &jsonValue,
                Credentials const &credentials);

Credentials tag_invoke(boost::json::value_to_tag<Credentials>,
                       boost::json::value const &jsonValue);

BidAskPrice tag_invoke(boost::json::value_to_tag<BidAskPrice>,
                       boost::json::value const &jsonValue);

} // namespace stockService