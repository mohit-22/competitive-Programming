#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int ct=0;
        for(int i=1 ; i<=n-2 ; i+=2){
            int x = arr[i]-(arr[i-1]+arr[i+1]);
            if(x<0){
                x = abs(x);
                if(x<=arr[i+1]){
                    arr[i+1]-=x;
                    ct+=x;
                }
                else{
                    arr[i+1] = 0;
                    ct+=arr[i+1];
                    x-=arr[i+1];
                    arr[i-1]-=x;
                    ct+=x;
                }
            }
        }
        if(n%2==0){
            if(arr[n-1]<arr[n-2]){
                ct+=(arr[n-2]-arr[n-1]);
                arr[n-2]=arr[n-1];
            }
        }
        cout<<ct<<endl;
    }
    return 0;
}