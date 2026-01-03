// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n>>k;
//         int arr[n];
//         int s=0;
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//             // s+=arr[i];
//         }
//         sort(arr,arr+n);
//         int i=2*k-1;
//         int j=n-k;
//         for(int m=i+1 ; m<j ; m++){
//             s+=arr[m];
//         }
//         int ct=0;
//         while(ct<k){
//             if(arr[i]+arr[i-1]>=arr[j]){
//                 s+=(arr[i]+arr[i-1]);
//                 if(i==j){
//                     j++;
//                     ct++;
//                 }
//                 i-=2;
//             }
//             else {
//                 s+=arr[j];
//                 j++;
//             }
//             ct++;
//         }
//         cout<<s<<endl;
        
//     }
//     return 0;
// }







// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n>>k;
//         int arr[n];
//         int m = k;
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//         }
//         sort(arr,arr+n);
//         int i=0;
//         int j=n-1;
//         while(k>0 &&  i<=j){
//             if(arr[i]+arr[i+1]<=arr[j]){
//                 i+=2;
//             }
//             else{
//                 j--;
//             }
//             k--;
//         }
//         int sum=0;
//         for(int x=i;x<=j ; x++){
//             sum+=arr[x];
//         }
//         int mx = 0;
//         int sum2=0;
//         for(int i=0 ; i<n-m ; i++){
//             sum2+=arr[i];
//         }
//         mx = max(sum,sum2);
//         int sum3=0;
//         for(int i=2*m ; i<n ; i++){
//             sum3+=arr[i];
//         }
//         mx = max(sum3,mx);
//         cout<<mx<<endl;
//         // cout<<sum2<<endl;
        
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
        int n,k;
        cin >> n>>k;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int prev[n];
        prev[0] = arr[0];
        for(int i=1 ; i<n ; i++){
            prev[i] = arr[i] + prev[i-1];
        }
        int ans=0;
        for(int first = 0 ; first<=k ; first++){
            int second = k-first;
            int start = 2*first;
            int end = n-second-1;
            int sum=0;
            if(start==0){
                sum+=prev[end];
            }
            else{
                sum+=prev[end]-prev[start-1];
            }
            ans=max(ans,sum);
        }

        cout<<ans<<endl;
        
    }
    return 0;
}