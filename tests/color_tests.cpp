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


namespace
{
///////////////////

void testRgbDefaultCtor()
{
   {
      const std::string caseLabel = "Rgb default ctor";
      sutil::Rgb rgb;
      VERIFY(rgb.r == 0, caseLabel);
      VERIFY(rgb.g == 0, caseLabel);
      VERIFY(rgb.b == 0, caseLabel);
   }
}

void testRgbComponentCtor()
{
   {
      const std::string caseLabel = "Rgb component ctor";
      sutil::Rgb rgb{1, 2, 3};
      VERIFY(rgb.r == 1, caseLabel);
      VERIFY(rgb.g == 2, caseLabel);
      VERIFY(rgb.b == 3, caseLabel);
   }
}


void testRgbSwap()
{
   {
      const std::string caseLabel = "Rgb swap";
      sutil::Rgb a{1, 2, 3};
      sutil::Rgb b{10, 20, 30};

      swap(a, b);

      VERIFY(a == sutil::Rgb(10, 20, 30), caseLabel);
      VERIFY(b == sutil::Rgb(1, 2, 3), caseLabel);
   }
}


void testRgbEquality()
{
   {
      const std::string caseLabel = "Rgb equality for equal colors";
      sutil::Rgb a{10, 20, 30};
      sutil::Rgb b{10, 20, 30};
      VERIFY(a == b, caseLabel);
   }
   {
      const std::string caseLabel = "Rgb equality for inequal colors";
      sutil::Rgb a{10, 20, 30};
      sutil::Rgb b{11, 20, 30};
      VERIFY(!(a == b), caseLabel);

      sutil::Rgb c{10, 20, 30};
      sutil::Rgb d{10, 22, 30};
      VERIFY(!(a == b), caseLabel);

      sutil::Rgb e{10, 20, 30};
      sutil::Rgb f{10, 20, 33};
      VERIFY(!(a == b), caseLabel);
   }
}


void testRgbInequality()
{
   {
      const std::string caseLabel = "Rgb inequality for inequal colors";
      sutil::Rgb a{10, 20, 30};
      sutil::Rgb b{11, 20, 30};
      VERIFY(a != b, caseLabel);

      sutil::Rgb c{10, 20, 30};
      sutil::Rgb d{10, 22, 30};
      VERIFY(a != b, caseLabel);

      sutil::Rgb e{10, 20, 30};
      sutil::Rgb f{10, 20, 33};
      VERIFY(a != b, caseLabel);
   }
   {
      const std::string caseLabel = "Rgb inequality for equal colors";
      sutil::Rgb a{10, 20, 30};
      sutil::Rgb b{10, 20, 30};
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
