#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int c[1001][1001];
int f[1001][1001];
int d[1001];
vector<int> a[1001];

void max_flow(int start, int end) {
    while (true) {
        memset(d, -1, sizeof(d));
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < a[x].size(); i++) {
                int y = a[x][i];
                if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    q.push(y);
                    d[y] = x;
                    if (y == end) break;
                }
            }
        }
        if (d[end] == -1) break;
        int flow = 1000000000;
        for (int i = end; i != start; i = d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }
        for (int i = end; i != start; i = d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
    }
}

int main() {
    cin >> n >> m;
    int start = 1, end = n;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(y);
        a[y].push_back(x);
        c[x][y] = z;
    }
    max_flow(start, end);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f[start][i];
    }
    cout << ans << '\n';
    return 0;
}
