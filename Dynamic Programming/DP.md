# What is DP?
- Dynamic Programming is mainly an optimization over plain recursion.
- The idea is to simply store the results of subproblems, so that we do not have to re-compute them when needed later. 
- This simple optimization reduces time complexities from exponential to polynomial.


# Characteristics of a DP Problem:
- Overlapping Subproblems - When the solutions to the same subproblems are needed repetitively for solving the actual problem. The problem is said to have overlapping subproblems property.
- Optimal Substructure - If the optimal solution of the given problem can be obtained by using optimal solutions of its subproblems then the problem is said to have Optimal Substructure Property.


# Identifying a DP Problem :
It can be a DP problem if it asks for the following:
- Count total number of unique ways to reach destination or final state. 
- Given multiple ways to reach a final destination / state, find which way will be the maximum or minimum, or best or worst. It is about maximising or minimising a certain quantity
- All dynamic programming problems satisfy the overlapping subproblems property and most of the classic Dynamic  programming problems also satisfy the optimal substructure property.


# Ways to Solve a problem:

### 1. Memoization
- Top Down
- Required Ans -> Base Case -> Required Ans

### 2. Tabulation
- Bottom Up
- Base Case -> Required Ans


# Steps

### Problem -> Recursion
1. Represent problem in terms of index
2. According to problem statement, perform every possible action we can perform from the given state.
3. Question:
- Count all ways -> sum of all stuffs
- find min -> min(all stuffs)
 
### Recursion -> Memoization
1. look at the parameters which are changing
2. store value 
3. check if already computed

### Memoization -> Tabulation
1. Initialize the dp array
2. base case initialization
3. when will the lines be executed (0 -> n-1)
4. stuff done index, replace it with dp array

### Tabulation -> Space Optimization
1. Remove array with multiple variable