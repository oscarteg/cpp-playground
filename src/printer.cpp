#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

struct Printer {
  std::ostream &os;
  // constructor
  Printer(std::ostream &os) : os(os) {}

  template <typename T> void operator()(const T &obj) { os << obj << ' '; }
};

int main() {
  std::vector<int> v{1, 2, 3};
  std::for_each(v.begin(), v.end(), Printer(std::cout));
  std::string s{"ABC"};
  std::ranges::for_each(s, Printer(std::cout));
}
