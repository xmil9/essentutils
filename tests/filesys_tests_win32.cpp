//
// essentutils tests
// Tests for file system utilities.
//
// Jul-2019, Michael Lindner
// MIT license
//
#ifdef _WIN32
#include "filesys_tests.h"
#include "filesys.h"
#include "test_util.h"
#include <string>

using namespace std;
using namespace sutil;


namespace
{
///////////////////

void testAppDirectory()
{
   {
      const string caseLabel = "appDirectory";
      const filesystem::path dir = appDirectory();
      VERIFY(!dir.empty(), caseLabel);
   }
}


void testUserDirectory()
{
   {
      const string caseLabel = "userDirectory";
      const filesystem::path dir = userDirectory();
      VERIFY(!dir.empty(), caseLabel);
   }
}

} // namespace


///////////////////

void testFilesys()
{
   testAppDirectory();
   testUserDirectory();
}

#endif // _WIN32
