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

- to_string(int x) // Converts integer to string and return that

- Split words from strings using stringstream function

  ```
  string str = "Geeks for Geeks";
  istringstream ss(str);
  string word;
  while (ss >> word) {
    cout << word << "\n";
  }

  ```
