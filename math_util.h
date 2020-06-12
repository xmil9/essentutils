//
// essentutils
// Math utilities.
//
// Jun-2020, Michael Lindner
// MIT license
//
#pragma once
#include <cassert>
#include <utility>


namespace sutil
{

////////////////////
// Value ranges.

template <typename T>
T clampToRange(T val, T min, T max)
{
	// Normalize.
	if (min > max)
   {
      using std::swap;
      swap(min, max);
	}

	// Clamp.
	if (val < min)
		val = min;
	if (val > max)
		val = max;

   assert(min <= val && val <= max);
	return val;
}

} // namespace sutil
