#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,l,r;
        cin >> n>>l>>r;
        int arr[n];
        for(int i=0 ;i<n ; i++){
            cin>>arr[i];
        }
        int sum=0;
        int start = 0;
        int ct=0;
        for(int i=0 ; i<n ; i++){
            if(arr[i]>r){
                sum=0;
                start=i+1;
                continue;
            }
            sum+=arr[i];
            while(sum>r){
                sum-=arr[start];
                start++;
            }

            if(sum>=l && sum<=r){
                ct++;
                sum=0;
                start=i+1;
            }
        }
        cout<<ct<<endl;
        
    }
    return 0;
}