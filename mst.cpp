#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> vis(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int ans = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        /* testing pacepeek haha */
        ans += w;
        for (auto [v, w] : adj[u]) {
            if (!vis[v]) pq.push({w, v});
        }
    }
    cout << ans << endl;
    return 0;
}
