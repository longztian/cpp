/**
 * Defination of  singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode* next;
 *
 *   ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

// reverse twice
class Solution {
public:
  ListNode* plusOne(ListNode* head) {
    ListNode *p, *dummy = new ListNode(0);
    while (head) {
      p = head->next;
      head->next = dummy->next;
      dummy->next = head;
      head = p;
    }

    head = dummy->next;
    dummy->next = nullptr;

    bool plus = true;
    while (head) {
      if (plus) {
        if (head->val == 9) {
          head->val = 0;
        } else {
          head->val += 1;
          plus = false;
        }
      }

      p = head->next;
      head->next = dummy->next;
      dummy->next = head;
      head = p;
    }

    if (plus) {
      head = new ListNode(1);
      head->next = dummy->next;
      dummy->next = head;
    }

    p = dummy->next;
    delete dummy;
    return p;
  }
};

// recursive
class Solution {
public:
  ListNode* plusOne(ListNode* head) {
    int carry = myPlusOne(head);
    if (carry) {
      auto p = new ListNode(1);
      p->next = head;
      head = p;
    }

    return head;
  }

private:
  int myPlusOne(ListNode* head) {
    if (head == nullptr) return 1;

    int carry = myPlusOne(head->next);
    if (carry) {
      if (head->val == 9) {
        head->val = 0;
        carry = 1;
      } else {
        head->val += 1;
        carry = 0;
      }
    }

    return carry;
  }
};
