
#include <string>
namespace stockService {
struct BidAskPrice {
  std::string stockName;
  std::uint32_t quantity;
  double price;
};
} // namespace stockService