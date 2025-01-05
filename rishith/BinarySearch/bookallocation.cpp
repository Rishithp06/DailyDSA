### Problem Statement: Book Allocation Problem

You are given:
- An array `arr` where each element represents the number of pages in a book.
- An integer `m` which represents the number of students.

Your task is to allocate books to students such that:
1. Each student gets a contiguous sequence of books.
2. The maximum number of pages assigned to any student is minimized.

Return the minimum number of pages that can be allocated to the student who gets the most pages. If it's not possible to allocate books, return `-1`.

---

### Example Input and Output
#### Example 1:
**Input:**
- `arr = [12, 34, 67, 90]`
- `m = 2`

**Output:**
- `113`

**Explanation:**
- The books can be allocated as follows:
  - Student 1: [12, 34, 67] → Total pages = 113
  - Student 2: [90] → Total pages = 90
- The maximum pages any student gets is minimized to 113.

#### Example 2:
**Input:**
- `arr = [5, 17, 100, 11]`
- `m = 4`

**Output:**
- `100`

**Explanation:**
- Each student gets exactly one book since the number of students equals the number of books.

---

### Approach to Solve the Problem

We solve this problem using **Binary Search** to find the minimum possible maximum pages. Here's the step-by-step breakdown:

#### Step 1: Define the Range for Binary Search
- The lowest possible value (`low`) is the maximum pages in a single book, i.e., `*max_element(arr.begin(), arr.end())`.
- The highest possible value (`high`) is the sum of all pages in the books, i.e., `accumulate(arr.begin(), arr.end(), 0)`.

#### Step 2: Use Binary Search to Find the Optimal Allocation
- Calculate `mid` as the average of `low` and `high`.
- Use the helper function `countStudents` to check how many students are required if the maximum pages allocated to any student is `mid`.
  - If the number of students required is more than `m`, increase `low` to `mid + 1` (because we need fewer pages per student).
  - Otherwise, decrease `high` to `mid - 1` (because the current allocation might not be optimal).

#### Step 3: Return the Result
- The value of `low` after the loop is the minimum possible maximum pages.

---

### Code Explanation

#### Helper Function: `countStudents`
This function calculates the number of students required to allocate books such that no student gets more than `pages` pages.
```cpp
int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); // Size of the array
    int students = 1; // At least one student is required
    long long pagesStudent = 0; // Pages assigned to the current student

    for (int i = 0; i < n; i++) {
        // Check if the current book can be allocated to the current student
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i]; // Add pages to the current student
        } else {
            // Assign the current book to the next student
            students++;
            pagesStudent = arr[i];
        }
    }

    return students; // Return the total number of students required
}
```

#### Main Function: `findPages`
This function uses binary search to find the minimum possible maximum pages.
```cpp
int findPages(vector<int>& arr, int n, int m) {
    // If there are more students than books, allocation is impossible
    if (m > n) return -1;

    // Initialize binary search range
    int low = *max_element(arr.begin(), arr.end()); // Maximum single book
    int high = accumulate(arr.begin(), arr.end(), 0); // Sum of all pages

    while (low <= high) {
        int mid = (low + high) / 2; // Midpoint of the range
        int students = countStudents(arr, mid); // Number of students needed

        if (students > m) {
            // Too many students required, increase low
            low = mid + 1;
        } else {
            // Fewer or equal students required, decrease high
            high = mid - 1;
        }
    }

    return low; // Minimum maximum pages
}
```

#### Example Usage
```cpp
int main() {
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2;

    int result = findPages(arr, n, m);
    if (result == -1) {
        cout << "Allocation is not possible" << endl;
    } else {
        cout << "The minimum number of pages: " << result << endl;
    }

    return 0;
}
```

---

### Complexity Analysis

#### Time Complexity
- **Binary Search:** \(O(\log(	ext{sum of pages} - 	ext{max pages}))\)
- **Counting Students:** \(O(n)\), where \(n\) is the number of books.
- Total: \(O(n \cdot \log(	ext{sum of pages}))\)

#### Space Complexity
- \(O(1)\): No extra space is used.

---

### Summary
- The problem is solved using binary search to minimize the maximum pages allocated to any student.
- The helper function efficiently calculates the number of students required for a given maximum page allocation.
- This approach ensures optimal and efficient allocation, suitable for large inputs.

STRIVER EXAMPLE

Example 2:
Input Format:
 n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
Result:
 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.

We can allocate books in several ways but it is clearly said in the question that we have to allocate the books in such a way that the maximum number of pages received by a student should be minimum.

Assume the given array is {25 46 28 49 24} and number of students, M = 4. Now, we can allocate these books in different ways. Some of them are the following:

25 | 46 | 28 | 49, 24  → Maximum no. of pages a student receive = 73
25 | 46 | 28, 49 | 24  → Maximum no. of pages a student receive = 77
25 | 46, 28 | 49 | 24  → Maximum no. of pages a student receive = 74
25, 46 | 28 | 49 | 24  → Maximum no. of pages a student receive = 71
From the above allocations, we can clearly observe that the minimum possible maximum number of pages is 71.

When it is impossible to allocate books:

When the number of books is lesser than the number of students, we cannot allocate books to all the students even if we give only a single book to each student. So, if m > n, we should return -1.

Observations:

Minimum possible answer: We will get the minimum answer when we give n books of the array to n students(i.e. Each student will receive 1 book). Now, in this case, the maximum number of pages will be the maximum element in the array. So, the minimum possible answer is max(arr[]).
Maximum possible answer: We will get the maximum answer when we give all n books to a single student. The maximum no. of pages he/she will receive is the summation of array elements i.e. sum(arr[]). So, the maximum possible answer is sum(arr[]).
From the observations, it is clear that our answer lies in the range [max(arr[]), sum(arr[])]. andre one book aadru kodle beka so max(arr[]) madudre that book will be given tot atleast one student , that is the low range.
max andre if students=1,then all books to him so max is sum of all elements. that is the range , now play with range.

How to calculate the number of students to whom we can allocate the books if one can receive at most ‘pages’ number of pages:

In order to calculate the number of students we will write a function, countStudents(). This function will take the array and ‘pages’ as parameters and return the number of students to whom we can allocate the books.

countStudents(arr[], pages):

We will first declare two variables i.e. ‘students’(stores the no. of students), and pagesStudent(stores the number of pages of a student). As we are starting with the first student, ‘students’ should be initialized with 1.
We will start traversing the given array.
If pagesStudent + arr[i] <= pages: If upon adding the pages with the existing number of pages does not exceed the limit, we can allocate this i-th book to the current student.
Otherwise, we will move to the next student(i.e. students += 1 ) and allocate the book.
Finally, we will return the value of ‘students’.

