#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <math.h>
#include <map>
#include <vector>

using namespace std;

int target = 200;

namespace one {
  void main() {
    vector<int> coinSizes = {1, 2, 5, 10, 20, 50, 100, 200};

    int* ways = new int[target + 1];
    for (int i = 0; i <= target; i++) {
      ways[i] = 0;
    }
    ways[1] = 1;

    for (int i = 0; i < coinSizes.size(); i++) {
      for (int j = coinSizes[i]; j <= target; j++) {
        ways[j] += ways[j - coinSizes[i]];
      }
    }

    cout << "Total ways: " << ways[target] << endl;
  }
}

namespace two {
  int lastFirst = -1;

  map<vector<int>, int> cache;

  void print(vector<int>& coins) {
    if (!coins.size() || coins[0] == lastFirst) {
      return;
    }
    lastFirst = coins[0];
    cout << "Exploring: ";
    for (auto it : coins) {
      cout << it << " ";
    }
    cout << endl;
  }

  int sum(vector<int>& coins) {
    if (cache.find(coins) != cache.end()) {
      return cache[coins];
    }

    int sum = 0;
    for (auto it : coins) {
      sum += it;
    }
    cache[coins] = sum;
    return sum;
  }

  void composeMoney(int amount, int start, vector<int>& coins, vector<int>& selected) {
    int currentTotal = sum(selected);
    if (currentTotal >= amount) {
      return;
    }

    print(selected);

    for (int i = start; i < coins.size(); i++) {
      selected.push_back(coins[i]);
      composeMoney(amount, i, coins, selected);
      selected.pop_back();
    }
  }

  void main() {
    vector<int> coins;
    coins.push_back(200);
    coins.push_back(100);
    coins.push_back(50);
    coins.push_back(20);
    coins.push_back(10);
    coins.push_back(5);
    coins.push_back(2);
    coins.push_back(1);
    vector<int> selected;
    composeMoney(target, 0, coins, selected);
    int total = 0;
    for (auto it : cache) {
      if (it.second == target) {
        total++;
      }
    }
    cout << "Total ways: " << total << endl;
  }
}

int main(int argc, char** argv) {
  one::main();
  two::main();
  return 0;
}
