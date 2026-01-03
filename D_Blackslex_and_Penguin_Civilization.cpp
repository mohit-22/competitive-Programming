#include <bits/stdc++.h>
using namespace std;

void mohit(map<int,int>mp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if(mp[a[i]]==-1) cout<<0<<endl;;
    }
    // return;
}
 
void amit(vector<pair<int,int>>vp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if( i<vp.size() &&  vp[i].first==-1) cout<<0<<endl;;
    }
}
int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr);
    int t; if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        vector<int> s;
        s.reserve(1<<n);
        s.push_back(1);
        s.push_back(0);

        vector<int>a;
        for(int i=0 ; i<5 ; i++){
            a.push_back(i+1);
        }

         map<int,int>mp; 
        for(int i=0 ; i<n ; i++){
             mp[a[i]]++; 
            } 
        vector<pair<int,int>>vp; 
 
        for(int i=0 ; i<n ; i++){
             vp.push_back({i,a[i]});
        }
 
        mohit(mp,a);
        if(mp[a[0]]==-1){
            cout<<0<<endl;
            continue;
        }
        for(int k=2;k<=n;++k){
            int hf = 1 << (k - 1);
            vector<int> mx;
            mx.reserve(1 << k);
            transform(s.begin(), s.end(), back_inserter(mx), [](int v){ return (v << 1) | 1; });
            for (int i = 0; i < hf; ++i) mx.push_back(i << 1);
            s = std::move(mx);

        }

        amit(vp,a);

        auto it = s.begin();
            if (it != s.end()) {
                cout << *it;
                ++it;
            }
            for (; it != s.end(); ++it) {
                cout << ' ' << *it;
            }
            cout << '\n';

    }
    return 0;
}
