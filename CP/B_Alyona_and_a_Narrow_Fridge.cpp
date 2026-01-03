#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // int t;
    // cin >> t;
    // while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int low = 0;
        int high = n-1;
        int ans = INT_MIN;
        while(low<=high){
            int s=0;
            int mid = low+(high-low)/2;
            vector<int>v;
            for(int i=0 ; i<=mid ; i++){
                v.push_back(arr[i]);
            }
            // sort(arr,arr+mid+1);
            sort(v.begin(),v.end());
            for(int i=v.size()-1 ; i>=0 ; i-=2){
                s+=v[i];
            }
            if(s<=k){
                 low = mid+1;
                 ans = max(ans,mid+1);
            }
            else high = mid-1;
        }
        cout<<ans<<endl;
        
    // }
    return 0;
}