- transform(Iterator inputBegin, Iterator inputEnd, Iterator OutputBegin, unary_operation)
- Two Pointers

  > Try to select pointers where moving them handles both cases
  > Ex: if we take i = 0 and j = n-1 then if i++ and j-- both cases
  > decrease the difference(A[j] - A[i]), Hence it is good to take
  > i = 0 & j = 1 so that on i++, difference decreases and on j++
  > difference increases and then handle the cases.
  > Follow this in all Two Pointers Questions
  > (Refer Question Diff - Two Pointers)

- to_string(int x) // Converts integer no. to string

- Split words from strings using stringstream function
  `istringstream ss(str); string word; while (ss >> word) { cout << word << "\n"; }`
