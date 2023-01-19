/*

input -> weighted graph as an adjancency matrix
output -> All pair  shortest distance


- create a distance "d" where d[i][j] = x where there is a direct
    where x is edge cost from node "i" to  node "j"

- for all node "i" d[i][i] = 0
- for all nodes "i" and "j" where there isn't any direct edge from "i" -> "j"
    d[i][j] = INF

- for all node "k":
    for all node "u":
        for all node "v":
            d[u][v] = min( d[u][v], d[u][k] + d[k][v] )

- output all pair shortest distance "d"

time complexity: O(v^3)
space complesity: O(V^2)

*/