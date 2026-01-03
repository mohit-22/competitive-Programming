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
        map<int,int>mp;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end());

        int i=0,j=0;
        int ans=0;
        int mx = 0;
        while(j<v.size()){
            if(j-i+1>k){
                mx-=v[i].second;
                i++;
                continue;
            }
            if(i==j){
                mx+=v[j].second;
                j++;
            }
            else{
                if(v[j-1].first+1==v[j].first){
                    mx+=v[j].second;
                    j++;
                }
                else{       
                    i=j;
                    mx=0;
                    continue;
                }
            }
            ans=max(ans,mx);
            
        }
        cout<<ans<<endl;

        

        
        
    }
    return 0;
}