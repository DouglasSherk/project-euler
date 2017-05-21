#ifndef __EULER_PALINDROMES_INCLUDED_
#define __EULER_PALINDROMES_INCLUDED_

#include <string>

namespace euler {

bool isPalindromic(std::string n) {
  return n == std::string(n.rbegin(), n.rend());
}

bool isPalindromic(long long n) {
  return isPalindromic(std::to_string(n));
}

}

#endif // __EULER_PALINDROMES_INCLUDED_
