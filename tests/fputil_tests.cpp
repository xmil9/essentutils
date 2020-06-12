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


void testFpLess()
{
   {
      const std::string caseLabel = "fpLess for zero epsilon";
      VERIFY(sutil::fpLess(2.34500001, 2.34500002, 0.0), caseLabel);
   }
   {
      const std::string caseLabel =
         "fpLess for values with larger difference than epsilon";
      VERIFY(sutil::fpLess(2.3451, 2.3452, 0.00001), caseLabel);
   }
   {
      const std::string caseLabel =
         "fpLess for values with smaller difference than epsilon";
      VERIFY(!sutil::fpLess(2.34500000001, 2.34500000002, 0.00001), caseLabel);
   }
}


void testFpLessEqual()
{
   {
      const std::string caseLabel = "fpLessEqual for zero epsilon";
      VERIFY(sutil::fpLessEqual(2.34500001, 2.34500002, 0.0), caseLabel);
      VERIFY(sutil::fpLessEqual(2.34500002, 2.34500002, 0.0), caseLabel);
   }
   {
      const std::string caseLabel =
         "fpLessEqual for values with larger difference than epsilon";
      VERIFY(sutil::fpLessEqual(2.34501, 2.34502, 0.000001), caseLabel);
      VERIFY(sutil::fpLessEqual(2.34502, 2.34502, 0.000001), caseLabel);
   }
   {
      const std::string caseLabel =
         "fpLessEqual for values with smaller difference than epsilon";
      VERIFY(sutil::fpLessEqual(2.34500000003, 2.34500000002, 0.00001), caseLabel);
   }
}


void testFpGreater()
{
   {
      const std::string caseLabel = "fpGreater for zero epsilon";
      VERIFY(sutil::fpGreater(2.34500002, 2.34500001, 0.0), caseLabel);
   }
   {
      const std::string caseLabel =
         "fpGreater for values with larger difference than epsilon";
      VERIFY(sutil::fpGreater(2.34502, 2.34501, 0.000001), caseLabel);
   }
   {
      const std::string caseLabel =
         "fpGreater for values with smaller difference than epsilon";
      VERIFY(!sutil::fpGreater(2.34500000002, 2.34500000001, 0.00001), caseLabel);
   }
}


void testFpGreaterEqual()
{
   {
      const std::string caseLabel = "fpGreaterEqual for zero epsilon";
      VERIFY(sutil::fpGreaterEqual(2.34500002, 2.34500001, 0.0), caseLabel);
      VERIFY(sutil::fpGreaterEqual(2.34500002, 2.34500002, 0.0), caseLabel);
   }
   {
      const std::string caseLabel =
         "fpGreaterEqual for values with larger difference than epsilon";
      VERIFY(sutil::fpGreaterEqual(2.34502, 2.34501, 0.000001), caseLabel);
      VERIFY(sutil::fpGreaterEqual(2.34502, 2.34502, 0.000001), caseLabel);
   }
   {
      const std::string caseLabel =
         "fpGreaterEqual for values with smaller difference than epsilon";
      VERIFY(sutil::fpGreaterEqual(2.34500000002, 2.34500000003, 0.00001), caseLabel);
   }
}

} // namespace


///////////////////

void testFpUtil()
{
   testFpEqual();
   testFpLess();
   testFpLessEqual();
   testFpGreater();
   testFpGreaterEqual();
}
