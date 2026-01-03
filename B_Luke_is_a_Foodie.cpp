


#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n>>x;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int brr[n];
        int crr[n];
        for(int i=0 ; i<n ; i++){
            brr[i] = -x+arr[i];
        }
        for(int i=0 ; i<n ; i++){
            crr[i] = x+arr[i];
        }
        int ct=0;
        for(int i=0 ; i<n-1; i++){

            int x = max(brr[i],brr[i+1]);
            int y = min(crr[i],crr[i+1]);
            if(x>y) ct++;
            else{
                brr[i+1] = x;
                crr[i+1] = y;
            }
        }

        cout<<ct<<endl;

        
        
    }
    return 0;
}