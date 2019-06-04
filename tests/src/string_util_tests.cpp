#include "string_util_tests.h"
#include "string_util.h"
#include "test_util.h"
#include <set>
#include <vector>

using namespace std;
using namespace sutil;


namespace
{
///////////////////

void testStartsWith()
{
   {
      const string caseLabel = "startsWith for string starting with other";
      VERIFY(startsWith("abcdefg", "abc"), caseLabel);
   }
   {
      const string caseLabel = "startsWith for same string";
      VERIFY(startsWith("abc", "abc"), caseLabel);
   }
   {
      const string caseLabel = "startsWith for prefix string longer than target string";
      VERIFY(!startsWith("abc", "abcdef"), caseLabel);
   }
   {
      const string caseLabel = "startsWith for single character prefix string";
      VERIFY(startsWith("abc", "a"), caseLabel);
   }
   {
      const string caseLabel = "startsWith for empty prefix string";
      VERIFY(startsWith("abc", ""), caseLabel);
   }
   {
      const string caseLabel = "startsWith for empty target string";
      VERIFY(!startsWith("", "abc"), caseLabel);
   }
   {
      const string caseLabel = "startsWith for empty strings";
      VERIFY(startsWith("", ""), caseLabel);
   }
   {
      const string caseLabel = "startsWith for string not starting with other";
      VERIFY(!startsWith("abcdefg", "123"), caseLabel);
   }
   {
      const string caseLabel = "startsWith for string ending with other";
      VERIFY(!startsWith("abcdefg", "efg"), caseLabel);
   }
   {
      const string caseLabel = "startsWith for string containing other";
      VERIFY(!startsWith("abcdefg", "bcd"), caseLabel);
   }
}


void testEndsWith()
{
   {
      const string caseLabel = "endsWith for string enfing with other";
      VERIFY(endsWith("abcdefg", "fg"), caseLabel);
   }
   {
      const string caseLabel = "endsWith for same string";
      VERIFY(endsWith("abc", "abc"), caseLabel);
   }
   {
      const string caseLabel = "endsWith for tail string longer than target string";
      VERIFY(!endsWith("abc", "abczx"), caseLabel);
   }
   {
      const string caseLabel = "endsWith for single character tail string";
      VERIFY(endsWith("abc", "c"), caseLabel);
   }
   {
      const string caseLabel = "endsWith for empty tail string";
      VERIFY(endsWith("abc", ""), caseLabel);
   }
   {
      const string caseLabel = "endsWith for empty target string";
      VERIFY(!endsWith("", "abc"), caseLabel);
   }
   {
      const string caseLabel = "endsWith for empty strings";
      VERIFY(endsWith("", ""), caseLabel);
   }
   {
      const string caseLabel = "endsWith for string not ending with other";
      VERIFY(!endsWith("abcdefg", "123"), caseLabel);
   }
   {
      const string caseLabel = "endsWith for string starting with other";
      VERIFY(!endsWith("abcdefg", "abc"), caseLabel);
   }
   {
      const string caseLabel = "endsWith for string containing other";
      VERIFY(!endsWith("abcdefg", "ef"), caseLabel);
   }
}


void testLowercase()
{
   {
      const string caseLabel = "lowercase for English alphabet";
      VERIFY(lowercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == "abcdefghijklmnopqrstuvwxyz", caseLabel);
   }
   {
      const string caseLabel = "lowercase for lowercase characters";
      VERIFY(lowercase("abcdefghijklmnopqrstuvwxyz") == "abcdefghijklmnopqrstuvwxyz", caseLabel);
   }
   {
      const string caseLabel = "lowercase for digits characters";
      VERIFY(lowercase("1234567890") == "1234567890", caseLabel);
   }
   {
      const string caseLabel = "lowercase for other characters";
      VERIFY(lowercase("!@#$%^&*()_+=-;://?.>,<") == "!@#$%^&*()_+=-;://?.>,<", caseLabel);
   }
   {
      const string caseLabel = "lowercase for control characters";
      VERIFY(lowercase("\n\t\r") == "\n\t\r", caseLabel);
   }
   {
      const string caseLabel = "lowercase for empty string";
      VERIFY(lowercase("") == "", caseLabel);
   }
}


void testUppercase()
{
   {
      const string caseLabel = "uppercase for English alphabet";
      VERIFY(uppercase("abcdefghijklmnopqrstuvwxyz") == "ABCDEFGHIJKLMNOPQRSTUVWXYZ", caseLabel);
   }
   {
      const string caseLabel = "uppercase for uppercase characters";
      VERIFY(uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == "ABCDEFGHIJKLMNOPQRSTUVWXYZ", caseLabel);
   }
   {
      const string caseLabel = "uppercase for digits characters";
      VERIFY(uppercase("1234567890") == "1234567890", caseLabel);
   }
   {
      const string caseLabel = "uppercase for other characters";
      VERIFY(uppercase("!@#$%^&*()_+=-;://?.>,<") == "!@#$%^&*()_+=-;://?.>,<", caseLabel);
   }
   {
      const string caseLabel = "uppercase for control characters";
      VERIFY(uppercase("\n\t\r") == "\n\t\r", caseLabel);
   }
   {
      const string caseLabel = "uppercase for empty string";
      VERIFY(uppercase("") == "", caseLabel);
   }
}


void testTrim()
{
   {
      const string caseLabel = "trim single leading space";
      VERIFY(trim(" abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim multiple leading spaces";
      VERIFY(trim("     abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim single trailing space";
      VERIFY(trim("abc ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim multiple trailing spaces";
      VERIFY(trim("abc   ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim single leading and trailing space";
      VERIFY(trim(" abc ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim multiple leading and trailing spaces";
      VERIFY(trim("     abc  ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim non-space character";
      VERIFY(trim("zzzzabczz", 'z') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim control character character";
      VERIFY(trim("\nabc\n\n", '\n') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim nothing";
      VERIFY(trim("abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim empty string";
      VERIFY(trim("", ' ') == "", caseLabel);
   }
   {
      const string caseLabel = "trim everything";
      VERIFY(trim("     ", ' ') == "", caseLabel);
   }
}


void testTrimLeft()
{
   {
      const string caseLabel = "trimLeft single space";
      VERIFY(trimLeft(" abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft multiple spaces";
      VERIFY(trimLeft("     abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft trailing space";
      VERIFY(trimLeft("abc ", ' ') == "abc ", caseLabel);
   }
   {
      const string caseLabel = "trimLeft non-space character";
      VERIFY(trimLeft("zzzzabc", 'z') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft control character character";
      VERIFY(trimLeft("\n\nabc", '\n') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft nothing";
      VERIFY(trimLeft("abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft empty string";
      VERIFY(trimLeft("", ' ') == "", caseLabel);
   }
   {
      const string caseLabel = "trimLeft everything";
      VERIFY(trimLeft("     ", ' ') == "", caseLabel);
   }
}


void testTrimRight()
{
   {
      const string caseLabel = "trimRight single space";
      VERIFY(trimRight("abc ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight multiple spaces";
      VERIFY(trimRight("abc   ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight leading space";
      VERIFY(trimRight(" abc", ' ') == " abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight non-space character";
      VERIFY(trimRight("abczzzz", 'z') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight control character character";
      VERIFY(trimRight("abc\n\n", '\n') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight nothing";
      VERIFY(trimRight("abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight empty string";
      VERIFY(trimRight("", ' ') == "", caseLabel);
   }
   {
      const string caseLabel = "trimRight everything";
      VERIFY(trimRight("     ", ' ') == "", caseLabel);
   }
}


void testSplit()
{
   {
      const string caseLabel = "split at spaces";
      const vector<string> expected{"abc", "de", "fghi"};
      VERIFY(split("abc de fghi", " ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split at other character";
      const vector<string> expected{"abc", "de", "fghi"};
      VERIFY(split("abc:de:fghi", ":") == expected, caseLabel);
   }
   {
      const string caseLabel = "split at control character";
      const vector<string> expected{"abc", "de", "fghi"};
      VERIFY(split("abc\nde\nfghi", "\n") == expected, caseLabel);
   }
   {
      const string caseLabel = "split at string";
      const vector<string> expected{"abc", "de", "fghi"};
      VERIFY(split("abc<sep>de<sep>fghi", "<sep>") == expected, caseLabel);
   }
   {
      const string caseLabel = "split string without separator";
      const vector<string> expected{"abc"};
      VERIFY(split("abc", " ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split string leading separator";
      const vector<string> expected{"", "abc"};
      VERIFY(split(" abc", " ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split string trailing separator";
      const vector<string> expected{"abc", ""};
      VERIFY(split("abc ", " ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split string with only separators";
      const vector<string> expected{"", "", ""};
      VERIFY(split("  ", " ") == expected, caseLabel);
   }
}


void testJoin()
{
   {
      const string caseLabel = "join with spaces";
      const vector<string> input{"abc", "de", "fghi"};
      VERIFY(join(input.begin(), input.end(), " ") == "abc de fghi", caseLabel);
   }
   {
      const string caseLabel = "join with other string";
      const vector<string> input{"abc", "de", "fghi"};
      VERIFY(join(input.begin(), input.end(), "::") == "abc::de::fghi", caseLabel);
   }
   {
      const string caseLabel = "join without glue string";
      const vector<string> input{"abc", "de", "fghi"};
      VERIFY(join(input.begin(), input.end(), "") == "abcdefghi", caseLabel);
   }
   {
      const string caseLabel = "join with control character";
      const vector<string> input{"abc", "de", "fghi"};
      VERIFY(join(input.begin(), input.end(), "\n") == "abc\nde\nfghi", caseLabel);
   }
   {
      const string caseLabel = "join single piece";
      const vector<string> input{"abc"};
      VERIFY(join(input.begin(), input.end(), " ") == "abc", caseLabel);
   }
   {
      const string caseLabel = "join empty pieces";
      const vector<string> input{"", ""};
      VERIFY(join(input.begin(), input.end(), " ") == "", caseLabel);
   }
   {
      const string caseLabel = "join no pieces";
      const vector<string> input;
      VERIFY(join(input.begin(), input.end(), " ") == "", caseLabel);
   }
   {
      const string caseLabel = "join from other collection";
      const set<string> input{"abc", "de", "fghi"};
      VERIFY(join(input.begin(), input.end(), " ") == "abc de fghi", caseLabel);
   }
}

} // namespace


///////////////////

void testStringUtil()
{
   testStartsWith();
   testEndsWith();
   testLowercase();
   testUppercase();
   testTrim();
   testTrimLeft();
   testTrimRight();
   testSplit();
   testJoin();
}
