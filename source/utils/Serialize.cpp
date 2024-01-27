#include "Serialize.h"
#include "model/BidAskPrice.h"
#include "model/Credentials.h"

namespace stockService {

class JsonObjectWrapper {

public:
  explicit JsonObjectWrapper(const Json::object &jsonObject)
      : jsonObject{jsonObject} {}

  template <typename T> T getField(std::string_view nameOfTheField) const {
    return jsonObject.contains(nameOfTheField)
               ? Json::value_to<T>(jsonObject.at(nameOfTheField))
               : T();
  }

private:
  const Json::object &jsonObject;
};

void tag_invoke(boost::json::value_from_tag, boost::json::value &jsonValue,
                Credentials const &credentials) {
  jsonValue = {{"username", credentials.username},
               {"password", credentials.password}};
}

Credentials tag_invoke(boost::json::value_to_tag<Credentials>,
                       boost::json::value const &jsonValue) {

  const auto &jsonObject = jsonValue.as_object();
  return Credentials{
      boost::json::value_to<std::string>(jsonObject.at("username")),
      boost::json::value_to<std::string>(jsonObject.at("password"))};
}

BidAskPrice tag_invoke(boost::json::value_to_tag<BidAskPrice>,
                       boost::json::value const &jsonValue) {

  const auto &jsonObjectWrapper = JsonObjectWrapper{jsonValue.as_object()};
  return BidAskPrice{jsonObjectWrapper.getField<std::uint64_t>("id"),
                     jsonObjectWrapper.getField<std::string>("stockName"),
                     jsonObjectWrapper.getField<std::uint32_t>("quantity"),
                     jsonObjectWrapper.getField<double>("price")};
}

void tag_invoke(boost::json::value_from_tag, boost::json::value &jsonValue,
                BidAskPrice const &bidAskPrice) {
  jsonValue = {{"id", bidAskPrice.id},
               {"stockName", bidAskPrice.stockName},
               {"quantity", bidAskPrice.quantity},
               {"price", bidAskPrice.price}};
}

} // namespace stockService