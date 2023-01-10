/*
input -> weithted graph and a source
output -> distance of all nodes form the soruce

- create a distance array 'd'
- initliaze all values of 'd' to infinity
- d[src] = 0
- create a visited array and mark all nodes as unvisited

-for i = 0 to n-1:
    - pick the 'unvisited' node with minimum d[node]
    - visited[node] = 1
    - for all adj_node of node:
        if d[node] + c(node, adj_node) < d[adj_node]:
            d[node] = d[adj_node] + c(node, adj_node)
    
- output array 'd'


space complexity -> O(n)
time complexity -> O(n^2)
*/