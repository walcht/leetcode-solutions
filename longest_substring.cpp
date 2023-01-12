#include <string>

using namespace std;

// a sliding window is defined by its start and end index (excluded) in a parent
// string SlidingWindow(str, 0, 1) creates a sliding window of size 1 (NOT 2)
struct SlidingWindow {
  int start = 0;
  int end = 0;

  const string &parentStr;

  SlidingWindow(const string &p_parentStr) : parentStr(p_parentStr) {}

  // checks wether the element index by end ib the parent string is in the
  // sliding window if yes, returns its index, -1 otherwise
  int getCharIndex() const {
    for (int i = start; i < end; ++i)
      if (parentStr[i] == parentStr[end])
        return i;

    return -1;
  }

  // returns length of this sliding window
  int getLength() const { return end - start; }
};

class Solution {
public:
  int lengthOfLongestSubstring(string s) {

    // make sure s is not empty
    if (s.empty())
      return 0;

    int longest_substr = 1;

    SlidingWindow current_substr(s);

    auto updateLongestSubStr = [&] {
      if (current_substr.getLength() > longest_substr)
        longest_substr = current_substr.getLength();
    };

    while (current_substr.end < s.length()) {

      int find_result = current_substr.getCharIndex();

      // if newly added character is a duplicate, update longest substr and
      // reset start index of the sliding window
      if (find_result >= 0) {

        updateLongestSubStr();
        current_substr.start = find_result + 1;
      }

      ++current_substr.end;
    }

    updateLongestSubStr();

    return longest_substr;
  }
};
