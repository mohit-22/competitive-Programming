// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         int arr[n];
//         for(int i = 0 ; i<n ; i++){
//             cin>>arr[i];
//         }
//         int ct0=0;
//         int ct = 0;
//         if(arr[n-1]==0) ct0++;
//         else if(arr[n-1]!=0) ct++;
//         for(int i = 0 ; i<n-1 ; i++){
//             if(arr[i]==0 && arr[i+1]!=0) ct0++;
//             else if(arr[i]!=0) ct++;
//         }
//         if(n==1){
//             if(arr[0]!=0) cout<<1<<endl;
//             else cout<<1<<endl;
//         }
//         else if(ct==0) cout<<0<<endl;
//         else if(n-1==ct0 || n-1==ct) cout<<1<<endl;
//         else{
//             if(arr[n-1]==0){
//                 if(arr[0]==0) cout<<ct0-1<<endl;
//                 else if(arr[0]!=0) cout<<ct0<<endl;
//             }
//             else if(arr[n-1]!=0) {
//                 if(arr[0]==0) cout<<ct0<<endl;
//                 else if(arr[0]!=0) cout<<ct0+1<<endl;
//             }
            
//         }
//     }
//     return 0;
// }


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
        int ct0=0;
        int ct1=0;
        for(int i = 0 ;i<n ; i++){
            cin>>arr[i];
            if(arr[i]==0) ct0++;
            else ct1++;
        }
        if(ct1==0) cout<<0<<endl;
        else if(n-1==ct0 || n-1==ct1) cout<<1<<endl;
        else {
            int ct=0;
            for(int i = 0 ; i<n ; ){
            if(arr[i]!=0){
                while(i<n && arr[i]!=0){
                    arr[i]=0;
                    i++;
                }
                ct++;
            }

            i++;
            }
            if(ct>=2) cout<<2<<endl;
            else cout<<ct<<endl;
        }
    }
    return 0;
}