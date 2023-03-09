#ifndef _TEST_UTIL_VALUES_HPP_
#define _TEST_UTIL_VALUES_HPP_

namespace util
{
  // max
  // Gets the largest value from a template parameter pack of values
  template <typename T, T size = T(), T... sizes>
  struct max
  {
    static constexpr T value = size > max<T, sizes...>::value ? size : max<T, sizes...>::value;
  };

  template <typename T, T size>
  struct max<T, size>
  {
    static constexpr T value = size;
  };

  // max_v
  // Equal to the value of max<>::value
  template <typename T, T size = T(), T... sizes>
  constexpr T max_v = max<T, size, sizes...>::value;

  // min
  // Gets the smallest value from a template parameter pack of values
  template <typename T, T size = T(), T... sizes>
  struct min
  {
    static constexpr T value = size < min<T, sizes...>::value ? size : min<T, sizes...>::value;
  };

  template <typename T, T size>
  struct min<T, size>
  {
    static constexpr T value = size;
  };

  // min_V
  // Equal to the value of min<>::value
  template <typename T, T size = T(), T... sizes>
  constexpr T min_v = min<T, size, sizes...>::value;

  template <typename T>
  int sign(T val) 
  {
    return (T(0) < val) - (val < T(0));
  }
}

#endif // #ifndef _TEST_UTIL_VALUES_HPP_