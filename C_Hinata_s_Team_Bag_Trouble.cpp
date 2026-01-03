#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n;
    cin >> n;
    double arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int ct=0;
    int i=0;
    int j=n-1;
    while(i<=j){
        if(arr[i]+arr[j]<=3.00){
            ct++;
            i++;
            j--;
            
        }
        else {
            ct++;
            j--;
        }
    }
    cout<<ct<<endl;
        
    return 0;
}