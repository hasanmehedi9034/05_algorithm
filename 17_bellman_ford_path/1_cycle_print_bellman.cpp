
/*
input -> A weighted graph and a src node (wiht no negative cycle)
output -> shortest distance from src node to all other nodes

d[u] + c(u, v) < d[v]


- created a distance array "d" with all value to infinity
- create parent array
- d[src] = 0

negative_cycle = false
last_updated_node = -1

for i = 1 to n - 1:
    for  all edge e(u, v, w): 
        if d[u] + w < d[v]:
            d[v] = d[u] + w
            if i == n:
                -negative_cycle = true
                - last_updated_node = v


print the distance array "d"

if negative_cycle == flase:
    print the distance array "d"
    selected_node = destination_node
    declare a vector path

    while true:
        path.push_back(selected_node)
        if selected_node == src: break
        selected_node = parent[selected_node]
    
    reverse the vector path
    print the path

else:
    print negative cycle
    selected_node = last_updated_node
    for i = 0 to n - 1:
        selected_node = parent[selected_node]
    declare a vector "cycle":
    cycle.push_back(selected_node)
    while true:
        selected_node = parent[selected_node]
        cycle.push_back(selected_node)
        if selected_node == last_updated_node:
            break
    reverse the cycle_vector

    print_cycle;
        

time complexity -> O(n * m)
space complesity -> O(n)
*/