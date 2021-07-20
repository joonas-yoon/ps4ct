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
    stack<ListNode*> st;

    void init(ListNode* head){
        for(ListNode* it = head; it != nullptr; it = it->next) {
            st.push(it);
        }
    }

    void solve(ListNode* head) {
        int len = st.size();
        ListNode *it = head, *cur = head;
        // printf("[%d", it->val);
        it = it->next;
        for(int i = 1; i < len; i++) {
            if(i % 2) {
                cur->next = st.top();
                // printf(",%d", st.top()->val);
                st.pop();
            }
            else {
                cur->next = it;
                // printf(",%d", it->val);
                it = it->next;
            }
            cur = cur->next;
        }
        cur->next = nullptr;
        // printf("]");
    }

    void reorderList(ListNode* head) {
        init(head);
        solve(head);
    }
};