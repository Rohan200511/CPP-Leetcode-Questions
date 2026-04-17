#  Binary Tree Node Replacement using Inorder Neighbors

##  Problem Statement
You are given a **binary tree** constructed from an array representation.

Your task is to **modify the tree** such that:
- Each node’s value is replaced by the **sum of its inorder predecessor and successor**.

---

##  Definitions

- **Inorder Traversal (LNR):**

Left → Root → Right


- **Inorder Predecessor:**
The element just before the current node in inorder traversal.

- **Inorder Successor:**
The element just after the current node in inorder traversal.

---

##  Objective

New Value = Inorder Predecessor + Inorder Successor


### Edge Cases:
- If predecessor doesn't exist → take `0`
- If successor doesn't exist → take `0`

---

##  Approach

### Step-by-step:

1. **Build Binary Tree**
   - Use array representation:
     ```
     left child → 2*i + 1  
     right child → 2*i + 2
     ```

2. **Perform Inorder Traversal**
   - Store values in a vector

3. **Create Modified Array**
   - For each index `i`:
     - predecessor = `i-1` (or 0)
     - successor = `i+1` (or 0)
     - new value = sum of both

4. **Rebuild Tree**
   - Construct a new tree using modified values

5. **Print Result**
   - Display inorder traversal before and after modification

---

##  Key Insight
Instead of modifying nodes directly:
- First extract inorder sequence
- Apply transformation
- Rebuild tree

This simplifies logic and avoids pointer complexity.

---
