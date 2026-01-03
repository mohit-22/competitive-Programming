#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
       int t;
       cin>>t;
       while(t--){
       int n,k;
       cin>>n>>k;
       int arr[n];
       for(int i = 0;i<n;i++){cin>>arr[i];}
       if(k==1){
              int m = -1;
              for(int i = 1;i<=n-2;i++) m = max(m,arr[i]);
              int ans = max(m+arr[0],max(m+arr[n-1],arr[0]+arr[n-1]));
              cout<<ans<<endl;
       }
       else{
              sort(arr,arr+n);
              int sum = 0;
              for(int i = n-1;i>n-k-2;i--){
                     sum += arr[i];
              }
              cout<<sum<<endl;
       }
       }
}