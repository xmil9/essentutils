//
// essentutils tests
// Tests for Angle clas.
//
// Oct-2020, Michael Lindner
// MIT license
//
#include "angle_tests.h"
#include "angle.h"
#include "fputil.h"
#include "math_util.h"
#include "test_util.h"
#include <unordered_map>

using namespace sutil;


namespace
{
///////////////////

void testDefaultCtor()
{
   {
      const std::string caseLabel = "Angle default ctor";

      using Fp = float;
      constexpr Angle<Fp> a;

      VERIFY(a == 0.0f, caseLabel);
   }
}


void testCtorValue()
{
   {
      const std::string caseLabel = "Angle value ctor";

      using Fp = double;
      constexpr Angle a{0.5};

      VERIFY(a == 0.5, caseLabel);
   }
}


void testMakeRadians()
{
   {
      const std::string caseLabel = "Angle::makeRadians";

      using Fp = float;
      constexpr Angle a = Angle<Fp>::makeRadians(2.84f);

      VERIFY(a == 2.84f, caseLabel);
   }
}


void testMakeDegrees()
{
   {
      const std::string caseLabel = "Angle::makeDegrees";

      using Fp = float;
      constexpr Angle a = Angle<Fp>::makeDegrees(90.0f);

      VERIFY(a == 0.5f * Pi<Fp>, caseLabel);
   }
}


void testConversionToFp()
{
   {
      const std::string caseLabel = "Angle::operator Fp()";

      using Fp = double;
      constexpr Fp rad = 1.76;
      constexpr Angle a{rad};

      VERIFY(a.operator double() == rad, caseLabel);
   }
}


void testDegreesAccessor()
{
   {
      const std::string caseLabel = "Angle::degrees()";

      using Fp = double;
      constexpr Fp deg = 57.28;
      constexpr Angle a = Angle<Fp>::makeDegrees(deg);

      VERIFY(sutil::equal(a.degrees(), deg), caseLabel);
   }
}


void testRadiansAccessor()
{
   {
      const std::string caseLabel = "Angle::radians()";

      using Fp = double;
      constexpr Fp rad = -1.28;
      constexpr Angle a = Angle<Fp>::makeRadians(rad);

      VERIFY(a == rad, caseLabel);
   }
}


void testSwap()
{
   {
      const std::string caseLabel = "Angle swap";

      using Fp = float;
      Angle a{1.64f};
      Angle b{-0.93f};
      swap(a, b);

      VERIFY(a == -0.93f, caseLabel);
      VERIFY(b == 1.64f, caseLabel);
   }
}


void testEquality()
{
   {
      const std::string caseLabel = "Equality for equal angles.";

      using Fp = float;
      const Angle a{1.64f};
      const Angle b = a;

      VERIFY(a == b, caseLabel);
   }
   {
      const std::string caseLabel = "Equality for unequal angles.";

      using Fp = float;
      const Angle a{1.64f};
      const Angle b{0.47f};

      VERIFY(!(a == b), caseLabel);
   }
}


void testInequality()
{
   {
      const std::string caseLabel = "Inequality for equal angles.";

      using Fp = float;
      const Angle a{1.64f};
      const Angle b = a;

      VERIFY(!(a != b), caseLabel);
   }
   {
      const std::string caseLabel = "Inequality for unequal angles.";

      using Fp = float;
      const Angle a{1.64f};
      const Angle b{0.47f};

      VERIFY(a != b, caseLabel);
   }
}


void testLess()
{
   {
      const std::string caseLabel = "Less-than for angles.";

      using Fp = float;
      const Angle a{1.64f};
      const Angle b{1.0f};
      const Angle c{2.0f};

      VERIFY(!(a < a), caseLabel);
      VERIFY(!(a < b), caseLabel);
      VERIFY(a < c, caseLabel);
   }
}


void testLessEqual()
{
   {
      const std::string caseLabel = "Less-equal-than for angles.";

      using Fp = float;
      const Angle a{1.64f};
      const Angle b{1.0f};
      const Angle c{2.0f};

      VERIFY(a <= a, caseLabel);
      VERIFY(!(a <= b), caseLabel);
      VERIFY(a <= c, caseLabel);
   }
}


void testGreater()
{
   {
      const std::string caseLabel = "Greater-than for angles.";

      using Fp = float;
      const Angle a{1.64f};
      const Angle b{1.0f};
      const Angle c{2.0f};

      VERIFY(!(a > a), caseLabel);
      VERIFY(a > b, caseLabel);
      VERIFY(!(a > c), caseLabel);
   }
}


void testGreaterEqual()
{
   {
      const std::string caseLabel = "Greater-equal-than for angles.";

      using Fp = float;
      const Angle a{1.64f};
      const Angle b{1.0f};
      const Angle c{2.0f};

      VERIFY(a >= a, caseLabel);
      VERIFY(a >= b, caseLabel);
      VERIFY(!(a >= c), caseLabel);
   }
}


void testHashing()
{
   {
      const std::string caseLabel = "Angle hashing.";

      using Fp = float;
      const Angle a{1.64f};
      const Angle b{1.0f};
      const Angle c{2.0f};

      std::unordered_map<Angle<Fp>, int> map;
      map[a] = 1;
      map[b] = 2;
      map[c] = 3;

      VERIFY(map[a] == 1, caseLabel);
      VERIFY(map[b] == 2, caseLabel);
      VERIFY(map[c] == 3, caseLabel);
   }
}

} // namespace


///////////////////

void testAngle()
{
   testDefaultCtor();
   testCtorValue();
   testMakeRadians();
   testMakeDegrees();
   testConversionToFp();
   testRadiansAccessor();
   testDegreesAccessor();
   testSwap();
   testEquality();
   testInequality();
   testLess();
   testLessEqual();
   testGreater();
   testGreaterEqual();
   testHashing();
}
