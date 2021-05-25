// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/add-two-numbers-as-lists/

// Strategy :
// I stored the answer in A and assigned its head pointer to 'ans'
// Read given in code comments

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *ans = A, *prev;
    int carry = 0;
    int t;
    // Stored ans in A until one of its become empty
  
    while(A && B){
        t = A->val + B->val + carry;
        if(t < 10){
            carry = 0;
            A->val = t;
        }
        else{
            carry = t/10;
            A->val = t%10;
        }
        // if n(A) < n(B) then A == NULL comes first, so checking it so that pointer remains in last element
        if(A->next == NULL){
            B = B->next;
            break;
        }else{
            A = A->next;
            B = B->next;
        }
    }
    // This Condn becoz A never move to last pointer(see above comment)
    if(A->next){
      while(A){
        t = A->val + carry;
        if(t < 10){
            carry = 0;
            A->val = t;
        }
        else{
            carry = t/10;
            A->val = t%10;
        }
        A = A->next;
      } 
    }
    else if(B){
        while(B){
          // Creating new node and then connect it to A
            ListNode *temp = new ListNode(0);
            A->next = temp;
            A = A->next;
            t = B->val + carry;
            if(t < 10){
                carry = 0;
                A->val = t;
            }
            else{
                carry = t/10;
                A->val = t%10;
            }
            B = B->next;
        } 
    }
    // Adding carry
    if(carry > 0){
        ListNode *temp = new ListNode(carry);
        A->next = temp;
        A = A->next;
    }
    
    return ans;
    
}
