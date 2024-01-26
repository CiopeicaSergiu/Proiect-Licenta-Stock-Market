
#include <string>
namespace stockService {
struct BidAskPrice {
  std::uint64_t id = 0xFFFFFFFFFFFFFFFFUL;
  std::string stockName;
  std::uint32_t quantity;
  double price;
};
} // namespace stockService