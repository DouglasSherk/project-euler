#include <iostream>
#include <math.h>
#include "Vector.h"
#include "HashTable.h"

struct Position {
  int x;
  int y;
  bool operator ==(const Position& other) const {
    return this->x == other.x && this->y == other.y;
  }
  operator size_t() const {
    return this->x * 10000 + this->y;
  }
};

HashTable<Position, unsigned long>* memos;

unsigned long run(int size, const Position& pos) {
  cout << "At {" << pos.x << "," << pos.y << "}" << endl;
  if (pos.x > size || pos.y > size) {
    cout << "{" << pos.x << "," << pos.y << "} past limit" << endl;
    return 0;
  }
  if (memos->has(pos)) {
    return memos->get(pos);
  }
  unsigned long paths = run(size, Position({pos.x + 1, pos.y})) +
                        run(size, Position({pos.x, pos.y + 1}));
  memos->set(pos, paths);
  return paths + 1;
}

int main(int argc, char** argv) {
  memos = new HashTable<Position, unsigned long>;
  cout << "Total paths: " << run(2, Position({0, 0})) << endl;
  delete memos;
  //memos = new HashTable<Position, unsigned long>;
  //cout << "Total paths: " << run(20, Position({0, 0})) << endl;
  //delete memos;
  return 0;
}
