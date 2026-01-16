#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    map<int,vector<int>>mp;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
        mp[arr[i]-(i+1)].push_back(i);
    }
    int ans=0;
    for(auto it:mp){
        int x = 0;
        for(int i=0 ; i<it.second.size() ; i++){
            x+=(arr[it.second[i]]);
        }
        ans = max(ans,x);
    }
    cout<<ans<<endl;
    
}