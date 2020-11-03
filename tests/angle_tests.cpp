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


void testFromRadians()
{
   {
      const std::string caseLabel = "Angle::fromRadians";

      using Fp = float;
      constexpr Angle a = Angle<Fp>::fromRadians(2.84f);

      VERIFY(a == 2.84f, caseLabel);
   }
}


void testFromDegrees()
{
   {
      const std::string caseLabel = "Angle::fromDegrees";

      using Fp = float;
      constexpr Angle a = Angle<Fp>::fromDegrees(90.0f);

      VERIFY(a == 0.5f * Pi<Fp>, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprAssignmentFromFp(Fp rad)
{
   Angle<Fp> a{1.0};
   a = rad;
   return a;
}

void testScalarAssignment()
{
   {
      const std::string caseLabel = "Angle::operator=(Fp val)";

      using Fp = double;
      constexpr Fp rad = 1.76;
      Angle<Fp> a;
      a = rad;

      VERIFY(a == rad, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator=(Fp val) as constexpr";

      using Fp = double;
      constexpr Fp rad = 1.76;
      constexpr Angle<Fp> a = constexprAssignmentFromFp<Fp>(rad);

      VERIFY(a == rad, caseLabel);
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
      constexpr Angle a = Angle<Fp>::fromDegrees(deg);

      VERIFY(sutil::equal(a.degrees(), deg), caseLabel);
   }
}


void testRadiansAccessor()
{
   {
      const std::string caseLabel = "Angle::radians()";

      using Fp = double;
      constexpr Fp rad = -1.28;
      constexpr Angle a = Angle<Fp>::fromRadians(rad);

      VERIFY(a.radians() == rad, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprCompoundAddition()
{
   Angle<Fp> a{1.64f};
   Angle<Fp> b{-1.0f};
   a += b;
   return a;
}

void testCompoundAddition()
{
   {
      const std::string caseLabel = "Angle::operator+=(Angle)";

      using Fp = float;
      Angle a{1.64f};
      Angle b{-1.0f};
      a += b;

      VERIFY(a == 0.64f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator+=(Angle) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprCompoundAddition<Fp>();

      VERIFY(a == 0.64f, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprCompoundScalarAddition()
{
   Angle<Fp> a{1.64f};
   a += -1.0f;
   return a;
}

void testCompoundScalarAddition()
{
   {
      const std::string caseLabel = "Angle::operator+=(Scalar)";

      using Fp = float;
      Angle a{1.64f};
      a += -1.0f;

      VERIFY(a == 0.64f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator+=(Scalar) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprCompoundScalarAddition<Fp>();

      VERIFY(a == 0.64f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator+=(Scalar) with integer scalar";

      using Fp = float;
      Angle a{1.64f};
      a += -1;

      VERIFY(a == 0.64f, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprCompoundSubtraction()
{
   Angle<Fp> a{1.74f};
   Angle<Fp> b{-1.0f};
   a -= b;
   return a;
}

void testCompoundSubtraction()
{
   {
      const std::string caseLabel = "Angle::operator-=(Angle)";

      using Fp = float;
      Angle a{1.64f};
      Angle b{-1.0f};
      a -= b;

      VERIFY(a == 2.64f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator-=(Angle) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprCompoundSubtraction<Fp>();

      VERIFY(a == 2.74f, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprCompoundScalarSubtraction()
{
   Angle<Fp> a{1.74f};
   a -= -1.0f;
   return a;
}

void testCompoundScalarSubtraction()
{
   {
      const std::string caseLabel = "Angle::operator-=(Scalar)";

      using Fp = float;
      Angle a{1.64f};
      a -= -1.0f;

      VERIFY(a == 2.64f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator-=(Scalar) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprCompoundScalarSubtraction<Fp>();

      VERIFY(a == 2.74f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator-=(Scalar) with integer scalar";

      using Fp = float;
      Angle a{1.64f};
      a -= -1;

      VERIFY(a == 2.64f, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprCompoundMultiplication()
{
   Angle<Fp> a{2.0f};
   Angle<Fp> b{-1.5f};
   a *= b;
   return a;
}

void testCompoundMultiplication()
{
   {
      const std::string caseLabel = "Angle::operator*=(Angle)";

      using Fp = float;
      Angle a{2.0f};
      Angle b{-1.5f};
      a *= b;

      VERIFY(a == -3.0f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator*=(Angle) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprCompoundMultiplication<Fp>();

      VERIFY(a == -3.0f, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprCompoundScalarMultiplication()
{
   Angle<Fp> a{2.0f};
   a *= 1.5f;
   return a;
}

void testCompoundScalarMultiplication()
{
   {
      const std::string caseLabel = "Angle::operator*=(Scalar)";

      using Fp = float;
      Angle a{2.0f};
      a *= -1.5f;

      VERIFY(a == -3.0f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator*=(Scalar) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprCompoundScalarMultiplication<Fp>();

      VERIFY(a == 3.0f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator*=(Scalar) with integer scalar";

      using Fp = float;
      Angle a{.2f};
      a *= -2;

      VERIFY(a == -.4f, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprCompoundDivision()
{
   Angle<Fp> a{6.0f};
   Angle<Fp> b{2.0f};
   a /= b;
   return a;
}

void testCompoundDivision()
{
   {
      const std::string caseLabel = "Angle::operator/=(Angle)";

      using Fp = float;
      Angle a{6.0f};
      Angle b{2.0f};
      a /= b;

      VERIFY(a == 3.0f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator/=(Angle) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprCompoundDivision<Fp>();

      VERIFY(a == 3.0f, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprCompoundScalarDivision()
{
   Angle<Fp> a{6.0f};
   a /= 3.0f;
   return a;
}

void testCompoundScalarDivision()
{
   {
      const std::string caseLabel = "Angle::operator/=(Scalar)";

      using Fp = float;
      Angle a{6.0f};
      a /= 3.0f;

      VERIFY(a == 2.0f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator/=(Scalar) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprCompoundScalarDivision<Fp>();

      VERIFY(a == 2.0f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle::operator/=(Scalar) with integer scalar";

      using Fp = float;
      Angle a{6.0f};
      a /= 3;

      VERIFY(a == 2.0f, caseLabel);
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


void testEqualityWithScalar()
{
   {
      const std::string caseLabel = "Equality for equal angle and scalar.";

      using Fp = float;
      constexpr Fp s = 1.64f;
      constexpr Angle a{s};

      VERIFY(a == s, caseLabel);
      VERIFY(s == a, caseLabel);
   }
   {
      const std::string caseLabel = "Equality for unequal angle and scalar.";

      using Fp = float;
      constexpr Fp s = 1.64f;
      const Angle a{0.47f};

      VERIFY(!(a == s), caseLabel);
      VERIFY(!(s == a), caseLabel);
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


void testInequalityWithScalar()
{
   {
      const std::string caseLabel = "Inequality for equal angle and scalar.";

      using Fp = float;
      constexpr Fp s = 1.64f;
      constexpr Angle a{s};

      VERIFY(!(a != s), caseLabel);
      VERIFY(!(s != a), caseLabel);
   }
   {
      const std::string caseLabel = "Inequality for unequal angle and scalar.";

      using Fp = float;
      constexpr Fp s = 1.64f;
      const Angle a{0.47f};

      VERIFY(a != s, caseLabel);
      VERIFY(s != a, caseLabel);
   }
}


void testLess()
{
   {
      const std::string caseLabel = "Less-than for angles.";

      using Fp = float;
      constexpr Angle a{1.64f};
      constexpr Angle b{1.0f};
      constexpr Angle c{2.0f};

      VERIFY(!(a < a), caseLabel);
      VERIFY(!(a < b), caseLabel);
      VERIFY(a < c, caseLabel);
   }
}


void testLessWithScalar()
{
   {
      const std::string caseLabel = "Less-than for angle and scalar.";

      using Fp = float;
      constexpr Angle a{1.64f};
      constexpr Fp b{1.64f};
      constexpr Fp c{1.0f};
      constexpr Fp d{2.0f};

      VERIFY(!(a < b), caseLabel);
      VERIFY(!(a < c), caseLabel);
      VERIFY(a < d, caseLabel);
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


void testLessEqualWithScalar()
{
   {
      const std::string caseLabel = "Less-equal-than for angle and scalar.";

      using Fp = float;
      constexpr Angle a{1.64f};
      constexpr Fp b{1.64f};
      constexpr Fp c{1.0f};
      constexpr Fp d{2.0f};

      VERIFY(a <= b, caseLabel);
      VERIFY(!(a <= c), caseLabel);
      VERIFY(a <= d, caseLabel);
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


void testGreaterWithScalar()
{
   {
      const std::string caseLabel = "Greater-than for angle and scalar.";

      using Fp = float;
      const Angle a{1.64f};
      constexpr Fp b{1.64f};
      constexpr Fp c{1.0f};
      constexpr Fp d{2.0f};

      VERIFY(!(a > b), caseLabel);
      VERIFY(a > c, caseLabel);
      VERIFY(!(a > d), caseLabel);
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


void testGreaterEqualWithScalar()
{
   {
      const std::string caseLabel = "Greater-equal-than for angle and scalar.";

      using Fp = float;
      constexpr Angle a{1.64f};
      constexpr Fp b{1.64f};
      constexpr Fp c{1.0f};
      constexpr Fp d{2.0f};

      VERIFY(a >= b, caseLabel);
      VERIFY(a >= c, caseLabel);
      VERIFY(!(a >= d), caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprAddition()
{
   constexpr Angle<Fp> a{1.2f};
   constexpr Angle<Fp> b{-1.0f};
   return a + b;
}

void testAddition()
{
   {
      const std::string caseLabel = "Angle operator+(Angle, Angle)";

      using Fp = float;
      const Angle a{1.64f};
      const Angle b{-1.0f};
      const Angle c = a + b;

      VERIFY(c == 0.64f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle operator+(Angle, Angle) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprAddition<Fp>();

      VERIFY(a == 0.2f, caseLabel);
   }
}


void testAdditionWithScalar()
{
   {
      const std::string caseLabel = "Angle operator+(Angle, Scalar)";

      using Fp = float;
      constexpr Angle a{1.64f};
      constexpr Angle c = a + -1.0f;

      VERIFY(c == 0.64f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle operator+(Angle, Scalar) with integer scalar";

      using Fp = float;
      constexpr Angle a{1.64f};
      constexpr Angle c = a + -1;

      VERIFY(c == 0.64f, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprSubstraction()
{
   constexpr Angle<Fp> a{1.7f};
   constexpr Angle<Fp> b{-.8f};
   return a - b;
}

void testSubstraction()
{
   {
      const std::string caseLabel = "Angle operator-(Angle, Angle)";

      using Fp = float;
      const Angle a{1.5f};
      const Angle b{-1.0f};
      const Angle c = a - b;

      VERIFY(c == 2.5f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle operator-(Angle, Angle) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprSubstraction<Fp>();

      VERIFY(a == 2.5f, caseLabel);
   }
}


void testSubtractionWithScalar()
{
   {
      const std::string caseLabel = "Angle operator-(Angle, Scalar)";

      using Fp = float;
      constexpr Angle a{1.64f};
      constexpr Angle c = a - -1.0f;

      VERIFY(c == 2.64f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle operator-(Angle, Scalar) with integer scalar";

      using Fp = float;
      constexpr Angle a{1.64f};
      constexpr Angle c = a - -1;

      VERIFY(c == 2.64f, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprMultiplication()
{
   constexpr Angle<Fp> a{1.2f};
   constexpr Angle<Fp> b{2.0f};
   return a * b;
}

void testMultiplication()
{
   {
      const std::string caseLabel = "Angle operator*(Angle, Angle)";

      using Fp = float;
      const Angle a{1.6f};
      const Angle b{-.5f};
      const Angle c = a * b;

      VERIFY(c == -.8f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle operator*(Angle, Angle) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprMultiplication<Fp>();

      VERIFY(a == 2.4f, caseLabel);
   }
}


void testMultiplicationWithScalar()
{
   {
      const std::string caseLabel = "Angle operator*(Angle, Scalar)";

      using Fp = float;
      constexpr Angle a{1.2f};
      constexpr Angle c = a * 2.0f;

      VERIFY(c == 2.4f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle operator*(Angle, Scalar) with integer scalar";

      using Fp = float;
      constexpr Angle a{1.2f};
      constexpr Angle c = a * 2;

      VERIFY(c == 2.4f, caseLabel);
   }
}


template <typename Fp> constexpr Angle<Fp> constexprDivision()
{
   constexpr Angle<Fp> a{1.2f};
   constexpr Angle<Fp> b{2.0f};
   return a / b;
}

void testDivision()
{
   {
      const std::string caseLabel = "Angle operator/(Angle, Angle)";

      using Fp = float;
      const Angle a{1.6f};
      const Angle b{4.f};
      const Angle c = a / b;

      VERIFY(c == .4f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle operator/(Angle, Angle) as constexpr";

      using Fp = float;
      constexpr Angle a = constexprDivision<Fp>();

      VERIFY(a == .6f, caseLabel);
   }
}


void testDivisionWithScalar()
{
   {
      const std::string caseLabel = "Angle operator/(Angle, Scalar)";

      using Fp = float;
      constexpr Angle a{1.2f};
      constexpr Angle c = a / 2.0f;

      VERIFY(c == .6f, caseLabel);
   }
   {
      const std::string caseLabel = "Angle operator/(Angle, Scalar) with integer scalar";

      using Fp = float;
      constexpr Angle a{1.2f};
      constexpr Angle c = a / 2;

      VERIFY(c == .6f, caseLabel);
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
   testFromRadians();
   testFromDegrees();
   testScalarAssignment();
   testConversionToFp();
   testRadiansAccessor();
   testDegreesAccessor();
   testCompoundAddition();
   testCompoundScalarAddition();
   testCompoundSubtraction();
   testCompoundScalarSubtraction();
   testCompoundMultiplication();
   testCompoundScalarMultiplication();
   testCompoundDivision();
   testCompoundScalarDivision();
   testSwap();
   testEquality();
   testEqualityWithScalar();
   testInequality();
   testInequalityWithScalar();
   testLess();
   testLessWithScalar();
   testLessEqual();
   testLessEqualWithScalar();
   testGreater();
   testGreaterWithScalar();
   testGreaterEqual();
   testGreaterEqualWithScalar();
   testAddition();
   testAdditionWithScalar();
   testSubstraction();
   testSubtractionWithScalar();
   testMultiplication();
   testMultiplicationWithScalar();
   testDivision();
   testDivisionWithScalar();
   testHashing();
}
