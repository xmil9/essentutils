//
// essentutils tests
// Main entry point.
//
// Jun-2019, Michael Lindner
// MIT license
//
#include "angle_tests.h"
#include "color_tests.h"
#include "filesys_tests.h"
#include "fputil_tests.h"
#include "math_util_tests.h"
#include "rand_util_tests.h"
#include "string_util_tests.h"
#include "type_traits_util_tests.h"
#include <cstdlib>
#include <iostream>


int main()
{
   testAngle();
   testColor();
   testFilesys();
   testFpUtil();
   testMathUtil();
   testRandUtil();
   testStringUtil();
   testTypeTraitsUtil();

   std::cout << "essentutils tests finished.\n";
   return EXIT_SUCCESS;
}
