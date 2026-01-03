#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // int t;
    // cin >> t;
    // while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int brr[n];
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
        }
       vector<bool> v(n+1, false);
       int i=0 ;
       int j=0;
       while(i<n && j<n){
        if(arr[i]!=brr[j] && v[arr[i]]==false){
            v[brr[j]] = true;
            j++;
        }
        else if(arr[i]!=arr[j] && v[arr[i]]==true){
            i++;
        }
        else{
            i++;
            j++;
        }
       }
       int ct=0;
       for(auto it:v){
        if(it==true) ct++;
       }
       cout<<ct<<endl;
    // }
    return 0;
}






