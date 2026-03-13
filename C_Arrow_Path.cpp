#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<string> g(2);
        g[0] = a; g[1] = b;
        vector<vector<char>> seen(2, vector<char>(n, 0));
        deque<pair<int,int>> q;
        seen[0][0] = 1;
        q.emplace_back(0, 0);
        bool reachable = false;
        const int dr[4] = {0, 0, 1, -1};
        const int dc[4] = {1, -1, 0, 0};
        while(!q.empty()) {
            auto cur = q.front(); q.pop_front();
            int r = cur.first, c = cur.second;
            if(r == 1 && c == n-1) { reachable = true; break; }
            for(int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr < 0 || nr > 1 || nc < 0 || nc >= n) continue;
                int dir = (g[nr][nc] == '>') ? 1 : -1;
                int fc = nc + dir;
                if(fc < 0 || fc >= n) continue;
                if(!seen[nr][fc]) {
                    seen[nr][fc] = 1;
                    q.emplace_back(nr, fc);
                }
            }
        }
        cout << (reachable ? "YES\n" : "NO\n");
    }
}