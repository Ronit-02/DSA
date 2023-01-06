# Time Complexity and Space Complexity


## Why we need time complexity?
Generally, there is always more than one way to solve a problem in computer science with different algorithms. Therefore, it is highly required to use a method to compare the solutions in order to judge which one is more optimal. The method must be:

- Independent of the machine and its configuration, on which the algorithm is running on.
- Shows a direct correlation with the number of inputs.
- Can distinguish two algorithms clearly without ambiguity.


## Time Complexity
In order to calculate time complexity on an algorithm, it is assumed that a constant time c is taken to execute one operation, and then the total operations for an input length on N are calculated.

Example 1: `O(N^2)`
```
int a[n];
for(int i = 0;i < n;i++)       --> N*c 
  cin >> a[i]  

for(int i = 0;i < n;i++)       --> N*N*c
  for(int j = 0;j < n;j++)
    if(i!=j && a[i]+a[j] == z)
       return true

return false
```
Assuming that each of the operations in the computer takes approximately constant time, let it be c. 


## Notations in Complexity Analysis
1. Big-O Notation `O`
- worst-case time complexity
- the set of functions grows slower than or at the same rate as the expression
- maximum amount of time an algorithm requires to consider all input values

2. Omega Notation `Ω`
- best case of an algorithm
- defines whether the set of functions will grow faster or at the same rate as the expression
- minimum amount of time an algorithm requires to consider all input values

3. Theta Notation `Θ`
- average case time complexity
- the set of functions lies in both O(expression) and Omega(expression)


## Order of Growth
Order of growth is how the time of execution depends on the length of the input. In the above example, it is clearly evident that the time of execution quadratically depends on the length of the array. Order of growth will help to compute the running time with ease.

```
O(1) < O(log N) < O(N) < O(N*log N) < O(N^2) < O(N^3) < O(2^n) < O(N!)
```

| Input Constraints      | Time Complexity | Algorithms |
| ----------- | ----------- | ----------- |
| < 10..12      | O(n!)      | Recursion and Backtracking |
| < 15..22   | O(2^n*n)        | Recursion, backtracking, and bit manipulation |
| < 30..40   | O(2^n/2 * n)        | Meet in the middle, Divide and Conquer |
| < 100   | O(n^4)        | DP, Constructive |
| < 400   | O(n^3)        | DP, Constructive |
| < 2000   | O(n^2 * logn)        | DP, Binary Search, Sorting, Divide and Conquer |
| < 10^4   | O(n^2)        | DP, Graph, Trees, Constructive |
| < 10^6   | O(n*logn)        | Sorting, Binary Search, Divide and Conquer |
| < 10^8   | O(n) , O(logn) , O(1)        | Constructive, Mathematical, Greedy |


## Space Complexity
The space complexity of an algorithm quantifies the amount of space taken by an algorithm to run as a function of the length of the input. 

Example: `O(N)`
```
int freq[n];
int a[n];

for(int i = 0; i<n; i++)
{
   cin>>a[i];
   freq[a[i]]++;
} 
```


## Series
1. Arithmetic series: 1 + 2 + 3 + 4 + .. n = 1/2(n)(n+1) = `O(n^2)`
2. Geometric series: 1 + x + x^2 + x^3 + .. x^n  = `O(x^n)`
3. Harmonic series: 1 + 1/2 + 1/4 + 1/8 + .. 1/n = ln(n) = `O(logn)`