// Manish Kumar, IIIT Allahabad
// Hard

// Using Trie Data structure

https://www.interviewbit.com/problems/shortest-unique-prefix/

const int ALPHABET_SIZE = 26;

struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	int countPrefix = 0;
	int pos = 0;
};


void insert(struct TrieNode *root, string key, int pos)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index]){
			pCrawl->children[index] = new TrieNode();
          
        }
        pCrawl->children[index]->pos = pos;
		pCrawl->children[index]->countPrefix++;
		pCrawl = pCrawl->children[index];
	}

}

void uniquePrefix(vector<string> &res, TrieNode* curr, string uniqueWord){
    if(curr->countPrefix == 1){
        res[curr->pos] = uniqueWord;
      	return;
    }
    
        for(int i = 0; i < 26; i++){
            if(curr->children[i]){
                string s = uniqueWord;
                s += i+'a';
          	uniquePrefix(res, curr->children[i], s);
            }
        }
}

vector<string> Solution::prefix(vector<string> &A) {
    TrieNode* head = new TrieNode();
    vector<string> res(A.size());
    string uniqueWord;
    for(int i = 0; i < A.size(); i++){
        insert(head, A[i], i);
    }
    
    uniquePrefix(res, head, uniqueWord);
    return res;
}
