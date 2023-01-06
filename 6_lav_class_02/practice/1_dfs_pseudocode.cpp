/*

------------ binary tree ---------
void dfs(int node) {
    cout << node << endl;

    // base case
    if node  does not have any child:
        return

    // general case
    dfs(node.left_child);
    dfs(node.right_child);
}


-------- n-ary tree ------------------------------
void dfs(int node) {
    cout << node << endl;

    // base case
    if node does not have any child:
        return;

    // general case
    for all child of node:
        dfs(child);
}


--------- graph ----------
visited array[]

void dfs(int node) {
    cout << node << endl;
    visited[node] = 1;

    for all adj_node of node:
        if visited[adj_node] == 0;
            dfs(adj_node);

}


*/




