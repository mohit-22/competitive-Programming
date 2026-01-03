#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n>>c;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int brr[c];
        for(int i=0 ; i<c ; i++){
            cin>>brr[i];
        }
        sort(arr,arr+n,greater<int>());
        vector<pair<int,int>>v;
        int x=0;
        for(int i=0 ; i<n ; i++){
            if(x<c) v.push_back({brr[x],brr[arr[i]-1]});
            else v.push_back({INT_MAX,brr[arr[i]-1]});
            x++;
        }
        int ans=0;
        for(auto it:v){
            ans+=min(it.first,it.second);
        }
        cout<<ans<<endl;
        
    }
    return 0;
}