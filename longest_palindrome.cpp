#include <string>

using namespace std;

struct Palindrome {
  // parent string from where this palindrome substr is exteacted
  const string &parentStr;

  int start;
  int end; // last index excluded

  Palindrome(const string &_parentStr, int _start = 0, int _end = 1)
      : parentStr(_parentStr), start(_start), end(_end) {}

  int getLength() const { return end - start; }
  string getPalindrome() const { return parentStr.substr(start, end - start); }
};

class Solution {
public:
  string longestPalindrome(string s) {

    // initial longest palindrome is the first character in s
    Palindrome palindrome(s, 0, 1);

    // i stantds for the center of the current palindrome substring
    for (int i = 0; i < s.length() - 1; ++i) {
      // example: "bab" => start is 1, end is 1
      int substr_start = i;
      int substr_end = i;

      // find first character that is different thant s[substr_start]
      // the region from substr_start => substr_end is the center of the current
      // palindrome substr exampe:
      //    "abba" for i = 1; center = "bb"
      //    "abc" for i = 1; center = "b"
      while (substr_end < s.length() - 1) {
        if (s[substr_end + 1] != s[substr_end])
          break;
        ++substr_end;
      }

      while (true) {
        if (substr_start - 1 < 0)
          break;
        if (substr_end + 1 >= s.length())
          break;
        if (s[substr_start - 1] != s[substr_end + 1])
          break;

        --substr_start;
        ++substr_end;
      }

      if ((substr_end - substr_start + 1) > palindrome.getLength()) {
        palindrome.start = substr_start;
        palindrome.end = substr_end + 1;
      }
    }

    return palindrome.getPalindrome();
  }
};
