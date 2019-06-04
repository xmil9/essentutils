//
// essentutils
// String utilities.
//
// Jun-2019, Michael Lindner
// MIT license
//
#pragma once
#include <iterator>
#include <optional>
#include <string>
#include <vector>


namespace sutil
{
///////////////////

bool startsWith(const std::string& s, const std::string& start);
bool endsWith(const std::string& s, const std::string& tail);
std::string lowercase(const std::string& s);
std::string uppercase(const std::string& s);
std::string trim(const std::string& s, char ch);
std::string trimLeft(const std::string& s, char ch);
std::string trimRight(const std::string& s, char ch);
std::vector<std::string> split(const std::string& s, const std::string& separator);
template <typename Iter>
std::string join(Iter it, Iter end, const std::string& glue = "");

template <typename Int> Int intFromStr_throw(const std::string& s);
template <typename Int> Int intFromStr(const std::string& s, Int defaultValue) noexcept;
template <typename Int> std::optional<Int> intFromStr(const std::string& s) noexcept;
template <typename FP> FP fpFromStr_throw(const std::string& s);
template <typename FP> FP fpFromStr(const std::string& s, FP defaultValue) noexcept;
template <typename FP> std::optional<FP> fpFromStr(const std::string& s) noexcept;

std::string utf8(const std::string& s);
std::string utf8(const std::wstring& s);
std::wstring utf16(const std::string& s);
std::wstring utf16(const std::wstring& s);


///////////////////

// Template definitions

template <typename Iter> std::string join(Iter it, Iter end, const std::string& glue)
{
   static_assert(std::is_same_v<std::iterator_traits<Iter>::value_type, std::string>);

   std::string joined;
   for (; it != end; ++it)
   {
      if (!joined.empty())
         joined += glue;
      joined += *it;
   }
   return joined;
}


template <typename Int> Int intFromStr_throw(const std::string& s)
{
   if constexpr (std::is_same_v<Int, long>)
      return std::stol(s.c_str());
   else if constexpr (std::is_same_v<Int, long long>)
      return std::stoll(s.c_str());
   else if constexpr (std::is_same_v<Int, unsigned long>)
      return std::stoul(s.c_str());
   else if constexpr (std::is_same_v<Int, unsigned long long>)
      return std::stoull(s.c_str());
   else
      return static_cast<Int>(std::stoi(s.c_str()));
}


template <typename Int> Int intFromStr(const std::string& s, Int defaultValue) noexcept
{
   try
   {
      return intFromStr_throw<Int>(s);
   }
   catch (...)
   {
      return defaultValue;
   }
}


template <typename Int> std::optional<Int> intFromStr(const std::string& s) noexcept
{
   try
   {
      return intFromStr_throw<Int>(s);
   }
   catch (...)
   {
      return {};
   }
}


template <typename FP> FP fpFromStr_throw(const std::string& s)
{
   if constexpr (std::is_same_v<FP, double>)
      return std::stod(s.c_str());
   else if constexpr (std::is_same_v<FP, long double>)
      return std::stold(s.c_str());
   else
      return std::stof(s.c_str());
}


template <typename FP> FP fpFromStr(const std::string& s, FP defaultValue) noexcept
{
   try
   {
      return fpFromStr_throw<FP>(s);
   }
   catch (...)
   {
      return defaultValue;
   }
}


template <typename FP> std::optional<FP> fpFromStr(const std::string& s) noexcept
{
   try
   {
      return fpFromStr_throw<FP>(s);
   }
   catch (...)
   {
      return {};
   }
}

} // namespace sutil
