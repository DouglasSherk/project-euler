#ifndef __EULER_TYPES_INCLUDED_
#define __EULER_TYPES_INCLUDED_

#include <string>
#include <sstream>

namespace euler {

int toInt(std::string n) {
  std::stringstream strstream;
  strstream << n;
  int n_int;
  strstream >> n_int;
  return n_int;
}

}

#endif // __EULER_TYPES_INCLUDED_
