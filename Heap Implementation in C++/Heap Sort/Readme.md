# 🌀 Heap Sort

Heap Sort is a **comparison-based sorting algorithm** that uses a **binary heap** data structure to sort elements efficiently in **O(n log n)** time.

---

## 📖 Overview

Heap Sort works in two main phases:

1. **Build a Max Heap** from the input data.
2. **Extract elements** from the heap one by one and rebuild the heap.

The algorithm ensures that the largest element moves to the end of the array in each iteration.

---

## ⚙️ Working Steps

1. Build a **Max Heap** from the input array.
2. Swap the **root (maximum element)** with the last element.
3. Reduce heap size by 1 and call **heapify** on the root.
4. Repeat until the heap size becomes 1.

---

## 🧠 Complexity Analysis

| Operation | Time Complexity |
|------------|-----------------|
| Building Heap | O(n) |
| Heapify (per element) | O(log n) |
| **Overall Time Complexity** | **O(n log n)** |
| Space Complexity | O(1) |
| Stability | Not Stable |

---

## 📊 Example

**Input:** `[12, 11, 13, 5, 6, 7]`  
**Output:** `[5, 6, 7, 11, 12, 13]`

---

## 🖼️ Visualization

Here’s how Heap Sort organizes and sorts the array step by step 👇  

![Heap Sort Visualization](https://upload.wikimedia.org/wikipedia/commons/1/1b/Sorting_heapsort_anim.gif)

*(Source: Wikimedia Commons)*

---

## 🔍 Key Insights

- Uses **heap property** to find max/min efficiently.
- Works **in-place**, requiring no extra memory.
- Suitable for large datasets when memory is limited.

---

## 🧩 Related Implementations

- [Min Heap Implementation](../MinHeap/README.md)
- [Max Heap Implementation](../MaxHeap/README.md)

---

## 📚 References

- [GeeksforGeeks – Heap Sort](https://www.geeksforgeeks.org/heap-sort/)


---

### 🧾 Author
Developed by **Rohan** — exploring Data Structures and Algorithms in C++.

