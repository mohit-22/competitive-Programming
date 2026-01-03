








#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // int t;
    // cin >> t;
    // while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        for(int i =0 ; i<n ; i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int i=0,j=n-1;
        int ct=0;
        while(i<=j){
            int sum = arr[j];
            while(sum<=k){
                if(i>=j) break;
                sum+=arr[j];
                i++;
            }
            j--;
            if(sum>k) ct++;
        }
        cout<<ct<<endl;
    return 0;
}