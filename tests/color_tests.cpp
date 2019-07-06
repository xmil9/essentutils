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


void testRgbSwap()
{
  {
      const string caseLabel = "Rgb swap";
      Rgb a{1, 2, 3};
      Rgb b{10, 20, 30};
      
      swap(a, b);
      
      VERIFY(a == Rgb(10, 20, 30), caseLabel);
      VERIFY(b == Rgb(1, 2, 3), caseLabel);
   }
}


void testRgbEquality()
{
   {
      const string caseLabel = "Rgb equality for equal colors";
      Rgb a{10, 20, 30};
      Rgb b{10, 20, 30};
      VERIFY(a == b, caseLabel);
   }
   {
      const string caseLabel = "Rgb equality for inequal colors";
      Rgb a{10, 20, 30};
      Rgb b{11, 20, 30};
      VERIFY(!(a == b), caseLabel);
      
      Rgb c{10, 20, 30};
      Rgb d{10, 22, 30};
      VERIFY(!(a == b), caseLabel);
      
      Rgb e{10, 20, 30};
      Rgb f{10, 20, 33};
      VERIFY(!(a == b), caseLabel);
   }
}


void testRgbInequality()
{
   {
      const string caseLabel = "Rgb inequality for inequal colors";
      Rgb a{10, 20, 30};
      Rgb b{11, 20, 30};
      VERIFY(a != b, caseLabel);
      
      Rgb c{10, 20, 30};
      Rgb d{10, 22, 30};
      VERIFY(a != b, caseLabel);
      
      Rgb e{10, 20, 30};
      Rgb f{10, 20, 33};
      VERIFY(a != b, caseLabel);
   }
   {
      const string caseLabel = "Rgb inequality for equal colors";
      Rgb a{10, 20, 30};
      Rgb b{10, 20, 30};
      VERIFY(!(a != b), caseLabel);
   }
}

} // namespace


///////////////////

void testColor()
{
   testRgbDefaultCtor();
   testRgbComponentCtor();
   testRgbSwap();
   testRgbEquality();
   testRgbInequality();
}
