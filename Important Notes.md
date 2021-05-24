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

###### https://www.geeksforgeeks.org/c-classes-and-objects/

Read this article for more about Classes
