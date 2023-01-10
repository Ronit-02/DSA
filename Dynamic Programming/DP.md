# Dynamic Programming

## What is DP?
- Dynamic Programming is mainly an optimization over plain recursion.
- The idea is to simply store the results of subproblems, so that we do not have to re-compute them when needed later. 
- This simple optimization reduces time complexities from exponential to polynomial.

## Ways to Solve a problem:
### 1. Memoization
- Top Down
- Required Ans -> Base Case -> Required Ans

### 2. Tabulation
- Bottom Up
- Base Case -> Required Ans

## Problem -> Recursion
1. Try to represent the problem in terms of index
2. Do all possible stuffs on that index acc to the problem statement
3. Question:
- Count all ways -> sum of all stuffs
- find min -> min(all stuffs)

## Recursion -> Memoization
1. look at the parameters which are changing
2. store value 
3. check if already computed

## Memoization -> Tabulation
1. Initialize the dp array
2. base case initialization
3. when will the lines be executed (0 -> n-1)
4. stuff done index, replace it with dp array

## Tabulation -> Space Optimization
1. Remove array with multiple variable