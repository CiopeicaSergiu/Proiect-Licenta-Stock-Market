#include "PriceGenerator.h"
#include <random>

namespace priceGenerator {
double generateFloatNrWithNormalDistr(const double mean,
                                      const double stdDeviation) {

  std::mt19937 gen{std::random_device{}()};

  std::normal_distribution nrGenNormalDistr{mean, stdDeviation};

  return nrGenNormalDistr(gen);
}

double generateBuyCostNormalDistribution(const double financialIntrumentPrice) {

  const double mean = 1 / 10.0 * financialIntrumentPrice;
  const double stdDeviation = 5.0;

  return financialIntrumentPrice +
         generateFloatNrWithNormalDistr(mean, stdDeviation);
}
} // namespace priceGenerator
