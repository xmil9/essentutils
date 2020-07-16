//
// essentutils tests
// Tests for type traits utilities.
//
// Jul-2020, Michael Lindner
// MIT license
//
#include "type_traits_util_tests.h"
#include "type_traits_util.h"
#include "test_util.h"
#include <iterator>
#include <list>
#include <vector>


namespace
{
///////////////////

void testIsIterator()
{
   // Check iterator types.
   static_assert(sutil::IsIterator_v<std::vector<int>::iterator>,
                 "IsIterator failed for std::vector<int>::iterator.");
   static_assert(sutil::IsIterator_v<std::string::const_iterator>,
                 "IsIterator failed for std::string::const_iterator.");
   static_assert(sutil::IsIterator_v<std::list<float>::iterator>,
                 "IsIterator failed for std::list<float>::iterator.");
   static_assert(sutil::IsIterator_v<int*>, "IsIterator failed for pointer.");

   struct CustomIter
   {
      using difference_type = std::ptrdiff_t;
      using value_type = int;
      using pointer = value_type*;
      using reference = value_type&;
      using iterator_category = std::forward_iterator_tag;
   };
   static_assert(sutil::IsIterator_v<CustomIter>, "IsIterator failed for CustomIter.");

   // Check non-iterator types.
   static_assert(!sutil::IsIterator_v<int>, "IsIterator allowed int.");
   static_assert(!sutil::IsIterator_v<int&>, "IsIterator allowed reference.");

   struct CustomType
   {
      bool b = false;
   };
   static_assert(!sutil::IsIterator_v<CustomType>, "IsIterator allowed CustomType.");
}

} // namespace


///////////////////

void testTypeTraitsUtil()
{
   testIsIterator();
}
