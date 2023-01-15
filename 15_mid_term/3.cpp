#include<bits/stdc++.h>
using namespace std;

const int N = 102;

vector<int> adj_list[N];
int visited[N];
int level[N];
int parent[N];

void dfs(int src) {
    visited[src] = 1;

    for (int adj_node: adj_list[src]) {
        if(visited[adj_node] == 0) {
            dfs(adj_node);
        }

        if (level[src] + 1 > level[adj_node]) {
            level[adj_node] = level[src] + 1;
            parent[adj_node] = src;
        }
    }
    visited[src] = 2;
}


int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1);

    for (int node: parent) {
        cout << node << " ";
    }
}