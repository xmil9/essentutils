//
// essentutils
// Random number utilities.
//
// Jun-2019, Michael Lindner
// MIT license
//
#include <random>


namespace sutil
{
///////////////////

// Generates random floating point numbers in range [a, b).
template <typename FP = double> class Random
{
 public:
   // Values in range (0, 1] with random seed.
   Random();
   // Values in range (0, 1] with given seed.
   Random(FP seed);
   // Values in range (a, b] with random seed.
   Random(FP a, FP b);
   // Values in range (a, b] with given seed.
   Random(FP a, FP b, FP seed);
   Random(const Random&) = delete;
   Random(Random&&) = default;

   Random& operator=(const Random&) = delete;
   Random& operator=(Random&&) = default;

   FP next();

 private:
   std::mt19937 m_gen;
   std::uniform_real_distribution<FP> m_dist;
};


template <typename FP>
Random<FP>::Random() : Random{std::random_device{}()}
{
}


template <typename FP>
Random<FP>::Random(FP seed) : Random{static_cast<FP>(0), static_cast<FP>(1), seed}
{
}


template <typename FP> Random<FP>::Random(FP a, FP b) : Random{a, b, std::random_device{}()}
{
}


template <typename FP> Random<FP>::Random(FP a, FP b, FP seed) : m_gen{seed}, m_dist{a, b}
{
}


template <typename FP>
FP Random<FP>::next()
{
   return m_dist(m_gen);
}

} // namespace sutil
