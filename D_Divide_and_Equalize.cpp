#include <bits/stdc++.h>
using namespace std;

#define int long long

void mpf(int n,map<int,int>&mp2){
    // map<int,int>mp;
    while(n%2==0){
        mp2[2]++;
        n=n/2;
    }
    for(int i=3 ; i<=sqrt(n) ; i+=2){
        while(n%i==0){
            mp2[i]++;
            n = n/i;
        }
    }
    if(n>1) mp2[n]++;
    return;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        map<int,int>mp2;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            mpf(arr[i],mp2);
        }
        bool flag = true;
        for(auto it:mp2){
            if(it.second%n!=0){
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}