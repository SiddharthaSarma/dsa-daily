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

// Method 2
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* cur = NULL;
    while (head) {
      ListNode* temp = head->next;
      head->next = cur;
      cur = head;
      head = temp;
    }
    return cur;
  }
};
