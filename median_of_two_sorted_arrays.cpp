#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int target_index = (nums1.size() + nums2.size() - 1) / 2;

    int offset_nums1 = 0;
    int offset_nums2 = 0;

    int index_in_merged_array = 0;

    // true = first array, false = last array
    bool last_modified_array = false;

    auto indexMoveOperation = [&] {
      if (offset_nums1 >= nums1.size()) {
        offset_nums2++;
        last_modified_array = false;
      }

      else if (offset_nums2 >= nums2.size()) {
        offset_nums1++;
        last_modified_array = true;
      }

      else if (nums1[offset_nums1] > nums2[offset_nums2]) {
        offset_nums2++;
        last_modified_array = false;
      }

      else {
        offset_nums1++;
        last_modified_array = true;
      }

      ++index_in_merged_array;
    };

    while (index_in_merged_array < target_index + 1)
      indexMoveOperation();

    // in case merged size is even, do one extra time the previous operation
    if (!((nums1.size() + nums2.size()) % 2)) {
      int tmp_val = last_modified_array ? nums1[offset_nums1 - 1]
                                        : nums2[offset_nums2 - 1];
      indexMoveOperation();

      return last_modified_array ? (nums1[offset_nums1 - 1] + tmp_val) / 2.00
                                 : (nums2[offset_nums2 - 1] + tmp_val) / 2.00;
    }

    return last_modified_array ? nums1[offset_nums1 - 1]
                               : nums2[offset_nums2 - 1];
  }
};
