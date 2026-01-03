#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,q;
        cin >> n>>m>>q;
        int arr[m];
        int brr[q];
        for(int i=0 ;i<m ; i++){
            cin>>arr[i];
        }
        for(int i=0 ; i<q ; i++){
            cin>>brr[i];
        }
        sort(arr,arr+m);
        for(int i=0 ;i<q ; i++){
            if(brr[i]>=arr[0] && brr[i]<=arr[m-1]){
                auto b = lower_bound(arr,arr+m,brr[i]);
                int idx = (b - arr);
                int a = idx-1;
                cout<<((arr[idx]-arr[a])/2)<<endl;

            }
            else{
                if(brr[i]<arr[0]){
                    cout<<arr[0]-1<<endl;
                }
                else if(brr[i]>arr[m-1]){
                    cout<<n-arr[m-1]<<endl;
                }
                // cout<<min(n-arr[n-1],arr[0]-1)<<endl;
            }
        }
        
    }
    return 0;
}