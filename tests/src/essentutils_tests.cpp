//
// essentutils tests
// Main entry point.
//
// Jun-2019, Michael Lindner
// MIT license
//
#include "color_tests.h"
#include "string_util_tests.h"
#include <cstdlib>
#include <iostream>


int main()
{
   testColor();
   testStringUtil();

   std::cout << "essentutils tests finished.\n";
   return EXIT_SUCCESS;
}
