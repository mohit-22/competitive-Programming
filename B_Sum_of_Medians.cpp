// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n>>k;
//         int s=n*k;
//         int arr[s];
//         for(int i=0 ; i<s ; i++){
//             cin>>arr[i];
//         }
//         int x=0;    
//         if(n%2==0) x=n/2;
//         else x=(n/2)+1;

//         int ans=0;
//         if(n==1){
//             for(int i=0; i<s;i++){
//                 ans+=arr[i];
//             }
//         }
//         else if(x==1){
//             for(int i=0 ; i<s ; i+=2){
//                 ans+=arr[i];
//             }
//         }
//         else{
//             int count=0;
//             for(int i=s-1-(n-x);i>=0 ; i=i-(n-x+1)){
//                 ans+=arr[i];
//                 count++;
//                 if(count==k) break;
//             }
//         }
//         cout<<ans<<endl;
        
//     }
//     return 0;
// }


// method 2 by chat gpt

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int s = n * k;
        vector<int> arr(s);
        for(int i = 0; i < s; i++){
            cin >> arr[i];
        }

        int step = (n / 2) + 1;
        int ans = 0;
        int count = 0;
        for (int i = s - step; count < k; i -= step) {
            ans += arr[i];
            count++;
        }
        
        cout << ans << "\n";
    }
    return 0;
}
