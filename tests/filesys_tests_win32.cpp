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


namespace
{
///////////////////

void testAppDirectory()
{
   {
      const std::string caseLabel = "appDirectory";
      const std::filesystem::path dir = esl::appDirectory();
      VERIFY(!dir.empty(), caseLabel);
   }
}


void testUserDirectory()
{
   {
      const std::string caseLabel = "userDirectory";
      const std::filesystem::path dir = esl::userDirectory();
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
