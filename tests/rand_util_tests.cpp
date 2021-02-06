//
// essentutils tests
// Tests for random number utilities.
//
// Aug-2020, Michael Lindner
// MIT license
//
#include "rand_util_tests.h"
#include "rand_util.h"
#include "fputil.h"
#include "test_util.h"

using namespace esl;


namespace
{
///////////////////

template <typename Fp> bool verifyUniqueness(std::vector<Fp> vals)
{
   std::sort(vals.begin(), vals.end());
   const auto equalValIter = std::adjacent_find(vals.begin(), vals.end(),
                                                [](Fp a, Fp b) { return equal(a, b); });
   return equalValIter == vals.end();
}


template <typename Fp> bool verifyRange(const std::vector<Fp>& vals, Fp min, Fp max)
{
   const auto match = std::find_if_not(
      vals.begin(), vals.end(), [min, max](Fp val) { return min <= val && val < max; });
   return match == vals.end();
}


///////////////////

void testRandomDefaultCtor()
{
   {
      const std::string caseLabel = "Random default ctor";

      using Fp = float;
      constexpr std::size_t numVals = 100;
      std::vector<Fp> vals;

      Random<float> rnd;
      for (std::size_t i = 0; i < numVals; ++i)
         vals.push_back(rnd.next());

      VERIFY(verifyUniqueness(vals), caseLabel);
      VERIFY(verifyRange(vals, 0.0f, 1.0f), caseLabel);
   }
}


void testRandomCtorWithSeed()
{
   {
      const std::string caseLabel = "Random ctor with seed";

      using Fp = float;
      constexpr std::size_t numVals = 100;
      constexpr unsigned int seed = 123456789;

      std::vector<Fp> valsA;
      Random<float> rndA{seed};
      for (std::size_t i = 0; i < numVals; ++i)
         valsA.push_back(rndA.next());

      VERIFY(verifyUniqueness(valsA), caseLabel);
      VERIFY(verifyRange(valsA, 0.0f, 1.0f), caseLabel);

      std::vector<Fp> valsB;
      Random<float> rndB{seed};
      for (std::size_t i = 0; i < numVals; ++i)
         valsB.push_back(rndB.next());

      VERIFY(valsA == valsB, caseLabel);
   }
}


void testRandomCtorWithRangeValues()
{
   {
      const std::string caseLabel = "Random ctor with range";

      using Fp = double;
      constexpr std::size_t numVals = 100;
      constexpr Fp min = 101.0;
      constexpr Fp max = 200.0;

      std::vector<Fp> vals;
      Random<float> rnd{min, max};
      for (std::size_t i = 0; i < numVals; ++i)
         vals.push_back(rnd.next());

      VERIFY(verifyUniqueness(vals), caseLabel);
      VERIFY(verifyRange(vals, min, max), caseLabel);
   }
}


void testRandomCtorWithRangeValuesAndSeed()
{
   {
      const std::string caseLabel = "Random ctor with seed";

      using Fp = double;
      constexpr std::size_t numVals = 100;
      constexpr unsigned int seed = 123456789;
      constexpr Fp min = 101.0;
      constexpr Fp max = 200.0;

      std::vector<Fp> valsA;
      Random<float> rndA{min, max, seed};
      for (std::size_t i = 0; i < numVals; ++i)
         valsA.push_back(rndA.next());

      VERIFY(verifyUniqueness(valsA), caseLabel);
      VERIFY(verifyRange(valsA, min, max), caseLabel);

      std::vector<Fp> valsB;
      Random<float> rndB{min, max, seed};
      for (std::size_t i = 0; i < numVals; ++i)
         valsB.push_back(rndB.next());

      VERIFY(valsA == valsB, caseLabel);
   }
}


} // namespace


///////////////////

void testRandUtil()
{
   testRandomDefaultCtor();
   testRandomCtorWithSeed();
   testRandomCtorWithRangeValues();
   testRandomCtorWithRangeValuesAndSeed();
}
