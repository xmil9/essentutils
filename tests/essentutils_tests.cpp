//
// essentutils tests
// Main entry point.
//
// Jun-2019, Michael Lindner
// MIT license
//
#include "color_tests.h"
#include "filesys_tests.h"
#include "fputil_tests.h"
#include "math_util_tests.h"
#include "string_util_tests.h"
#include <cstdlib>
#include <iostream>


int main()
{
   testColor();
   testFilesys();
   testFpUtil();
   testMathUtil();
   testStringUtil();

   std::cout << "essentutils tests finished.\n";
   return EXIT_SUCCESS;
}
