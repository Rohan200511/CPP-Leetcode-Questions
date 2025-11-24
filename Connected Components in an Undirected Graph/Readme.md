Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

Note: You can return the components in any order, driver code will print the components in sorted order.

Examples :

    Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
    Output: [[0, 1, 2], [3, 4]]
    Explanation:
  <img width="200" height="200" alt="image" src="https://github.com/user-attachments/assets/e664ce2a-c7b7-4185-84d7-bdac92712549" />


    Input: V = 7, edges[][] = [[0, 1], [6, 0], [2, 4], [2, 3], [3, 4]]
    Output: [[0, 1, 6], [2, 3, 4], [5]]
    Explanation:
<img width="250" height="250" alt="image" src="https://github.com/user-attachments/assets/126fa2db-f709-4578-a3c6-fee677380d27" />
<br>
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V
