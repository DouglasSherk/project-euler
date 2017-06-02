#ifndef __EULER_TYPES_INCLUDED_
#define __EULER_TYPES_INCLUDED_

#include <string>
#include <sstream>

namespace euler {

template <class T>
T toInt(std::string n) {
  std::stringstream strstream;
  strstream << n;
  T n_int;
  strstream >> n_int;
  return n_int;
}

template <class T>
T reverseInt(T n) {
  std::string n_str = std::to_string(n);
  return toInt<T>(std::string(n_str.rbegin(), n_str.rend()));
}

}

#endif // __EULER_TYPES_INCLUDED_
