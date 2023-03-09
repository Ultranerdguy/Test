#ifndef _TEST_UTIL_TYPES_HPP_
#define _TEST_UTIL_TYPES_HPP_

namespace util
{
  // largest
  // Gets the largest data type in the template parameter pack
  template <typename T = void, typename ...Ts>
  struct largest
  {
    using type = typename std::conditional_t<(sizeof(T) > sizeof(typename largest<Ts...>::type)), T, typename largest<Ts...>::type>;
  };

  template <typename T>
  struct largest<T>
  {
    using type = T;
  };

  template <typename ...Ts>
  struct largest<void, Ts...>
  {
    using type = typename largest<Ts...>::type;
  };

  template <typename T>
  struct largest<T, void>
  {
    using type = T;
  };

  template <>
  struct largest<void>
  {
  };

  // largest_t
  // Equal to the type of largest<>::type
  template <typename T = void, typename ...Ts>
  using largest_t = typename largest<T, Ts...>::type;

  // smallest
  // Gets the smallest data type in the template parameter pack
  template <typename T = void, typename ...Ts>
  struct smallest
  {
    using type = typename std::conditional_t<(sizeof(T) < sizeof(typename smallest<Ts...>::type)), T, typename smallest<Ts...>::type>;
  };

  template <typename T>
  struct smallest<T>
  {
    using type = T;
  };

  template <typename ...Ts>
  struct smallest<void, Ts...>
  {
    using type = typename smallest<Ts...>::type;
  };

  template <typename T>
  struct smallest<T, void>
  {
    using type = T;
  };

  template <>
  struct smallest<void>
  {
  };

  // smallest_t
  // Equal to the type of smallest<>::type
  template <typename T = void, typename ...Ts>
  using smallest_t = typename smallest<T, Ts...>::type;
  
  // conjunction_test
  // Tests if all types in ...Types satisfy the test described by TestClass
  // TestClass must have a public static member variable convertible to a bool
  template <template <typename T> typename TestClass, typename ...Types>
  struct conjunction_test
    : std::conjunction<TestClass<Types>...>
  {};
  
  // conjunction_test_v
  // Equal to the value of conjunction_test
  template <template <typename T> typename TestClass, typename ...Types>
  constexpr bool conjunction_test_v = conjunction_test<TestClass, Types...>::value;

  // disjunction_test
  // Tests if any types in ...Types satisfy the test described by TestClass
  // TestClass must have a public static member variable convertible to a bool
  template <template <typename T> typename TestClass, typename ...Types>
  struct disjunction_test
    : std::disjunction<TestClass<Types>...>
  {};

  // disjunction_test_v
  // Equal to the value of disjunction_test
  template <template <typename T> typename TestClass, typename ...Types>
  constexpr bool disjunction_test_v = disjunction_test<TestClass, Types...>::value;
}

#endif // #ifndef _TEST_UTIL_TYPES_HPP_