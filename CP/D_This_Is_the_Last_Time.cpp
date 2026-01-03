#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        // vector<pair<int,int>>
        vector<pair<pair<int,int>,int>>v;
        for(int i=0 ; i<n ; i++){
            int a,b,c;
            cin>>a>>b>>c;
            v.push_back({{a,b},c});
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second<b.second;
        });
        set<int>s;
        s.insert(k);
        for(auto it:v){
            auto i = s.lower_bound(it.first.first);
            if(i!=s.end() && *i<=it.first.second){
                k = it.second;
                s.insert(k);
            }
        }
        cout<<*s.rbegin()<<endl;

    }
    return 0;
}