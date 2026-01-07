// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// void bfs_T(int n, vector<vector<int>> &adj, vector<int> &dpt, vector<int> &parent, int &mx_d) {
//     queue<int> q;
//     q.push(1);

//     dpt[1] = 1;
//     parent[1] = -1;
//     mx_d = 1;

//     while (!q.empty()) {
//         int current = q.front();
//         q.pop();

//         int sz = adj[current].size();
//         for (int idx = 0; idx < sz; idx++) {
//             int next = adj[current][idx];

//             if (parent[current] == next) continue;

//             parent[next] = current;
//             dpt[next] = dpt[current] + 1;

//             if (dpt[next] > mx_d) {
//                 mx_d = dpt[next];
//             }

//             q.push(next);
//         }
//     }
// }

// void fill_ct(int n, vector<int> &dpt, vector<int> &parent, vector<int> &cnt, vector<int> &cc) {
//     for (int i = 1; i <= n; i++) {
//         cnt[ dpt[i] ]++;
//     }

//     for (int i = 1; i <= n; i++) {
//         if (parent[i] != -1) {
//             cc[ parent[i] ]++;
//         }
//     }
// }

// void fill_mx_chi(int n, vector<int> &dpt, vector<int> &cc, vector<int> &mx_cht) {
//     for (int node = 1; node <= n; node++) {
//         int level = dpt[node];
//         int c = cc[node];

//         if (c > mx_cht[level]) {
//             mx_cht[level] = c;
//         }
//     }
// }

// int cl_Ans(int mx_d, vector<int> &cnt, vector<int> &mx_cht) {
//     int answer = 0;

//     for (int d = 1; d < mx_d; ++d) {
//         if (cnt[d] > answer) {
//             answer = cnt[d];
//         }

//         if (mx_cht[d] == cnt[d + 1]) {
//             int need = cnt[d + 1] + 1;
//             if (need > answer) {
//                 answer = need;
//             }
//         }
//     }

//     if (mx_d >= 1 && cnt[mx_d] > answer) {
//         answer = cnt[mx_d];
//     }

//     return answer;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;

//         vector<vector<int>> adj(n + 1);
//         for (int i = 0; i < n - 1; i++) {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         vector<int> dpt(n + 1, 0);
//         vector<int> parent(n + 1, 0);
//         int mx_d = 1;

//         bfs_T(n, adj, dpt, parent, mx_d);

//         vector<int> cnt(mx_d + 2, 0);
//         vector<int> cc(n + 1, 0);

//         fill_ct(n, dpt, parent, cnt, cc);

//         vector<int> mx_cht(mx_d + 2, 0);

//         fill_mx_chi(n, dpt, cc, mx_cht);

//         int answer = cl_Ans(mx_d, cnt, mx_cht);

//         cout << answer << '\n';
//     }

//     return 0;
// }





#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void bfs_T(int n, vector<vector<int>> &adj, vector<int> &dpt, vector<int> &parent, int &mx_d) {
    queue<int> q;
    q.push(1);

    dpt[1] = 1;
    parent[1] = -1;
    mx_d = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        int sz = adj[current].size();
        for (int idx = 0; idx < sz; idx++) {
            int next = adj[current][idx];

            if (parent[current] == next) continue;

            parent[next] = current;
            dpt[next] = dpt[current] + 1;

            if (dpt[next] > mx_d) {
                mx_d = dpt[next];
            }

            q.push(next);
        }
    }
}

void fill_ct(int n, vector<int> &dpt, vector<int> &parent, vector<int> &cnt, vector<int> &cc) {
    for (int i = 1; i <= n; i++) {
        cnt[ dpt[i] ]++;
    }

    for (int i = 1; i <= n; i++) {
        if (parent[i] != -1) {
            cc[ parent[i] ]++;
        }
    }
}

void fill_mx_chi(int n, vector<int> &dpt, vector<int> &cc, vector<int> &mx_cht) {
    for (int node = 1; node <= n; node++) {
        int level = dpt[node];
        int c = cc[node];

        if (c > mx_cht[level]) {
            mx_cht[level] = c;
        }
    }
}

int cl_Ans(int mx_d, vector<int> &cnt, vector<int> &mx_cht) {
    int answer = 0;

    for (int d = 1; d < mx_d; ++d) {
        if (cnt[d] > answer) {
            answer = cnt[d];
        }

        if (mx_cht[d] == cnt[d + 1]) {
            int need = cnt[d + 1] + 1;
            if (need > answer) {
                answer = need;
            }
        }
    }

    if (mx_d >= 1 && cnt[mx_d] > answer) {
        answer = cnt[mx_d];
    }

