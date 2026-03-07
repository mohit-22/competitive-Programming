// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// // bool canFindSum(multiset<int>s, int x) {
// //     bitset<100001> dp; 
// //     dp[0] = 1;
// //     for (int num : s) {
// //         dp |= (dp << num);
// //     }
// //     return dp[x];
// // }

// bool canFindSum(multiset<int>s, int x) {
//     vector<bool>dp(x+1,false);
//     dp[0] = true;
//     for(auto curr:s){
//         for(int i=x ; i>=curr ; i--){
//             if(dp[i-curr]) dp[i]=true;
//         }
//     }
//     return dp[x];
// }

// int32_t main(){
//     int t;
//     cin >> t;
//     multiset<int>s;
//     while(t--){
//         int n,v;
//         cin>>n>>v;
//         if(n==1) s.insert(1<<v);
//         else{
//             if(canFindSum(s,v)) cout<<"YES"<<endl;
//             else cout<<"NO"<<endl;
//         }
        
        
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main(){
    int m;
    cin >> m;

    vector<long long> cnt(31,0);

    while(m--){
        int t;
        long long v;
        cin >> t >> v;

        if(t==1){
            cnt[v]++;
        }
        else{
            long long w = v;

            for(int i=30;i>=0;i--){
                long long val = (1LL<<i);
                long long take = min(cnt[i], w/val);
                w -= take*val;
            }

            if(w==0) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}