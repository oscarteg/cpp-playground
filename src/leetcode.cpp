#include <cstdio>
#include <stack>

class Solution {
public:
  bool isValid(std::string s) {

    std::stack<char> stack;
    std::unordered_map<char, char> closeToOpen = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };

    for (char &c : s) {
      // If it's a closing bracket
      if (closeToOpen.count(c)) {
        if (stack.empty() || stack.top() != c) {
          return false;
        }
        stack.pop();
      } else {
        stack.push(c);
      }
    }

    return stack.empty();
  }
};

int main() {
  printf(Solution().isValid("(){") ? "true\n" : "false\n");
  return 0;
}
