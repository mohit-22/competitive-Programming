#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        map<int,int>mp;
        int sum=0;
        int ct=0;
        for(int i=0 ; i<n ; i++){
            sum+=arr[i];
            if(sum==0 || mp[sum]>0){
                mp.clear();
                ct++;
                sum=0;
            }
            else{
                mp[sum]++;
            }
        }
        cout<<ct<<endl;

    }
    return 0;
}