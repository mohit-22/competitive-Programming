#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            arr[i] = arr[i]+(i+1);
        }
        sort(arr,arr+n);
        int ct=0;
        int sum=0;
        for(int i=0 ; i<n ; i++){
            sum+=arr[i];
            if(sum<=k){
                ct++;
            }
            else break;
        }
        cout<<ct<<endl;
        
        
    }
    return 0;
}