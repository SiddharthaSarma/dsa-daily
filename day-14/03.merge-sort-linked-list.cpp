/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* mid = getMid(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return merge(left, right);
  }

  ListNode* merge(ListNode* list1, ListNode* list2) {
    ListNode dummyNode(0);
    ListNode* ptr = &dummyNode;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        ptr->next = list1;
        list1 = list1->next;
      } else {
        ptr->next = list2;
        list2 = list2->next;
      }
      ptr = ptr->next;
    }
    if (list1) {
      ptr->next = list1;
    } else {
      ptr->next = list2;
    }

    return dummyNode.next;
  }

  ListNode* getMid(ListNode* head) {
    ListNode* midPtr = nullptr;
    while (head && head->next) {
      midPtr = (midPtr == nullptr) ? head : midPtr->next;
      head = head->next->next;
    }
    ListNode* mid = midPtr->next;
    midPtr->next = nullptr;
    return mid;
  }
};
