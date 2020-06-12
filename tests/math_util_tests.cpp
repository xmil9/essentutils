//
// essentutils tests
// Tests for math utilities.
//
// Jun-2020, Michael Lindner
// MIT license
//
#include "math_util_tests.h"
#include "math_util.h"
#include "test_util.h"


namespace
{
///////////////////

void testClampToRange()
{
   {
      const std::string caseLabel = "clampToRange for value in range";
      VERIFY(sutil::clampToRange(2.0, 1.0, 4.0) == 2.0, caseLabel);
      VERIFY(sutil::clampToRange(-2.0, -4.0, -1.0) == -2.0, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for value less than min";
      VERIFY(sutil::clampToRange(1.0f, 2.0f, 4.0f) == 2.0f, caseLabel);
      VERIFY(sutil::clampToRange(-3.0f, -2.0f, 4.0f) == -2.0f, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for value greater than max";
      VERIFY(sutil::clampToRange(5, 2, 4) == 4, caseLabel);
      VERIFY(sutil::clampToRange(0, -5, -2) == -2, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for value equal to min";
      VERIFY(sutil::clampToRange(1.0, 1.0, 4.0) == 1.0, caseLabel);
      VERIFY(sutil::clampToRange(-4.0, -4.0, -1.0) == -4.0, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for value equal to max";
      VERIFY(sutil::clampToRange(4.0f, 1.0f, 4.0f) == 4.0f, caseLabel);
      VERIFY(sutil::clampToRange(-1.0f, -4.0f, -1.0f) == -1.0f, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for denormalized range";
      VERIFY(sutil::clampToRange(0.0, 4.0, 1.0) == 1.0, caseLabel);
      VERIFY(sutil::clampToRange(1, -1, -4) == -1, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for min == max";
      VERIFY(sutil::clampToRange(0.0, 1.0, 1.0) == 1.0, caseLabel);
      VERIFY(sutil::clampToRange(4, 2, 2) == 2, caseLabel);
   }
}

} // namespace


///////////////////

void testMathUtil()
{
   testClampToRange();
}
