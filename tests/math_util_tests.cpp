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


void testShiftIntoRange()
{
   {
      const std::string caseLabel = "shiftIntoRange for value in range";
      VERIFY(sutil::shiftIntoRange(2, 0, 10) == 2, caseLabel);
      VERIFY(sutil::shiftIntoRange(88, 85, 100) == 88, caseLabel);
      VERIFY(sutil::shiftIntoRange(-7, -15, -5) == -7, caseLabel);
      VERIFY(sutil::shiftIntoRange(70, 0, 360) == 70, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for value less than min";
      VERIFY(sutil::shiftIntoRange(-32, 0, 10) == 8, caseLabel);
      VERIFY(sutil::shiftIntoRange(19, 85, 100) == 94, caseLabel);
      VERIFY(sutil::shiftIntoRange(-37, -15, -5) == -7, caseLabel);
      VERIFY(sutil::shiftIntoRange(-560, 0, 360) == 160, caseLabel);
      VERIFY(sutil::shiftIntoRange(-720, 0, 360) == 360, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for value greater than max";
		VERIFY(sutil::shiftIntoRange(56, 0, 10) == 6, caseLabel);
		VERIFY(sutil::shiftIntoRange(119, 85, 100) == 89, caseLabel);
		VERIFY(sutil::shiftIntoRange(22, -15, -5) == -8, caseLabel);
		VERIFY(sutil::shiftIntoRange(780, 0, 360) == 60, caseLabel);
		VERIFY(sutil::shiftIntoRange(720, 0, 360) == 0, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for value equal to min";
		VERIFY(sutil::shiftIntoRange(0, 0, 10) == 0, caseLabel);
		VERIFY(sutil::shiftIntoRange(85, 85, 100) == 85, caseLabel);
		VERIFY(sutil::shiftIntoRange(-15, -15, -5) == -15, caseLabel);
		VERIFY(sutil::shiftIntoRange(0, 0, 360) == 0, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for value equal to max";
		VERIFY(sutil::shiftIntoRange(10, 0, 10) == 10, caseLabel);
		VERIFY(sutil::shiftIntoRange(100, 85, 100) == 100, caseLabel);
		VERIFY(sutil::shiftIntoRange(-5, -15, -5) == -5, caseLabel);
		VERIFY(sutil::shiftIntoRange(360, 0, 360) == 360, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for denormalized range";
		VERIFY(sutil::shiftIntoRange(-22, 10, 0) == 8, caseLabel);
		VERIFY(sutil::shiftIntoRange(101, 100, 85) == 86, caseLabel);
		VERIFY(sutil::shiftIntoRange(-7, -5, -15) == -7, caseLabel);
		VERIFY(sutil::shiftIntoRange(-1, 360, 0) == 359, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for empty range";
		VERIFY(sutil::shiftIntoRange(5, 10, 10) == 5, caseLabel);
   }
}

} // namespace


///////////////////

void testMathUtil()
{
   testClampToRange();
   testShiftIntoRange();
}
