#include <string>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {

    // no need to do anything if we have less than 1 row
    if (numRows <= 1)
      return s;

    string result;

    // global initial index in string s to start jumping sequence from
    int initial_index = 0;

    int current_jump = 2 * numRows - 3;
    int complementary_jump = -1;

    while (current_jump >= -1) {

      int current_index = initial_index;

      while (current_index < s.length()) {

        if (current_jump > 0) {
          result.append(1, s[current_index]);
          current_index += current_jump + 1;
        }

        if ((complementary_jump > 0) && (current_index < s.length())) {
          result.append(1, s[current_index]);
          current_index += complementary_jump + 1;
        }
      }

      current_jump -= 2;
      complementary_jump += 2;

      ++initial_index;
    }

    return result;
  }
};
