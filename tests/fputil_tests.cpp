//
// essentutils tests
// Tests for floating point utilities.
//
// Jun-2020, Michael Lindner
// MIT license
//
#include "fputil_tests.h"
#include "fputil.h"
#include "test_util.h"


namespace
{
///////////////////

void testFpEqual()
{
   {
      const std::string caseLabel = "fpEqual for zero epsilon";
      VERIFY(sutil::fpEqual(2.345000001, 2.345000001, 0.0), caseLabel);
   }
   {
      const std::string caseLabel =
         "fpEqual for values with larger difference than epsilon";
      VERIFY(!sutil::fpEqual(2.3451, 2.3452, 0.00001), caseLabel);
   }
   {
      const std::string caseLabel =
         "fpEqual for values with smaller difference than epsilon";
      VERIFY(sutil::fpEqual(2.34500000001, 2.34500000002, 0.00001), caseLabel);
   }
}

} // namespace


///////////////////

void testFpUtil()
{
   testFpEqual();
}
