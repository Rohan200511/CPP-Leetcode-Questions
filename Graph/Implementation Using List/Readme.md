# Build Graph — Undirected (Adjacency List)


## Overview
This repository demonstrates an **undirected graph** represented using an **adjacency list**.  
No implementation code is included here — this README explains structure, visualization, and how to include the diagram in your repo.

---

## Adjacency List (given)

    0: 1
    1: 0 2 3
    2: 1 3 4
    3: 1 2
    4: 2


Each line shows a vertex followed by its neighbors. Because the graph is undirected, every edge appears in both endpoints' lists (e.g., `0: 1` and `1: 0`).

---

## Quick Explanation

    - **Vertices:** 0, 1, 2, 3, 4  
    - **Edges:** (0—1), (1—2), (1—3), (2—3), (2—4)  
    - **Undirected:** edges have no direction — `u-v` == `v-u`.
