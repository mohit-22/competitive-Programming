#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
       int n;
       cin>>n;
       int arr[n];
       map<int,int>mp;
       for(int i=0 ; i<n ; i++){
        cin>>arr[i];
        mp[arr[i]]++;
       } 
       vector<int>v;
       for(auto it:mp){
        v.push_back(it.second);
       }
       sort(v.begin(),v.end(),greater<int>());
       int ans = v[0];
       int prev = ans;
       for(int i=1 ; i<v.size() ; i++){
        if(v[i]>=prev){
            ans+=(prev-1);
            prev--;
        }
        else{
            ans+=v[i];
            prev = v[i];
        }
        if(prev==0) break;
       }
       cout<<ans<<endl;
       


    }


    
    return 0;
}