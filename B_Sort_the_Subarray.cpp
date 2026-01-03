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
//         for(int i=0 ; i<n; i++){
//             cin>>arr[i];
//         }
//         int brr[n];
//         for(int i=0 ; i<n ; i++){
//             cin>>brr[i];
//         }
//         int x = -1;
//         int y= -1;
//         for(int i=0 ; i<n ; i++){
//             if(arr[i]!=brr[i]){
//                 x=i;
//                 break;
//             }
//         }
//         for(int i=n-1 ; i>=0 ; i--){
//             if(arr[i]!=brr[i]){
//                 y=i;
//                 break;
//             }
//         }
//         int mx = INT_MIN;
//         int mn = INT_MAX;
//         for(int i=x ; i<=y ; i++){
//             mx=max(arr[i],mx);
//             mn = min(arr[i],mn);
//         }
//         for(int i=x-1 ; i>=0 ; i--){
//             if(arr[i]<=mn){
//                 mn = arr[i];
//                 x = i;
//             }
//             else break;
//         }
//         for(int i=y+1 ; i<n ; i++){
//             if(arr[i]>=mx){
//                 mx = arr[i];
//                 y = i;
//             }
//             else break;
//         }
        
//         cout<<x+1<<" "<<y+1<<endl;
//     }
//     return 0;
// }










#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main() {
       int t;
       cin>>t;
       while(t--){
        int n;
        cin>>n;
        int arr[n];
        int brr[n];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int change1 = 0;
        int change2 = 0;
        for(int i = 0;i<n;i++){
            cin>>brr[i];
            if(brr[i]!=arr[i] && change1==0){
                change1 = i;
            }
            else if(brr[i]!=arr[i]){
                change2 = i;
            }
        }
        while(change1>0){
            if(brr[change1-1]<=brr[change1]) change1--;
            else break;
        }
        while(change2<n-1){
            if(brr[change2+1]>=brr[change2]) change2++;
            else break;
        }
        cout<<change1 + 1<<" "<<change2 + 1<<endl;
    }
}