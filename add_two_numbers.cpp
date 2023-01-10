#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    // create new ListNode on the heap
    ListNode *sum = new ListNode();

    // create a copy of the original ListNode pointer to manipulate it without
    // losing the original pointer
    ListNode *sum_copy = sum;

    // holds carry bit for the addition operation
    int carry = 0;

    // keep running if l1 or l2 are NOT nullptr or carry is NOT null
    while (l1 || l2 || carry) {
      int l1_element = 0;
      int l2_element = 0;

      if (l1) {
        l1_element = l1->val;
        l1 = l1->next;
      }

      if (l2) {
        l2_element = l2->val;
        l2 = l2->next;
      }

      sum_copy->val = (l1_element + l2_element + carry) % 10;
      carry = (l1_element + l2_element + carry) / 10;

      // only create next ListNode object if l1 or l2 are not nullptr
      // or if the carry is NOT null
      if (l1 || l2 || carry) {
        sum_copy->next = new ListNode();
        sum_copy = sum_copy->next;
      }
    }

    return sum;
  }
};
