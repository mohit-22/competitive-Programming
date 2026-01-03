// #include <bits/stdc++.h>
// using namespace std;

// // #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int x,y,a;
//         cin >> x>>y>>a;

//         int sum=0;
//         bool flag=true;
//         if(x!=0 && y!=0){
//             while(sum<a+0.5){
//                 sum+=x;
//                 if(sum>=a+0.5){
//                     flag= false;
//                     break;
//                 }
//                 sum+=y;
//             }
//         }
        
//         if(flag==false) cout<<"NO"<<endl;
//         else cout<<"YES"<<endl;
        
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
        int x,y,a;
        cin >> x>>y>>a;

        int m = x+y;
        int n = a%m;

        if(x>=n+0.5) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }
    return 0;
}