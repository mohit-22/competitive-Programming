// // #include <bits/stdc++.h>
// // using namespace std;

// // #define int long long

// // int m = 998244353;

// // int32_t main(){
// //     int t;
// //     cin >> t;
// //     while(t--){
// //         int n;
// //         cin >> n;
// //         vector<int> arr(n), brr(n);
// //         for(int i=0 ; i<n ; i++){
// //             cin>>arr[i];
// //         }
// //         for(int i=0 ; i<n ; i++){
// //             cin>>brr[i];
// //         }
// //         vector<int> crr = arr;  // copy directly
// //         vector<int> drr = brr;


// //         vector<pair<int,int>>v1;
// //         v1.push_back({arr[0],0});
// //         for(int i=1 ; i<n ; i++){
// //             int x = max(arr[i],arr[i-1]);
// //             if(x==arr[i]) v1.push_back({x,i});
// //             else v1.push_back({x,v1[i-1].second});
// //             arr[i] = x;
// //         }

// //         vector<pair<int,int>>v2;
// //         v2.push_back({brr[0],0});

// //         for(int i=1 ; i<n ; i++){
// //             int x = max(brr[i],brr[i-1]);
// //             if(x==brr[i]) v2.push_back({x,i});
// //             else v2.push_back({x,v2[i-1].second});
// //             brr[i] =x;
// //         }
// //         vector<int>ans(n);
// //         for(int i=0 ; i<n ; i++){
// //             int x = max(v1[i].first,v2[i].first);
// //             if(v1[i].first==v2[i].first){
// //                 int a = 1<<v1[i].first;
// //                 int b = 1<<drr[abs(i-v1[i].second)];
// //                 int c = 1<<v2[i].first;
// //                 int d = 1<<crr[abs(i-v2[i].second)];
// //                 ans[i] = (max(a+b,c+d))%m;
// //             }
// //             else{
// //                 if(x==v1[i].first){
// //                     int a = 1<<v1[i].first;
// //                     int b = 1<<drr[abs(i-v1[i].second)];
// //                     ans[i] = (a+b)%m;
// //                 }
// //                 else{
// //                     int c = 1<<v2[i].first;
// //                     int d = 1<<crr[abs(i-v2[i].second)];
// //                     ans[i] = (c+d)%m;
// //                 }
// //             }  

// //         }

// //         for(int i=0 ; i<n ; i++){
// //             cout<<ans[i]<<" ";
// //         }
// //         cout<<endl;

        
// //     }
// //     return 0;
// // }




// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// int M = 998244353;



// int powMod(int x, int n) {
//     int res = 1;

//     // Loop until exponent becomes 0
//     while(n >= 1) {
        
//         // n is odd, multiply result by current x and take modulo
//         if(n & 1) {
//             res = (res * x) % M;
            
//             // Reduce exponent by 1 to make it even
//             n--;  
//         }
        
//         // n is even, square the base and halve the exponent
//         else {
//             x = (x * x) % M;
//             n /= 2;
//         }
//     }
//     return res;
// }



// int32_t main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n),b(n);

//         for(int i=0;i<n;i++) cin>>a[i];

//         for(int &i:b) cin>>i;

//         pair<int,int> mxa,mxb;

//         for(int i=0;i<n;i++){
//             if(a[i]>mxa.first) {
//                 mxa.first=a[i];
//                 mxa.second=i;
//             }
//             if(b[i]>mxb.first){
//                 mxb.first=b[i];
//                 mxb.second=i;
//             }

//             if(mxa.first>mxb.first){
//                 int ans=powMod(2,mxa.first);
//                 ans=(ans+(powMod(2,b[i-mxa.second])))%M;
//             }else if(mxa.first<mxb.first){
                
//             }
//         }

//     }
//     return 0;
// }





#include <bits/stdc++.h>
using namespace std;
 
#define int long long
int m = 998244353;
 
int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n), brr(n);
        for (int i=0; i<n; i++) cin >> arr[i];
        for (int i=0; i<n; i++) cin >> brr[i];
 
        vector<int> pow2(n);
        pow2[0] = 1;
        for(int i=1;i<n;i++) pow2[i] = ((pow2[i-1]) * 2)%m;
 
        // store prefix max + index
        vector<pair<int,int>> v1(n), v2(n);
        v1[0] = {arr[0], 0};
        v2[0] = {brr[0], 0};
 
        for (int i=1; i<n; i++) {
            if (arr[i] >= v1[i-1].first) v1[i] = {arr[i], i};
            else v1[i] = v1[i-1];
            
            if (brr[i] >= v2[i-1].first) v2[i] = {brr[i], i};
            else v2[i] = v2[i-1];
        }
 
        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            int x = max(v1[i].first, v2[i].first);
            if (v1[i].first == v2[i].first) {
                // int a = 1 << v1[i].first;
                // int b = 1 << brr[abs(i-v1[i].second)];
                // int c = 1 << v2[i].first;
                // int d = 1 << arr[abs(i-v2[i].second)];
                int a = (pow2[v1[i].first]);
                // int b = (pow2[brr[abs(i-v1[i].second)]]);
                // int c = (pow2[v2[i].first]);
                // int d = (pow2[arr[abs(i-v2[i].second)]]);
                // int x = (max(a+b, c+d));
                    int b = brr[abs(i-v1[i].second)];
                 int d = arr[abs(i-v2[i].second)];
                 if(b>d){
                        int b = (pow2[brr[abs(i-v1[i].second)]]);
                        ans[i] = (a+b)%m;
                 }
                 else{
                    int d = (pow2[arr[abs(i-v2[i].second)]]);
                    ans[i] = (a+d)%m;
                 }
            } else {
                if (x == v1[i].first) {
                    // int a = 1 << v1[i].first;
                    // int b = 1 << brr[abs(i-v1[i].second)];
                    int a = (pow2[v1[i].first]);
                    int b = (pow2[brr[abs(i-v1[i].second)]]);
                    int x = a+b;
                    ans[i] = x%m ;
                } else {
                    // int c = 1 << v2[i].first;
                    // int d = 1 << arr[abs(i-v2[i].second)];
                    int c = (pow2[v2[i].first]);
                int d = (pow2[arr[abs(i-v2[i].second)]]);
                int x = c+d;
                    ans[i] = x % m;
                }
            }
        }
 
        for (int i=0; i<n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}