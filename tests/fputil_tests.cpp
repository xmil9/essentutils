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


///////////////////

void testEqual()
{
   {
      const std::string caseLabel = "equal for integer type";
      VERIFY(sutil::equal(2, 2), caseLabel);
      VERIFY(!sutil::equal(2, 3), caseLabel);
   }
   {
      const std::string caseLabel = "equal for floating point type";
      VERIFY(sutil::equal(2.123, 2.123), caseLabel);
      VERIFY(!sutil::equal(2.123, 2.124), caseLabel);
      VERIFY(sutil::equal(2.00000000000000000003, 2.00000000000000000004), caseLabel);
   }
}


void testLess()
{
   {
      const std::string caseLabel = "less for integer type";
      VERIFY(sutil::less(2, 3), caseLabel);
      VERIFY(!sutil::less(2, 2), caseLabel);
   }
   {
      const std::string caseLabel = "less for floating point type";
      VERIFY(sutil::less(2.123, 2.1234), caseLabel);
      VERIFY(!sutil::less(2.123, 2.123), caseLabel);
      VERIFY(!sutil::less(2.00000000000000000003, 2.00000000000000000004), caseLabel);
   }
}


void testLessEqual()
{
   {
      const std::string caseLabel = "lessEqual for integer type";
      VERIFY(sutil::lessEqual(2, 3), caseLabel);
      VERIFY(sutil::lessEqual(2, 2), caseLabel);
   }
   {
      const std::string caseLabel = "lessEqual for floating point type";
      VERIFY(sutil::lessEqual(2.123, 2.1234), caseLabel);
      VERIFY(sutil::lessEqual(2.123, 2.123), caseLabel);
      VERIFY(sutil::lessEqual(2.00000000000000000003, 2.00000000000000000004), caseLabel);
   }
}


void testGreater()
{
   {
      const std::string caseLabel = "greater for integer type";
      VERIFY(sutil::greater(3, 2), caseLabel);
      VERIFY(!sutil::greater(2, 2), caseLabel);
   }
   {
      const std::string caseLabel = "greater for floating point type";
      VERIFY(sutil::greater(2.1234, 2.123), caseLabel);
      VERIFY(!sutil::greater(2.123, 2.123), caseLabel);
      VERIFY(!sutil::greater(2.00000000000000000004, 2.00000000000000000003), caseLabel);
   }
}


void testGreaterEqual()
{
   {
      const std::string caseLabel = "greaterEqual for integer type";
      VERIFY(sutil::greaterEqual(3, 2), caseLabel);
      VERIFY(sutil::greaterEqual(2, 2), caseLabel);
   }
   {
      const std::string caseLabel = "greaterEqual for floating point type";
      VERIFY(sutil::greaterEqual(2.1234, 2.123), caseLabel);
      VERIFY(sutil::greaterEqual(2.123, 2.123), caseLabel);
      VERIFY(sutil::greaterEqual(2.00000000000000000004, 2.00000000000000000003), caseLabel);
   }
}


void testSqrt()
{
   {
      const std::string caseLabel = "sqrt for float type";
      VERIFY(sutil::fpEqual(sutil::sqrt(9.0f), 3.0f), caseLabel);
   }
   {
      const std::string caseLabel = "sqrt for double type";
      VERIFY(sutil::fpEqual(sutil::sqrt(9.0), 3.0), caseLabel);
   }
   {
      const std::string caseLabel = "sqrt for long double type";
      VERIFY(sutil::fpEqual(sutil::sqrt(9.0L), 3.0L), caseLabel);
   }
   {
      const std::string caseLabel = "sqrt for integer types";
      VERIFY(sutil::fpEqual(sutil::sqrt<float>(9), 3.0f), caseLabel);
   }
   {
      const std::string caseLabel = "sqrt for integer types";
      VERIFY(sutil::fpEqual(sutil::sqrt<double>(9L), 3.0), caseLabel);
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

   testEqual();
   testLess();
   testLessEqual();
   testGreater();
   testGreaterEqual();

   testSqrt();
}
