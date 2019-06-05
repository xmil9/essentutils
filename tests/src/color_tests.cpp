//
// essentutils tests
// Tests for color utilities.
//
// Jun-2019, Michael Lindner
// MIT license
//
#include "color_tests.h"
#include "color.h"
#include "test_util.h"

using namespace std;
using namespace sutil;


namespace
{
///////////////////

void testRgbDefaultCtor()
{
   {
      const string caseLabel = "Rgb default ctor";
      Rgb rgb;
      VERIFY(rgb.r == 0, caseLabel);
      VERIFY(rgb.g == 0, caseLabel);
      VERIFY(rgb.b == 0, caseLabel);
   }
}

void testRgbComponentCtor()
{
   {
      const string caseLabel = "Rgb component ctor";
      Rgb rgb{1, 2, 3};
      VERIFY(rgb.r == 1, caseLabel);
      VERIFY(rgb.g == 2, caseLabel);
      VERIFY(rgb.b == 3, caseLabel);
   }
}

} // namespace


///////////////////

void testColor()
{
   testRgbDefaultCtor();
   testRgbComponentCtor();
}
