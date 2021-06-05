// Manish Kumar, IIIT Allahabad
// Medium, Trie

// https://www.interviewbit.com/problems/xor-between-two-arrays/
// https://www.youtube.com/watch?v=jCu-Pd0IjIA

// Class, here 'left' replesents for '0' & 'right' represents for '1'  
class trieNode{
  public:
    trieNode* left;
    trieNode* right;
};

// func() to insert value in trie
void insert(trieNode* head, int val){
  trieNode* curr = head;
  for(int i = 31; i>= 0; i--){
    int b = (val >> i) & 1;
    if(b==0){
      if(!curr->left)
        curr->left = new trieNode();

      curr = curr->left;
    }else {
      if(!curr->right)
        curr->right = new trieNode();
      curr = curr->right;
    }
  }
}

// func() to find maximum xor present in trie to each elements of vector
int findMaxXor(trieNode* head, vector<int> arr){
    int n = arr.size();
  int max_xor = INT_MIN;
  for(int i = 0; i < n; i++){
    int val = arr[i];
    int curr_xor = 0;
    trieNode* curr = head;
    for(int j = 31; j>= 0; j--){
      int b = (val >> j) & 1;
      if(b==0){
        if(curr->right){
          curr_xor += pow(2,j);
          curr = curr->right;
        }else{
          if(curr->left)
            curr = curr->left;
            else
                break;
        }
      }else {
        if(curr->left){
          curr_xor += pow(2,j);
          curr = curr->left;
        }else
          if(curr->right)
            curr = curr->right;
            else
                break;
      }
    }
    if(curr_xor > max_xor)
      max_xor = curr_xor;
  }

  return max_xor;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    trieNode* head = new trieNode();
    // Insert all elements of A in trie
    for(auto i:A){
        insert(head, i);
    }
    // then, check for maximum xor from each value for B
    return findMaxXor(head, B);
}
