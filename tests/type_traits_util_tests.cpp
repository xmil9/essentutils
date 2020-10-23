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
#include <map>
#include <vector>


namespace
{
///////////////////

void testIsIterator()
{
   // Check iterator types.
   static_assert(sutil::isIterator_v<std::vector<int>::iterator>,
                 "IsIterator failed for std::vector<int>::iterator.");
   static_assert(sutil::isIterator_v<std::string::const_iterator>,
                 "IsIterator failed for std::string::const_iterator.");
   static_assert(sutil::isIterator_v<std::list<float>::iterator>,
                 "IsIterator failed for std::list<float>::iterator.");
   static_assert(sutil::isIterator_v<int*>, "IsIterator failed for pointer.");

   struct CustomIter
   {
      using difference_type = std::ptrdiff_t;
      using value_type = int;
      using pointer = value_type*;
      using reference = value_type&;
      using iterator_category = std::forward_iterator_tag;
   };
   static_assert(sutil::isIterator_v<CustomIter>, "IsIterator failed for CustomIter.");

   // Check non-iterator types.
   static_assert(!sutil::isIterator_v<int>, "IsIterator allowed int.");
   static_assert(!sutil::isIterator_v<int&>, "IsIterator allowed reference.");

   struct CustomType
   {
      bool b = false;
   };
   static_assert(!sutil::isIterator_v<CustomType>, "IsIterator allowed CustomType.");
}


void testIsOneOf()
{
   struct A
   {
   };
   struct B
   {
   };

   static_assert(sutil::isOneOf_v<int, int>);
   static_assert(sutil::isOneOf_v<int, int, short>);
   static_assert(sutil::isOneOf_v<int, short, long, int>);
   static_assert(sutil::isOneOf_v<void, A, B, void>);
   static_assert(sutil::isOneOf_v<float*, float, float&, float*>);
   static_assert(sutil::isOneOf_v<const float, unsigned int, const float>);
   static_assert(sutil::isOneOf_v<A, B, A>);
   static_assert(
      sutil::isOneOf_v<std::vector<int>, std::map<int, int>, std::vector<int>>);

   static_assert(!sutil::isOneOf_v<int, bool, short, long>);
   static_assert(!sutil::isOneOf_v<float, float*, float&, const float>);
   static_assert(!sutil::isOneOf_v<float, A, B, std::vector<float>>);
   static_assert(!sutil::isOneOf_v<A, B, B, bool>);
   static_assert(!sutil::isOneOf_v<std::vector<int>, std::map<int, int>, A, B>);
   static_assert(!sutil::isOneOf_v<std::vector<int>, std::vector<unsigned int>,
                                   std::vector<double>>);
}

} // namespace


///////////////////

void testTypeTraitsUtil()
{
   testIsIterator();
   testIsOneOf();
}
