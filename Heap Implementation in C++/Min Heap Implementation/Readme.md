# 🔽 Min Heap Implementation

A **Min Heap** is a complete binary tree where the **parent node is always smaller** than its child nodes.  
It provides efficient access to the **minimum element** in O(1) time and supports insertion and deletion in **O(log n)**.

---

## 📘 Overview

- **Type:** Binary Heap (Complete Binary Tree)
- **Property:** Every parent ≤ its children
- **Root Node:** Minimum element of the heap

---

## ⚙️ Operations Supported

| Operation | Description | Time Complexity |
|------------|--------------|-----------------|
| `insert(x)` | Inserts an element into the heap | O(log n) |
| `getMin()` | Returns the smallest element (root) | O(1) |
| `extractMin()` | Removes the smallest element | O(log n) |
| `heapify(i)` | Maintains heap property from index `i` | O(log n) |
| `buildHeap()` | Converts array → Min Heap | O(n) |

---

## 🧩 Example

**Input Array:**  
[10, 40, 20, 30, 50, 60]

markdown
Copy code

**Min Heap:**  
markdown
Copy code
    10
   /  \
 30    20
/  \   /
40 50 60

yaml
Copy code

**Extracting min (10):**  
Heap becomes `[20, 30, 60, 40, 50]`

---

## 🖼️ Visualization

Here’s a visual example of how a Min Heap organizes data 👇  

![Min Heap Visualization](https://upload.wikimedia.org/wikipedia/commons/6/69/Min-heap.png)

*(Source: Wikimedia Commons)*

---

## 🧠 Key Insights

- Helps in **implementing Priority Queues**
- Used in **Dijkstra’s Algorithm** and **Prim’s Algorithm**
- Always keeps **smallest element at root**

---

## 🔗 Related Implementations

- [Max Heap Implementation](https://github.com/Rohan200511/CPP-Leetcode-Questions/tree/a9ececafac26ce5c2dd2bf0356034a0222aa8215/Heap%20Implementation%20in%20C%2B%2B/Max%20Heap%20Implementaion)
- [Heap Sort](https://github.com/Rohan200511/CPP-Leetcode-Questions/tree/bd28a3b379fdec735270d3a066cb2f0d3ac79808/Heap%20Implementation%20in%20C%2B%2B/Heap%20Sort)

---

## 📚 References

- [GeeksforGeeks – Min Heap](https://www.geeksforgeeks.org/min-heap-in-java/)
- [Wikipedia – Heap (Data Structure)](https://en.wikipedia.org/wiki/Heap_(data_structure))

---

### 🧾 Author
Developed by **Rohan** — learning DSA in C++ with practical heap-based implementations.
