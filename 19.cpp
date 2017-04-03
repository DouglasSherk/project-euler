#include <iostream>
#include <math.h>
#include "Vector.h"
#include <string>

using namespace std;

// 1 Jan 1900 was a Monday.
// Days in each month:
//  Jan 31
//  Feb 28 (unless leap year, 29)
//  Mar 31
//  Apr 30
//  May 31
//  Jun 30
//  Jul 31
//  Aug 31
//  Sep 30
//  Oct 31
//  Nov 31
//  Dec 31
// A leap year occurs on any year evenly divisible by 4, but not on a century
// unless it is divisible by 400.

// There aren't really 13, we just index from 1 instead of 0.
#define MONTHS 13

bool isLeapYear(int year) {
  // Year is a multiple of 4, or it's a century that is evenly divisible by 400.
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main(int argc, char** argv) {
  int daysInMonths[MONTHS] = {
    0,
    31, // Jan
    28, // Feb (special)
    31, // Mar
    30, // Apr
    31, // May
    30, // Jun
    31, // Jul
    31, // Aug
    30, // Sep
    31, // Oct
    31, // Nov
    31  // Dec
  };
  int day = 7, month = 1, year = 1900;
  int sum = 0;
  while (year <= 2000 && month <= 12 && day <= 31) {
    day += 7;
    int daysInMonth = daysInMonths[month] + (month == 2 && isLeapYear(year) ? 1 : 0);
    cout << "Evaluating " << year << "-" << month << "-" << day << endl;
    if (day > daysInMonth) {
      month++;
      day %= daysInMonth;
    }
    if (month >= MONTHS) {
      month = 1;
      year++;
    }
    if (day == 1) {
      cout << year << "-" << month << "-" << day << " was a Sunday" << endl;
      sum++;
    }
  }
  cout << "Total Sundays that were the first day of the month: " << sum << endl;
  return 0;
}
