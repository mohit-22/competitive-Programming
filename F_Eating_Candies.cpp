#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        vector<int>pre(n);
        pre[0] = arr[0];
        for(int i=1 ; i<n ;i++){
            pre[i] = arr[i]+pre[i-1];
        }
        vector<int>suff(n);
        suff[n-1] = arr[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            suff[i] = arr[i]+suff[i+1];
        }

        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j){
            if(pre[i]>suff[j]) j--;
            else if(pre[i]<suff[j]) i++;
            else if(pre[i]==suff[j]){
                ans = max(ans,(i+1)+(n-j));
                i++;
                j--;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}



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
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//         }
//         int sumA=0;
//         int sumB=0;
//         int ans=0;
//         int ct=0;
//         int i=0,j=n-1;
//         while(i<=j){

//             if(i==j){
//                 if(sumA>sumB){
//                     sumB+=arr[j];
//                     j--;
//                 }
//                 else if(sumB>=sumA){
//                     sumA+=arr[i];
//                     i++;
//                 }
//                 ct++;
//                 if(sumA==sumB){
//                     ans= max(ans,ct);
//                 }

//             }
            
//             if(i>j){
//                 break;
//             }

//             if(sumA>sumB ){
//                 sumB+=arr[j];
//                 ct++;
//                 if(sumA==sumB){
//                     ans= max(ans,ct);
//                 }
//                 j--;
                
//             }
//             else if(sumB>sumA ){
//                 sumA+=arr[i];
//                 ct++;
//                 if(sumA==sumB){
//                     ans= max(ans,ct);
//                 }
//                 i++;
                
//             }
//             else if(sumA==sumB ){
//                 sumA+=arr[i];
//                 i++;
//                 sumB+=arr[j];
//                 j--;
//                 ct+=2;
//                 if(sumA==sumB){
//                     ans= max(ans,ct);
//                 }
                
//             }

//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }