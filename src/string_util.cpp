//
// essentutils
// String utilities.
//
// Jun-2019, Michael Lindner
// MIT license
//
#include "string_util.h"
#include <algorithm>
#include <clocale>
#include <cstddef>
#include <cstdlib>

using namespace std;


namespace
{
///////////////////

// RAII class for setting the global locale to UTF8 for the lifetime of
// an instance.
class Utf8Locale
{
 public:
   Utf8Locale();
   ~Utf8Locale();
   Utf8Locale(const Utf8Locale&) = delete;
   Utf8Locale(Utf8Locale&&) = default;
   Utf8Locale& operator=(const Utf8Locale&) = delete;
   Utf8Locale& operator=(Utf8Locale&&) = default;

 private:
   std::string m_prevLocale;
};


Utf8Locale::Utf8Locale()
{
   char* prevLocale = std::setlocale(LC_ALL, "en_US.utf8");
   if (prevLocale)
      m_prevLocale = prevLocale;
}

Utf8Locale::~Utf8Locale()
{
   if (!m_prevLocale.empty())
      std::setlocale(LC_ALL, m_prevLocale.c_str());
}

} // namespace


namespace sutil
{
///////////////////

bool startsWith(const std::string& s, const std::string& start)
{
   const size_t pos = s.find(start);
   return (pos == 0);
}


bool endsWith(const std::string& s, const std::string& tail)
{
   const size_t pos = s.rfind(tail);
   return (pos + tail.size() == s.size());
}


std::string lowercase(const std::string& s)
{
   // Only works correctly for ANSI characters. Unicode characters (UTF8) cannot be
   // handled correctly without a third-party lib like ICU!

   std::string lower;
   // The behavior of std::tolower is undefined if the argument's value is neither
   // representable as unsigned char nor equal to EOF. To use these functions safely
   // with plain chars (or signed chars), the argument should first be converted to
   // unsigned char. (cppreference.com)
   transform(s.begin(), s.end(), back_inserter(lower),
             [](unsigned char ch) { return static_cast<char>(tolower(ch)); });
   return lower;
}


std::string uppercase(const std::string& s)
{
   // Only works correctly for ANSI characters. Unicode characters (UTF8) cannot be
   // handled correctly without a third-party lib like ICU!

   std::string upper;
   // The behavior of std::toupper is undefined if the argument's value is neither
   // representable as unsigned char nor equal to EOF. To use these functions safely
   // with plain chars (or signed chars), the argument should first be converted to
   // unsigned char. (cppreference.com)
   transform(s.begin(), s.end(), back_inserter(upper),
             [](unsigned char ch) { return static_cast<char>(toupper(ch)); });
   return upper;
}


std::string trim(const std::string& s, char ch)
{
   return trimRight(trimLeft(s, ch), ch);
}


std::string trimLeft(const std::string& s, char ch)
{
   const size_t pos = s.find_first_not_of(ch);
   if (pos != string::npos)
      return s.substr(pos);
   return "";
}


std::string trimRight(const std::string& s, char ch)
{
   const size_t pos = s.find_last_not_of(ch);
   if (pos != string::npos)
      return s.substr(0, pos + 1);
   return "";
}


std::vector<std::string> split(const std::string& s, const std::string& separator)
{
   vector<string> split;

   const size_t sepLen = separator.size();
   size_t pos = 0;
   size_t next = s.find(separator, pos);
   while (next != -1)
   {
      split.push_back(s.substr(pos, next - pos));
      pos = next + sepLen;
      next = s.find(separator, pos);
   }

   split.push_back(s.substr(pos));
   return split;
}


std::string utf8(const std::string& s)
{
   // Nothing to do but it's convenient to have the overload available to
   // reduce checks in calling code.
   return s;
}


std::string utf8(const std::wstring& s)
{
   Utf8Locale utf8Locale;

   vector<char> buffer(s.size() * 4, 0);
   const size_t numBytesWritten = wcstombs(buffer.data(), s.c_str(), buffer.size());
   if (numBytesWritten == -1)
      return "";

   return buffer.data();
}


std::wstring utf16(const std::string& s)
{
   Utf8Locale utf8Locale;

   vector<wchar_t> buffer(s.size() * 4, 0);
   const size_t numBytesWritten = mbstowcs(buffer.data(), s.c_str(), buffer.size());
   if (numBytesWritten == -1)
      return L"";

   return buffer.data();
}


std::wstring utf16(const std::wstring& s)
{
   // Nothing to do but it's convenient to have the overload available to
   // reduce checks in calling code.
   return s;
}

} // namespace util
