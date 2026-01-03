// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,q;
//         cin >> n>>q;
//         int arr[n];
//         for(int i = 0 ; i<n ; i++){
//             cin>>arr[i];
//         }
//         for(int j = 0 ; j<q ; j++){
//             int l,r,k;
//             cin>>l>>r>>k;
//             int brr[n];
//             for(int i = 0 ;i<n ; i++){  
//                 brr[i] = arr[i];
//             }
//             for(int i=l-1 ; i<r ; i++){
//                 brr[i] = k;
//             }
//             int sum = 0;
//             for(int i = 0 ; i<n ; i++){
//                 sum+=brr[i];
//             }
//             if(sum%2!=0) cout<<"YES"<<endl;
//             else cout<<"NO"<<endl;
            
//          }
        
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
        int n,q;
        cin >> n>>q;
        int arr[n];
        int brr[n];
        int sum = 0;
        brr[0] = 0;
        for(int i = 0 ; i<n ; i++){
            cin>>arr[i];
            sum +=arr[i];
            brr[i+1] = sum;

        }
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            int x = sum - brr[r] + brr[l-1] + (r-l+1)*k;
            if(x%2==0) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        
    }
    return 0;
}