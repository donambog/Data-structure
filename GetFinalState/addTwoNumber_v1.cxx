#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        std::unique_ptr<ListNode>head = make_unique<ListNode>(0); // head dummy node
        ListNode* current = head.get();

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int newVal = carry;

            if (l1 != nullptr) {
                newVal += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                newVal += l2->val;
                l2 = l2->next;
            }

            carry = newVal / 10;
            newVal = newVal % 10;

            current->next = new ListNode(newVal);
            current = current->next;
        }

        return head->next; // Return the real head of the result
    }

    void deleteList(ListNode* head) {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp; // Free memory
        }
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test Case 1: [2,4,3] + [5,6,4] = [7,0,8]
    ListNode* l1_1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2_1 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* result1 = solution.addTwoNumbers(l1_1, l2_1);
    cout << "Test Case 1 Output: ";
    printList(result1);
    solution.deleteList(result1); // Clean up memory

    // Test Case 2: [0] + [0] = [0]
    ListNode* l1_2 = new ListNode(0);
    ListNode* l2_2 = new ListNode(0);
    ListNode* result2 = solution.addTwoNumbers(l1_2, l2_2);
    cout << "Test Case 2 Output: ";
    printList(result2);
    solution.deleteList(result2); // Clean up memory

    // Test Case 3: [9,9,9,9,9,9,9] + [1] = [0,0,0,0,0,0,0,1]
    ListNode* l1_3 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))))))));
    ListNode* l2_3 = new ListNode(1);
    ListNode* result3 = solution.addTwoNumbers(l1_3, l2_3);
    cout << "Test Case 3 Output: ";
    printList(result3);
    solution.deleteList(result3); // Clean up memory

    // Test Case 4: [2,5,3] + [5,6,4] = [7,1,8]
    ListNode* l1_4 = new ListNode(2, new ListNode(5, new ListNode(3)));
    ListNode* l2_4 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* result4 = solution.addTwoNumbers(l1_4, l2_4);
    cout << "Test Case 4 Output: ";
    printList(result4);
    solution.deleteList(result4); // Clean up memory

    // Test Case 5: [9,9,9,9] + [1] = [0,0,0,0,1]
    ListNode* l1_5 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    ListNode* l2_5 = new ListNode(1);
    ListNode* result5 = solution.addTwoNumbers(l1_5, l2_5);
    cout << "Test Case 5 Output: ";
    printList(result5);
    solution.deleteList(result5); // Clean up memory

    // Clean up remaining memory for the input lists
    solution.deleteList(l1_1);
    solution.deleteList(l2_1);
    solution.deleteList(l1_2);
    solution.deleteList(l2_2);
    solution.deleteList(l1_3);
    solution.deleteList(l2_3);
    solution.deleteList(l1_4);
    solution.deleteList(l2_4);
    solution.deleteList(l1_5);
    solution.deleteList(l2_5);

    return 0;
}
