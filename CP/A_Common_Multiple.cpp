#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int MOD = 998244353;

inline int addmod(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
inline int mulmod(int64 a, int64 b){ return int((a*b) % MOD); }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    while(T--){
        int N; cin >> N;
        vector<vector<int>> g(N+1);
        for(int i=0;i<N-1;i++){
            int u,v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // root the tree at 1, build parent/order and children lists
        vector<int> parent(N+1, -1);
        vector<int> order; order.reserve(N);
        parent[1] = 0;
        order.push_back(1);
        for(int i=0;i<(int)order.size();++i){
            int u = order[i];
            for(int v: g[u]){
                if(parent[v] == -1){
                    parent[v] = u;
                    order.push_back(v);
                }
            }
        }
        vector<vector<int>> children(N+1);
        for(int v=2; v<=N; ++v) children[parent[v]].push_back(v);

        // ways[u] : vector of pairs {ways_no_selected, ways_with_selected} indexed by size s
        vector<vector<array<int,2>>> ways(N+1);
        vector<int> subtreeMax(N+1,0);

        // postorder
        for(int idx = N-1; idx >= 0; --idx){
            int u = order[idx];
            // dp[a][d][s] a = #children with non-empty F (capped 2), d = #children with any selected (capped 2)
            // stored as dp[3][3] vectors length curMax+1

            
            vector<vector<vector<int>>> dp(3, vector<vector<int>>(3, vector<int>(1,0)));
            dp[0][0][0] = 1;
            int curMax = 0;

            for(int v : children[u]){
                int childMax = subtreeMax[v];
                // child's ways: ways[v][s][b] where b=0/1 (0: no selected in that child's subtree, 1: exists at least one selected)
                vector<array<int,2>>& w = ways[v];
                int newMax = curMax + childMax;   
                vector<vector<vector<int>>> ndp(3, vector<vector<int>>(3, vector<int>(newMax+1, 0)));

                for(int a=0;a<3;++a){
                    for(int d=0; d<3; ++d){
                        for(int s=0; s<=curMax; ++s){
                            int val = dp[a][d][s];
                            if(!val) continue;
                            for(int sc = 0; sc <= childMax; ++sc){
                                // child contributes sc to F-size
                                // child has two options for b: 0 or 1
                                int w0 = w[sc][0];
                                if(w0){
                                    int a2 = a + (sc > 0 ? 1 : 0); if(a2 > 2) a2 = 2;
                                    int d2 = d; // b=0
                                    ndp[a2][d2][s+sc] = addmod(ndp[a2][d2][s+sc], mulmod(val, w0));
                                }
                                int w1 = w[sc][1];
                                if(w1){
                                    int a2 = a + (sc > 0 ? 1 : 0); if(a2 > 2) a2 = 2;
                                    int d2 = d + 1; if(d2 > 2) d2 = 2;
                                    ndp[a2][d2][s+sc] = addmod(ndp[a2][d2][s+sc], mulmod(val, w1));
                                }
                            }
                        }
                    }
                }
                dp.swap(ndp);
                curMax = newMax;
            } // children processed

            // build ways[u] from dp
            int maxSize = curMax + 1; // if u in F we can have +1
            ways[u].assign(maxSize+1, {0,0}); // index 0..maxSize
            // iterate dp states
            for(int a=0;a<3;++a){
                for(int d=0; d<3; ++d){
                    for(int s=0; s<=curMax; ++s){
                        int val = dp[a][d][s];
                        if(!val) continue;
                        // Option 1: u not in F => total size s, allowed only if a <= 1
                        if(a <= 1){
                            int bflag = (d > 0 ? 1 : 0);
                            ways[u][s][bflag] = addmod(ways[u][s][bflag], val);
                        }
                        // Option 2: u in F and selected => size s+1, subtree has selected => b=1
                        ways[u][s+1][1] = addmod(ways[u][s+1][1], val);
                        // Option 3: u in F and NOT selected => only allowed if d >= 2 (two different child-subtrees have selected nodes)
                        if(d >= 2){
                            ways[u][s+1][1] = addmod(ways[u][s+1][1], val);
                        }
                    }
                }
            }
            // compute subtreeMax[u]
            int realMax = 0;
            for(int s = 0; s < (int)ways[u].size(); ++s){
                if(ways[u][s][0] || ways[u][s][1]) realMax = s;
            }
            subtreeMax[u] = realMax;
            // shrink to realMax
            ways[u].resize(realMax+1);
        }

        // final answers: for K=1..N sum ways[1][K][0]+ways[1][K][1]
        vector<int> ans(N+1,0);
        for(int k=1;k<=N;++k){
            if(k < (int)ways[1].size()){
                ans[k] = addmod(ways[1][k][0], ways[1][k][1]);
            } else ans[k] = 0;
        }
        for(int k=1;k<=N;++k){
            if(k>1) cout << ' ';
            cout << ans[k];
        }
        cout << '\n';
    }
    return 0;
}
