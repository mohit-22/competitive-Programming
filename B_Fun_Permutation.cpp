#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        // int x = arr[0]+1;
        for(int i=0 ; i<n ; i++){
            // if(arr[i]%2!=0) cout<<arr[i]+1<<" ";
            cout<<n+1-arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}