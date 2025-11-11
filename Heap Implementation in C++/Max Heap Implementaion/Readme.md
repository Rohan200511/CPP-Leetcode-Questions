# 🔼 Max Heap Implementation

A **Max Heap** is a complete binary tree where the **parent node is always greater** than its child nodes.  
It allows efficient access to the **maximum element** in O(1) time and supports insertion and deletion in **O(log n)**.

---

## 📘 Overview

- **Type:** Binary Heap (Complete Binary Tree)
- **Property:** Every parent ≥ its children  
- **Root Node:** Maximum element of the heap

---

## ⚙️ Operations Supported

| Operation | Description | Time Complexity |
|------------|--------------|-----------------|
| `insert(x)` | Inserts an element into the heap | O(log n) |
| `getMax()` | Returns the largest element (root) | O(1) |
| `extractMax()` | Removes the largest element | O(log n) |
| `heapify(i)` | Maintains heap property from index `i` | O(log n) |
| `buildHeap()` | Converts array → Max Heap | O(n) |

---

## 🧩 Example

**Input Array:**  
[10, 40, 20, 30, 50, 60]

markdown
Copy code

**Max Heap:**  
markdown
Copy code
    60
   /  \
 50    40
/  \   /
30 10 20

yaml
Copy code

**Extracting max (60):**  
Heap becomes `[50, 30, 40, 10, 20]`

---

## 🖼️ Visualization

Here’s how elements are organized in a Max Heap 👇  

![Max Heap Visualization](https://upload.wikimedia.org/wikipedia/commons/3/38/Max-Heap.svg)

*(Source: Wikimedia Commons)*

---

## 🧠 Key Insights

- Forms the base for **Heap Sort**  
- Used in **Priority Queues** where the highest value has the highest priority  
- Always keeps **largest element at root**

---

## 🔗 Related Implementations

- [Min Heap Implementation](https://github.com/Rohan200511/CPP-Leetcode-Questions/tree/bd28a3b379fdec735270d3a066cb2f0d3ac79808/Heap%20Implementation%20in%20C%2B%2B/Min%20Heap%20Implementation)
- [Heap Sort](https://github.com/Rohan200511/CPP-Leetcode-Questions/tree/bd28a3b379fdec735270d3a066cb2f0d3ac79808/Heap%20Implementation%20in%20C%2B%2B/Heap%20Sort)


---

## 📚 References

- [GeeksforGeeks – Max Heap](https://www.geeksforgeeks.org/max-heap-in-java/)
- [Wikipedia – Heap (Data Structure)](https://en.wikipedia.org/wiki/Heap_(data_structure))

---

### 🧾 Author
Developed by **Rohan** — learning DSA in C++ with practical heap-based implementations.
