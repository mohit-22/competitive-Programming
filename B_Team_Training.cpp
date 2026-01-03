#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n>>x;
        int arr[n];
        for(int i=0  ;i<n ;i++){
            cin>>arr[i];    
        }
        sort(arr,arr+n,greater<int>());
        int ct=0;
        for(int i=0 ; i<n ; ){
            if(arr[i]>=x){
                ct++;
                i++;
            }
            else{
                int sum=0;
                int k=1;
                while(sum<x && i<n){
                    sum = (arr[i])*k;
                    i++;
                    k++;
                }
                if(sum>=x) ct++;
            }
        }
        cout<<ct<<endl;
        
    }
    return 0;
}