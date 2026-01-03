#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v1;
        vector<int>v2;
        for(int i=0 ; i<n ; i++){
            int x;cin>>x;v1.push_back(x);
        }
        for(int i=0 ; i<n ; i++){
            int x;cin>>x;v2.push_back(x);
        }
        vector<pair<int,int>>v3;
        for(int i=0 ; i<n ; i++){
            v3.push_back({v1[i]+v2[i],i});
        }
        // sort(v3.begin(),v3.end());
        // int x = v3[v3.size()-1].second;
        // int sum = v3[v3.size()-1].first;
        // for(int i=0 ; i<n ; i++){
        //     if(i!=x){
        //         sum+=max(v1[i],v2[i]);
        //     }
        // }
        // cout<<sum<<endl;
        int sum=0;
        int mx = INT_MIN;
        for(int i=0 ; i<n ; i++){
            if(v1[i]>v2[i]){
                sum+=v1[i];
                mx = max(mx,v2[i]);
            }
            else{
                sum+=v2[i];
                mx = max(mx,v1[i]);
            }
        }
        cout<<sum+mx<<endl;
    }
    return 0;
}