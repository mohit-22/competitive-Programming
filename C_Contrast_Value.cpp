






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
//         bool flag = true;
//         for(int i=0; i<n ; i++){
//             cin>>arr[i];
//             if(i!=0){
//                 if(arr[i]!=arr[i-1]){
//                     flag = false;
//                 }
//             }
//         }
//         if(flag){
//             cout<<1<<endl;
//             continue;
//         }
//         int ct=0;
//         for(int i=0 ; i<n-1 ; ){
//             if(arr[i]<=arr[i+1]){
//                 while(i+1<n && arr[i]<=arr[i+1]){
//                     i++;
//                 }
//                 ct++;
//             }
//             else{
//                 while(i+1<n && arr[i]>=arr[i+1]){
//                     i++;
//                 }
//                 ct++;
//             }
//         }
//         cout<<ct+1<<endl;

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
        bool flag = true;
        for(int i=0; i<n ; i++){
            cin>>arr[i];
        }
        vector<int>b;
        for(int i=0 ; i<n ; i++){
            if(i==0 || arr[i]!=arr[i-1]) b.push_back(arr[i]);
        }
        if(b.size()==1){
            cout<<1<<endl;
            continue;
        }
        int ct=0;
        for(int i=1 ; i<b.size()-1 ; i++){
             if( (b[i] > b[i-1] && b[i] > b[i+1]) ||
                (b[i] < b[i-1] && b[i] < b[i+1]) ) {
                ct++;
            }
        }
        cout<<ct+2<<endl;

    }
    return 0;
}