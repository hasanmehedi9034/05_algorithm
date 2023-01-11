#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[102];

int main() {
    for (int i = 2; i <= 50; i++) {
        int adj_node = i + i;

        while(adj_node < 102) {
            adj_list[i].push_back(adj_node);
            adj_node += i;
        }
    }

    for (int i = 0; i <= 101; i++) {
        if (adj_list[i].size() <= 0) continue;
        cout << i << " -> ";
        for (int adj_node: adj_list[i]) {
            cout << adj_node << " ";
        }
        cout << endl;
    }
}