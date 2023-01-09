#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N];
int level[N];
int parent[N];

void dfs(int src, int lb, int p) {
    visited[src] = 1;
    level[src] = lb;
    parent[src] = p;
    // cout << src << " ";

    for(int adj_node: adj_list[src]) {
        if (visited[adj_node] == 0) {
            dfs(adj_node, lb + 1, src);
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

    int src = 1;
    int dest = n;
    dfs(src, 1, -1);

    if (visited[dest] == 0) return 0;
    cout << level[dest] << endl;

    vector<int>path;

    int selected_node = dest;
    while(true) {
        path.push_back(selected_node);
        if (selected_node == src) {
            break;
        }
        selected_node = parent[selected_node];
    }
    reverse(path.begin(), path.end());
    for(int node: path) {
        cout << node << " ";
    }

    return 0;
}