#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        vector<vector<int64>> a(n, vector<int64>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        vector<vector<char>> onpath(n, vector<char>(m, 0));
        vector<pair<int,int>> path;
        int r = 0, c = 0;
        path.emplace_back(0,0);
        onpath[0][0] = 1;
        int ci = 0, cj = 0;
        for (char ch : s) {
            if (ch == 'D') ++ci;
            else ++cj;
            onpath[ci][cj] = 1;
            path.emplace_back(ci,cj);
        }
        vector<int64> rowNon(n, 0), colNon(m, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!onpath[i][j]) {
                    rowNon[i] += a[i][j];
                    colNon[j] += a[i][j];
                }
        vector<int64> assignedRow(n, 0), assignedCol(m, 0);
        vector<vector<int64>> b = a;
        int L = (int)path.size();
        for (int k = 0; k < L - 1; ++k) {
            int i = path[k].first;
            int j = path[k].second;
            char nextMove = s[k];
            int64 val;
            if (nextMove == 'D') {
                val = -rowNon[i] - assignedRow[i];
            } else {
                val = -colNon[j] - assignedCol[j];
            }
            b[i][j] = val;
            assignedRow[i] += val;
            assignedCol[j] += val;
        }
        int li = path[L-1].first, lj = path[L-1].second;
        int64 lastVal = -rowNon[li] - assignedRow[li];
        b[li][lj] = lastVal;
        assignedRow[li] += lastVal;
        assignedCol[lj] += lastVal;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << b[i][j] << (j+1==m?'\n':' ');
            }
        }
    }
    return 0;
}