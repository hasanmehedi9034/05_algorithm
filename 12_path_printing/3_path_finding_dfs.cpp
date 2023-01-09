#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N];


void dfs(int src) {
    visited[src] = 1;
    cout << src << " ";

    for(int adj_node: adj_list[src]) {
        if (visited[adj_node] == 0) {
            dfs(adj_node);
        }
    }
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

    int src = 5;
    dfs(src);
}