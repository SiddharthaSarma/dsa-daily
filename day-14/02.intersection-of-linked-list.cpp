// https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    ListNode* a = headA;
    ListNode* b = headB;
    while (a != b) {
      a = a ? a->next : headB;
      b = b ? b->next : headA;
    }
    return a;
  }
};
