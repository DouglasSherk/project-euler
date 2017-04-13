#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  ifstream namesFile("22_names.txt");

  // We don't have a string class, so use STL's for now.
  string line;

  // We can't sort our home-baked vector, so let's just use the STL one for now.
  vector<string> names;

  while (getline(namesFile, line, ',')) {
    line.erase(remove(line.begin(), line.end(), '\"'), line.end());
    names.push_back(line);
  }

  sort(names.begin(), names.end());

  unsigned long totalSum = 0;
  for (int i = 0; i < names.size(); i++) {
    int charSum = 0;
    for (int j = 0; j < names[i].length(); j++) {
      charSum += names[i][j] - 'A' + 1;
    }
    charSum *= (i + 1);
    totalSum += charSum;
    cout << names[i] << " charSum: " << charSum << ", new totalSum: " << totalSum << endl;
  }

  cout << "Total score of all names: " << totalSum << endl;

  return 0;
}
