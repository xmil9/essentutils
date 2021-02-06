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
      esl::Rgb rgb;
      VERIFY(rgb.r == 0, caseLabel);
      VERIFY(rgb.g == 0, caseLabel);
      VERIFY(rgb.b == 0, caseLabel);
   }
}

void testRgbComponentCtor()
{
   {
      const std::string caseLabel = "Rgb component ctor";
      esl::Rgb rgb{1, 2, 3};
      VERIFY(rgb.r == 1, caseLabel);
      VERIFY(rgb.g == 2, caseLabel);
      VERIFY(rgb.b == 3, caseLabel);
   }
}


void testRgbSwap()
{
   {
      const std::string caseLabel = "Rgb swap";
      esl::Rgb a{1, 2, 3};
      esl::Rgb b{10, 20, 30};

      swap(a, b);

      VERIFY(a == esl::Rgb(10, 20, 30), caseLabel);
      VERIFY(b == esl::Rgb(1, 2, 3), caseLabel);
   }
}


void testRgbEquality()
{
   {
      const std::string caseLabel = "Rgb equality for equal colors";
      esl::Rgb a{10, 20, 30};
      esl::Rgb b{10, 20, 30};
      VERIFY(a == b, caseLabel);
   }
   {
      const std::string caseLabel = "Rgb equality for inequal colors";
      esl::Rgb a{10, 20, 30};
      esl::Rgb b{11, 20, 30};
      VERIFY(!(a == b), caseLabel);

      esl::Rgb c{10, 20, 30};
      esl::Rgb d{10, 22, 30};
      VERIFY(!(a == b), caseLabel);

      esl::Rgb e{10, 20, 30};
      esl::Rgb f{10, 20, 33};
      VERIFY(!(a == b), caseLabel);
   }
}


void testRgbInequality()
{
   {
      const std::string caseLabel = "Rgb inequality for inequal colors";
      esl::Rgb a{10, 20, 30};
      esl::Rgb b{11, 20, 30};
      VERIFY(a != b, caseLabel);

      esl::Rgb c{10, 20, 30};
      esl::Rgb d{10, 22, 30};
      VERIFY(a != b, caseLabel);

      esl::Rgb e{10, 20, 30};
      esl::Rgb f{10, 20, 33};
      VERIFY(a != b, caseLabel);
   }
   {
      const std::string caseLabel = "Rgb inequality for equal colors";
      esl::Rgb a{10, 20, 30};
      esl::Rgb b{10, 20, 30};
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
