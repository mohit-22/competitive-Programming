#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        vector<pair<int,int>>vp;
        vector<bool>v(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            vp.push_back({arr[i],i+1});
        }
        sort(vp.begin(),vp.end());
        int i=0;
        for(auto it:vp){
            if(it.first<it.second){
              v[i] = true;
              }
            else v[i] = false;

            i++;
        }
        int ct=0;
        vector<int>s(n);
        for(int i=0 ; i<n ; i++){
            if(v[i]==true){
                ct++;
                s[i] = ct;
            }
            else s[i] = ct;
        }
        int ans=0;
        for(int i=0 ; i<n ; i++){
            if(v[i]==true){
                auto it = lower_bound(vp.begin(), vp.end(), make_pair(vp[i].second+1, 0LL)) - vp.begin();
                if(it<n){
                    if(v[it]==true){
                        ans+=s[n-1]-s[it]+1;
                    }
                    else{
                        ans+=s[n-1]-s[it];
                    }
                }
            }
        }
        cout<<ans<<endl;


        
    }
    return 0;
}