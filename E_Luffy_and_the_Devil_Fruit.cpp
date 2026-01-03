#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
ios_base::sync_with_stdio(false); cin.tie(NULL);     
    int n,k;
    cin >> n>>k;
    int arr[n];
    for(int i=0  ;i<n ; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int lo = 1;
    int hi=arr[n-1];
    int ans=hi;
    
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int sum=0;
        for(int i=0 ; i<n ; i++){
            // if(arr[i]%mid==0) sum+=arr[i]/mid;
            // else sum+=(arr[i]/mid)+1;
            sum+=(arr[i]+mid-1)/mid;
        }
        if(sum<=k){
            ans=mid;
            hi = mid-1;
        }
        else {
            lo=mid+1;
        }
        
    } 

    cout<<ans<<endl;
        
    
    return 0;
}