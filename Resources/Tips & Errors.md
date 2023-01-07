# DSA Tips💡

1. Buffer overflow, when you check out of bounds
- check edge case, then compare values
- Throws an error
``` cpp
if(grid[i][j] == 0 || i < 0 || j < 0)
    return 0;
```
- Check edge case i < 0 first and then put up a condition for gird[ ] [ ] value
``` cpp
if(i < 0 || j < 0 || grid[i][j] == 0)
    return 0;
```

2. Passing Pointer by reference
- If a pointer is passed to a function as a parameter and tried to be modified then the changes made to the pointer does not reflects back outside that function. This is because only a copy of the pointer is passed to the function. It can be said that “pass by pointer” is passing a pointer by value. In most cases, this does not present a problem. But the problem comes when you modify the pointer inside the function. Instead of modifying the variable, you are only modifying a copy of the pointer and the original pointer remains unmodified.


3. Provide ( ) to reduce load on compiler
``` cpp
// Before
ans = ans * 10 + digit;

// After
ans = (ans*10) + digit;
```

4. In OR operator only one condition is checked, if the first one is true the second one is not executed
``` cpp
int a = 1;
int b = 2;

if ( a-- > 0 || ++b > 2 ) {
	cout << a << b;                  // output: a = 0 , b = 2 (as b doesn’t get executed)
}
```

5. Can through error
``` cpp
s + (e - s)/2;    // correct
e + (s - e)/2;    // wrong
```

6. You can't modify a reference to x because it is const. It is const because iterating a std::set through loop gives only const values
```cpp
int arr[] = {1,2,3,4};
for(auto it: arr){       // doesn't modifies the value
    it = 0;
}
```

7. Memory limit exceeded error or Segmentation Fault (SIGSEGV) in DFS approach -> switch to BFS


8. how to custom sort an ??
- **Important Note**: By default for pair<int,int> it will sort on the basis of first and if it is equal it will automatically sort on the basis of second
- example 1 sorting 1d vector
```cpp 
static bool comparator(int &a, int &b){
    return a > b;  // desceding order
}

void fn(vector<int> &arr){
    sort(arr.begin(), arr.end(), comparator);
}
```
- example 2 (sorting 2d vector)
```cpp
static bool comparator(vector<int> &a, vector<int> &b){
    if(a[1] != b[1]) return a[1] < b[1];
    else return a[0] < b[0]
}

void fn(vector<vector<int>> &arr){
    sort(arr.begin(), arr.end(), comparator);
}
```