#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int>mp;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        sort(arr,arr+n);
        vector<int>v;
        v.push_back(arr[0]);
        for(int i=1 ; i<n ;){
            while(i<n && arr[i]!=arr[i-1]){
                v.push_back(arr[i]);
                i++;
            }
            i++;
        }
        // sort(v.begin(),v.end(),greater<int>());
        // int ans=0;
        // ans+=mp[v[0]];
        // for(int i=1 ; i<v.size() ; i++){
        //     if(v[i]+1==v[i-1]){
        //         ans+=max(0LL,mp[v[i]]-mp[v[i-1]]);
        //     }
        //     else{
        //         ans+=mp[v[i]];
        //     }
        // }
        // cout<<ans<<endl;

        sort(v.begin(),v.end());
        int ans=0;
        ans+=mp[v[0]];
        for(int i=1 ; i<v.size() ; i++){
            if(v[i]==v[i-1]+1){
                ans+=max(0LL,mp[v[i]]-mp[v[i-1]]);
            }
            else{
                ans+=mp[v[i]];
            }
        }
        cout<<ans<<endl;

        

        
        

    }
    return 0;
}