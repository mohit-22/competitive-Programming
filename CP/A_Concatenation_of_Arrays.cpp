#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>>v;
        vector<pair<int,pair<int,int>>>v1;
        int i=0;
        while(n--){
            int a,b;
            cin>>a>>b;
            v.push_back({a,b});
            v1.push_back({i,{min(a,b),max(a,b)}});
            i++;
        }
        sort(v1.begin(),v1.end(),[](auto &x, auto &y){
            // return a.second<b.second;
            if (x.second.second != y.second.second)
                return x.second.second < y.second.second;   // sort by max(a,b)
            return x.second.first < y.second.first;         // if equal, sort by min(a,b)
        });
        for(auto it:v1){
            cout<<v[it.first].first<<" "<<v[it.first].second<<" ";
        }
        cout<<endl;
    }
    return 0;
}