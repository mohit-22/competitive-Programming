#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n],brr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
        }
        sort(arr,arr+n);
        sort(brr,brr+n,greater<int>());
        int i=0,j=0;
        int ct=0;
        while(j<n){
            int x = arr[i];
            int y = brr[j];
            int z = ((y+1)*x)+y;
            if(z<=k){
                ct++;
                i++;
                j++;
            }else j++;
        }
        cout<<ct<<endl;
        
    }
    return 0;
}