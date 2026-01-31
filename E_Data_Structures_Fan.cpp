#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Seg {
    int n;
    vector<ll> tot, one;
    vector<char> lazy;
    Seg(int _n=0): n(_n), tot(4*_n), one(4*_n), lazy(4*_n,0) {}
    void build(int idx, int l, int r, const vector<ll>& a, const string& s){
        if(l==r){
            tot[idx] = a[l];
            one[idx] = (s[l]=='1') ? a[l] : 0;
            return;
        }
        int m=(l+r)>>1;
        build(idx<<1,l,m,a,s);
        build(idx<<1|1,m+1,r,a,s);
        tot[idx] = tot[idx<<1] ^ tot[idx<<1|1];
        one[idx] = one[idx<<1] ^ one[idx<<1|1];
    }
    void apply_flip(int idx){
        one[idx] = tot[idx] ^ one[idx];
        lazy[idx] ^= 1;
    }
    void push(int idx){
        if(lazy[idx]){
            apply_flip(idx<<1);
            apply_flip(idx<<1|1);
            lazy[idx]=0;
        }
    }
    void update_range(int idx,int l,int r,int ql,int qr){
        if(ql>r || qr<l) return;
        if(ql<=l && r<=qr){
            apply_flip(idx);
            return;
        }
        push(idx);
        int m=(l+r)>>1;
        update_range(idx<<1,l,m,ql,qr);
        update_range(idx<<1|1,m+1,r,ql,qr);
        one[idx] = one[idx<<1] ^ one[idx<<1|1];
    }
    ll query_one(){ return one[1]; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        vector<ll> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        string s; cin>>s;
        s = " " + s;
        int q; cin>>q;
        Seg seg(n);
        seg.build(1,1,n,a,s);
        while(q--){
            int tp; cin>>tp;
            if(tp==1){
                int l,r; cin>>l>>r;
                seg.update_range(1,1,n,l,r);
            } else {
                int g; cin>>g;
                if(g==1) cout<<seg.query_one();
                else cout<<(seg.tot[1] ^ seg.query_one());
                if(t==0 && q==0) cout<<"\n"; else cout<<" ";
            }
        }
    }
    return 0;
}