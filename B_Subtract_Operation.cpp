#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        int arr[ n];
        // unordered_map<int,int>mp;
        map<int,int>mp;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        bool flag =false;
      
        for(auto it: mp){
            int x = it.first-k;
            if(mp.find(x)!=mp.end()){
                flag=true;
                break;
            }
            
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}