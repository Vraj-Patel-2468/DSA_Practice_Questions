#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        if (head == nullptr) return 0;
        ListNode* head2 = head, *it = head;
        std::stack<int> ahead;
        while (it != nullptr) {
            ahead.push(head2->val);
            head2 = head2->next;
            if (it->next) {
                it = it->next->next;
            } else {
                break;
            }
        }
        it = head2;
        int max_sum = INT_MIN;
        while (it != nullptr) {
            max_sum = std::max((ahead.top() + it->val), max_sum);
            ahead.pop();
            it = it->next;
        }
        return max_sum;
    }
};

int main() {
    Solution solution;
    ListNode* list1 = new ListNode(4, new ListNode(2, new ListNode(2, new ListNode(3))));
    int result1 = solution.pairSum(list1);
    cout << "Max sum of pairs for [4, 2, 2, 3]: " << result1 <<endl;
    ListNode* list2 = new ListNode(5, new ListNode(4, new ListNode(2, new ListNode(1))));
    int result2 = solution.pairSum(list2);
    cout << "Max sum of pairs for [5, 4, 2, 1]: " << result2 <<endl;
    ListNode* list3 = new ListNode(1, new ListNode(100000));
    int result3 = solution.pairSum(list3);
    cout << "Max sum of pairs for [1, 100000]: " << result3 << endl;
    return 0;
}
