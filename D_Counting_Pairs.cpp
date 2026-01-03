#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        int arr[n];
        int sum=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        sort(arr,arr+n);
        int p = sum-y;
        int q = sum-x;
        int i=0;
        int j = n-1;
        int ct=0;
        while(i<j){
            if(arr[i]+arr[j]>=p && arr[i]+arr[j]<=q){
                // int z = arr[i]+arr[j]-p;
                // int w = arr[j]-z;
                int w = p-arr[i];
                auto it = lower_bound(arr+i+1,arr+n,w)-arr;
                ct+=j-it+1;
                i++;
            }
            else if(arr[i]+arr[j]<p){
                i++;
            }
            else if(arr[i]+arr[j]>q){
                j--;
            }
        }
        cout<<ct<<endl;
    }
    return 0;
}






