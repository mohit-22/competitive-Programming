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
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        int mx3 = INT_MAX;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            if(arr[i]%2!=0) mx1 = max(mx1,arr[i]);
            else mx2 = max(mx2,arr[i]);
            mx3 = min(mx3,arr[i]);
        }
        int ans1=0;
        int ans2=0;
        int ans3=0;
        for(int i=0 ; i<n ; i++){
            ans1+=(mx1^arr[i]);
            ans2+=(mx2^arr[i]);
            ans3+=(mx3^arr[i]);

        }
        cout<<max({ans1,ans2,ans3})<<endl;
    }
    return 0;
}