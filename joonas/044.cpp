class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        for (ListNode* it = head; it; it = it->next) {
            v.push_back(it);
        }
        int n = v.size(), h = n/2;
        v[h]->next = nullptr;
        for (int i=0; i<h; ++i) {
            v[i]->next = v[n-1-i];
            v[n-1-i]->next = i+1 < h+(n&1) ? v[i+1] : nullptr;
        }
    }
};