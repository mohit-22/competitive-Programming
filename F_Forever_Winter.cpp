#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n+1);
        vector<int> deg(n+1, 0);
        for(int i=0;i<m;i++){
            int u,v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        vector<int> highNeighborCount(n+1, 0);
        for(int v=1; v<=n; ++v) {
            int cnt = 0;
            for(int u : g[v]) if(deg[u] > 1) ++cnt;
            highNeighborCount[v] = cnt;
        }
        int x = -1, center = -1;
        for(int v=1; v<=n; ++v) {
            if(highNeighborCount[v] > 1) { x = highNeighborCount[v]; center = v; break; }
        }
        int y = -1;
        for(int u : g[center]) {
            if(deg[u] > 1) { y = deg[u] - 1; break; }
        }
        cout << x << " " << y << '\n';
    }
    return 0;
}