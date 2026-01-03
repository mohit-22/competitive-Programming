#include <bits/stdc++.h>
using namespace std;

const long long MOD2 = 676767677LL;
#define int long long

class comb {
private:
    vector<int> facct;
    vector<int> inv_facct;
    int pw(int a,int e){
        a%=MOD2;
        int res=1;
        while(e>0){
            if(e&1) res=(int)(res*a%MOD2);
            a=(int)(a*a%MOD2);
            e>>=1;
        }
        return res;
    }
public:
    comb(int mx_valll){
        facct.assign(mx_valll+1,1);
        inv_facct.assign(mx_valll+1,1);
        for(int i=1;i<=mx_valll;i++) facct[i]=(int)(facct[i-1]*i%MOD2);
        int invv_l = pw(facct[mx_valll], MOD2-2);
        inv_facct[mx_valll]=invv_l;
        for(int i=mx_valll;i>0;i--) inv_facct[i-1]=(int)(inv_facct[i]*i%MOD2);
    }
    int nCr(int n,int r){
        if(r<0||r>n) return 0;
        int k=min(r,n-r);
        int num=1,den=1;
        for(int i=1;i<=k;++i){
            num=(int)(num*(n-k+i)%MOD2);
            den=(int)(den*i%MOD2);
        }
        return (int)(num*pw(den,MOD2-2)%MOD2);
    }
    static int ft_pw(int a,int e){
        a%=MOD2;
        int res=1;
        while(e>0){
            if(e&1) res=(int)(res*a%MOD2);
            a=(int)(a*a%MOD2);
            e>>=1;
        }
        return res;
    }
};

class const_soolv {
private:
    vector<int> d_cc(const vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> contii(n, 0);
        vector<char> mrk(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            int diff = arr[i] - arr[i + 1];
            if (diff == 1) {
                if (mrk[i] == 'A' || mrk[i + 1] == 'A') return vector<int>();
                mrk[i] = mrk[i + 1] = 'B';
            } else if (diff == -1) {
                if (mrk[i] == 'B' || mrk[i + 1] == 'B') return vector<int>();
                mrk[i] = mrk[i + 1] = 'A';
            }
        }
        for (int i = 0; i < n; ++i) {
            if (mrk[i] == 'A') contii[i] = 1;
            else if (mrk[i] == 'B') contii[i] = 2;
        }
        return contii;
    }

    bool propagate_iterative(vector<int>& contii, const vector<vector<int>>& grr) {
        int n = (int)contii.size();
        vector<char> seen(n, 0);
        for (int i = 0; i < n; ++i) {
            if (contii[i] == 0 || seen[i]) continue;
            // BFS from i
            queue<int>q;
            q.push(i);
            seen[i]=1;
            while(!q.empty()){
                int u=q.front();q.pop();
                int required_for_neighbors = (contii[u]==2)?1:2;
                for(int v:grr[u]){
                    if(contii[v]==0){
                        contii[v]=required_for_neighbors;
                        if(!seen[v]){
                            seen[v]=1;
                            q.push(v);
                        }
                    } else {
                        if(contii[v]!=required_for_neighbors) return false;
                        if(!seen[v]){
                            seen[v]=1;
                            q.push(v);
                        }
                    }
                }
            }
        }
        return true;
    }

    tuple<int, int, int, bool, bool> analyzeComponents(
        const vector<int>& contii,
        const vector<vector<int>>& grr) {
        int n = (int)contii.size();
        vector<char> visited(n, 0);
        int fixed_right = 0, o_conents = 0, e_conents = 0;
        bool f_f = false, f_o = false;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            vector<int> component;
            stack<int> st;
            st.push(i);
            visited[i] = 1;
            while (!st.empty()) {
                int u = st.top(); st.pop();
                component.push_back(u);
                for (int v : grr[u]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        st.push(v);
                    }
                }
            }
            bool has_fixed = false;
            int count_constraint2 = 0;
            for (int node : component) {
                if (contii[node] != 0) {
                    has_fixed = true;
                    if (contii[node] == 2) ++count_constraint2;
                }
            }
            if (has_fixed) {
                fixed_right += count_constraint2;
            } else {
                int comp_size = (int)component.size();
                fixed_right += comp_size / 2;
                if (comp_size % 2 == 1) ++o_conents;
                else ++e_conents;
                if (find(component.begin(), component.end(), 0) != component.end()) {
                    f_f = true;
                    f_o = (comp_size % 2 == 1);
                }
            }
        }
        return {fixed_right, o_conents, e_conents, f_f, f_o};
    }

public:
    int solve(const vector<int>& arr, comb& combobj) {
        int n = (int)arr.size();
        if (n == 1) return 2 % MOD2;
        for (int i = 0; i < n - 1; i++) {
            if (llabs(arr[i] - arr[i + 1]) > 1) return 0;
        }
        vector<vector<int>> grr(n);
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                grr[i].push_back(i + 1);
                grr[i + 1].push_back(i);
            }
        }
        vector<int> contii = d_cc(arr);
        if (contii.empty()) return 0;
        if (!propagate_iterative(contii, grr)) return 0;
        auto anay = analyzeComponents(contii, grr);
        auto [b_r, o_c, e_c, f_f, f_o] = anay;
        int ans = 0;
        int e_pow = 1;
        for (int i = 0; i < e_c; ++i) e_pow = (int)(e_pow * 2 % MOD2);
        {
            vector<int> st;
            int rem = o_c;
            int f_eff = f_o ? 1 : 0;
            if (f_f) {
                rem = o_c - (f_o ? 1 : 0);
                st = {1, 0};
            } else {
                int s = 1;
                if (contii[0] == 2) s = 0;
                else if (contii[0] == 1) s = 1;
                st = {s};
            }
            for (int s : st) {
                int flip = 1 ^ s;
                int t_r = arr[0] - s;
                int ad = b_r + (f_f ? f_eff * flip : 0);
                int nd = t_r - ad;
                if (0 <= nd && nd <= rem) {
                    int ways = (combobj.nCr(rem, nd) % MOD2) * (e_pow % MOD2) % MOD2;
                    ans = (ans + ways) % MOD2;
                }
            }
        }
        return ans;
    }
};

int32_t main() {
\
    int t;
    cin >> t;
    vector<vector<int>> t_d(t);
    int max_n = 0;
    for(int tc=0; tc<t; ++tc){
        int n; cin >> n;
        vector<int> tmp(n);
        for(int i=0;i<n;++i) cin>>tmp[i];
        t_d[tc].swap(tmp);
        max_n = max(max_n, n);
    }
    comb math_util(max_n+10);
    const_soolv solver;
    for(const auto& t_c : t_d){
        cout << solver.solve(t_c, math_util) << '\n';
    }
    return 0;
}
