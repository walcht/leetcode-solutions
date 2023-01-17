#include <string>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {

    string result;

    int initial_index = 0;

    int current_jump = 2 * numRows - 3;
    if (current_jump < 0)
      current_jump = 0;

    int initial_jump = current_jump;

    auto last_row_jumps = [&]() {
      int current_index = initial_index;

      while (current_index < s.length()) {
        result.append(1, s[current_index]);
        current_index += initial_jump + 1;
      }
    };

    // intermediate values where 2 jumps are performed each run
    while (current_jump > 1) {

      int current_index = initial_index;
      int jump_in_between = initial_jump - current_jump - 1;

      while (current_index < s.length()) {

        result.append(1, s[current_index]);
        current_index += current_jump + 1;

        if (current_index < s.length()) {
          result.append(1, s[current_index]);
          current_index += jump_in_between + 1;
        }
      }

      current_jump -= 2;
      ++initial_index;
    }

    // perfom jumps on last row
    last_row_jumps();

    return result;
  }
};
