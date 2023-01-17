/*

input -> A weighted graph and a src node (wiht no negative cycle)
output -> shortest distance from src node to all other nodes

d[u] + c(u, v) < d[v]


- created a distance array "d" with all value to infinity
- d[src] = 0

- negative_cycle = false

for i = 1 to n - 1:
    for  all edge e(u, v, w): 
        if d[u] + w < d[v]:
            d[v] = d[u] + w
            if i == n:
                relaxed = true


print whether negative cycle detect
print the distance array "d"

time complexity -> O(n * m)
space complesity -> O(n)


*/



#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int>> adj_list[N];
int d[N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({ u, w });
    }

    int src = 1;
    
    d[src] = 0;

    bool negative_cycle = false;

    for(int i = 1; i <= n; i++) {
        for (int node = 1; node <= n; node++) {
            for (auto adj_node: adj_list[node]) {
                int  u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    
                    if (i == n) negative_cycle = true;
                }
            }
        }
    }

    if (negative_cycle == true) {
        cout << "Graph has negative cycle" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << ", ";
    }
    cout << endl;
}