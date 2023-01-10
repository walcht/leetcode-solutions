#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // Time Complexity: Worst Case O(N^2) (in theory only), in practice this is
  // much faster Memory: Worst Case O(N)
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> complement_map;

    for (int i = 0; i < nums.size(); i++) {
      auto got = complement_map.find(target - nums[i]);
      if (got != complement_map.end()) {
        return vector<int>{i, got->second};
      }

      complement_map[nums[i]] = i;
    }

    return vector<int>{-1, -1};
  }

  // Time Complexity: Worst Case O(N^2)
  // Memory: O(1)
  vector<int> twoSum_01(vector<int> &nums, int target) {

    vector<int> target_couple(2);

    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          target_couple[0] = i;
          target_couple[1] = j;
          return target_couple;
        }
      }
    }

    return target_couple; // no worries about copying, copy elision
                          // optmizationtakes care of it
  }
};
