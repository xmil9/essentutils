//
// essentutils tests
// Tests for string utilities.
//
// Jun-2019, Michael Lindner
// MIT license
//
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
      VERIFY(lowercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == "abcdefghijklmnopqrstuvwxyz",
             caseLabel);
   }
   {
      const string caseLabel = "lowercase for lowercase characters";
      VERIFY(lowercase("abcdefghijklmnopqrstuvwxyz") == "abcdefghijklmnopqrstuvwxyz",
             caseLabel);
   }
   {
      const string caseLabel = "lowercase for digits characters";
      VERIFY(lowercase("1234567890") == "1234567890", caseLabel);
   }
   {
      const string caseLabel = "lowercase for other characters";
      VERIFY(lowercase("!@#$%^&*()_+=-;://?.>,<") == "!@#$%^&*()_+=-;://?.>,<",
             caseLabel);
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
      VERIFY(uppercase("abcdefghijklmnopqrstuvwxyz") == "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
             caseLabel);
   }
   {
      const string caseLabel = "uppercase for uppercase characters";
      VERIFY(uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
             caseLabel);
   }
   {
      const string caseLabel = "uppercase for digits characters";
      VERIFY(uppercase("1234567890") == "1234567890", caseLabel);
   }
   {
      const string caseLabel = "uppercase for other characters";
      VERIFY(uppercase("!@#$%^&*()_+=-;://?.>,<") == "!@#$%^&*()_+=-;://?.>,<",
             caseLabel);
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


void testIntFromStrThrow()
{
   {
      const string caseLabel = "intFromStrThrow for number";
      try
      {
         VERIFY(intFromStrThrow<int>("1234") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for negative number";
      try
      {
         VERIFY(intFromStrThrow<int>("-1234") == -1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for number followed by text";
      try
      {
         VERIFY(intFromStrThrow<int>("1234abc") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for number within text";
      try
      {
         intFromStrThrow<int>("abc1234def");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const string caseLabel = "intFromStrThrow for number starting with zeros";
      try
      {
         VERIFY(intFromStrThrow<int>("000001234") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for zero";
      try
      {
         VERIFY(intFromStrThrow<int>("0") == 0, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for multiple zeros";
      try
      {
         VERIFY(intFromStrThrow<int>("00000") == 0, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for multiple numbers separated by space";
      try
      {
         VERIFY(intFromStrThrow<int>("1 2 3") == 1, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for too large number";
      try
      {
         intFromStrThrow<int>(
            "9999999999999999999999999999999999999999999999999999999999999999999999");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const string caseLabel = "intFromStrThrow for int8_t";
      try
      {
         VERIFY(intFromStrThrow<int8_t>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for int16_t";
      try
      {
         VERIFY(intFromStrThrow<int16_t>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for int32_t";
      try
      {
         VERIFY(intFromStrThrow<int32_t>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for int64_t";
      try
      {
         VERIFY(intFromStrThrow<int64_t>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for char";
      try
      {
         VERIFY(intFromStrThrow<char>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for unsigned char";
      try
      {
         VERIFY(intFromStrThrow<unsigned char>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for short";
      try
      {
         VERIFY(intFromStrThrow<short>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for unsigned short";
      try
      {
         VERIFY(intFromStrThrow<unsigned short>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for long";
      try
      {
         VERIFY(intFromStrThrow<long>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for unsigned long";
      try
      {
         VERIFY(intFromStrThrow<unsigned long>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for long long";
      try
      {
         VERIFY(intFromStrThrow<long long>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow for unsigned long long";
      try
      {
         VERIFY(intFromStrThrow<unsigned long long>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
}


void testIntFromStrWithDefault()
{
   {
      const string caseLabel = "intFromStr with default for number";
      VERIFY(intFromStr<int>("1234", 98) == 1234, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for negative number";
      VERIFY(intFromStr<int>("-1234", 98) == -1234, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for number followed by text";
      VERIFY(intFromStr<int>("1234abc", 98) == 1234, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for number within text";
      VERIFY(intFromStr<int>("abc1234def", 98) == 98, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for number starting with zeros";
      VERIFY(intFromStr<int>("000001234", 98) == 1234, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for zero";
      VERIFY(intFromStr<int>("0", 98) == 0, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for multiple zeros";
      VERIFY(intFromStr<int>("00000", 98) == 0, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr with default for multiple numbers separated by space";
      VERIFY(intFromStr<int>("1 2 3", 98) == 1, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for too large number";
      VERIFY(intFromStr<int>(
                "9999999999999999999999999999999999999999999999999999999999999999999999",
                98) == 98,
             caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for int8_t";
      VERIFY(intFromStr<int8_t>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for int16_t";
      VERIFY(intFromStr<int16_t>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for int32_t";
      VERIFY(intFromStr<int32_t>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for int64_t";
      VERIFY(intFromStr<int64_t>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for char";
      VERIFY(intFromStr<char>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for unsigned char";
      VERIFY(intFromStr<unsigned char>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for short";
      VERIFY(intFromStr<short>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for unsigned short";
      VERIFY(intFromStr<unsigned short>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for long";
      VERIFY(intFromStr<long>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for unsigned long";
      VERIFY(intFromStr<unsigned long>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for long long";
      VERIFY(intFromStr<long long>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with default for unsigned long long";
      VERIFY(intFromStr<unsigned long long>("12", 98) == 12, caseLabel);
   }
}


void testIntFromStrWithOptional()
{
   {
      const string caseLabel = "intFromStr with optional for number";
      VERIFY(intFromStr<int>("1234") == optional{1234}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for negative number";
      VERIFY(intFromStr<int>("-1234") == optional{-1234}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for number followed by text";
      VERIFY(intFromStr<int>("1234abc") == optional{1234}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for number within text";
      VERIFY(intFromStr<int>("abc1234def") == optional<int>{}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for number starting with zeros";
      VERIFY(intFromStr<int>("000001234") == optional{1234}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for zero";
      VERIFY(intFromStr<int>("0") == optional{0}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for multiple zeros";
      VERIFY(intFromStr<int>("00000") == optional{0}, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr with optional for multiple numbers separated by space";
      VERIFY(intFromStr<int>("1 2 3") == optional{1}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for too large number";
      VERIFY(
         intFromStr<int>(
            "9999999999999999999999999999999999999999999999999999999999999999999999") ==
            optional<int>{},
         caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for int8_t";
      VERIFY(intFromStr<int8_t>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for int16_t";
      VERIFY(intFromStr<int16_t>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for int32_t";
      VERIFY(intFromStr<int32_t>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for int64_t";
      VERIFY(intFromStr<int64_t>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for char";
      VERIFY(intFromStr<char>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for unsigned char";
      VERIFY(intFromStr<unsigned char>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for short";
      VERIFY(intFromStr<short>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for unsigned short";
      VERIFY(intFromStr<unsigned short>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for long";
      VERIFY(intFromStr<long>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for unsigned long";
      VERIFY(intFromStr<unsigned long>("12") == optional<unsigned long>{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for long long";
      VERIFY(intFromStr<long long>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr with optional for unsigned long long";
      VERIFY(intFromStr<unsigned long long>("12") == optional<unsigned long long>{12},
             caseLabel);
   }
}


void testFpFromStrThrow()
{
   {
      const string caseLabel = "fpFromStrThrow for number";
      try
      {
         VERIFY(fpFromStrThrow<float>("123.4") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for number with many decimals";
      try
      {
         VERIFY(fpFromStrThrow<float>("123.4567890123456789") == 123.4567890123456789f,
                caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for integer number";
      try
      {
         VERIFY(fpFromStrThrow<float>("1234") == 1234.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for negative number";
      try
      {
         VERIFY(fpFromStrThrow<float>("-123.4") == -123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for number followed by text";
      try
      {
         VERIFY(fpFromStrThrow<float>("123.4abc") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for number within text";
      try
      {
         fpFromStrThrow<float>("abc123.4def");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for number starting with zeros";
      try
      {
         VERIFY(fpFromStrThrow<float>("00000123.4") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for zero";
      try
      {
         VERIFY(fpFromStrThrow<float>("0") == 0.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for multiple zeros";
      try
      {
         VERIFY(fpFromStrThrow<float>("00000") == 0.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for multiple numbers separated by space";
      try
      {
         VERIFY(fpFromStrThrow<float>("1 2 3") == 1.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for multiple decimal points";
      try
      {
         VERIFY(fpFromStrThrow<float>("1.2.3") == 1.2f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for too large number";
      try
      {
         fpFromStrThrow<float>(
            "9999999999999999999999999999999999999999999999999999999999999999999999.9");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for double";
      try
      {
         VERIFY(fpFromStrThrow<double>("12.34") == 12.34, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow for long double";
      try
      {
         VERIFY(fpFromStrThrow<long double>("12.34") == 12.34L, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
}


void testFpFromStrWithDefault()
{
   {
      const string caseLabel = "fpFromStr with default for number";
      VERIFY(fpFromStr<float>("123.4", 98.0f) == 123.4f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for number with many decimals";
      VERIFY(fpFromStr<float>("123.4567890123456789", 98.0f) == 123.4567890123456789f,
             caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for integer number";
      VERIFY(fpFromStr<float>("1234", 98.0f) == 1234.0f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for negative number";
      VERIFY(fpFromStr<float>("-123.4", 98.0f) == -123.4f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for number followed by text";
      VERIFY(fpFromStr<float>("123.4abc", 98.0f) == 123.4f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for number within text";
      VERIFY(fpFromStr<float>("abc123.4def", 98.0f) == 98.0f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for number starting with zeros";
      VERIFY(fpFromStr<float>("00000123.4", 98.0f) == 123.4f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for zero";
      VERIFY(fpFromStr<float>("0", 98.0f) == 0.0f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for multiple zeros";
      VERIFY(fpFromStr<float>("00000", 98.0f) == 0.0f, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr with default for multiple numbers separated by space";
      VERIFY(fpFromStr<float>("1 2 3", 98.0f) == 1.0f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for multiple decimal points";
      VERIFY(fpFromStr<float>("1.2.3", 98.0f) == 1.2f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for too large number";
      VERIFY(
         fpFromStr<float>(
            "9999999999999999999999999999999999999999999999999999999999999999999999.9",
            98.0f) == 98.0f,
         caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for double";
      VERIFY(fpFromStr<double>("12.34", 98.0f) == 12.34, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with default for long double";
      VERIFY(fpFromStr<long double>("12.34", 98.0f) == 12.34L, caseLabel);
   }
}


void testFpFromStrWithOptional()
{
   {
      const string caseLabel = "fpFromStr with optional for number";
      VERIFY(fpFromStr<float>("123.4") == optional{123.4f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for number with many decimals";
      VERIFY(fpFromStr<float>("123.4567890123456789") == optional{123.4567890123456789f},
             caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for integer number";
      VERIFY(fpFromStr<float>("1234") == optional{1234.0f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for negative number";
      VERIFY(fpFromStr<float>("-123.4") == optional{-123.4f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for number followed by text";
      VERIFY(fpFromStr<float>("123.4abc") == optional{123.4f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for number within text";
      VERIFY(fpFromStr<float>("abc123.4def") == optional<float>{}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for number starting with zeros";
      VERIFY(fpFromStr<float>("00000123.4") == optional{123.4f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for zero";
      VERIFY(fpFromStr<float>("0") == optional{0.0f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for multiple zeros";
      VERIFY(fpFromStr<float>("00000") == optional{0.0f}, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr with optional for multiple numbers separated by space";
      VERIFY(fpFromStr<float>("1 2 3") == optional{1.0f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for multiple decimal points";
      VERIFY(fpFromStr<float>("1.2.3") == optional{1.2f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for too large number";
      VERIFY(
         fpFromStr<float>(
            "9999999999999999999999999999999999999999999999999999999999999999999999.9") ==
            optional<float>{},
         caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for double";
      VERIFY(fpFromStr<double>("12.34") == optional{12.34}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr with optional for long double";
      VERIFY(fpFromStr<long double>("12.34") == optional{12.34L}, caseLabel);
   }
}


void testUtf8WithString()
{
   {
      const string caseLabel = "utf8 for std::string with alphabet";
      VERIFY(utf8("abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY") ==
                "abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY",
             caseLabel);
   }
   {
      const string caseLabel = "utf8 for std::string with digits";
      VERIFY(utf8("1234567890") == "1234567890", caseLabel);
   }
   {
      const string caseLabel = "utf8 for std::string with special characters";
      VERIFY(utf8("!@#$%^&*()_-=+[{]}|;:',<.>/?") == "!@#$%^&*()_-=+[{]}|;:',<.>/?",
             caseLabel);
   }
   {
      const string caseLabel = "utf8 for std::string with control characters";
      VERIFY(utf8("\n\t\r") == "\n\t\r", caseLabel);
   }
   {
      const string caseLabel = "utf8 for std::string with unicode characters";
      VERIFY(utf8("\xf0\x90\x90\x80") == "\xf0\x90\x90\x80", caseLabel);
   }
}


void testUtf8WithWString()
{
   {
      const string caseLabel = "utf8 for std::wstring with alphabet";
      VERIFY(utf8(L"abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY") ==
                "abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY",
             caseLabel);
   }
   {
      const string caseLabel = "utf8 for std::wstring with digits";
      VERIFY(utf8(L"1234567890") == "1234567890", caseLabel);
   }
   {
      const string caseLabel = "utf8 for std::wstring with special characters";
      VERIFY(utf8(L"!@#$%^&*()_-=+[{]}|;:',<.>/?") == "!@#$%^&*()_-=+[{]}|;:',<.>/?",
             caseLabel);
   }
   {
      const string caseLabel = "utf8 for std::wstring with control characters";
      VERIFY(utf8(L"\n\t\r") == "\n\t\r", caseLabel);
   }
   {
      const string caseLabel = "utf8 for std::wstring with unicode characters";
      VERIFY(utf8(L"\x20AC") == "\xE2\x82\xAC", caseLabel);
      VERIFY(utf8(L"\xD801\xDC00") == "\xf0\x90\x90\x80", caseLabel);
   }
}


void testUtf16WithString()
{
   {
      const string caseLabel = "utf16 for std::string with alphabet";
      VERIFY(utf16("abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY") ==
                L"abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY",
             caseLabel);
   }
   {
      const string caseLabel = "utf16 for std::string with digits";
      VERIFY(utf16("1234567890") == L"1234567890", caseLabel);
   }
   {
      const string caseLabel = "utf16 for std::string with special characters";
      VERIFY(utf16("!@#$%^&*()_-=+[{]}|;:',<.>/?") == L"!@#$%^&*()_-=+[{]}|;:',<.>/?",
             caseLabel);
   }
   {
      const string caseLabel = "utf16 for std::string with control characters";
      VERIFY(utf16("\n\t\r") == L"\n\t\r", caseLabel);
   }
   {
      const string caseLabel = "utf16 for std::string with unicode characters";
      VERIFY(utf16("\xE2\x82\xAC") == L"\x20AC", caseLabel);
      VERIFY(utf16("\xf0\x90\x90\x80") == L"\xD801\xDC00", caseLabel);
   }
}


void testUtf16WithWString()
{
   {
      const string caseLabel = "utf16 for std::string with alphabet";
      VERIFY(utf16(L"abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY") ==
                L"abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY",
             caseLabel);
   }
   {
      const string caseLabel = "utf16 for std::string with digits";
      VERIFY(utf16(L"1234567890") == L"1234567890", caseLabel);
   }
   {
      const string caseLabel = "utf16 for std::string with special characters";
      VERIFY(utf16(L"!@#$%^&*()_-=+[{]}|;:',<.>/?") == L"!@#$%^&*()_-=+[{]}|;:',<.>/?",
             caseLabel);
   }
   {
      const string caseLabel = "utf16 for std::string with control characters";
      VERIFY(utf16(L"\n\t\r") == L"\n\t\r", caseLabel);
   }
   {
      const string caseLabel = "utf16 for std::string with unicode characters";
      VERIFY(utf16(L"\x20AC") == L"\x20AC", caseLabel);
      VERIFY(utf16(L"\xD801\xDC00") == L"\xD801\xDC00", caseLabel);
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
   testIntFromStrThrow();
   testIntFromStrWithDefault();
   testIntFromStrWithOptional();
   testFpFromStrThrow();
   testFpFromStrWithDefault();
   testFpFromStrWithOptional();
   testUtf8WithString();
   testUtf8WithWString();
   testUtf16WithString();
   testUtf16WithWString();
}
