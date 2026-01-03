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
        bool flag = false;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            arr[i] = arr[i]%k;
            if(arr[i]==0) flag = true;
            else mp[arr[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        int ans=0;
        if(flag) ans++;

        sort(v.begin(),v.end());
        int i=0;
        int j=v.size()-1;
        while(i<=j){
            // if(i==j){
            //     if(2*v[i].first==k && v[i].second>1){
            //         ans+=1;
            //     }
            //     else ans+=v[i].second;
            //     break;
            // }
            if(v[i].first+v[j].first>k){
                // if(2*v[j].first==k && v[j].second>1){
                //     ans+=1;
                // }
                // else ans+=v[j].second;
                ans+=v[j].second;
                j--;       

            }
            else if(v[i].first+v[j].first<k){
                // if(2*v[i].first==k && v[i].second>1){
                //     ans+=1;
                // }
                // else ans+=v[i].second;
                ans+=v[i].second;
                i++;
            }
            else{
                // if(i!=j){
                    ans+=max(1LL,abs(v[i].second-v[j].second));
                    i++;
                    j--;
                // }
            }
        }
        cout<<ans<<endl;
        // for(auto it : mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
    }
    return 0;
}