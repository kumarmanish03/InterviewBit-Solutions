// Manish Kumar, IIIT Allahabad
// Easy
// TC : O(n*k*logk)
// SC : O(n*k)

// Strategy : Same as 'Merge K sorted arrays'

https://www.interviewbit.com/problems/merge-k-sorted-lists/


// Soln 1 (can be done without using PP pair, see soln 2)

#define PP pair<int, ListNode*>

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<PP, vector<PP>, greater<PP>> pq;
    for(auto node : A){
        pq.push({node->val, node});
    }
    // dummy Node
    ListNode *ans = new ListNode(0);
    ListNode *res = ans;

    while(!pq.empty()){
        ListNode *node = pq.top().second;
        pq.pop();
        ans->next = node;
        ans = node;
        if(node->next)
            pq.push({node->next->val, node->next});
    }

    return res->next;
}


// Soln 2
// Using comparator function

struct comp{
    bool operator()(auto &x, auto &y){
        return x->val > y->val;
    }    
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode*, vector<ListNode*>, comp> pq;
    for(auto node : A){
        pq.push(node);
    }
    // dummy Node
    ListNode *ans = new ListNode(0);
    ListNode *res = ans;

    while(!pq.empty()){
        ListNode *node = pq.top();
        pq.pop();
        ans->next = node;
        ans = node;
        if(node->next)
            pq.push(node->next);
    }

    return res->next;
}
