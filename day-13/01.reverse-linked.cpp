class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* temp = NULL;
    while (head) {
      temp = new ListNode(head->val, temp);
      head = head->next;
    }
    return temp;
  }
};
