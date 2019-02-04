使用并查集+tarjin式遍历思路
离线处理每个查询的答案是什么


void tarjin (int u) {
    vis[u] = 1;
    for (int i=0; i<mp[u].size(); i++) {
        int &v = mp[u][i];
        if (vis[v] == 0) {
            tarjin(v);

        }
    }
}
