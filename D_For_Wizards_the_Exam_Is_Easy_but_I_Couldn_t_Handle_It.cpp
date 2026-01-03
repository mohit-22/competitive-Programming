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
        vector<int>v;
        vector<int>v2;

        int ct=0;
        int mx = INT_MIN;
        for(int i=0 ; i<n-1 ; i++){
            if(arr[i]>arr[i+1]){
                v.push_back(i);
                if(mx<ct) mx=ct;
                v2.push_back(mx);
                ct=0;
            }
            else{
                ct++;
            }
        }
    }
    return 0;
}