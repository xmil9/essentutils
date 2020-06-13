//
// essentutils tests
// Tests for math utilities.
//
// Jun-2020, Michael Lindner
// MIT license
//
#include "math_util_tests.h"
#include "math_util.h"
#include "fputil.h"
#include "test_util.h"

using namespace sutil;


namespace
{
///////////////////

void testClampToRange()
{
   {
      const std::string caseLabel = "clampToRange for value in range";
      VERIFY(clampToRange(2.0, 1.0, 4.0) == 2.0, caseLabel);
      VERIFY(clampToRange(-2.0, -4.0, -1.0) == -2.0, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for value less than min";
      VERIFY(clampToRange(1.0f, 2.0f, 4.0f) == 2.0f, caseLabel);
      VERIFY(clampToRange(-3.0f, -2.0f, 4.0f) == -2.0f, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for value greater than max";
      VERIFY(clampToRange(5, 2, 4) == 4, caseLabel);
      VERIFY(clampToRange(0, -5, -2) == -2, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for value equal to min";
      VERIFY(clampToRange(1.0, 1.0, 4.0) == 1.0, caseLabel);
      VERIFY(clampToRange(-4.0, -4.0, -1.0) == -4.0, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for value equal to max";
      VERIFY(clampToRange(4.0f, 1.0f, 4.0f) == 4.0f, caseLabel);
      VERIFY(clampToRange(-1.0f, -4.0f, -1.0f) == -1.0f, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for denormalized range";
      VERIFY(clampToRange(0.0, 4.0, 1.0) == 1.0, caseLabel);
      VERIFY(clampToRange(1, -1, -4) == -1, caseLabel);
   }
   {
      const std::string caseLabel = "clampToRange for min == max";
      VERIFY(clampToRange(0.0, 1.0, 1.0) == 1.0, caseLabel);
      VERIFY(clampToRange(4, 2, 2) == 2, caseLabel);
   }
}


void testShiftIntoRange()
{
   {
      const std::string caseLabel = "shiftIntoRange for value in range";
      VERIFY(shiftIntoRange(2, 0, 10) == 2, caseLabel);
      VERIFY(shiftIntoRange(88, 85, 100) == 88, caseLabel);
      VERIFY(shiftIntoRange(-7, -15, -5) == -7, caseLabel);
      VERIFY(shiftIntoRange(70, 0, 360) == 70, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for value less than min";
      VERIFY(shiftIntoRange(-32, 0, 10) == 8, caseLabel);
      VERIFY(shiftIntoRange(19, 85, 100) == 94, caseLabel);
      VERIFY(shiftIntoRange(-37, -15, -5) == -7, caseLabel);
      VERIFY(shiftIntoRange(-560, 0, 360) == 160, caseLabel);
      VERIFY(shiftIntoRange(-720, 0, 360) == 360, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for value greater than max";
      VERIFY(shiftIntoRange(56, 0, 10) == 6, caseLabel);
      VERIFY(shiftIntoRange(119, 85, 100) == 89, caseLabel);
      VERIFY(shiftIntoRange(22, -15, -5) == -8, caseLabel);
      VERIFY(shiftIntoRange(780, 0, 360) == 60, caseLabel);
      VERIFY(shiftIntoRange(720, 0, 360) == 0, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for value equal to min";
      VERIFY(shiftIntoRange(0, 0, 10) == 0, caseLabel);
      VERIFY(shiftIntoRange(85, 85, 100) == 85, caseLabel);
      VERIFY(shiftIntoRange(-15, -15, -5) == -15, caseLabel);
      VERIFY(shiftIntoRange(0, 0, 360) == 0, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for value equal to max";
      VERIFY(shiftIntoRange(10, 0, 10) == 10, caseLabel);
      VERIFY(shiftIntoRange(100, 85, 100) == 100, caseLabel);
      VERIFY(shiftIntoRange(-5, -15, -5) == -5, caseLabel);
      VERIFY(shiftIntoRange(360, 0, 360) == 360, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for denormalized range";
      VERIFY(shiftIntoRange(-22, 10, 0) == 8, caseLabel);
      VERIFY(shiftIntoRange(101, 100, 85) == 86, caseLabel);
      VERIFY(shiftIntoRange(-7, -5, -15) == -7, caseLabel);
      VERIFY(shiftIntoRange(-1, 360, 0) == 359, caseLabel);
   }
   {
      const std::string caseLabel = "shiftIntoRange for empty range";
      VERIFY(shiftIntoRange(5, 10, 10) == 5, caseLabel);
   }
}


void testDegreesFromRadians()
{
   const std::string caseLabel = "degreesFromRadians";
   VERIFY(degreesFromRadians(0.0) == 0.0, caseLabel);
   VERIFY(fpEqual(degreesFromRadians(0.5 * Pi<double>), 90.0, 0.000001), caseLabel);
   VERIFY(fpEqual(degreesFromRadians(Pi<double>), 180.0, 0.000001), caseLabel);
   VERIFY(fpEqual(degreesFromRadians(1.5f * Pi<float>), 270.0f, 0.000001f), caseLabel);
   VERIFY(fpEqual(degreesFromRadians(2.0f * Pi<float>), 360.0f, 0.000001f), caseLabel);
   VERIFY(fpEqual(degreesFromRadians(1.0), 57.295779513, 0.000001), caseLabel);
}


void testRadiansFromDegrees()
{
   const std::string caseLabel = "radiansFromDegrees";
   VERIFY(radiansFromDegrees(0.0) == 0.0, caseLabel);
   VERIFY(fpEqual(radiansFromDegrees(90.0), 0.5 * Pi<double>, 0.000001), caseLabel);
   VERIFY(fpEqual(radiansFromDegrees(180.0), Pi<double>, 0.000001), caseLabel);
   VERIFY(fpEqual(radiansFromDegrees(270.0f), 1.5f * Pi<float>, 0.000001f), caseLabel);
   VERIFY(fpEqual(radiansFromDegrees(360.0f), 0.5f * Pi<float>, 0.000001f), caseLabel);
   VERIFY(fpEqual(radiansFromDegrees(57.295779513), 0.5 * Pi<double>, 0.000001),
          caseLabel);
}

} // namespace


///////////////////

void testMathUtil()
{
   testClampToRange();
   testShiftIntoRange();
   testDegreesFromRadians();
   testRadiansFromDegrees();
}
