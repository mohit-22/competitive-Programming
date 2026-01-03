#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        unordered_map<int,int>mp;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        bool flag = true;
        for(auto it:mp){
            if(it.second%k!=0){
                flag=false;
                break;
            }
        }

        if(!flag){
            cout<<0<<endl;
            continue;
        }
        int r = 0;
        int ans=0;
        unordered_map<int,int>mp2;
        for(int i=0 ;i<n  ;i++){
            
            // int l = r;
            
            while(r<n &&  mp2[arr[r]]<mp[arr[r]]/k){
                mp2[arr[r]]++;
                r++;
            }
            ans+=r-i;
            mp2[arr[i]]--;
            
        }
        // ans+=n;
        cout<<ans<<endl;
        
    }
    return 0;
}