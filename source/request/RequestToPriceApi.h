#pragma once
#include <string>
#include <string_view>

class RequestToPriceApi {
public:
  RequestToPriceApi(const std::string_view stockName,
                    const unsigned int portNumber = 2000);

  std::string operator()(const std::string_view stockName,
                         const unsigned quantity);

private:
  std::string url{"http://localhost:{}/{}?stockName={}&quantity={}"};
};