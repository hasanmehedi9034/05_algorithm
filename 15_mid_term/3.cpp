#include<bits/stdc++.h>
using namespace std;

const int N = 102;

vector<int> adj_list[N];
int visited[N];
int level[N] = {0};
int parent[N];

void  dfs(int src, int l) {
    visited[src] = 1;
    level[src] = l;

    for (int adj_node: adj_list[src]) {
        if (visited[adj_node] == 0) {
            dfs(adj_node, l + 1);
        }

        if (level[adj_node] < level[src] + 1) {
            level[adj_node] = level[src] + 1;
            parent[adj_node] = src;
        }
    }
}


int bfs(int src) {
    queue<int> q;
    int dest_node;

    visited[src] = 1;
    q.push(src);
    level[src] = 1;

    while(!q.empty()) {
        int head = q.front();
        q.pop();

        for (int adj_node: adj_list[head]) {
            if (visited[adj_node] == 0) {
                visited[adj_node] = 1;
                q.push(adj_node);
                level[adj_node] = level[head] + 1;
                dest_node = adj_node;
                parent[adj_node] = head;
            }
        }
    }
    return dest_node;
}


int main() {
    // int n, m;
    // cin >> n >> m;

    // for (int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;

    //     adj_list[u].push_back(v);
    //     adj_list[v].push_back(u);
    // }

    // for (int i = 2; i <= 50; i++) {
    //     int adj_node = i + i;

    //     while(adj_node < 102) {
    //         adj_list[i].push_back(adj_node);
    //         adj_node += i;
    //     }
    // }

    // int dest = bfs(2);
    // cout << level[dest] << endl;

    // for (int i = 2; i <= 50; i++) {
    //     int src = i;
    //     int dest = bfs(src);
        

    //     if (visited[dest] == 0) return 0;
    //     cout << level[dest] << endl;
        
    //     visited[N] = {0};

    //     vector<int>path;

    //     int selected_node = dest;
    //     while(true) {
    //         path.push_back(selected_node);
    //         if (selected_node == src) {
    //             break;
    //         }
    //         selected_node = parent[selected_node];
    //     }
    //     reverse(path.begin(), path.end());
    //     // for(int node: path) {
    //     //     cout << node << " ";
    //     // }
        
    //     cout << level[100] << endl;
    //     for (int i = 0; i < N; i++) {
    //         level[i] = 0;
    //         visited[i] = 0;
    //         parent[i] = 0;
    //     } 

        
    // }

    // int src = 2;
    // int dest = bfs(src);
    

    // if (visited[dest] == 0) return 0;
    // cout << level[dest] << endl;

    // vector<int>path;

    // int selected_node = dest;
    // while(true) {
    //     path.push_back(selected_node);
    //     if (selected_node == src) {
    //         break;
    //     }
    //     selected_node = parent[selected_node];
    // }
    // reverse(path.begin(), path.end());
    // for(int node: path) {
    //     cout << node << " ";
    // }
    
    // for (int i = 0; i < N; i++) {
    //     level[i] = 0;
    // }
    

    // for (int node: parent) {
    //     cout << node << " ";
    // }
}

/*----------------------------------------------------------------

12 10
2 4
2 3
4 5
4 6
6 7
2 8
8 9
9 10
10 11
11 12

*/