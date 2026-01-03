#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // int t;
    // cin >> t;
    // while(t--){
        int n,k,x;
        cin >> n>>k>>x;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        vector<int>diff;
        int ct=1;
        for(int i=0; i<n-1 ; i++){
            if(arr[i+1]-arr[i]>x){
                ct++;
                diff.push_back(arr[i+1]-arr[i]);
            }
        }
        sort(diff.begin(),diff.end());

        for(int i=0 ; i<diff.size();i++){
            diff[i] = (diff[i]-1)/(x);
            if(diff[i]<=k){
                ct--;
                k-=diff[i];
            }
            else break;
        }
        cout<<ct<<endl;
    // }
    return 0;
}