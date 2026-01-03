#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n>>x;
        int arr[n];
        int mx=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            mx = max(mx,arr[i]);
        }
        int low =1;
        
        sort(arr,arr+n);
        int ans=0;
        int high = x+mx;

        while(low<=high){
            int  mid = low + (high-low)/2;
            int sum=0;
            bool flag = true;
            for(int i=0 ; i<n ; i++){
                if(arr[i]<mid)sum+=mid-arr[i];
                if(sum>x){
                    flag=false;
                    break;
                }
            }
            if(sum<=x){
                if(flag==true)ans = max(ans,mid);
                low = mid+1;
            }
            else if(sum>x) high = mid-1;
        }
        cout<<ans<<endl;
        
        
    }
    return 0;
}