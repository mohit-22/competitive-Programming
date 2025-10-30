#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        map<int,int>mp;
        for(int i=0 ; i<n  ; i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        sort(arr,arr+n);
        int ans = 1;
        for(int i=arr[n-1] ; i>=1 ; i--){
            auto it = lower_bound(arr,arr+n,4*i)-arr;
            // bool flag=true;
            // if(it==n){
            //     it=0;
            // }
            int a = mp[i]+mp[i*2]+mp[i*3];
            int b = n-a-(n-it);
            if(b<=k){
                ans=i;
                break;
            }


        }
        cout<<ans<<endl;
    }
    




    return 0;
}
