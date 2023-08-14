#include "Serialize.h"
#include "model/Credentials.h"

namespace stockService {

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
} // namespace stockService