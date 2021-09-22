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

// Method 3
class Solution {
public:
  ListNode* reverse(ListNode* head, ListNode* newHead) {
    if (!head) {
      return newHead;
    }
    ListNode* temp = head->next;
    head->next = newHead;
    return reverse(temp, head);
  }
  ListNode* reverseList(ListNode* head) {
    return reverse(head, NULL);
  }
};
