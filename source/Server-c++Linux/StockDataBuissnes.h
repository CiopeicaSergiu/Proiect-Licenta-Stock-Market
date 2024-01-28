#pragma once
#include <cstdint>

namespace stockService {
struct BidAskPrice;
}

enum class STATUS { SUCCESS, INSUFICENT_FUNDS, ERROR };

STATUS buyStock(const stockService::BidAskPrice &bidPrice,
                const stockService::BidAskPrice &askPrice);

void sellStock(const uint64_t ownedId,
               const stockService::BidAskPrice &bidPrice);
