- transform(Iterator inputBegin, Iterator inputEnd, Iterator OutputBegin, unary_operation)
  > used to convert letters to upeercase or lowercase, add something to all elements of array, or some operation which should operate on all values of array
- Two Pointers

  > Try to select pointers where moving them handles both cases
  > Ex: if we take i = 0 and j = n-1 then if i++ and j-- both cases
  > decrease the difference(A[j] - A[i]), Hence it is good to take
  > i = 0 & j = 1 so that on i++, difference decreases and on j++
  > difference increases and then handle the cases.
  > Follow this in all Two Pointers Questions
  > (Refer Question Diff - Two Pointers)

- Converts integer to string and return that
  `to_string(int x);`

- Split words from strings using stringstream function

  ```
  string str = "Geeks for Geeks";
  istringstream ss(str);
  string word;
  while (ss >> word) {
    cout << word << "\n";
  }

  ```

- Time Complexity :
  2^n > n^3 > n^2 > n > sqrt(n) > log(n)

- **subarray / sunstring** is a slice from a contiguous array (i.e., occupy consecutive positions) and inherently maintains the order of elements. For example, the subarrays of array {1, 2, 3} are {1} , {1, 2} , {1, 2, 3} , {2} , {2, 3} , and {3}. In general, for an array/string of size n, there are n\*(n+1)/2 non-empty subarrays/subsrings.

- **subsequence** is a sequence that can be derived from another sequence by zero or more elements, without changing the order of the remaining elements.
  For the same example, there are 15 sub-sequences. They are (1), (2), (3), (4), (1,2), (1,3),(1,4), (2,3), (2,4), (3,4), (1,2,3), (1,2,4), (1,3,4), (2,3,4), (1,2,3,4). More generally, we can say that for a sequence of size n, we can have (2n-1) non-empty sub-sequences in total.

- If you want to declare Array of size 10^5 or less, you can do it both locally & globally. But for Array of size more than 10^5, you should declare it globally, unless you will end up with segmentation fault

- In Binary Search questions, try to make predicate function, else work is simple

- Be carefull of constraints, in case of overflow use 'long long'

- In some questions which seems to hard , there may be pattern in it,

- Careful while using if-else put ==(double) while comparing not =(single)

- Careful of using Global Variables, because in competitive questions there are different test cases and if we save something in global variables(ex. vectors, arrays, strings) do clear or erase it, otherwise it may use earlier data of test cases;

- ```
    1 << n = 1 * 2^n (Left Shift Multiply)
  16 << n = 16 * 2^n
  n >> 1 = n/2*1 (Right Shift)
  n >> 4 = n/2^4
  ```

- An Object is an instance of a Class. When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated

##### https://www.geeksforgeeks.org/c-classes-and-objects/

Read this article for more about Classes

- ##### https://www.geeksforgeeks.org/linked-list-vs-array/

- ##### https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/

  \*(p + 0) = p[0] thats'why array starts from 0 index because if it start from one then memory of first block(where \*p is pointing) get wasted

- ##### https://www.geeksforgeeks.org/g-fact-30/

  delete vs free, 'delete' used for deallocating pointers pointing to memory allocated using 'new' operator

- This is Defination of a Linked List, here if you initialized node as `ListNode *temp = new ListNode(5)`, then temp->val = 5 & temp->next = NULL becoz of `ListNode(int x) : val(x), next(NULL) {}`

```
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
```

- `sort(a.begin(), a.end(), comp);`
  The given 'comp' function is a boolean function which asks 'should I swap' i.e, If 'comp' return true that means swap(a, b) [Now b comes before a], and if returns false then ignore;
  `min_element(), max_element()` function also accepts 'comp' function
  https://www.youtube.com/watch?v=3pvZhwp0U9w&t=304s

  - For min_element, comparator function return last index.For max-element, comparator function return first index. Hence design comp likewise

  - Dynamically allocation of 2D array of size arr[n][m]

  ```int** arr = new int*[n];
  for(int i = 0; i < n; i++)
  	arr[i] = new int[m];
  ```

Ex. for passing it as a parameter `solve(int** arr){}`

- 12! is storable in int

- By default, priority queue are sorted in decreasing
  order, and it is possible to find and remove the largest element in the queue from top
  If we want to create a priority queue that supports finding and removing the
  smallest element, we can do it as follows:
  `priority_queue<int,vector<int>,greater<int>> q;`

In this, Insertion and removal take O(logn) time, and retrieval takes O(1) time.

- int const* is pointer to const int
  int *const is const pointer to int
  int const\* const is const pointer to const int

- In function try to pass argument(int, vector, etc) by reference. Becoz by reference it does not make copy and hence less momory, time
- Comparator function using lambda function

```
  sort(ans.begin(), ans.end(), [&](auto&x, auto&y){
              return x > y
          });
```

- In DP Top Down approach try to initialize first
  before writing main iteration, and also start array (main array)
  where (from i = 1) so that it does not give array out of bounds error

- Longest Incresing subsequence :
  Firstly we will create another array of unique elements of original array and sort it. Now the longest increasing subsequence of our array must be present as a subsequence in our sorted array. That’s why our problem is now reduced to finding the common subsequence between the two arrays.

- DFS is used in finding shortest path in Trees while in Graph BFS is used to find shortest path becoz we have unique paths from two nodes in trees while in graph we can have exponential no. of unique paths b/w two nodes
  DFS will run in exponential time while BFS will run in polynomial time. That's why we will use BFS in Graph for finding shortest path

- For checking an element in map, dont check like this 'm[tocheck] == 0'
  instead use 'm.count(tocheck) == 0' becoz later will create another map element while checking which will increase MLE

- Also if sorting is not necessary, then you should use 'unordered_map/unordered_set' unless it may give MLE/TLE

- Do Dry run your code (very carefully) to find errors. Then its easy to debug and reach to Accepted Soln

- Floor(n) is just smallest or equal to 'n'.Ceil(n) is just largest or equal to 'n'. lowerbound(n) is no. whose value is atleast 'n'. upperbound(n) is no whose value is just greater than 'n'.

- Every character array in C/C++ ends with a '\0' (NULL) character. It marks the end of the string. If it is not added in the end, then the code may produce garbage characters after the string.
