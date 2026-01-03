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
        int sum=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        cout<<sum-(n-1)<<endl;

    }
    return 0;
}