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

void testStartsWithForString()
{
   {
      const string caseLabel = "startsWith<string> for string starting with other";
      VERIFY(startsWith("abcdefg", "abc"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<string> for same string";
      VERIFY(startsWith("abc", "abc"), caseLabel);
   }
   {
      const string caseLabel =
         "startsWith<string> for prefix string longer than target string";
      VERIFY(!startsWith("abc", "abcdef"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<string> for single character prefix string";
      VERIFY(startsWith("abc", "a"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<string> for empty prefix string";
      VERIFY(startsWith("abc", ""), caseLabel);
   }
   {
      const string caseLabel = "startsWith<string> for empty target string";
      VERIFY(!startsWith("", "abc"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<string> for empty strings";
      VERIFY(startsWith("", ""), caseLabel);
   }
   {
      const string caseLabel = "startsWith<string> for string not starting with other";
      VERIFY(!startsWith("abcdefg", "123"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<string> for string ending with other";
      VERIFY(!startsWith("abcdefg", "efg"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<string> for string containing other";
      VERIFY(!startsWith("abcdefg", "bcd"), caseLabel);
   }
}


void testStartsWithForWString()
{
   {
      const string caseLabel = "startsWith<wstring> for string starting with other";
      VERIFY(startsWith(L"abcdefg", L"abc"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<wstring> for same string";
      VERIFY(startsWith(L"abc", L"abc"), caseLabel);
   }
   {
      const string caseLabel =
         "startsWith<wstring> for prefix string longer than target string";
      VERIFY(!startsWith(L"abc", L"abcdef"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<wstring> for single character prefix string";
      VERIFY(startsWith(L"abc", L"a"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<wstring> for empty prefix string";
      VERIFY(startsWith(L"abc", L""), caseLabel);
   }
   {
      const string caseLabel = "startsWith<wstring> for empty target string";
      VERIFY(!startsWith(L"", L"abc"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<wstring> for empty strings";
      VERIFY(startsWith(L"", L""), caseLabel);
   }
   {
      const string caseLabel = "startsWith<wstring> for string not starting with other";
      VERIFY(!startsWith(L"abcdefg", L"123"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<wstring> for string ending with other";
      VERIFY(!startsWith(L"abcdefg", L"efg"), caseLabel);
   }
   {
      const string caseLabel = "startsWith<wstring> for string containing other";
      VERIFY(!startsWith(L"abcdefg", L"bcd"), caseLabel);
   }
}


void testEndsWithForString()
{
   {
      const string caseLabel = "endsWith<string> for string ending with other";
      VERIFY(endsWith("abcdefg", "fg"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<string> for same string";
      VERIFY(endsWith("abc", "abc"), caseLabel);
   }
   {
      const string caseLabel =
         "endsWith<string> for tail string longer than target string";
      VERIFY(!endsWith("abc", "abczx"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<string> for single character tail string";
      VERIFY(endsWith("abc", "c"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<string> for empty tail string";
      VERIFY(endsWith("abc", ""), caseLabel);
   }
   {
      const string caseLabel = "endsWith<string> for empty target string";
      VERIFY(!endsWith("", "abc"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<string> for empty strings";
      VERIFY(endsWith("", ""), caseLabel);
   }
   {
      const string caseLabel = "endsWith<string> for string not ending with other";
      VERIFY(!endsWith("abcdefg", "123"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<string> for string starting with other";
      VERIFY(!endsWith("abcdefg", "abc"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<string> for string containing other";
      VERIFY(!endsWith("abcdefg", "ef"), caseLabel);
   }
}


void testEndsWithForWString()
{
   {
      const string caseLabel = "endsWith<wstring> for string ending with other";
      VERIFY(endsWith(L"abcdefg", L"fg"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<wstring> for same string";
      VERIFY(endsWith(L"abc", L"abc"), caseLabel);
   }
   {
      const string caseLabel =
         "endsWith<wstring> for tail string longer than target string";
      VERIFY(!endsWith(L"abc", L"abczx"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<wstring> for single character tail string";
      VERIFY(endsWith(L"abc", L"c"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<wstring> for empty tail string";
      VERIFY(endsWith(L"abc", L""), caseLabel);
   }
   {
      const string caseLabel = "endsWith<wstring> for empty target string";
      VERIFY(!endsWith(L"", L"abc"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<wstring> for empty strings";
      VERIFY(endsWith(L"", L""), caseLabel);
   }
   {
      const string caseLabel = "endsWith<wstring> for string not ending with other";
      VERIFY(!endsWith(L"abcdefg", L"123"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<wstring> for string starting with other";
      VERIFY(!endsWith(L"abcdefg", L"abc"), caseLabel);
   }
   {
      const string caseLabel = "endsWith<wstring> for string containing other";
      VERIFY(!endsWith(L"abcdefg", L"ef"), caseLabel);
   }
}


void testLowercaseForString()
{
   {
      const string caseLabel = "lowercase<string> for English alphabet";
      VERIFY(lowercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == "abcdefghijklmnopqrstuvwxyz",
             caseLabel);
   }
   {
      const string caseLabel = "lowercase<string> for lowercase characters";
      VERIFY(lowercase("abcdefghijklmnopqrstuvwxyz") == "abcdefghijklmnopqrstuvwxyz",
             caseLabel);
   }
   {
      const string caseLabel = "lowercase<string> for digits characters";
      VERIFY(lowercase("1234567890") == "1234567890", caseLabel);
   }
   {
      const string caseLabel = "lowercase<string> for other characters";
      VERIFY(lowercase("!@#$%^&*()_+=-;://?.>,<") == "!@#$%^&*()_+=-;://?.>,<",
             caseLabel);
   }
   {
      const string caseLabel = "lowercase<string> for control characters";
      VERIFY(lowercase("\n\t\r") == "\n\t\r", caseLabel);
   }
   {
      const string caseLabel = "lowercase<string> for empty string";
      VERIFY(lowercase("") == "", caseLabel);
   }
}


void testLowercaseForWString()
{
   {
      const string caseLabel = "lowercase<wstring> for English alphabet";
      VERIFY(lowercase(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ") == L"abcdefghijklmnopqrstuvwxyz",
             caseLabel);
   }
   {
      const string caseLabel = "lowercase<wstring> for lowercase characters";
      VERIFY(lowercase(L"abcdefghijklmnopqrstuvwxyz") == L"abcdefghijklmnopqrstuvwxyz",
             caseLabel);
   }
   {
      const string caseLabel = "lowercase<wstring> for digits characters";
      VERIFY(lowercase(L"1234567890") == L"1234567890", caseLabel);
   }
   {
      const string caseLabel = "lowercase<wstring> for other characters";
      VERIFY(lowercase(L"!@#$%^&*()_+=-;://?.>,<") == L"!@#$%^&*()_+=-;://?.>,<",
             caseLabel);
   }
   {
      const string caseLabel = "lowercase<wstring> for control characters";
      VERIFY(lowercase(L"\n\t\r") == L"\n\t\r", caseLabel);
   }
   {
      const string caseLabel = "lowercase<wstring> for empty string";
      VERIFY(lowercase(L"") == L"", caseLabel);
   }
   {
      const string caseLabel = "lowercase<wstring> for unicode string";
      VERIFY(lowercase(L"\u0190") == L"\u025b", caseLabel);
   }
}


void testUppercaseForString()
{
   {
      const string caseLabel = "uppercase<string> for English alphabet";
      VERIFY(uppercase("abcdefghijklmnopqrstuvwxyz") == "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
             caseLabel);
   }
   {
      const string caseLabel = "uppercase<string> for uppercase characters";
      VERIFY(uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
             caseLabel);
   }
   {
      const string caseLabel = "uppercase<string> for digits characters";
      VERIFY(uppercase("1234567890") == "1234567890", caseLabel);
   }
   {
      const string caseLabel = "uppercase<string> for other characters";
      VERIFY(uppercase("!@#$%^&*()_+=-;://?.>,<") == "!@#$%^&*()_+=-;://?.>,<",
             caseLabel);
   }
   {
      const string caseLabel = "uppercase<string> for control characters";
      VERIFY(uppercase("\n\t\r") == "\n\t\r", caseLabel);
   }
   {
      const string caseLabel = "uppercase<string> for empty string";
      VERIFY(uppercase("") == "", caseLabel);
   }
}


void testUppercaseForWString()
{
   {
      const string caseLabel = "uppercase<wstring> for English alphabet";
      VERIFY(uppercase(L"abcdefghijklmnopqrstuvwxyz") == L"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
             caseLabel);
   }
   {
      const string caseLabel = "uppercase<wstring> for uppercase characters";
      VERIFY(uppercase(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ") == L"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
             caseLabel);
   }
   {
      const string caseLabel = "uppercase<wstring> for digits characters";
      VERIFY(uppercase(L"1234567890") == L"1234567890", caseLabel);
   }
   {
      const string caseLabel = "uppercase<wstring> for other characters";
      VERIFY(uppercase(L"!@#$%^&*()_+=-;://?.>,<") == L"!@#$%^&*()_+=-;://?.>,<",
             caseLabel);
   }
   {
      const string caseLabel = "uppercase<wstring> for control characters";
      VERIFY(uppercase(L"\n\t\r") == L"\n\t\r", caseLabel);
   }
   {
      const string caseLabel = "uppercase<wstring> for empty string";
      VERIFY(uppercase(L"") == L"", caseLabel);
   }
   {
      const string caseLabel = "uppercase<wstring> for unicode string";
      VERIFY(uppercase(L"\u025b") == L"\u0190", caseLabel);
   }
}


void testTrimForString()
{
   {
      const string caseLabel = "trim<string> single leading space";
      VERIFY(trim(" abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim<string> multiple leading spaces";
      VERIFY(trim("     abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim<string> single trailing space";
      VERIFY(trim("abc ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim<string> multiple trailing spaces";
      VERIFY(trim("abc   ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim<string> single leading and trailing space";
      VERIFY(trim(" abc ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim<string> multiple leading and trailing spaces";
      VERIFY(trim("     abc  ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim<string> non-space character";
      VERIFY(trim("zzzzabczz", 'z') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim<string> control character character";
      VERIFY(trim("\nabc\n\n", '\n') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim<string> nothing";
      VERIFY(trim("abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trim<string> empty string";
      VERIFY(trim("", ' ') == "", caseLabel);
   }
   {
      const string caseLabel = "trim<string> everything";
      VERIFY(trim("     ", ' ') == "", caseLabel);
   }
}


void testTrimForWString()
{
   {
      const string caseLabel = "trim<wstring> single leading space";
      VERIFY(trim(L" abc", ' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trim<wstring> multiple leading spaces";
      VERIFY(trim(L"     abc", ' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trim<wstring> single trailing space";
      VERIFY(trim(L"abc ", ' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trim<wstring> multiple trailing spaces";
      VERIFY(trim(L"abc   ", ' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trim<wstring> single leading and trailing space";
      VERIFY(trim(L" abc ", ' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trim<wstring> multiple leading and trailing spaces";
      VERIFY(trim(L"     abc  ", ' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trim<wstring> non-space character";
      VERIFY(trim(L"zzzzabczz", 'z') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trim<wstring> control character character";
      VERIFY(trim(L"\nabc\n\n", '\n') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trim<wstring> nothing";
      VERIFY(trim(L"abc", ' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trim<wstring> empty string";
      VERIFY(trim(L"", ' ') == L"", caseLabel);
   }
   {
      const string caseLabel = "trim<wstring> everything";
      VERIFY(trim(L"     ", ' ') == L"", caseLabel);
   }
}


void testTrimLeftForString()
{
   {
      const string caseLabel = "trimLeft<string> single space";
      VERIFY(trimLeft(" abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<string> multiple spaces";
      VERIFY(trimLeft("     abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<string> trailing space";
      VERIFY(trimLeft("abc ", ' ') == "abc ", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<string> non-space character";
      VERIFY(trimLeft("zzzzabc", 'z') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<string> control character character";
      VERIFY(trimLeft("\n\nabc", '\n') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<string> nothing";
      VERIFY(trimLeft("abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<string> empty string";
      VERIFY(trimLeft("", ' ') == "", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<string> everything";
      VERIFY(trimLeft("     ", ' ') == "", caseLabel);
   }
}


void testTrimLeftForWString()
{
   {
      const string caseLabel = "trimLeft<wstring>  single space";
      VERIFY(trimLeft(L" abc", L' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<wstring>  multiple spaces";
      VERIFY(trimLeft(L"     abc", L' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<wstring>  trailing space";
      VERIFY(trimLeft(L"abc ", L' ') == L"abc ", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<wstring>  non-space character";
      VERIFY(trimLeft(L"zzzzabc", L'z') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<wstring>  control character character";
      VERIFY(trimLeft(L"\n\nabc", L'\n') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<wstring>  nothing";
      VERIFY(trimLeft(L"abc", L' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<wstring>  empty string";
      VERIFY(trimLeft(L"", L' ') == L"", caseLabel);
   }
   {
      const string caseLabel = "trimLeft<wstring>  everything";
      VERIFY(trimLeft(L"     ", L' ') == L"", caseLabel);
   }
}


void testTrimRightForString()
{
   {
      const string caseLabel = "trimRight<string> single space";
      VERIFY(trimRight("abc ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<string> multiple spaces";
      VERIFY(trimRight("abc   ", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<string> leading space";
      VERIFY(trimRight(" abc", ' ') == " abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<string> non-space character";
      VERIFY(trimRight("abczzzz", 'z') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<string> control character character";
      VERIFY(trimRight("abc\n\n", '\n') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<string> nothing";
      VERIFY(trimRight("abc", ' ') == "abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<string> empty string";
      VERIFY(trimRight("", ' ') == "", caseLabel);
   }
   {
      const string caseLabel = "trimRight<string> everything";
      VERIFY(trimRight("     ", ' ') == "", caseLabel);
   }
}


void testTrimRightForWString()
{
   {
      const string caseLabel = "trimRight<wstring> single space";
      VERIFY(trimRight(L"abc ", L' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<wstring> multiple spaces";
      VERIFY(trimRight(L"abc   ", L' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<wstring> leading space";
      VERIFY(trimRight(L" abc", L' ') == L" abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<wstring> non-space character";
      VERIFY(trimRight(L"abczzzz", L'z') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<wstring> control character character";
      VERIFY(trimRight(L"abc\n\n", L'\n') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<wstring> nothing";
      VERIFY(trimRight(L"abc", L' ') == L"abc", caseLabel);
   }
   {
      const string caseLabel = "trimRight<wstring> empty string";
      VERIFY(trimRight(L"", L' ') == L"", caseLabel);
   }
   {
      const string caseLabel = "trimRight<wstring> everything";
      VERIFY(trimRight(L"     ", L' ') == L"", caseLabel);
   }
}


void testSplitForString()
{
   {
      const string caseLabel = "split<string> at spaces";
      const vector<string> expected{"abc", "de", "fghi"};
      VERIFY(split("abc de fghi", " ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<string> at other character";
      const vector<string> expected{"abc", "de", "fghi"};
      VERIFY(split("abc:de:fghi", ":") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<string> at control character";
      const vector<string> expected{"abc", "de", "fghi"};
      VERIFY(split("abc\nde\nfghi", "\n") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<string> at string";
      const vector<string> expected{"abc", "de", "fghi"};
      VERIFY(split("abc<sep>de<sep>fghi", "<sep>") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<string> string without separator";
      const vector<string> expected{"abc"};
      VERIFY(split("abc", " ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<string> string leading separator";
      const vector<string> expected{"", "abc"};
      VERIFY(split(" abc", " ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<string> string trailing separator";
      const vector<string> expected{"abc", ""};
      VERIFY(split("abc ", " ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<string> string with only separators";
      const vector<string> expected{"", "", ""};
      VERIFY(split("  ", " ") == expected, caseLabel);
   }
}


void testSplitForWString()
{
   {
      const string caseLabel = "split<wstring> at spaces";
      const vector<wstring> expected{L"abc", L"de", L"fghi"};
      VERIFY(split(L"abc de fghi", L" ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<wstring> at other character";
      const vector<wstring> expected{L"abc", L"de", L"fghi"};
      VERIFY(split(L"abc:de:fghi", L":") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<wstring> at control character";
      const vector<wstring> expected{L"abc", L"de", L"fghi"};
      VERIFY(split(L"abc\nde\nfghi", L"\n") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<wstring> at string";
      const vector<wstring> expected{L"abc", L"de", L"fghi"};
      VERIFY(split(L"abc<sep>de<sep>fghi", L"<sep>") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<wstring> string without separator";
      const vector<wstring> expected{L"abc"};
      VERIFY(split(L"abc", L" ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<wstring> string leading separator";
      const vector<wstring> expected{L"", L"abc"};
      VERIFY(split(L" abc", L" ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<wstring> string trailing separator";
      const vector<wstring> expected{L"abc", L""};
      VERIFY(split(L"abc ", L" ") == expected, caseLabel);
   }
   {
      const string caseLabel = "split<wstring> string with only separators";
      const vector<wstring> expected{L"", L"", L""};
      VERIFY(split(L"  ", L" ") == expected, caseLabel);
   }
}


void testJoinForString()
{
   {
      const string caseLabel = "join<string> with spaces";
      const vector<string> input{"abc", "de", "fghi"};
      VERIFY(join(input.begin(), input.end(), " ") == "abc de fghi", caseLabel);
   }
   {
      const string caseLabel = "join<string> with other string";
      const vector<string> input{"abc", "de", "fghi"};
      VERIFY(join(input.begin(), input.end(), "::") == "abc::de::fghi", caseLabel);
   }
   {
      const string caseLabel = "join<string> without glue string";
      const vector<string> input{"abc", "de", "fghi"};
      VERIFY(join(input.begin(), input.end(), "") == "abcdefghi", caseLabel);
   }
   {
      const string caseLabel = "join<string> with control character";
      const vector<string> input{"abc", "de", "fghi"};
      VERIFY(join(input.begin(), input.end(), "\n") == "abc\nde\nfghi", caseLabel);
   }
   {
      const string caseLabel = "join<string> single piece";
      const vector<string> input{"abc"};
      VERIFY(join(input.begin(), input.end(), " ") == "abc", caseLabel);
   }
   {
      const string caseLabel = "join<string> empty pieces";
      const vector<string> input{"", ""};
      VERIFY(join(input.begin(), input.end(), " ") == "", caseLabel);
   }
   {
      const string caseLabel = "join<string> no pieces";
      const vector<string> input;
      VERIFY(join(input.begin(), input.end(), " ") == "", caseLabel);
   }
   {
      const string caseLabel = "join<string> from other collection";
      const set<string> input{"abc", "de", "fghi"};
      VERIFY(join(input.begin(), input.end(), " ") == "abc de fghi", caseLabel);
   }
}


void testJoinForWString()
{
   {
      const string caseLabel = "join<wstring> with spaces";
      const vector<wstring> input{L"abc", L"de", L"fghi"};
      VERIFY(join(input.begin(), input.end(), L" ") == L"abc de fghi", caseLabel);
   }
   {
      const string caseLabel = "join<wstring> with other string";
      const vector<wstring> input{L"abc", L"de", L"fghi"};
      VERIFY(join(input.begin(), input.end(), L"::") == L"abc::de::fghi", caseLabel);
   }
   {
      const string caseLabel = "join<wstring> without glue string";
      const vector<wstring> input{L"abc", L"de", L"fghi"};
      VERIFY(join(input.begin(), input.end(), L"") == L"abcdefghi", caseLabel);
   }
   {
      const string caseLabel = "join<wstring> with control character";
      const vector<wstring> input{L"abc", L"de", L"fghi"};
      VERIFY(join(input.begin(), input.end(), L"\n") == L"abc\nde\nfghi", caseLabel);
   }
   {
      const string caseLabel = "join<wstring> single piece";
      const vector<wstring> input{L"abc"};
      VERIFY(join(input.begin(), input.end(), L" ") == L"abc", caseLabel);
   }
   {
      const string caseLabel = "join<wstring> empty pieces";
      const vector<wstring> input{L"", L""};
      VERIFY(join(input.begin(), input.end(), L" ") == L"", caseLabel);
   }
   {
      const string caseLabel = "join<wstring> no pieces";
      const vector<wstring> input;
      VERIFY(join(input.begin(), input.end(), L" ") == L"", caseLabel);
   }
   {
      const string caseLabel = "join<wstring> from other collection";
      const set<wstring> input{L"abc", L"de", L"fghi"};
      VERIFY(join(input.begin(), input.end(), L" ") == L"abc de fghi", caseLabel);
   }
}


void testIntFromStrThrowForString()
{
   {
      const string caseLabel = "intFromStrThrow<string> for number";
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
      const string caseLabel = "intFromStrThrow<string> for negative number";
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
      const string caseLabel = "intFromStrThrow<string> for number followed by text";
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
      const string caseLabel = "intFromStrThrow<string> for number within text";
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
      const string caseLabel = "intFromStrThrow<string> for number starting with zeros";
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
      const string caseLabel = "intFromStrThrow<string> for zero";
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
      const string caseLabel = "intFromStrThrow<string> for multiple zeros";
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
      const string caseLabel =
         "intFromStrThrow<string> for multiple numbers separated by space";
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
      const string caseLabel = "intFromStrThrow<string> for too large number";
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
      const string caseLabel = "intFromStrThrow<string> for int8_t";
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
      const string caseLabel = "intFromStrThrow<string> for int16_t";
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
      const string caseLabel = "intFromStrThrow<string> for int32_t";
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
      const string caseLabel = "intFromStrThrow<string> for int64_t";
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
      const string caseLabel = "intFromStrThrow<string> for char";
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
      const string caseLabel = "intFromStrThrow<string> for unsigned char";
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
      const string caseLabel = "intFromStrThrow<string> for short";
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
      const string caseLabel = "intFromStrThrow<string> for unsigned short";
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
      const string caseLabel = "intFromStrThrow<string> for long";
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
      const string caseLabel = "intFromStrThrow<string> for unsigned long";
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
      const string caseLabel = "intFromStrThrow<string> for long long";
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
      const string caseLabel = "intFromStrThrow<string> for unsigned long long";
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


void testIntFromStrThrowForWString()
{
   {
      const string caseLabel = "intFromStrThrow<wstring> for number";
      try
      {
         VERIFY(intFromStrThrow<int>(L"1234") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for negative number";
      try
      {
         VERIFY(intFromStrThrow<int>(L"-1234") == -1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for number followed by text";
      try
      {
         VERIFY(intFromStrThrow<int>(L"1234abc") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for number within text";
      try
      {
         intFromStrThrow<int>(L"abc1234def");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for number starting with zeros";
      try
      {
         VERIFY(intFromStrThrow<int>(L"000001234") == 1234, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for zero";
      try
      {
         VERIFY(intFromStrThrow<int>(L"0") == 0, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for multiple zeros";
      try
      {
         VERIFY(intFromStrThrow<int>(L"00000") == 0, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel =
         "intFromStrThrow<wstring> for multiple numbers separated by space";
      try
      {
         VERIFY(intFromStrThrow<int>(L"1 2 3") == 1, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for too large number";
      try
      {
         intFromStrThrow<int>(
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
      const string caseLabel = "intFromStrThrow<wstring> for int8_t";
      try
      {
         VERIFY(intFromStrThrow<int8_t>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for int16_t";
      try
      {
         VERIFY(intFromStrThrow<int16_t>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for int32_t";
      try
      {
         VERIFY(intFromStrThrow<int32_t>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for int64_t";
      try
      {
         VERIFY(intFromStrThrow<int64_t>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for char";
      try
      {
         VERIFY(intFromStrThrow<char>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for unsigned char";
      try
      {
         VERIFY(intFromStrThrow<unsigned char>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for short";
      try
      {
         VERIFY(intFromStrThrow<short>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for unsigned short";
      try
      {
         VERIFY(intFromStrThrow<unsigned short>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for long";
      try
      {
         VERIFY(intFromStrThrow<long>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for unsigned long";
      try
      {
         VERIFY(intFromStrThrow<unsigned long>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for long long";
      try
      {
         VERIFY(intFromStrThrow<long long>(L"12") == 12, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "intFromStrThrow<wstring> for unsigned long long";
      try
      {
         VERIFY(intFromStrThrow<unsigned long long>(L"12") == 12, caseLabel);
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
      const string caseLabel = "intFromStr<string> with default for number";
      VERIFY(intFromStr<int>("1234", 98) == 1234, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for negative number";
      VERIFY(intFromStr<int>("-1234", 98) == -1234, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<string> with default for number followed by text";
      VERIFY(intFromStr<int>("1234abc", 98) == 1234, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for number within text";
      VERIFY(intFromStr<int>("abc1234def", 98) == 98, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<string> with default for number starting with zeros";
      VERIFY(intFromStr<int>("000001234", 98) == 1234, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for zero";
      VERIFY(intFromStr<int>("0", 98) == 0, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for multiple zeros";
      VERIFY(intFromStr<int>("00000", 98) == 0, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<string> with default for multiple numbers separated by space";
      VERIFY(intFromStr<int>("1 2 3", 98) == 1, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for too large number";
      VERIFY(intFromStr<int>(
                "9999999999999999999999999999999999999999999999999999999999999999999999",
                98) == 98,
             caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for int8_t";
      VERIFY(intFromStr<int8_t>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for int16_t";
      VERIFY(intFromStr<int16_t>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for int32_t";
      VERIFY(intFromStr<int32_t>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for int64_t";
      VERIFY(intFromStr<int64_t>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for char";
      VERIFY(intFromStr<char>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for unsigned char";
      VERIFY(intFromStr<unsigned char>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for short";
      VERIFY(intFromStr<short>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for unsigned short";
      VERIFY(intFromStr<unsigned short>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for long";
      VERIFY(intFromStr<long>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for unsigned long";
      VERIFY(intFromStr<unsigned long>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for long long";
      VERIFY(intFromStr<long long>("12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with default for unsigned long long";
      VERIFY(intFromStr<unsigned long long>("12", 98) == 12, caseLabel);
   }
}


void testIntFromStrWithDefaultForWString()
{
   {
      const string caseLabel = "intFromStr<wstring> with default for number";
      VERIFY(intFromStr<int>(L"1234", 98) == 1234, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for negative number";
      VERIFY(intFromStr<int>(L"-1234", 98) == -1234, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<wstring> with default for number followed by text";
      VERIFY(intFromStr<int>(L"1234abc", 98) == 1234, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for number within text";
      VERIFY(intFromStr<int>(L"abc1234def", 98) == 98, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<wstring> with default for number starting with zeros";
      VERIFY(intFromStr<int>(L"000001234", 98) == 1234, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for zero";
      VERIFY(intFromStr<int>(L"0", 98) == 0, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for multiple zeros";
      VERIFY(intFromStr<int>(L"00000", 98) == 0, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<wstring> with default for multiple numbers separated by space";
      VERIFY(intFromStr<int>(L"1 2 3", 98) == 1, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for too large number";
      VERIFY(intFromStr<int>(
                L"9999999999999999999999999999999999999999999999999999999999999999999999",
                98) == 98,
             caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for int8_t";
      VERIFY(intFromStr<int8_t>(L"12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for int16_t";
      VERIFY(intFromStr<int16_t>(L"12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for int32_t";
      VERIFY(intFromStr<int32_t>(L"12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for int64_t";
      VERIFY(intFromStr<int64_t>(L"12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for char";
      VERIFY(intFromStr<char>(L"12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for unsigned char";
      VERIFY(intFromStr<unsigned char>(L"12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for short";
      VERIFY(intFromStr<short>(L"12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for unsigned short";
      VERIFY(intFromStr<unsigned short>(L"12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for long";
      VERIFY(intFromStr<long>(L"12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for unsigned long";
      VERIFY(intFromStr<unsigned long>(L"12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for long long";
      VERIFY(intFromStr<long long>(L"12", 98) == 12, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with default for unsigned long long";
      VERIFY(intFromStr<unsigned long long>(L"12", 98) == 12, caseLabel);
   }
}


void testIntFromStrWithOptionalForString()
{
   {
      const string caseLabel = "intFromStr<string> with optional for number";
      VERIFY(intFromStr<int>("1234") == optional{1234}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for negative number";
      VERIFY(intFromStr<int>("-1234") == optional{-1234}, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<string> with optional for number followed by text";
      VERIFY(intFromStr<int>("1234abc") == optional{1234}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for number within text";
      VERIFY(intFromStr<int>("abc1234def") == optional<int>{}, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<string> with optional for number starting with zeros";
      VERIFY(intFromStr<int>("000001234") == optional{1234}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for zero";
      VERIFY(intFromStr<int>("0") == optional{0}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for multiple zeros";
      VERIFY(intFromStr<int>("00000") == optional{0}, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<string> with optional for multiple numbers separated by space";
      VERIFY(intFromStr<int>("1 2 3") == optional{1}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for too large number";
      VERIFY(
         intFromStr<int>(
            "9999999999999999999999999999999999999999999999999999999999999999999999") ==
            optional<int>{},
         caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for int8_t";
      VERIFY(intFromStr<int8_t>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for int16_t";
      VERIFY(intFromStr<int16_t>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for int32_t";
      VERIFY(intFromStr<int32_t>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for int64_t";
      VERIFY(intFromStr<int64_t>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for char";
      VERIFY(intFromStr<char>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for unsigned char";
      VERIFY(intFromStr<unsigned char>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for short";
      VERIFY(intFromStr<short>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for unsigned short";
      VERIFY(intFromStr<unsigned short>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for long";
      VERIFY(intFromStr<long>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for unsigned long";
      VERIFY(intFromStr<unsigned long>("12") == optional<unsigned long>{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for long long";
      VERIFY(intFromStr<long long>("12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<string> with optional for unsigned long long";
      VERIFY(intFromStr<unsigned long long>("12") == optional<unsigned long long>{12},
             caseLabel);
   }
}


void testIntFromStrWithOptionalForWString()
{
   {
      const string caseLabel = "intFromStr<wstring> with optional for number";
      VERIFY(intFromStr<int>(L"1234") == optional{1234}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for negative number";
      VERIFY(intFromStr<int>(L"-1234") == optional{-1234}, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<wstring> with optional for number followed by text";
      VERIFY(intFromStr<int>(L"1234abc") == optional{1234}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for number within text";
      VERIFY(intFromStr<int>(L"abc1234def") == optional<int>{}, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<wstring> with optional for number starting with zeros";
      VERIFY(intFromStr<int>(L"000001234") == optional{1234}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for zero";
      VERIFY(intFromStr<int>(L"0") == optional{0}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for multiple zeros";
      VERIFY(intFromStr<int>(L"00000") == optional{0}, caseLabel);
   }
   {
      const string caseLabel =
         "intFromStr<wstring> with optional for multiple numbers separated by space";
      VERIFY(intFromStr<int>(L"1 2 3") == optional{1}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for too large number";
      VERIFY(
         intFromStr<int>(
            L"9999999999999999999999999999999999999999999999999999999999999999999999") ==
            optional<int>{},
         caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for int8_t";
      VERIFY(intFromStr<int8_t>(L"12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for int16_t";
      VERIFY(intFromStr<int16_t>(L"12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for int32_t";
      VERIFY(intFromStr<int32_t>(L"12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for int64_t";
      VERIFY(intFromStr<int64_t>(L"12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for char";
      VERIFY(intFromStr<char>(L"12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for unsigned char";
      VERIFY(intFromStr<unsigned char>(L"12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for short";
      VERIFY(intFromStr<short>(L"12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for unsigned short";
      VERIFY(intFromStr<unsigned short>(L"12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for long";
      VERIFY(intFromStr<long>(L"12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for unsigned long";
      VERIFY(intFromStr<unsigned long>(L"12") == optional<unsigned long>{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for long long";
      VERIFY(intFromStr<long long>(L"12") == optional{12}, caseLabel);
   }
   {
      const string caseLabel = "intFromStr<wstring> with optional for unsigned long long";
      VERIFY(intFromStr<unsigned long long>(L"12") == optional<unsigned long long>{12},
             caseLabel);
   }
}


void testFpFromStrThrowForString()
{
   {
      const string caseLabel = "fpFromStrThrow<string> for number";
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
      const string caseLabel = "fpFromStrThrow<string> for number with many decimals";
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
      const string caseLabel = "fpFromStrThrow<string> for integer number";
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
      const string caseLabel = "fpFromStrThrow<string> for negative number";
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
      const string caseLabel = "fpFromStrThrow<string> for number followed by text";
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
      const string caseLabel = "fpFromStrThrow<string> for number within text";
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
      const string caseLabel = "fpFromStrThrow<string> for number starting with zeros";
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
      const string caseLabel = "fpFromStrThrow<string> for zero";
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
      const string caseLabel = "fpFromStrThrow<string> for multiple zeros";
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
      const string caseLabel =
         "fpFromStrThrow<string> for multiple numbers separated by space";
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
      const string caseLabel = "fpFromStrThrow<string> for multiple decimal points";
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
      const string caseLabel = "fpFromStrThrow<string> for too large number";
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
      const string caseLabel = "fpFromStrThrow<string> for double";
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
      const string caseLabel = "fpFromStrThrow<string> for long double";
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


void testFpFromStrThrowForWString()
{
   {
      const string caseLabel = "fpFromStrThrow<wstring> for number";
      try
      {
         VERIFY(fpFromStrThrow<float>(L"123.4") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow<wstring> for number with many decimals";
      try
      {
         VERIFY(fpFromStrThrow<float>(L"123.4567890123456789") == 123.4567890123456789f,
                caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow<wstring> for integer number";
      try
      {
         VERIFY(fpFromStrThrow<float>(L"1234") == 1234.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow<wstring> for negative number";
      try
      {
         VERIFY(fpFromStrThrow<float>(L"-123.4") == -123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow<wstring> for number followed by text";
      try
      {
         VERIFY(fpFromStrThrow<float>(L"123.4abc") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow<wstring> for number within text";
      try
      {
         fpFromStrThrow<float>(L"abc123.4def");
         FAIL("Should have thrown", caseLabel);
      }
      catch (...)
      {
         // Expected to get here.
         ;
      }
   }
   {
      const string caseLabel = "fpFromStrThrow<wstring> for number starting with zeros";
      try
      {
         VERIFY(fpFromStrThrow<float>(L"00000123.4") == 123.4f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow<wstring> for zero";
      try
      {
         VERIFY(fpFromStrThrow<float>(L"0") == 0.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow<wstring> for multiple zeros";
      try
      {
         VERIFY(fpFromStrThrow<float>(L"00000") == 0.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel =
         "fpFromStrThrow<wstring> for multiple numbers separated by space";
      try
      {
         VERIFY(fpFromStrThrow<float>(L"1 2 3") == 1.0f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow<wstring> for multiple decimal points";
      try
      {
         VERIFY(fpFromStrThrow<float>(L"1.2.3") == 1.2f, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow<wstring> for too large number";
      try
      {
         fpFromStrThrow<float>(
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
      const string caseLabel = "fpFromStrThrow<wstring> for double";
      try
      {
         VERIFY(fpFromStrThrow<double>(L"12.34") == 12.34, caseLabel);
      }
      catch (...)
      {
         FAIL("Unexpected exception", caseLabel);
      }
   }
   {
      const string caseLabel = "fpFromStrThrow<wstring> for long double";
      try
      {
         VERIFY(fpFromStrThrow<long double>(L"12.34") == 12.34L, caseLabel);
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
      const string caseLabel = "fpFromStr<string> with default for number";
      VERIFY(fpFromStr<float>("123.4", 98.0f) == 123.4f, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<string> with default for number with many decimals";
      VERIFY(fpFromStr<float>("123.4567890123456789", 98.0f) == 123.4567890123456789f,
             caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with default for integer number";
      VERIFY(fpFromStr<float>("1234", 98.0f) == 1234.0f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with default for negative number";
      VERIFY(fpFromStr<float>("-123.4", 98.0f) == -123.4f, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<string> with default for number followed by text";
      VERIFY(fpFromStr<float>("123.4abc", 98.0f) == 123.4f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with default for number within text";
      VERIFY(fpFromStr<float>("abc123.4def", 98.0f) == 98.0f, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<string> with default for number starting with zeros";
      VERIFY(fpFromStr<float>("00000123.4", 98.0f) == 123.4f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with default for zero";
      VERIFY(fpFromStr<float>("0", 98.0f) == 0.0f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with default for multiple zeros";
      VERIFY(fpFromStr<float>("00000", 98.0f) == 0.0f, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<string> with default for multiple numbers separated by space";
      VERIFY(fpFromStr<float>("1 2 3", 98.0f) == 1.0f, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<string> with default for multiple decimal points";
      VERIFY(fpFromStr<float>("1.2.3", 98.0f) == 1.2f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with default for too large number";
      VERIFY(
         fpFromStr<float>(
            "9999999999999999999999999999999999999999999999999999999999999999999999.9",
            98.0f) == 98.0f,
         caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with default for double";
      VERIFY(fpFromStr<double>("12.34", 98.0f) == 12.34, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with default for long double";
      VERIFY(fpFromStr<long double>("12.34", 98.0f) == 12.34L, caseLabel);
   }
}


void testFpFromStrWithDefaultForWString()
{
   {
      const string caseLabel = "fpFromStr<wstring> with default for number";
      VERIFY(fpFromStr<float>(L"123.4", 98.0f) == 123.4f, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<wstring> with default for number with many decimals";
      VERIFY(fpFromStr<float>(L"123.4567890123456789", 98.0f) == 123.4567890123456789f,
             caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with default for integer number";
      VERIFY(fpFromStr<float>(L"1234", 98.0f) == 1234.0f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with default for negative number";
      VERIFY(fpFromStr<float>(L"-123.4", 98.0f) == -123.4f, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<wstring> with default for number followed by text";
      VERIFY(fpFromStr<float>(L"123.4abc", 98.0f) == 123.4f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with default for number within text";
      VERIFY(fpFromStr<float>(L"abc123.4def", 98.0f) == 98.0f, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<wstring> with default for number starting with zeros";
      VERIFY(fpFromStr<float>(L"00000123.4", 98.0f) == 123.4f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with default for zero";
      VERIFY(fpFromStr<float>(L"0", 98.0f) == 0.0f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with default for multiple zeros";
      VERIFY(fpFromStr<float>(L"00000", 98.0f) == 0.0f, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<wstring> with default for multiple numbers separated by space";
      VERIFY(fpFromStr<float>(L"1 2 3", 98.0f) == 1.0f, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<wstring> with default for multiple decimal points";
      VERIFY(fpFromStr<float>(L"1.2.3", 98.0f) == 1.2f, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with default for too large number";
      VERIFY(
         fpFromStr<float>(
            L"9999999999999999999999999999999999999999999999999999999999999999999999.9",
            98.0f) == 98.0f,
         caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with default for double";
      VERIFY(fpFromStr<double>(L"12.34", 98.0f) == 12.34, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with default for long double";
      VERIFY(fpFromStr<long double>(L"12.34", 98.0f) == 12.34L, caseLabel);
   }
}


void testFpFromStrWithOptionalForString()
{
   {
      const string caseLabel = "fpFromStr<string> with optional for number";
      VERIFY(fpFromStr<float>("123.4") == optional{123.4f}, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<string> with optional for number with many decimals";
      VERIFY(fpFromStr<float>("123.4567890123456789") == optional{123.4567890123456789f},
             caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with optional for integer number";
      VERIFY(fpFromStr<float>("1234") == optional{1234.0f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with optional for negative number";
      VERIFY(fpFromStr<float>("-123.4") == optional{-123.4f}, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<string> with optional for number followed by text";
      VERIFY(fpFromStr<float>("123.4abc") == optional{123.4f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with optional for number within text";
      VERIFY(fpFromStr<float>("abc123.4def") == optional<float>{}, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<string> with optional for number starting with zeros";
      VERIFY(fpFromStr<float>("00000123.4") == optional{123.4f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with optional for zero";
      VERIFY(fpFromStr<float>("0") == optional{0.0f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with optional for multiple zeros";
      VERIFY(fpFromStr<float>("00000") == optional{0.0f}, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<string> with optional for multiple numbers separated by space";
      VERIFY(fpFromStr<float>("1 2 3") == optional{1.0f}, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<string> with optional for multiple decimal points";
      VERIFY(fpFromStr<float>("1.2.3") == optional{1.2f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with optional for too large number";
      VERIFY(
         fpFromStr<float>(
            "9999999999999999999999999999999999999999999999999999999999999999999999.9") ==
            optional<float>{},
         caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with optional for double";
      VERIFY(fpFromStr<double>("12.34") == optional{12.34}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<string> with optional for long double";
      VERIFY(fpFromStr<long double>("12.34") == optional{12.34L}, caseLabel);
   }
}


void testFpFromStrWithOptionalForWString()
{
   {
      const string caseLabel = "fpFromStr<wstring> with optional for number";
      VERIFY(fpFromStr<float>(L"123.4") == optional{123.4f}, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<wstring> with optional for number with many decimals";
      VERIFY(fpFromStr<float>(L"123.4567890123456789") == optional{123.4567890123456789f},
             caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with optional for integer number";
      VERIFY(fpFromStr<float>(L"1234") == optional{1234.0f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with optional for negative number";
      VERIFY(fpFromStr<float>(L"-123.4") == optional{-123.4f}, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<wstring> with optional for number followed by text";
      VERIFY(fpFromStr<float>(L"123.4abc") == optional{123.4f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with optional for number within text";
      VERIFY(fpFromStr<float>(L"abc123.4def") == optional<float>{}, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<wstring> with optional for number starting with zeros";
      VERIFY(fpFromStr<float>(L"00000123.4") == optional{123.4f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with optional for zero";
      VERIFY(fpFromStr<float>(L"0") == optional{0.0f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with optional for multiple zeros";
      VERIFY(fpFromStr<float>(L"00000") == optional{0.0f}, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<wstring> with optional for multiple numbers separated by space";
      VERIFY(fpFromStr<float>(L"1 2 3") == optional{1.0f}, caseLabel);
   }
   {
      const string caseLabel =
         "fpFromStr<wstring> with optional for multiple decimal points";
      VERIFY(fpFromStr<float>(L"1.2.3") == optional{1.2f}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with optional for too large number";
      VERIFY(fpFromStr<float>(L"999999999999999999999999999999999999999999999999999999999"
                              L"9999999999999.9") == optional<float>{},
             caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with optional for double";
      VERIFY(fpFromStr<double>(L"12.34") == optional{12.34}, caseLabel);
   }
   {
      const string caseLabel = "fpFromStr<wstring> with optional for long double";
      VERIFY(fpFromStr<long double>(L"12.34") == optional{12.34L}, caseLabel);
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
   {
      const string caseLabel = "utf8 for empty std::string";
      VERIFY(utf8("") == "", caseLabel);
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
   {
      const string caseLabel = "utf8 for empty std::wstring";
      VERIFY(utf8(L"") == "", caseLabel);
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
   {
      const string caseLabel = "utf16 for empty std::string";
      VERIFY(utf16("") == L"", caseLabel);
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
   {
      const string caseLabel = "utf16 for empty std::wstring";
      VERIFY(utf16(L"") == L"", caseLabel);
   }
}


void testConvertToForString()
{
   {
      const string caseLabel = "convertTo std::string from std::wstring";
      VERIFY(convertTo<string>(L"abc123!@#\n\t\x20AC") == "abc123!@#\n\t\xE2\x82\xAC",
             caseLabel);
   }
   {
      const string caseLabel = "convertTo std::string from std::string";
      VERIFY(convertTo<string>("abc123!@#\n\t\xE2\x82\xAC") ==
                "abc123!@#\n\t\xE2\x82\xAC",
             caseLabel);
   }
   {
      const string caseLabel = "convertTo std::string from empty std::wstring";
      VERIFY(convertTo<string>(L"") == "", caseLabel);
   }
   {
      const string caseLabel = "convertTo std::string from empty std::string";
      VERIFY(convertTo<string>("") == "", caseLabel);
   }
}


void testConvertToForWString()
{
   {
      const string caseLabel = "convertTo std::wstring from std::string";
      VERIFY(convertTo<wstring>("abc123!@#\n\t\xE2\x82\xAC") == L"abc123!@#\n\t\x20AC",
             caseLabel);
   }
   {
      const string caseLabel = "convertTo std::wstring from std::wstring";
      VERIFY(convertTo<wstring>(L"abc123!@#\n\t\x20AC") == L"abc123!@#\n\t\x20AC",
             caseLabel);
   }
   {
      const string caseLabel = "convertTo std::wstring from empty std::wstring";
      VERIFY(convertTo<wstring>(L"") == L"", caseLabel);
   }
   {
      const string caseLabel = "convertTo std::wstring from empty std::string";
      VERIFY(convertTo<wstring>("") == L"", caseLabel);
   }
}


void testUtf8WithChar()
{
   {
      const string caseLabel = "utf8 for narrow character";
      VERIFY(utf8('a') == "a", caseLabel);
      VERIFY(utf8('1') == "1", caseLabel);
      VERIFY(utf8('$') == "$", caseLabel);
      VERIFY(utf8('\n') == "\n", caseLabel);
      VERIFY(utf8('\x90') == "\x90", caseLabel);
   }
}


void testUtf8WithWChar()
{
   {
      const string caseLabel = "utf8 for wide character";
      VERIFY(utf8(L'a') == "a", caseLabel);
      VERIFY(utf8(L'1') == "1", caseLabel);
      VERIFY(utf8(L'$') == "$", caseLabel);
      VERIFY(utf8(L'\n') == "\n", caseLabel);
      VERIFY(utf8(L'\x20AC') == "\xE2\x82\xAC", caseLabel);
   }
}


void testUtf16WithChar()
{
   {
      const string caseLabel = "utf16 for narrow character";
      VERIFY(utf16("a", 1) == L'a', caseLabel);
      VERIFY(utf16("1", 1) == L'1', caseLabel);
      VERIFY(utf16("$", 1) == L'$', caseLabel);
      VERIFY(utf16("\n", 1) == L'\n', caseLabel);
      VERIFY(utf16("\xE2\x82\xAC", 3) == L'\x20AC', caseLabel);
   }
   {
      const string caseLabel = "utf16 for narrow character and zero length";
      VERIFY(utf16("", 0) == L'\0', caseLabel);
   }
}


void testUtf16WithWChar()
{
   {
      const string caseLabel = "utf16 for wide character";
      VERIFY(utf16(L"a", 1) == L'a', caseLabel);
      VERIFY(utf16(L"1", 1) == L'1', caseLabel);
      VERIFY(utf16(L"$", 1) == L'$', caseLabel);
      VERIFY(utf16(L"\n", 1) == L'\n', caseLabel);
      VERIFY(utf16(L"\x20AC", 1) == L'\x20AC', caseLabel);
   }
   {
      const string caseLabel = "utf16 for wide character and zero length";
      VERIFY(utf16(L"", 0) == L'\0', caseLabel);
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
