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
        reverse(arr,arr+n);
        vector<int>v;
        for(int i=0 ; i<n-1 ; i++){
            int x = arr[i]/arr[i+1];
            if(x*arr[i+1]!=arr[i]){
                // int y = arr[i]
                v.push_back(arr[i+1]);
            }
        }
    }
    return 0;
}