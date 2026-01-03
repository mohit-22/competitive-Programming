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
        for(int i=0; i<n  ;i++){
            cin>>arr[i];
        }
        int ct=0;
        // int 
        for(int i=1 ; i<n ; i++){
            if(arr[i]-arr[i-1]==1){
                ct++;
                i++;
            }
        }
        cout<<ct<<endl;
    }
    return 0;
}