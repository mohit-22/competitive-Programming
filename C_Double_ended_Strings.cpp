#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int ans = INT_MIN;
        for(int i=0;i<a.size() ; i++){
            int k=i;
            int ct=0;
            for(int j=0 ; j<b.size() ; j++ ){
                int p = j;
                if(a[i]==b[j]){
                    while(a[i]==b[j]){
                        ct++;
                        i++;
                        if(i>=a.size()) break;
                        j++;
                        if(j>=b.size()) break;

                    }
                }
                ans = max(ans,ct);
                i = k;
                ct=0;
                j=p;
            }
            i = k;
            
            
        }

        cout<<a.size()+b.size()-2*ans<<endl;

        

        
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
//         string a;
//         string b;
//         cin>>a;
//         cin>>b;
//         int n = a.length();
//         int m = b.length();

//         vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//         for(int i=0 ; i<=n ; i++){
//             dp[n][0] = 0;
//         }

//         for(int i=0 ; i<=m ; i++){
//             dp[0][m] = 0;
//         }

//         int ans=0;
//         for(int i=1 ; i<=n ; i++){
//             for(int j=1 ; j<=m ; j++){
//                 if(a[i-1]==b[j-1]){
//                     dp[i][j] = 1+dp[i-1][j-1];
//                     ans = max(ans,dp[i][j]);
//                 }
//                 else{
//                     dp[i][j] = 0;
//                 }
//             }
//         }

//         // cout<<ans<<endl;

//         cout<<n+m-2*ans<<endl;
        
//     }
//     return 0;
// }