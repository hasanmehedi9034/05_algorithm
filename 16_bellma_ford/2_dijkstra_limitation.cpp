/*

input -> A weighted graph and a src node (wiht no negative cycle)
output -> shortest distance from src node to all other nodes

d[u] + c(u, v) < d[v]


- created a distance array "d" with all value to infinity
- d[src] = 0

for i = 1 to n - 1:
    for  all edge e(u, v, w): 
        if d[u] + w < d[v]:
            d[v] = d[u] + w

print the distance array "d"

time complexity -> O(n * m)
space complesity -> O(n)


*/