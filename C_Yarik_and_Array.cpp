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
//         for(int i=0; i<n ; i++){
//             cin>>arr[i];
//         }
//         int mx=arr[0];
//         int sum=arr[0];
//         for(int i=1 ; i<n ; i++){
//             if(sum==0){
//                 sum+=arr[i];
//             }
//             else if(sum>=0 && (abs((arr[i]-1)%2)==abs((arr[i-1])%2))){
//                 sum += arr[i];
                
//             }
//             else{
//                 sum=max(arr[i],arr[i-1]);
                
//             }
//             // if(sum<0) sum=0;
//             if(sum<0 || (abs((arr[i]-1)%2)!=abs((arr[i-1])%2))){
//                 if(arr[i]>0) sum=arr[i];
//                 else sum=0;
//             }
//             mx = max(mx,sum);
//         }
//         sort(arr,arr+n);
//         if(arr[0]<=0 && arr[n-1]<=0 ){
//             int x = *max_element(arr,arr+n);
//             cout<<x<<endl;
//         }
//         else cout<<mx<<endl;
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
        vector<int>arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        vector<int>brr = arr;
        for(int i=1 ; i<n ; i++){
            if((arr[i]+brr[i-1]>brr[i]) && (abs((arr[i]-1)%2)==abs((arr[i-1])%2))){
                brr[i] = arr[i]+brr[i-1];
            }
        }
        int ans = *max_element(brr.begin(),brr.end());
        cout<<ans<<endl;
        
    }
    return 0;
}