#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int cost = 0;
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second;
        if(visited[u]) continue;
        visited[u] = true;
        cost += p.first;
        for(pair<int, int> q : adj[u]){
            int v = q.first;
            int w = q.second;
            if(!visited[v]){
                pq.push({w, v});
            }
        }
    }
    cout << cost << endl;
    return 0;
}
