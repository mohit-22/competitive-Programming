#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n>>x;
        int arr[n];
        map<int,int>mp;
        for(int i=0; i<n ; i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
      
        int ans = n;
        for(int i=0 ; i<n ; i++){
            if(mp[i]==0){
                ans = i;
                break;
            }
            mp[i+x]+= mp[i]-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}