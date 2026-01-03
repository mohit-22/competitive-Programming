#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int ct=0;
        for(int i=0 ; i<n ; ){
            int x = k;
            bool flag=true;
            bool found = false;
            if(arr[i]==0){
                while(x>0){
                    if(i>=n || arr[i]==1 ){
                        flag=false;
                        break;
                    }
                    x--;
                    i++;
                }
                found = true;
            }
            if(flag==true && found==true) ct++;
            i++;
        }
        cout<<ct<<endl;
        
    }
    return 0;
}