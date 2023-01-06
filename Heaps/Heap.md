
# What is Heap Data Structure?
A Heap is a special Tree-based data structure in which the tree is a complete binary tree.


# Operations on Heap Data Structure?

1. Heapify - a process of creating a heap from an array.
2. Insertion - process to insert an element in existing heap time complexity O(log N).
3. Deletion - deleting the top element of the heap or the highest priority element, and then organizing the heap and returning the element with time complexity O(log N).
4. Peek - to check or find the most prior element in the heap, (max or min element for max and min heap).

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221220165711/MinHeapAndMaxHeap1.png" width="500">


# Insertion in Heap

``` cpp
void insert(int x){

        // 1. insertion at leaf node
        int index = size;
        arr[index] = x;
        size++;

        // 2. heapify the last node (bottom-up)
        while(index > 1){
            int parent = index/2;

            if(arr[index] > arr[parent]){
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
```

