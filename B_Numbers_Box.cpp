// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,m;
//         cin >> n>>m;
//         int t=n*m;
//         int arr[t];
//         int ctn=0;
//         for(int i=0 ; i<t;i++){
//             cin>>arr[i];
//             if(arr[i]<0) ctn++;
//         }
//         int sum=0;
//         int mn=INT_MAX;
//         for(int i=0 ; i<t;i++){
//             if(arr[i]<0) arr[i] = abs(arr[i]);
//             sum+=arr[i];
//             mn = min(arr[i],mn);
//         }
//         if(ctn%2==0) cout<<sum<<endl;
//         else cout<<sum-2*mn<<endl;

        
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
        int n,m;
        cin >> n>>m;
        int arr[n*m];
        int mn = INT_MAX;
        int sum=0;
        int ct=0;
        for(int i=0 ; i<n*m ; i++){
            cin>>arr[i];
            int x = abs(arr[i]);
            mn = min(x,mn);
            sum+=x;
            if(arr[i]<0) ct++;
        }
        if(ct%2==0) cout<<sum<<endl;
        else  cout<<sum-2*mn<<endl;

        
    }
    return 0;
}