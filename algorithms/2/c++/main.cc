#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*
 * unfortunately  _s.cc has no speedup.
 */
/*
 * Definition for singly-linked list.
 *
 *
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x):val(x),next(NULL){}
 * };
 */

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *rst, *pre, *cur;
    int carry = 0, sum;

    if (l1 == NULL)
      return l2;
    if (l2 == NULL)
      return l1;

    // alloc a useless head node, just to simplify program
    rst = new ListNode(0);
    pre = cur = rst;

    while (l1 && l2) {
      sum = l1->val + l2->val + carry;
      carry = sum/10;
      sum %= 10;
      cur = new ListNode(sum);
      pre->next = cur;
      pre = cur;

      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1) {
      sum = l1->val + carry;
      carry = sum/10;
      sum %= 10;
      l1->val = sum;
      cur = l1;
      pre->next = cur;
      pre = cur;
      l1 = l1->next;
    }

    while (l2) {
      sum = l2->val + carry;
      carry = sum/10;
      sum %= 10;
      l2->val = sum;
      cur = l2;
      pre->next = cur;
      pre = cur;
      l2 = l2->next;
    }

    if (carry) {
      cur = new ListNode(carry);
      pre->next = cur;
    }

    /*del the useless head node*/
    cur = rst;
    rst = rst->next;
    delete cur;
    return rst;
  }
};

void printlist(ListNode *l) {
  if (l == NULL)
    return;
  while (l) {
    cout << l->val << " -> ";
    l = l->next;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  ListNode *l1 = NULL, *l2 = NULL;

  l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);
  printlist(l1);

  l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);
  printlist(l2);

  printlist((new Solution())->addTwoNumbers(l2, l1));

  return 0;
}


/*
 * class Solution{
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode *rst,*pre,*cur;
    int carry = 0,sum;

    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    // alloc a useless head node, just to simplify program
    rst = new ListNode(0);
    pre = cur = rst;

    while(l1 && l2){
      sum = l1->val + l2->val + carry;
      carry = sum / 10;
      sum %= 10;
      cur = new ListNode(sum);
      pre->next = cur;
      pre = cur;

      l1 = l1->next;
      l2 = l2->next;
    }

    while(l1){
      sum = l1->val + carry;
      carry = sum / 10;
      sum %= 10;
      cur = new ListNode(sum);
      pre->next = cur;
      pre = cur;
      l1 = l1->next;
    }

    while(l2){
      sum = l2->val + carry;
      carry = sum / 10;
      sum %= 10;
      cur = new ListNode(sum);
      pre->next = cur;
      pre = cur;
      l2 = l2->next;
    }

    if(carry){
      cur = new ListNode(carry);
      pre->next = cur;
    }
    cur = rst;
    rst = rst->next;
    delete cur;
    return rst;
  }
};
*/