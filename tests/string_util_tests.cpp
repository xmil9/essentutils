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


namespace
{
///////////////////

void testStartsWithForString()
{
   {
      const std::string caseLabel =
         "startsWith<std::string> for string starting with other";
      VERIFY(esl::startsWith("abcdefg", "abc"), caseLabel);
   }
   {
      const std::string caseLabel = "startsWith<std::string> for same string";
      VERIFY(esl::startsWith("abc", "abc"), caseLabel);
   }
   {
      const std::string caseLabel =
         "startsWith<std::string> for prefix string longer than target string";
      VERIFY(!esl::startsWith("abc", "abcdef"), caseLabel);
   }
   {
      const std::string caseLabel =
         "startsWith<std::string> for single character prefix string";
      VERIFY(esl::startsWith("abc", "a"), caseLabel);
   }
   {
      const std::string caseLabel = "startsWith<std::string> for empty prefix string";
      VERIFY(esl::startsWith("abc", ""), caseLabel);
   }
   {
      const std::string caseLabel = "startsWith<std::string> for empty target string";
      VERIFY(!esl::startsWith("", "abc"), caseLabel);
   }
   {
      const std::string caseLabel = "startsWith<std::string> for empty strings";
      VERIFY(esl::startsWith("", ""), caseLabel);
   }
   {
      const std::string caseLabel =
         "startsWith<std::string> for string not starting with other";
      VERIFY(!esl::startsWith("abcdefg", "123"), caseLabel);
   }
   {
      const std::string caseLabel =
         "startsWith<std::string> for string ending with other";
      VERIFY(!esl::startsWith("abcdefg", "efg"), caseLabel);
   }
   {
      const std::string caseLabel = "startsWith<std::string> for string containing other";
      VERIFY(!esl::startsWith("abcdefg", "bcd"), caseLabel);
   }
}


void testStartsWithForWString()
{
   {
      const std::string caseLabel =
         "startsWith<std::wstring> for string starting with other string";
      VERIFY(esl::startsWith(L"abcdefg", L"abc"), caseLabel);
   }
   {
      const std::string caseLabel = "startsWith<std::wstring> for same string";
      VERIFY(esl::startsWith(L"abc", L"abc"), caseLabel);
   }
   {
      const std::string caseLabel =
         "startsWith<std::wstring> for prefix string longer than target string";
      VERIFY(!esl::startsWith(L"abc", L"abcdef"), caseLabel);
   }
   {
      const std::string caseLabel =
         "startsWith<std::wstring> for single character prefix string";
      VERIFY(esl::startsWith(L"abc", L"a"), caseLabel);
   }
   {
      const std::string caseLabel = "startsWith<std::wstring> for empty prefix string";
      VERIFY(esl::startsWith(L"abc", L""), caseLabel);
   }
   {
      const std::string caseLabel = "startsWith<std::wstring> for empty target string";
      VERIFY(!esl::startsWith(L"", L"abc"), caseLabel);
   }
   {
      const std::string caseLabel = "startsWith<std::wstring> for empty strings";
      VERIFY(esl::startsWith(L"", L""), caseLabel);
   }
   {
      const std::string caseLabel =
         "startsWith<std::wstring> for string not starting with other string";
      VERIFY(!esl::startsWith(L"abcdefg", L"123"), caseLabel);
   }
   {
      const std::string caseLabel =
         "startsWith<std::wstring> for string ending with other string";
      VERIFY(!esl::startsWith(L"abcdefg", L"efg"), caseLabel);
   }
   {
      const std::string caseLabel =
         "startsWith<std::wstring> for string containing other string";
      VERIFY(!esl::startsWith(L"abcdefg", L"bcd"), caseLabel);
   }
}


void testEndsWithForString()
{
   {
      const std::string caseLabel =
         "endsWith<std::string> for string ending with other string";
      VERIFY(esl::endsWith("abcdefg", "fg"), caseLabel);
   }
   {
      const std::string caseLabel = "endsWith<std::string> for same string";
      VERIFY(esl::endsWith("abc", "abc"), caseLabel);
   }
   {
      const std::string caseLabel =
         "endsWith<std::string> for tail string longer than target string";
      VERIFY(!esl::endsWith("abc", "abczx"), caseLabel);
   }
   {
      const std::string caseLabel =
         "endsWith<std::string> for single character tail string";
      VERIFY(esl::endsWith("abc", "c"), caseLabel);
   }
   {
      const std::string caseLabel = "endsWith<std::string> for empty tail string";
      VERIFY(esl::endsWith("abc", ""), caseLabel);
   }
   {
      const std::string caseLabel = "endsWith<std::string> for empty target string";
      VERIFY(!esl::endsWith("", "abc"), caseLabel);
   }
   {
      const std::string caseLabel = "endsWith<std::string> for empty strings";
      VERIFY(esl::endsWith("", ""), caseLabel);
   }
   {
      const std::string caseLabel =
         "endsWith<std::string> for string not ending with other string";
      VERIFY(!esl::endsWith("abcdefg", "123"), caseLabel);
   }
   {
      const std::string caseLabel =
         "endsWith<std::string> for string starting with other string";
      VERIFY(!esl::endsWith("abcdefg", "abc"), caseLabel);
   }
   {
      const std::string caseLabel = "endsWith<std::string> for string containing other";
      VERIFY(!esl::endsWith("abcdefg", "ef"), caseLabel);
   }
}


void testEndsWithForWString()
{
   {
      const std::string caseLabel =
         "endsWith<std::wstring> for string ending with other string";
      VERIFY(esl::endsWith(L"abcdefg", L"fg"), caseLabel);
   }
   {
      const std::string caseLabel = "endsWith<std::wstring> for same string";
      VERIFY(esl::endsWith(L"abc", L"abc"), caseLabel);
   }
   {
      const std::string caseLabel =
         "endsWith<std::wstring> for tail string longer than target string";
      VERIFY(!esl::endsWith(L"abc", L"abczx"), caseLabel);
   }
   {
      const std::string caseLabel =
         "endsWith<std::wstring> for single character tail string";
      VERIFY(esl::endsWith(L"abc", L"c"), caseLabel);
   }
   {
      const std::string caseLabel = "endsWith<std::wstring> for empty tail string";
      VERIFY(esl::endsWith(L"abc", L""), caseLabel);
   }
   {
      const std::string caseLabel = "endsWith<std::wstring> for empty target string";
      VERIFY(!esl::endsWith(L"", L"abc"), caseLabel);
   }
   {
      const std::string caseLabel = "endsWith<std::wstring> for empty strings";
      VERIFY(esl::endsWith(L"", L""), caseLabel);
   }
   {
      const std::string caseLabel =
         "endsWith<std::wstring> for string not ending with other string";
      VERIFY(!esl::endsWith(L"abcdefg", L"123"), caseLabel);
   }
   {
      const std::string caseLabel =
         "endsWith<std::wstring> for string starting with other string";
      VERIFY(!esl::endsWith(L"abcdefg", L"abc"), caseLabel);
   }
   {
      const std::string caseLabel =
         "endsWith<std::wstring> for string containing other string";
      VERIFY(!esl::endsWith(L"abcdefg", L"ef"), caseLabel);
   }
}


void testLowercaseForString()
{
   {
      const std::string caseLabel = "lowercase<std::string> for English alphabet";
      VERIFY(esl::lowercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
                "abcdefghijklmnopqrstuvwxyz",
             caseLabel);
   }
   {
      const std::string caseLabel = "lowercase<std::string> for lowercase characters";
      VERIFY(esl::lowercase("abcdefghijklmnopqrstuvwxyz") ==
                "abcdefghijklmnopqrstuvwxyz",
             caseLabel);
   }
   {
      const std::string caseLabel = "lowercase<std::string> for digits characters";
      VERIFY(esl::lowercase("1234567890") == "1234567890", caseLabel);
   }
   {
      const std::string caseLabel = "lowercase<std::string> for other characters";
      VERIFY(esl::lowercase("!@#$%^&*()_+=-;://?.>,<") == "!@#$%^&*()_+=-;://?.>,<",
             caseLabel);
   }
   {
      const std::string caseLabel = "lowercase<std::string> for control characters";
      VERIFY(esl::lowercase("\n\t\r") == "\n\t\r", caseLabel);
   }
   {
      const std::string caseLabel = "lowercase<std::string> for empty string";
      VERIFY(esl::lowercase("") == "", caseLabel);
   }
}


void testLowercaseForWString()
{
   {
      const std::string caseLabel = "lowercase<std::wstring> for English alphabet";
      VERIFY(esl::lowercase(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
                L"abcdefghijklmnopqrstuvwxyz",
             caseLabel);
   }
   {
      const std::string caseLabel = "lowercase<std::wstring> for lowercase characters";
      VERIFY(esl::lowercase(L"abcdefghijklmnopqrstuvwxyz") ==
                L"abcdefghijklmnopqrstuvwxyz",
             caseLabel);
   }
   {
      const std::string caseLabel = "lowercase<std::wstring> for digits characters";
      VERIFY(esl::lowercase(L"1234567890") == L"1234567890", caseLabel);
   }
   {
      const std::string caseLabel = "lowercase<std::wstring> for other characters";
      VERIFY(esl::lowercase(L"!@#$%^&*()_+=-;://?.>,<") == L"!@#$%^&*()_+=-;://?.>,<",
             caseLabel);
   }
   {
      const std::string caseLabel = "lowercase<std::wstring> for control characters";
      VERIFY(esl::lowercase(L"\n\t\r") == L"\n\t\r", caseLabel);
   }
   {
      const std::string caseLabel = "lowercase<std::wstring> for empty string";
      VERIFY(esl::lowercase(L"") == L"", caseLabel);
   }
   {
      const std::string caseLabel = "lowercase<std::wstring> for unicode string";
      VERIFY(esl::lowercase(L"\u0190") == L"\u025b", caseLabel);
   }
}


void testUppercaseForString()
{
   {
      const std::string caseLabel = "uppercase<std::string> for English alphabet";
      VERIFY(esl::uppercase("abcdefghijklmnopqrstuvwxyz") ==
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
             caseLabel);
   }
   {
      const std::string caseLabel = "uppercase<std::string> for uppercase characters";
      VERIFY(esl::uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
             caseLabel);
   }
   {
      const std::string caseLabel = "uppercase<std::string> for digits characters";
      VERIFY(esl::uppercase("1234567890") == "1234567890", caseLabel);
   }
   {
      const std::string caseLabel = "uppercase<std::string> for other characters";
      VERIFY(esl::uppercase("!@#$%^&*()_+=-;://?.>,<") == "!@#$%^&*()_+=-;://?.>,<",
             caseLabel);
   }
   {
      const std::string caseLabel = "uppercase<std::string> for control characters";
      VERIFY(esl::uppercase("\n\t\r") == "\n\t\r", caseLabel);
   }
   {
      const std::string caseLabel = "uppercase<std::string> for empty string";
      VERIFY(esl::uppercase("") == "", caseLabel);
   }
}


void testUppercaseForWString()
{
   {
      const std::string caseLabel = "uppercase<std::wstring> for English alphabet";
      VERIFY(esl::uppercase(L"abcdefghijklmnopqrstuvwxyz") ==
                L"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
             caseLabel);
   }
   {
      const std::string caseLabel = "uppercase<std::wstring> for uppercase characters";
      VERIFY(esl::uppercase(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
                L"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
             caseLabel);
   }
   {
      const std::string caseLabel = "uppercase<std::wstring> for digits characters";
      VERIFY(esl::uppercase(L"1234567890") == L"1234567890", caseLabel);
   }
   {
      const std::string caseLabel = "uppercase<std::wstring> for other characters";
      VERIFY(esl::uppercase(L"!@#$%^&*()_+=-;://?.>,<") == L"!@#$%^&*()_+=-;://?.>,<",
             caseLabel);
   }
   {
      const std::string caseLabel = "uppercase<std::wstring> for control characters";
      VERIFY(esl::uppercase(L"\n\t\r") == L"\n\t\r", caseLabel);
   }
   {
      const std::string caseLabel = "uppercase<std::wstring> for empty string";
      VERIFY(esl::uppercase(L"") == L"", caseLabel);
   }
   {
      const std::string caseLabel = "uppercase<std::wstring> for unicode string";
      VERIFY(esl::uppercase(L"\u025b") == L"\u0190", caseLabel);
   }
}


void testTrimForString()
{
   {
      const std::string caseLabel = "trim<std::string> single leading space";
      VERIFY(esl::trim(" abc", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::string> multiple leading spaces";
      VERIFY(esl::trim("     abc", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::string> single trailing space";
      VERIFY(esl::trim("abc ", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::string> multiple trailing spaces";
      VERIFY(esl::trim("abc   ", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::string> single leading and trailing space";
      VERIFY(esl::trim(" abc ", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel =
         "trim<std::string> multiple leading and trailing spaces";
      VERIFY(esl::trim("     abc  ", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::string> non-space character";
      VERIFY(esl::trim("zzzzabczz", 'z') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::string> control character character";
      VERIFY(esl::trim("\nabc\n\n", '\n') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::string> nothing";
      VERIFY(esl::trim("abc", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::string> empty string";
      VERIFY(esl::trim("", ' ') == "", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::string> everything";
      VERIFY(esl::trim("     ", ' ') == "", caseLabel);
   }
}


void testTrimForWString()
{
   {
      const std::string caseLabel = "trim<std::wstring> single leading space";
      VERIFY(esl::trim(L" abc", ' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::wstring> multiple leading spaces";
      VERIFY(esl::trim(L"     abc", ' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::wstring> single trailing space";
      VERIFY(esl::trim(L"abc ", ' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::wstring> multiple trailing spaces";
      VERIFY(esl::trim(L"abc   ", ' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel =
         "trim<std::wstring> single leading and trailing space";
      VERIFY(esl::trim(L" abc ", ' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel =
         "trim<std::wstring> multiple leading and trailing spaces";
      VERIFY(esl::trim(L"     abc  ", ' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::wstring> non-space character";
      VERIFY(esl::trim(L"zzzzabczz", 'z') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::wstring> control character character";
      VERIFY(esl::trim(L"\nabc\n\n", '\n') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::wstring> nothing";
      VERIFY(esl::trim(L"abc", ' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::wstring> empty string";
      VERIFY(esl::trim(L"", ' ') == L"", caseLabel);
   }
   {
      const std::string caseLabel = "trim<std::wstring> everything";
      VERIFY(esl::trim(L"     ", ' ') == L"", caseLabel);
   }
}


void testTrimLeftForString()
{
   {
      const std::string caseLabel = "trimLeft<std::string> single space";
      VERIFY(esl::trimLeft(" abc", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::string> multiple spaces";
      VERIFY(esl::trimLeft("     abc", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::string> trailing space";
      VERIFY(esl::trimLeft("abc ", ' ') == "abc ", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::string> non-space character";
      VERIFY(esl::trimLeft("zzzzabc", 'z') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::string> control character character";
      VERIFY(esl::trimLeft("\n\nabc", '\n') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::string> nothing";
      VERIFY(esl::trimLeft("abc", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::string> empty string";
      VERIFY(esl::trimLeft("", ' ') == "", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::string> everything";
      VERIFY(esl::trimLeft("     ", ' ') == "", caseLabel);
   }
}


void testTrimLeftForWString()
{
   {
      const std::string caseLabel = "trimLeft<std::wstring>  single space";
      VERIFY(esl::trimLeft(L" abc", L' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::wstring>  multiple spaces";
      VERIFY(esl::trimLeft(L"     abc", L' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::wstring>  trailing space";
      VERIFY(esl::trimLeft(L"abc ", L' ') == L"abc ", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::wstring>  non-space character";
      VERIFY(esl::trimLeft(L"zzzzabc", L'z') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::wstring>  control character character";
      VERIFY(esl::trimLeft(L"\n\nabc", L'\n') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::wstring>  nothing";
      VERIFY(esl::trimLeft(L"abc", L' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::wstring>  empty string";
      VERIFY(esl::trimLeft(L"", L' ') == L"", caseLabel);
   }
   {
      const std::string caseLabel = "trimLeft<std::wstring>  everything";
      VERIFY(esl::trimLeft(L"     ", L' ') == L"", caseLabel);
   }
}


void testTrimRightForString()
{
   {
      const std::string caseLabel = "trimRight<std::string> single space";
      VERIFY(esl::trimRight("abc ", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::string> multiple spaces";
      VERIFY(esl::trimRight("abc   ", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::string> leading space";
      VERIFY(esl::trimRight(" abc", ' ') == " abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::string> non-space character";
      VERIFY(esl::trimRight("abczzzz", 'z') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::string> control character character";
      VERIFY(esl::trimRight("abc\n\n", '\n') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::string> nothing";
      VERIFY(esl::trimRight("abc", ' ') == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::string> empty string";
      VERIFY(esl::trimRight("", ' ') == "", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::string> everything";
      VERIFY(esl::trimRight("     ", ' ') == "", caseLabel);
   }
}


void testTrimRightForWString()
{
   {
      const std::string caseLabel = "trimRight<std::wstring> single space";
      VERIFY(esl::trimRight(L"abc ", L' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::wstring> multiple spaces";
      VERIFY(esl::trimRight(L"abc   ", L' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::wstring> leading space";
      VERIFY(esl::trimRight(L" abc", L' ') == L" abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::wstring> non-space character";
      VERIFY(esl::trimRight(L"abczzzz", L'z') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::wstring> control character character";
      VERIFY(esl::trimRight(L"abc\n\n", L'\n') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::wstring> nothing";
      VERIFY(esl::trimRight(L"abc", L' ') == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::wstring> empty string";
      VERIFY(esl::trimRight(L"", L' ') == L"", caseLabel);
   }
   {
      const std::string caseLabel = "trimRight<std::wstring> everything";
      VERIFY(esl::trimRight(L"     ", L' ') == L"", caseLabel);
   }
}


void testSplitForString()
{
   {
      const std::string caseLabel = "split<std::string> at spaces";
      const std::vector<std::string> expected{"abc", "de", "fghi"};
      VERIFY(esl::split("abc de fghi", " ") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::string> at other character";
      const std::vector<std::string> expected{"abc", "de", "fghi"};
      VERIFY(esl::split("abc:de:fghi", ":") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::string> at control character";
      const std::vector<std::string> expected{"abc", "de", "fghi"};
      VERIFY(esl::split("abc\nde\nfghi", "\n") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::string> at string";
      const std::vector<std::string> expected{"abc", "de", "fghi"};
      VERIFY(esl::split("abc<sep>de<sep>fghi", "<sep>") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::string> string without separator";
      const std::vector<std::string> expected{"abc"};
      VERIFY(esl::split("abc", " ") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::string> string leading separator";
      const std::vector<std::string> expected{"", "abc"};
      VERIFY(esl::split(" abc", " ") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::string> string trailing separator";
      const std::vector<std::string> expected{"abc", ""};
      VERIFY(esl::split("abc ", " ") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::string> string with only separators";
      const std::vector<std::string> expected{"", "", ""};
      VERIFY(esl::split("  ", " ") == expected, caseLabel);
   }
}


void testSplitForWString()
{
   {
      const std::string caseLabel = "split<std::wstring> at spaces";
      const std::vector<std::wstring> expected{L"abc", L"de", L"fghi"};
      VERIFY(esl::split(L"abc de fghi", L" ") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::wstring> at other character";
      const std::vector<std::wstring> expected{L"abc", L"de", L"fghi"};
      VERIFY(esl::split(L"abc:de:fghi", L":") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::wstring> at control character";
      const std::vector<std::wstring> expected{L"abc", L"de", L"fghi"};
      VERIFY(esl::split(L"abc\nde\nfghi", L"\n") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::wstring> at string";
      const std::vector<std::wstring> expected{L"abc", L"de", L"fghi"};
      VERIFY(esl::split(L"abc<sep>de<sep>fghi", L"<sep>") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::wstring> string without separator";
      const std::vector<std::wstring> expected{L"abc"};
      VERIFY(esl::split(L"abc", L" ") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::wstring> string leading separator";
      const std::vector<std::wstring> expected{L"", L"abc"};
      VERIFY(esl::split(L" abc", L" ") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::wstring> string trailing separator";
      const std::vector<std::wstring> expected{L"abc", L""};
      VERIFY(esl::split(L"abc ", L" ") == expected, caseLabel);
   }
   {
      const std::string caseLabel = "split<std::wstring> string with only separators";
      const std::vector<std::wstring> expected{L"", L"", L""};
      VERIFY(esl::split(L"  ", L" ") == expected, caseLabel);
   }
}


void testJoinForString()
{
   {
      const std::string caseLabel = "join<std::string> with spaces";
      const std::vector<std::string> input{"abc", "de", "fghi"};
      VERIFY(esl::join(input.begin(), input.end(), " ") == "abc de fghi", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::string> with other string";
      const std::vector<std::string> input{"abc", "de", "fghi"};
      VERIFY(esl::join(input.begin(), input.end(), "::") == "abc::de::fghi", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::string> without glue string";
      const std::vector<std::string> input{"abc", "de", "fghi"};
      VERIFY(esl::join(input.begin(), input.end(), "") == "abcdefghi", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::string> with control character";
      const std::vector<std::string> input{"abc", "de", "fghi"};
      VERIFY(esl::join(input.begin(), input.end(), "\n") == "abc\nde\nfghi", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::string> single piece";
      const std::vector<std::string> input{"abc"};
      VERIFY(esl::join(input.begin(), input.end(), " ") == "abc", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::string> empty pieces";
      const std::vector<std::string> input{"", ""};
      VERIFY(esl::join(input.begin(), input.end(), " ") == "", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::string> no pieces";
      const std::vector<std::string> input;
      VERIFY(esl::join(input.begin(), input.end(), " ") == "", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::string> from other collection";
      const std::set<std::string> input{"abc", "de", "fghi"};
      VERIFY(esl::join(input.begin(), input.end(), " ") == "abc de fghi", caseLabel);
   }
}


void testJoinForWString()
{
   {
      const std::string caseLabel = "join<std::wstring> with spaces";
      const std::vector<std::wstring> input{L"abc", L"de", L"fghi"};
      VERIFY(esl::join(input.begin(), input.end(), L" ") == L"abc de fghi", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::wstring> with other string";
      const std::vector<std::wstring> input{L"abc", L"de", L"fghi"};
      VERIFY(esl::join(input.begin(), input.end(), L"::") == L"abc::de::fghi",
             caseLabel);
   }
   {
      const std::string caseLabel = "join<std::wstring> without glue string";
      const std::vector<std::wstring> input{L"abc", L"de", L"fghi"};
      VERIFY(esl::join(input.begin(), input.end(), L"") == L"abcdefghi", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::wstring> with control character";
      const std::vector<std::wstring> input{L"abc", L"de", L"fghi"};
      VERIFY(esl::join(input.begin(), input.end(), L"\n") == L"abc\nde\nfghi",
             caseLabel);
   }
   {
      const std::string caseLabel = "join<std::wstring> single piece";
      const std::vector<std::wstring> input{L"abc"};
      VERIFY(esl::join(input.begin(), input.end(), L" ") == L"abc", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::wstring> empty pieces";
      const std::vector<std::wstring> input{L"", L""};
      VERIFY(esl::join(input.begin(), input.end(), L" ") == L"", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::wstring> no pieces";
      const std::vector<std::wstring> input;
      VERIFY(esl::join(input.begin(), input.end(), L" ") == L"", caseLabel);
   }
   {
      const std::string caseLabel = "join<std::wstring> from other collection";
      const std::set<std::wstring> input{L"abc", L"de", L"fghi"};
      VERIFY(esl::join(input.begin(), input.end(), L" ") == L"abc de fghi", caseLabel);
   }
}


void testIntFromStrThrowForString()
{
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for number";
      try
      {
         VERIFY(esl::intFromStrThrow<int>("1234") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for negative number";
      try
      {
         VERIFY(esl::intFromStrThrow<int>("-1234") == -1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "intFromStrThrow<std::string> for number followed by text";
      try
      {
         VERIFY(esl::intFromStrThrow<int>("1234abc") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for number within text";
      try
      {
         esl::intFromStrThrow<int>("abc1234def");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const std::string caseLabel =
         "intFromStrThrow<std::string> for number starting with zeros";
      try
      {
         VERIFY(esl::intFromStrThrow<int>("000001234") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for zero";
      try
      {
         VERIFY(esl::intFromStrThrow<int>("0") == 0, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for multiple zeros";
      try
      {
         VERIFY(esl::intFromStrThrow<int>("00000") == 0, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "intFromStrThrow<std::string> for multiple numbers separated by space";
      try
      {
         VERIFY(esl::intFromStrThrow<int>("1 2 3") == 1, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for too large number";
      try
      {
         esl::intFromStrThrow<int>(
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
      const std::string caseLabel = "intFromStrThrow<std::string> for int8_t";
      try
      {
         VERIFY(esl::intFromStrThrow<int8_t>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for int16_t";
      try
      {
         VERIFY(esl::intFromStrThrow<int16_t>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for int32_t";
      try
      {
         VERIFY(esl::intFromStrThrow<int32_t>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for int64_t";
      try
      {
         VERIFY(esl::intFromStrThrow<int64_t>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for char";
      try
      {
         VERIFY(esl::intFromStrThrow<char>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for unsigned char";
      try
      {
         VERIFY(esl::intFromStrThrow<unsigned char>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for short";
      try
      {
         VERIFY(esl::intFromStrThrow<short>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for unsigned short";
      try
      {
         VERIFY(esl::intFromStrThrow<unsigned short>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for long";
      try
      {
         VERIFY(esl::intFromStrThrow<long>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for unsigned long";
      try
      {
         VERIFY(esl::intFromStrThrow<unsigned long>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for long long";
      try
      {
         VERIFY(esl::intFromStrThrow<long long>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::string> for unsigned long long";
      try
      {
         VERIFY(esl::intFromStrThrow<unsigned long long>("12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
}


void testIntFromStrThrowForWString()
{
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for number";
      try
      {
         VERIFY(esl::intFromStrThrow<int>(L"1234") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for negative number";
      try
      {
         VERIFY(esl::intFromStrThrow<int>(L"-1234") == -1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "intFromStrThrow<std::wstring> for number followed by text";
      try
      {
         VERIFY(esl::intFromStrThrow<int>(L"1234abc") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "intFromStrThrow<std::wstring> for number within text";
      try
      {
         esl::intFromStrThrow<int>(L"abc1234def");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const std::string caseLabel =
         "intFromStrThrow<std::wstring> for number starting with zeros";
      try
      {
         VERIFY(esl::intFromStrThrow<int>(L"000001234") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for zero";
      try
      {
         VERIFY(esl::intFromStrThrow<int>(L"0") == 0, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for multiple zeros";
      try
      {
         VERIFY(esl::intFromStrThrow<int>(L"00000") == 0, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "intFromStrThrow<std::wstring> for multiple numbers separated by space";
      try
      {
         VERIFY(esl::intFromStrThrow<int>(L"1 2 3") == 1, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for too large number";
      try
      {
         esl::intFromStrThrow<int>(
            L"9999999999999999999999999999999999999999999999999999999999999999999999");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for int8_t";
      try
      {
         VERIFY(esl::intFromStrThrow<int8_t>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for int16_t";
      try
      {
         VERIFY(esl::intFromStrThrow<int16_t>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for int32_t";
      try
      {
         VERIFY(esl::intFromStrThrow<int32_t>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for int64_t";
      try
      {
         VERIFY(esl::intFromStrThrow<int64_t>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for char";
      try
      {
         VERIFY(esl::intFromStrThrow<char>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for unsigned char";
      try
      {
         VERIFY(esl::intFromStrThrow<unsigned char>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for short";
      try
      {
         VERIFY(esl::intFromStrThrow<short>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for unsigned short";
      try
      {
         VERIFY(esl::intFromStrThrow<unsigned short>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for long";
      try
      {
         VERIFY(esl::intFromStrThrow<long>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for unsigned long";
      try
      {
         VERIFY(esl::intFromStrThrow<unsigned long>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "intFromStrThrow<std::wstring> for long long";
      try
      {
         VERIFY(esl::intFromStrThrow<long long>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "intFromStrThrow<std::wstring> for unsigned long long";
      try
      {
         VERIFY(esl::intFromStrThrow<unsigned long long>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
}


void testIntFromStrWithDefaultForString()
{
   {
      const std::string caseLabel = "intFromStr<std::string> with default for number";
      VERIFY(esl::intFromStr<int>("1234", 98) == 1234, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with default for negative number";
      VERIFY(esl::intFromStr<int>("-1234", 98) == -1234, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with default for number followed by text";
      VERIFY(esl::intFromStr<int>("1234abc", 98) == 1234, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with default for number within text";
      VERIFY(esl::intFromStr<int>("abc1234def", 98) == 98, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with default for number starting with zeros";
      VERIFY(esl::intFromStr<int>("000001234", 98) == 1234, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with default for zero";
      VERIFY(esl::intFromStr<int>("0", 98) == 0, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with default for multiple zeros";
      VERIFY(esl::intFromStr<int>("00000", 98) == 0, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with default for multiple numbers separated by space";
      VERIFY(esl::intFromStr<int>("1 2 3", 98) == 1, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with default for too large number";
      VERIFY(esl::intFromStr<int>(
                "9999999999999999999999999999999999999999999999999999999999999999999999",
                98) == 98,
             caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with default for int8_t";
      VERIFY(esl::intFromStr<int8_t>("12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with default for int16_t";
      VERIFY(esl::intFromStr<int16_t>("12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with default for int32_t";
      VERIFY(esl::intFromStr<int32_t>("12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with default for int64_t";
      VERIFY(esl::intFromStr<int64_t>("12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with default for char";
      VERIFY(esl::intFromStr<char>("12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with default for unsigned char";
      VERIFY(esl::intFromStr<unsigned char>("12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with default for short";
      VERIFY(esl::intFromStr<short>("12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with default for unsigned short";
      VERIFY(esl::intFromStr<unsigned short>("12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with default for long";
      VERIFY(esl::intFromStr<long>("12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with default for unsigned long";
      VERIFY(esl::intFromStr<unsigned long>("12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with default for long long";
      VERIFY(esl::intFromStr<long long>("12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with default for unsigned long long";
      VERIFY(esl::intFromStr<unsigned long long>("12", 98) == 12, caseLabel);
   }
}


void testIntFromStrWithDefaultForWString()
{
   {
      const std::string caseLabel = "intFromStr<std::wstring> with default for number";
      VERIFY(esl::intFromStr<int>(L"1234", 98) == 1234, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with default for negative number";
      VERIFY(esl::intFromStr<int>(L"-1234", 98) == -1234, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with default for number followed by text";
      VERIFY(esl::intFromStr<int>(L"1234abc", 98) == 1234, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with default for number within text";
      VERIFY(esl::intFromStr<int>(L"abc1234def", 98) == 98, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with default for number starting with zeros";
      VERIFY(esl::intFromStr<int>(L"000001234", 98) == 1234, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with default for zero";
      VERIFY(esl::intFromStr<int>(L"0", 98) == 0, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with default for multiple zeros";
      VERIFY(esl::intFromStr<int>(L"00000", 98) == 0, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with default for multiple numbers separated by space";
      VERIFY(esl::intFromStr<int>(L"1 2 3", 98) == 1, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with default for too large number";
      VERIFY(esl::intFromStr<int>(
                L"9999999999999999999999999999999999999999999999999999999999999999999999",
                98) == 98,
             caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with default for int8_t";
      VERIFY(esl::intFromStr<int8_t>(L"12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with default for int16_t";
      VERIFY(esl::intFromStr<int16_t>(L"12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with default for int32_t";
      VERIFY(esl::intFromStr<int32_t>(L"12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with default for int64_t";
      VERIFY(esl::intFromStr<int64_t>(L"12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with default for char";
      VERIFY(esl::intFromStr<char>(L"12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with default for unsigned char";
      VERIFY(esl::intFromStr<unsigned char>(L"12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with default for short";
      VERIFY(esl::intFromStr<short>(L"12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with default for unsigned short";
      VERIFY(esl::intFromStr<unsigned short>(L"12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with default for long";
      VERIFY(esl::intFromStr<long>(L"12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with default for unsigned long";
      VERIFY(esl::intFromStr<unsigned long>(L"12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with default for long long";
      VERIFY(esl::intFromStr<long long>(L"12", 98) == 12, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with default for unsigned long long";
      VERIFY(esl::intFromStr<unsigned long long>(L"12", 98) == 12, caseLabel);
   }
}


void testIntFromStrWithOptionalForString()
{
   {
      const std::string caseLabel = "intFromStr<std::string> with optional for number";
      VERIFY(esl::intFromStr<int>("1234") == std::optional{1234}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with optional for negative number";
      VERIFY(esl::intFromStr<int>("-1234") == std::optional{-1234}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with optional for number followed by text";
      VERIFY(esl::intFromStr<int>("1234abc") == std::optional{1234}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with optional for number within text";
      VERIFY(esl::intFromStr<int>("abc1234def") == std::optional<int>{}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with optional for number starting with zeros";
      VERIFY(esl::intFromStr<int>("000001234") == std::optional{1234}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with optional for zero";
      VERIFY(esl::intFromStr<int>("0") == std::optional{0}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with optional for multiple zeros";
      VERIFY(esl::intFromStr<int>("00000") == std::optional{0}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with optional for multiple numbers separated by space";
      VERIFY(esl::intFromStr<int>("1 2 3") == std::optional{1}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with optional for too large number";
      VERIFY(
         esl::intFromStr<int>(
            "9999999999999999999999999999999999999999999999999999999999999999999999") ==
            std::optional<int>{},
         caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with optional for int8_t";
      VERIFY(esl::intFromStr<int8_t>("12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with optional for int16_t";
      VERIFY(esl::intFromStr<int16_t>("12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with optional for int32_t";
      VERIFY(esl::intFromStr<int32_t>("12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with optional for int64_t";
      VERIFY(esl::intFromStr<int64_t>("12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with optional for char";
      VERIFY(esl::intFromStr<char>("12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with optional for unsigned char";
      VERIFY(esl::intFromStr<unsigned char>("12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with optional for short";
      VERIFY(esl::intFromStr<short>("12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with optional for unsigned short";
      VERIFY(esl::intFromStr<unsigned short>("12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with optional for long";
      VERIFY(esl::intFromStr<long>("12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with optional for unsigned long";
      VERIFY(esl::intFromStr<unsigned long>("12") == std::optional<unsigned long>{12},
             caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::string> with optional for long long";
      VERIFY(esl::intFromStr<long long>("12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::string> with optional for unsigned long long";
      VERIFY(esl::intFromStr<unsigned long long>("12") ==
                std::optional<unsigned long long>{12},
             caseLabel);
   }
}


void testIntFromStrWithOptionalForWString()
{
   {
      const std::string caseLabel = "intFromStr<std::wstring> with optional for number";
      VERIFY(esl::intFromStr<int>(L"1234") == std::optional{1234}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for negative number";
      VERIFY(esl::intFromStr<int>(L"-1234") == std::optional{-1234}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for number followed by text";
      VERIFY(esl::intFromStr<int>(L"1234abc") == std::optional{1234}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for number within text";
      VERIFY(esl::intFromStr<int>(L"abc1234def") == std::optional<int>{}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for number starting with zeros";
      VERIFY(esl::intFromStr<int>(L"000001234") == std::optional{1234}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with optional for zero";
      VERIFY(esl::intFromStr<int>(L"0") == std::optional{0}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for multiple zeros";
      VERIFY(esl::intFromStr<int>(L"00000") == std::optional{0}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for multiple numbers separated by space";
      VERIFY(esl::intFromStr<int>(L"1 2 3") == std::optional{1}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for too large number";
      VERIFY(
         esl::intFromStr<int>(
            L"9999999999999999999999999999999999999999999999999999999999999999999999") ==
            std::optional<int>{},
         caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with optional for int8_t";
      VERIFY(esl::intFromStr<int8_t>(L"12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with optional for int16_t";
      VERIFY(esl::intFromStr<int16_t>(L"12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with optional for int32_t";
      VERIFY(esl::intFromStr<int32_t>(L"12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with optional for int64_t";
      VERIFY(esl::intFromStr<int64_t>(L"12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with optional for char";
      VERIFY(esl::intFromStr<char>(L"12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for unsigned char";
      VERIFY(esl::intFromStr<unsigned char>(L"12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with optional for short";
      VERIFY(esl::intFromStr<short>(L"12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for unsigned short";
      VERIFY(esl::intFromStr<unsigned short>(L"12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel = "intFromStr<std::wstring> with optional for long";
      VERIFY(esl::intFromStr<long>(L"12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for unsigned long";
      VERIFY(esl::intFromStr<unsigned long>(L"12") == std::optional<unsigned long>{12},
             caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for long long";
      VERIFY(esl::intFromStr<long long>(L"12") == std::optional{12}, caseLabel);
   }
   {
      const std::string caseLabel =
         "intFromStr<std::wstring> with optional for unsigned long long";
      VERIFY(esl::intFromStr<unsigned long long>(L"12") ==
                std::optional<unsigned long long>{12},
             caseLabel);
   }
}


void testFpFromStrThrowForString()
{
   {
      const std::string caseLabel = "fpFromStrThrow<std::string> for number";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>("123.4") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "fpFromStrThrow<std::string> for number with many decimals";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>("123.4567890123456789") ==
                   123.4567890123456789f,
                caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::string> for integer number";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>("1234") == 1234.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::string> for negative number";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>("-123.4") == -123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "fpFromStrThrow<std::string> for number followed by text";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>("123.4abc") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::string> for number within text";
      try
      {
         esl::fpFromStrThrow<float>("abc123.4def");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const std::string caseLabel =
         "fpFromStrThrow<std::string> for number starting with zeros";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>("00000123.4") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::string> for zero";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>("0") == 0.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::string> for multiple zeros";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>("00000") == 0.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "fpFromStrThrow<std::string> for multiple numbers separated by space";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>("1 2 3") == 1.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "fpFromStrThrow<std::string> for multiple decimal points";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>("1.2.3") == 1.2f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::string> for too large number";
      try
      {
         esl::fpFromStrThrow<float>(
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
      const std::string caseLabel = "fpFromStrThrow<std::string> for double";
      try
      {
         VERIFY(esl::fpFromStrThrow<double>("12.34") == 12.34, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::string> for long double";
      try
      {
         VERIFY(esl::fpFromStrThrow<long double>("12.34") == 12.34L, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
}


void testFpFromStrThrowForWString()
{
   {
      const std::string caseLabel = "fpFromStrThrow<std::wstring> for number";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>(L"123.4") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "fpFromStrThrow<std::wstring> for number with many decimals";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>(L"123.4567890123456789") ==
                   123.4567890123456789f,
                caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::wstring> for integer number";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>(L"1234") == 1234.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::wstring> for negative number";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>(L"-123.4") == -123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "fpFromStrThrow<std::wstring> for number followed by text";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>(L"123.4abc") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::wstring> for number within text";
      try
      {
         esl::fpFromStrThrow<float>(L"abc123.4def");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const std::string caseLabel =
         "fpFromStrThrow<std::wstring> for number starting with zeros";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>(L"00000123.4") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::wstring> for zero";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>(L"0") == 0.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::wstring> for multiple zeros";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>(L"00000") == 0.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "fpFromStrThrow<std::wstring> for multiple numbers separated by space";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>(L"1 2 3") == 1.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel =
         "fpFromStrThrow<std::wstring> for multiple decimal points";
      try
      {
         VERIFY(esl::fpFromStrThrow<float>(L"1.2.3") == 1.2f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::wstring> for too large number";
      try
      {
         esl::fpFromStrThrow<float>(
            L"9999999999999999999999999999999999999999999999999999999999999999999999.9");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::wstring> for double";
      try
      {
         VERIFY(esl::fpFromStrThrow<double>(L"12.34") == 12.34, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const std::string caseLabel = "fpFromStrThrow<std::wstring> for long double";
      try
      {
         VERIFY(esl::fpFromStrThrow<long double>(L"12.34") == 12.34L, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
}


void testFpFromStrWithDefaultForString()
{
   {
      const std::string caseLabel = "fpFromStr<std::string> with default for number";
      VERIFY(esl::fpFromStr<float>("123.4", 98.0f) == 123.4f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with default for number with many decimals";
      VERIFY(esl::fpFromStr<float>("123.4567890123456789", 98.0f) ==
                123.4567890123456789f,
             caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with default for integer number";
      VERIFY(esl::fpFromStr<float>("1234", 98.0f) == 1234.0f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with default for negative number";
      VERIFY(esl::fpFromStr<float>("-123.4", 98.0f) == -123.4f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with default for number followed by text";
      VERIFY(esl::fpFromStr<float>("123.4abc", 98.0f) == 123.4f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with default for number within text";
      VERIFY(esl::fpFromStr<float>("abc123.4def", 98.0f) == 98.0f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with default for number starting with zeros";
      VERIFY(esl::fpFromStr<float>("00000123.4", 98.0f) == 123.4f, caseLabel);
   }
   {
      const std::string caseLabel = "fpFromStr<std::string> with default for zero";
      VERIFY(esl::fpFromStr<float>("0", 98.0f) == 0.0f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with default for multiple zeros";
      VERIFY(esl::fpFromStr<float>("00000", 98.0f) == 0.0f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with default for multiple numbers separated by space";
      VERIFY(esl::fpFromStr<float>("1 2 3", 98.0f) == 1.0f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with default for multiple decimal points";
      VERIFY(esl::fpFromStr<float>("1.2.3", 98.0f) == 1.2f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with default for too large number";
      VERIFY(
         esl::fpFromStr<float>(
            "9999999999999999999999999999999999999999999999999999999999999999999999.9",
            98.0f) == 98.0f,
         caseLabel);
   }
   {
      const std::string caseLabel = "fpFromStr<std::string> with default for double";
      VERIFY(esl::fpFromStr<double>("12.34", 98.0f) == 12.34, caseLabel);
   }
   {
      const std::string caseLabel = "fpFromStr<std::string> with default for long double";
      VERIFY(esl::fpFromStr<long double>("12.34", 98.0f) == 12.34L, caseLabel);
   }
}


void testFpFromStrWithDefaultForWString()
{
   {
      const std::string caseLabel = "fpFromStr<std::wstring> with default for number";
      VERIFY(esl::fpFromStr<float>(L"123.4", 98.0f) == 123.4f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with default for number with many decimals";
      VERIFY(esl::fpFromStr<float>(L"123.4567890123456789", 98.0f) ==
                123.4567890123456789f,
             caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with default for integer number";
      VERIFY(esl::fpFromStr<float>(L"1234", 98.0f) == 1234.0f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with default for negative number";
      VERIFY(esl::fpFromStr<float>(L"-123.4", 98.0f) == -123.4f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with default for number followed by text";
      VERIFY(esl::fpFromStr<float>(L"123.4abc", 98.0f) == 123.4f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with default for number within text";
      VERIFY(esl::fpFromStr<float>(L"abc123.4def", 98.0f) == 98.0f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with default for number starting with zeros";
      VERIFY(esl::fpFromStr<float>(L"00000123.4", 98.0f) == 123.4f, caseLabel);
   }
   {
      const std::string caseLabel = "fpFromStr<std::wstring> with default for zero";
      VERIFY(esl::fpFromStr<float>(L"0", 98.0f) == 0.0f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with default for multiple zeros";
      VERIFY(esl::fpFromStr<float>(L"00000", 98.0f) == 0.0f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with default for multiple numbers separated by space";
      VERIFY(esl::fpFromStr<float>(L"1 2 3", 98.0f) == 1.0f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with default for multiple decimal points";
      VERIFY(esl::fpFromStr<float>(L"1.2.3", 98.0f) == 1.2f, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with default for too large number";
      VERIFY(
         esl::fpFromStr<float>(
            L"9999999999999999999999999999999999999999999999999999999999999999999999.9",
            98.0f) == 98.0f,
         caseLabel);
   }
   {
      const std::string caseLabel = "fpFromStr<std::wstring> with default for double";
      VERIFY(esl::fpFromStr<double>(L"12.34", 98.0f) == 12.34, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with default for long double";
      VERIFY(esl::fpFromStr<long double>(L"12.34", 98.0f) == 12.34L, caseLabel);
   }
}


void testFpFromStrWithOptionalForString()
{
   {
      const std::string caseLabel = "fpFromStr<std::string> with optional for number";
      VERIFY(esl::fpFromStr<float>("123.4") == std::optional{123.4f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with optional for number with many decimals";
      VERIFY(esl::fpFromStr<float>("123.4567890123456789") ==
                std::optional{123.4567890123456789f},
             caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with optional for integer number";
      VERIFY(esl::fpFromStr<float>("1234") == std::optional{1234.0f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with optional for negative number";
      VERIFY(esl::fpFromStr<float>("-123.4") == std::optional{-123.4f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with optional for number followed by text";
      VERIFY(esl::fpFromStr<float>("123.4abc") == std::optional{123.4f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with optional for number within text";
      VERIFY(esl::fpFromStr<float>("abc123.4def") == std::optional<float>{}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with optional for number starting with zeros";
      VERIFY(esl::fpFromStr<float>("00000123.4") == std::optional{123.4f}, caseLabel);
   }
   {
      const std::string caseLabel = "fpFromStr<std::string> with optional for zero";
      VERIFY(esl::fpFromStr<float>("0") == std::optional{0.0f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with optional for multiple zeros";
      VERIFY(esl::fpFromStr<float>("00000") == std::optional{0.0f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with optional for multiple numbers separated by space";
      VERIFY(esl::fpFromStr<float>("1 2 3") == std::optional{1.0f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with optional for multiple decimal points";
      VERIFY(esl::fpFromStr<float>("1.2.3") == std::optional{1.2f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with optional for too large number";
      VERIFY(
         esl::fpFromStr<float>(
            "9999999999999999999999999999999999999999999999999999999999999999999999.9") ==
            std::optional<float>{},
         caseLabel);
   }
   {
      const std::string caseLabel = "fpFromStr<std::string> with optional for double";
      VERIFY(esl::fpFromStr<double>("12.34") == std::optional{12.34}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::string> with optional for long double";
      VERIFY(esl::fpFromStr<long double>("12.34") == std::optional{12.34L}, caseLabel);
   }
}


void testFpFromStrWithOptionalForWString()
{
   {
      const std::string caseLabel = "fpFromStr<std::wstring> with optional for number";
      VERIFY(esl::fpFromStr<float>(L"123.4") == std::optional{123.4f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with optional for number with many decimals";
      VERIFY(esl::fpFromStr<float>(L"123.4567890123456789") ==
                std::optional{123.4567890123456789f},
             caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with optional for integer number";
      VERIFY(esl::fpFromStr<float>(L"1234") == std::optional{1234.0f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with optional for negative number";
      VERIFY(esl::fpFromStr<float>(L"-123.4") == std::optional{-123.4f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with optional for number followed by text";
      VERIFY(esl::fpFromStr<float>(L"123.4abc") == std::optional{123.4f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with optional for number within text";
      VERIFY(esl::fpFromStr<float>(L"abc123.4def") == std::optional<float>{},
             caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with optional for number starting with zeros";
      VERIFY(esl::fpFromStr<float>(L"00000123.4") == std::optional{123.4f}, caseLabel);
   }
   {
      const std::string caseLabel = "fpFromStr<std::wstring> with optional for zero";
      VERIFY(esl::fpFromStr<float>(L"0") == std::optional{0.0f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with optional for multiple zeros";
      VERIFY(esl::fpFromStr<float>(L"00000") == std::optional{0.0f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with optional for multiple numbers separated by space";
      VERIFY(esl::fpFromStr<float>(L"1 2 3") == std::optional{1.0f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with optional for multiple decimal points";
      VERIFY(esl::fpFromStr<float>(L"1.2.3") == std::optional{1.2f}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with optional for too large number";
      VERIFY(esl::fpFromStr<float>(
                L"999999999999999999999999999999999999999999999999999999999"
                L"9999999999999.9") == std::optional<float>{},
             caseLabel);
   }
   {
      const std::string caseLabel = "fpFromStr<std::wstring> with optional for double";
      VERIFY(esl::fpFromStr<double>(L"12.34") == std::optional{12.34}, caseLabel);
   }
   {
      const std::string caseLabel =
         "fpFromStr<std::wstring> with optional for long double";
      VERIFY(esl::fpFromStr<long double>(L"12.34") == std::optional{12.34L}, caseLabel);
   }
}


void testUtf8WithString()
{
   {
      const std::string caseLabel = "utf8 for std::string with alphabet";
      VERIFY(esl::utf8("abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY") ==
                "abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY",
             caseLabel);
   }
   {
      const std::string caseLabel = "utf8 for std::string with digits";
      VERIFY(esl::utf8("1234567890") == "1234567890", caseLabel);
   }
   {
      const std::string caseLabel = "utf8 for std::string with special characters";
      VERIFY(esl::utf8("!@#$%^&*()_-=+[{]}|;:',<.>/?") ==
                "!@#$%^&*()_-=+[{]}|;:',<.>/?",
             caseLabel);
   }
   {
      const std::string caseLabel = "utf8 for std::string with control characters";
      VERIFY(esl::utf8("\n\t\r") == "\n\t\r", caseLabel);
   }
   {
      const std::string caseLabel = "utf8 for std::string with unicode characters";
      VERIFY(esl::utf8("\xf0\x90\x90\x80") == "\xf0\x90\x90\x80", caseLabel);
   }
   {
      const std::string caseLabel = "utf8 for empty std::string";
      VERIFY(esl::utf8("") == "", caseLabel);
   }
}


void testUtf8WithWString()
{
   {
      const std::string caseLabel = "utf8 for std::wstring with alphabet";
      VERIFY(esl::utf8(L"abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY") ==
                "abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY",
             caseLabel);
   }
   {
      const std::string caseLabel = "utf8 for std::wstring with digits";
      VERIFY(esl::utf8(L"1234567890") == "1234567890", caseLabel);
   }
   {
      const std::string caseLabel = "utf8 for std::wstring with special characters";
      VERIFY(esl::utf8(L"!@#$%^&*()_-=+[{]}|;:',<.>/?") ==
                "!@#$%^&*()_-=+[{]}|;:',<.>/?",
             caseLabel);
   }
   {
      const std::string caseLabel = "utf8 for std::wstring with control characters";
      VERIFY(esl::utf8(L"\n\t\r") == "\n\t\r", caseLabel);
   }
   {
      const std::string caseLabel = "utf8 for std::wstring with unicode characters";
      VERIFY(esl::utf8(L"\x20AC") == "\xE2\x82\xAC", caseLabel);
      VERIFY(esl::utf8(L"\xD801\xDC00") == "\xf0\x90\x90\x80", caseLabel);
   }
   {
      const std::string caseLabel = "utf8 for empty std::wstring";
      VERIFY(esl::utf8(L"") == "", caseLabel);
   }
}


void testUtf16WithString()
{
   {
      const std::string caseLabel = "utf16 for std::string with alphabet";
      VERIFY(esl::utf16("abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY") ==
                L"abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY",
             caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for std::string with digits";
      VERIFY(esl::utf16("1234567890") == L"1234567890", caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for std::string with special characters";
      VERIFY(esl::utf16("!@#$%^&*()_-=+[{]}|;:',<.>/?") ==
                L"!@#$%^&*()_-=+[{]}|;:',<.>/?",
             caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for std::string with control characters";
      VERIFY(esl::utf16("\n\t\r") == L"\n\t\r", caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for std::string with unicode characters";
      VERIFY(esl::utf16("\xE2\x82\xAC") == L"\x20AC", caseLabel);
      VERIFY(esl::utf16("\xf0\x90\x90\x80") == L"\xD801\xDC00", caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for empty std::string";
      VERIFY(esl::utf16("") == L"", caseLabel);
   }
}


void testUtf16WithWString()
{
   {
      const std::string caseLabel = "utf16 for std::string with alphabet";
      VERIFY(esl::utf16(L"abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY") ==
                L"abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY",
             caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for std::string with digits";
      VERIFY(esl::utf16(L"1234567890") == L"1234567890", caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for std::string with special characters";
      VERIFY(esl::utf16(L"!@#$%^&*()_-=+[{]}|;:',<.>/?") ==
                L"!@#$%^&*()_-=+[{]}|;:',<.>/?",
             caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for std::string with control characters";
      VERIFY(esl::utf16(L"\n\t\r") == L"\n\t\r", caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for std::string with unicode characters";
      VERIFY(esl::utf16(L"\x20AC") == L"\x20AC", caseLabel);
      VERIFY(esl::utf16(L"\xD801\xDC00") == L"\xD801\xDC00", caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for empty std::wstring";
      VERIFY(esl::utf16(L"") == L"", caseLabel);
   }
}


void testConvertToForString()
{
   {
      const std::string caseLabel = "convertTo std::string from std::wstring";
      VERIFY(esl::convertTo<std::string>(L"abc123!@#\n\t\x20AC") ==
                "abc123!@#\n\t\xE2\x82\xAC",
             caseLabel);
   }
   {
      const std::string caseLabel = "convertTo std::string from std::string";
      VERIFY(esl::convertTo<std::string>("abc123!@#\n\t\xE2\x82\xAC") ==
                "abc123!@#\n\t\xE2\x82\xAC",
             caseLabel);
   }
   {
      const std::string caseLabel = "convertTo std::string from empty std::wstring";
      VERIFY(esl::convertTo<std::string>(L"") == "", caseLabel);
   }
   {
      const std::string caseLabel = "convertTo std::string from empty std::string";
      VERIFY(esl::convertTo<std::string>("") == "", caseLabel);
   }
}


void testConvertToForWString()
{
   {
      const std::string caseLabel = "convertTo std::wstring from std::string";
      VERIFY(esl::convertTo<std::wstring>("abc123!@#\n\t\xE2\x82\xAC") ==
                L"abc123!@#\n\t\x20AC",
             caseLabel);
   }
   {
      const std::string caseLabel = "convertTo std::wstring from std::wstring";
      VERIFY(esl::convertTo<std::wstring>(L"abc123!@#\n\t\x20AC") ==
                L"abc123!@#\n\t\x20AC",
             caseLabel);
   }
   {
      const std::string caseLabel = "convertTo std::wstring from empty std::wstring";
      VERIFY(esl::convertTo<std::wstring>(L"") == L"", caseLabel);
   }
   {
      const std::string caseLabel = "convertTo std::wstring from empty std::string";
      VERIFY(esl::convertTo<std::wstring>("") == L"", caseLabel);
   }
}


void testUtf8WithChar()
{
   {
      const std::string caseLabel = "utf8 for narrow character";
      VERIFY(esl::utf8('a') == "a", caseLabel);
      VERIFY(esl::utf8('1') == "1", caseLabel);
      VERIFY(esl::utf8('$') == "$", caseLabel);
      VERIFY(esl::utf8('\n') == "\n", caseLabel);
      VERIFY(esl::utf8('\x90') == "\x90", caseLabel);
   }
}


void testUtf8WithWChar()
{
   {
      const std::string caseLabel = "utf8 for wide character";
      VERIFY(esl::utf8(L'a') == "a", caseLabel);
      VERIFY(esl::utf8(L'1') == "1", caseLabel);
      VERIFY(esl::utf8(L'$') == "$", caseLabel);
      VERIFY(esl::utf8(L'\n') == "\n", caseLabel);
      VERIFY(esl::utf8(L'\x20AC') == "\xE2\x82\xAC", caseLabel);
   }
}


void testUtf16WithChar()
{
   {
      const std::string caseLabel = "utf16 for narrow character";
      VERIFY(esl::utf16("a", 1) == L'a', caseLabel);
      VERIFY(esl::utf16("1", 1) == L'1', caseLabel);
      VERIFY(esl::utf16("$", 1) == L'$', caseLabel);
      VERIFY(esl::utf16("\n", 1) == L'\n', caseLabel);
      VERIFY(esl::utf16("\xE2\x82\xAC", 3) == L'\x20AC', caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for narrow character and zero length";
      VERIFY(esl::utf16("", 0) == L'\0', caseLabel);
   }
}


void testUtf16WithWChar()
{
   {
      const std::string caseLabel = "utf16 for wide character";
      VERIFY(esl::utf16(L"a", 1) == L'a', caseLabel);
      VERIFY(esl::utf16(L"1", 1) == L'1', caseLabel);
      VERIFY(esl::utf16(L"$", 1) == L'$', caseLabel);
      VERIFY(esl::utf16(L"\n", 1) == L'\n', caseLabel);
      VERIFY(esl::utf16(L"\x20AC", 1) == L'\x20AC', caseLabel);
   }
   {
      const std::string caseLabel = "utf16 for wide character and zero length";
      VERIFY(esl::utf16(L"", 0) == L'\0', caseLabel);
   }
}

} // namespace


///////////////////

void testStringUtil()
{
   testStartsWithForString();
   testStartsWithForWString();
   testEndsWithForString();
   testEndsWithForWString();
   testLowercaseForString();
   testLowercaseForWString();
   testUppercaseForString();
   testUppercaseForWString();
   testTrimForString();
   testTrimForWString();
   testTrimLeftForString();
   testTrimLeftForWString();
   testTrimRightForString();
   testTrimRightForWString();
   testSplitForString();
   testSplitForWString();
   testJoinForString();
   testJoinForWString();
   testIntFromStrThrowForString();
   testIntFromStrThrowForWString();
   testIntFromStrWithDefaultForString();
   testIntFromStrWithDefaultForWString();
   testIntFromStrWithOptionalForString();
   testIntFromStrWithOptionalForWString();
   testFpFromStrThrowForString();
   testFpFromStrThrowForWString();
   testFpFromStrWithDefaultForString();
   testFpFromStrWithDefaultForWString();
   testFpFromStrWithOptionalForString();
   testFpFromStrWithOptionalForWString();
   testUtf8WithString();
   testUtf8WithWString();
   testUtf16WithString();
   testUtf16WithWString();
   testConvertToForString();
   testConvertToForWString();
   testUtf8WithChar();
   testUtf8WithWChar();
   testUtf16WithChar();
   testUtf16WithWChar();
}
