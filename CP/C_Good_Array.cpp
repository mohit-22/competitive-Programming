#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // int t;
    // cin >> t;
    // while(t--){
        int n;
        cin >> n;
        int arr[n];
        map<int,int>mp;
        int s=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            mp[arr[i]]++;
            s+=arr[i];
        }
        vector<int>ans;
        for(int i=0  ;i<n ; i++){
            int x = (s-arr[i])/2;
            if(x*2!=(s-arr[i])){
                continue;
            }
            if(x==arr[i]){
                if(mp[x]>1){
                    ans.push_back(i+1);
                }
            }
            else{
                if(mp[x]>0){
                    ans.push_back(i+1);
                }
            }
            
        }
        cout<<ans.size()<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }

    // }
    return 0;
}