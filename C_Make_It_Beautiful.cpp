// // #include <bits/stdc++.h>
// // using namespace std;

// // #define int long long

// // int32_t main(){
// //     int t;
// //     cin >> t;
// //     while(t--){
// //         int n,k;
// //         cin >> n>>k;
// //         // int arr[n];
// //         vector<int>v1;
// //         vector<int>v2;
// //         vector<int>v3;
// //         vector<int>v4;
// //         for(int i=0 ;i<n  ;i++){
// //             int x;
// //             cin>>x;
// //             if(x<=2 ) v1.push_back(x);
// //             else if(x%4==0) v4.push_back(x);
// //             else if(x%4==3) v2.push_back(x);
// //             else v3.push_back(x);
// //         }
// //         sort(v1.begin(),v1.end());
// //         sort(v2.begin(),v2.end());
// //         sort(v3.begin(),v3.end());
// //         sort(v4.begin(),v4.end());
// //         int ans=0;
// //         for(int i=0 ; i<v1.size() ;i++){
// //             if(v1[i]==0 && k>0){
// //                 ans++;
// //                 k--;
// //             }
// //             else{
// //                 ans+=__builtin_popcountll(v1[i]);
// //             }
// //         }
// //         for(int i=0 ; i<v3.size() ; i++){
// //             int x = ceil(v3[i]/4.0);
// //             int y = 4*x-1;
// //             k = k-y;
// //             if(k>=0) ans+=__builtin_popcountll(y);
// //             else break;
// //         }
// //         for(int i=0 ; i<v4.size() ; i++){
// //             k--;
// //             if(k>=0) ans+=(__builtin_popcountll(v4[i])+1);
// //             else break;
// //         }


// //         int m = 0;
// //         while(k--){
// //             for(int i=0 ; i<v2.size() ; i++){
// //                 int x = (ceil(log2(v2[i])));
// //                 int w = __builtin_popcountll(v2[i]);
// //                 ans+=w;
// //                 m=i;
// //                 int z = pow(2,x+1);
// //                 int p = z-v2[i]-1;
// //                 k = k-p;
// //                 if(k>=0){
// //                     ans++;
// //                     v2[i] = pow(2,x+1)-1;
// //                 }
// //                 else break;
// //             }
// //         }
// //         for(int i=m ; i<v2.size() ; i++){
// //             ans+=__builtin_popcountll(v2[i]);
// //         }
// //         cout<<ans<<endl;
// //     }
// //     return 0;
// // }






// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n>>k;
//         vector<int>v(n);
//         for(int i=0 ; i<n ; i++){
//             cin>>v[i];
//         }
//         int x = 0;
//         int ans=0;
//         bool flag = true;
//         while(k>0){
//             for(int i=0 ; i<n ; i++){
//                 int y = (v[i]&(1LL<<x));
//                 if(k>=(1LL<<x)){
//                     if(y==0){
//                         ans++;
//                         k-=(1LL<<x);
//                     }
//                 }
//                 else{
//                     flag=false;
//                     break;
//                 }
//             }
//             x++;
//             if(!flag) break;
//         }
//         for(int i=0 ; i<n ; i++){
//             ans+=__builtin_popcountll(v[i]);
//         }
//         cout<<ans<<endl;

        
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    int k; 
    string str;
    cin >> n >> k >> str;
    int ans = 0;
    for (int i = 0; i < k; i++){
        map<char, int> mp2;
        int mx = 0;
        int ct2 = 0;
        for (int j = i; j < n; j+=k){
            mp2[str[j]]++;
            mx = max(mx, mp2[str[j]]);
            ct2++;
        }
        ans += (ct2 - mx);
    }
    cout << ans << endl;
}