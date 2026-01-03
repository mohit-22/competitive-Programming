// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,w;
//         cin >> n>>w;
//         int arr[n];
//         for(int i=0;i<n ; i++){
//             cin>>arr[i];
//         }
//         sort(arr,arr+n);
//         int i=0;
//         int j=n-1;
//         int ct=0;
//         int x = n;
//         while(i<=j){
//             int sum=0;
//             while(j>=0 && sum<w && i<=j){
//                 if(sum+arr[j]<=w){
//                     sum+=arr[j];
//                     j--;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             while(i<n && sum<w && i<=j){
//                 if(sum+arr[i]<=w){
//                     sum+=arr[i];
//                     i++;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             ct++;
//             // x = j-i+1;
//         }
//         cout<<ct<<endl;
        
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
        int n,w;
        cin >> n>>w;
        multiset<int>s;
        for(int i=0 ; i<n  ;i++){
            int x;
            cin>>x;
            s.insert(x);
        }
        int ans=1;
        int left = w;
        while(!s.empty()){
            auto itr = s.upper_bound(left);
            if(itr==s.begin()){
                left = w;
                ans++;
            }
            else{
                itr--;
                int val = *itr;
                left-=val;
                s.erase(itr);
            }
        }
        cout<<ans<<endl;
        
        
    }
    return 0;
}