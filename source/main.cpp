#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <iostream>
#include <sstream>

int main() {
  // RAII cleanup

  curlpp::Cleanup myCleanup;

  // Send request and get a result.
  // Here I use a shortcut to get it in a string stream ...
  std::string urlStrig{"https://query1.finance.yahoo.com/v8/finance/chart/"
                       "aapl?metrics=high?&interval=1d&range=5d"};

  std::ostringstream osBuffer;
  osBuffer << curlpp::options::Url(urlStrig);

  const auto information = osBuffer.str();
  std::cout << information << std::endl;
  return 0;
}