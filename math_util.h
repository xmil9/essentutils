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

// Limits a value to given min and max values.
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


// Shifts a given value into the range of given min and max values. The
// value will end up in the same position within the range.
// Example:
//   780 shift into [0, 360] => 60
template <typename T>
T shiftIntoRange(T val, T min, T max)
{
   static_assert(std::is_integral_v<T>);

	// Normalize.
	if (min > max)
   {
      using std::swap;
      swap(min, max);
	}

	// Guard against div by zero.
	T len = max - min;
	if (len == 0)
		return val;

	// Shift.
	if (val < min)
		val = max - (min - val) % len;
	if (val > max)
		val = min + (val - min) % len;

   assert(min <= val && val <= max);
	return val;
}

} // namespace sutil
