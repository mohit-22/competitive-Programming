#include <bits/stdc++.h>
using namespace std;

#define int long long

int bs(vector<pair<int,int>>&v,int k){
    int n = v.size();
    int low = 0;
    int high = n-1;
    int ans=-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(v[mid].first<=k){
            low = mid+1;
            ans = max(ans,mid);
        }
        else high = mid-1;
    }
    return ans;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        int brr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
        }
        vector<pair<int,int>>v;
        for(int i=0 ; i<n ; i++){
            v.push_back({arr[i],brr[i]});
        }
        sort(v.begin(),v.end());
        bool flag = false;
        for(int i=0 ; i<n ; i++){
            int x = bs(v,k);
            if(x==n-1){
                flag = true;
                break;
            }
            int y = k-v[x+1].second;
            k = k+y;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}