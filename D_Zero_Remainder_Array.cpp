#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        map<int,int>mp;
        for(int i=0 ; i<n; i++){
            mp[arr[i]%k]++;
        }
        int mx = 0;
        for(auto it:mp){
            if(it.first!=0){
                int x = k*(it.second-1)+((k-it.first)%k);
                mx = max(mx,x);
            }
        }
        if(mx==0) cout<<0<<endl;
        else cout<<mx+1<<endl;
        
    }
    return 0;
}