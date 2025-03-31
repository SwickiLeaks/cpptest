#include <algorithm>
#include <bits/stdc++.h>
#include <ranges>
#include <string>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x) : val(x), next(nullptr){};
  ListNode(int x, ListNode *next) : val(x), next(next){};
};

ListNode *createLinkedList(vector<int> &values) {
  if (values.empty())
    return nullptr;
  ListNode *head = new ListNode(values[0]);
  ListNode *current = head;

  for (size_t i = 1; i < values.size(); i++) {
    current->next = new ListNode(values[i]);
    current = current->next;
  }

  return head;
}

void freeLinkedList(ListNode *head) {
  while (head) {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

void printLinkedList(ListNode *head) {
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

/**
 * @brief Class containing the solution for the problem
 */
class Solution {
public:
  Solution() {}
  ~Solution() {}

  ListNode *mergeTwoLists(ListNode *head1, ListNode *head2) {

    if (head1 == nullptr)
      return head2;
    if (head2 == nullptr)
      return head1;

    if (head1->val <= head2->val) {
      head1->next = mergeTwoLists(head1->next, head2);
      return head1;
    } else {
      head2->next = mergeTwoLists(head1, head2->next);
      return head2;
    }
  };
};

/**
 * @brief Main function
 */
int main() {
  Solution solution;

  vector<int> vlist1 = {1, 2, 4};
  vector<int> vlist2 = {2, 4, 6};

  ListNode *list1 = createLinkedList(vlist1);
  ListNode *list2 = createLinkedList(vlist2);

  printLinkedList(list1);
  printLinkedList(list2);

  ListNode *result = solution.mergeTwoLists(list1, list2);

  printLinkedList(result);

  freeLinkedList(result);

  return 0;
}