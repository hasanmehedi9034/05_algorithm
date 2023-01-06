/*

5 8
########
#.A#...#
#.##.#B#
#......#
########


    # -> -1
    . -> 0




    (x, y) -> right (x, y + 1)
           -> left  (x, y - 1)
           -> up    (x - 1, y)
           -> down  (x + 1, y)

    x y
    0 1
    0 -1
    -1 0
    1 0

    dx[] = {0, 0, -1, 1}
    dy[] = {1, -1, 0, 0}

    for (int i = 0; i < 4; i++) {
        int nex_x = x + dx[i];
        int nex_y = y + dy[i];
    }

    1. is the cell within the maze
    2. is the cell forbidden
    3. is the cell visited
*/

#include <bits/stdc++.h>
using namespace std;


const int N = 2002;
int maze[N][N], visited[N][N], level[N][N];
int n, m;


int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> co_or) {
    int x = co_or.first;
    int y = co_or.second;

    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    }
    return false;
}

bool is_forbidden(pair<int, int> co_or)  {
    int x = co_or.first;
    int y = co_or.second;

    if (maze[x][y] = -1) return true;
    return false;
}

void bfs(pair<int, int> src) {
    queue< pair<int, int> > q;
    
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;

    q.push(src);

    while(!q.empty()) {
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++) {
            int nex_x = x + dx[i];
            int nex_y = y + dy[i];

            pair<int, int> adj_node = {nex_x, nex_y};

            if(is_inside(adj_node) && 
                !is_forbidden(adj_node) && 
                visited[nex_x][nex_y] == 0) {
                    visited[nex_x][nex_y] = 1;
                    level[nex_x][nex_y] = level[x][y] + 1;
                    q.push(adj_node);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    pair<int, int> src, dst;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            level[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        
        for (int j = 0; j < input.length(); j++) {
            if (input[j] == '#') {
                maze[i][j] = -1;
            }
            else if (input[j] == '.') {
                maze[i][j] = 0;
            }
            else if (input[j] == 'A') {
                src = {i, j};
                maze[i][j] = 2;
            }
            else if (input[j] == 'B') {
                dst = {i, j};
                maze[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maze[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    bfs(src);

    if (level[dst.first][dst.second] == -1) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        cout  << level[dst.first][dst.second] << endl;
    }

}




