## What is sorting ?
A Sorting Algorithm is used to rearrange a given array or list of elements according 
to a comparison operator.

## Different types of Sorting Algorithms
1. Selection Sort
2. Insertion Sort
3. Bubble Sort
4. Merge Sort
5. Quick Sort
6. Radix Sort
7. Heap Sort
8. Counting Sort
9. Bucket Sort
10. STL Sort (introsort, uses 3 algos)

---

# Selection Sort
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning.

The algorithm maintains two subarrays in a given array.
- The subarray which already sorted. 
- The remaining subarray was unsorted.

<img src="https://www.w3resource.com/w3r_images/selection-short.png" width="400">

---

# Insertion Sort
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

`Characteristics of Insertion Sort:`
- This algorithm is one of the simplest algorithm with simple implementation
- Basically, Insertion sort is efficient for small data values
- Insertion sort is adaptive in nature, i.e. it is appropriate for data sets which are already partially sorted.

---

# STL Sort
- Time Complexity: O(nlogn)
- safer than any other algo
- more flexible
