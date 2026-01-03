// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n>>k;
//         string s;
//         cin>>s;

//         int i=0;
//         int j=0;
//         int ctw=0;
//         int ans =INT_MAX;
//         while(j<n){
//             if(s[j]=='W') ctw++;
//             if(j-i+1==k){
//                 ans = min(ans,ctw);
//                 if(s[i]=='W') ctw--;
//                 i++;
//             }
//             j++;
//         }
//         cout<<ans<<endl;
        
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
        string s;
        cin>>s;
        int ct=0;
        int i=0;
        int j=0;
        int ans = INT_MAX;
        while(j<n){
            if(s[j]=='W') ct++;
            if(j-i+1==k){
                ans = min(ans,ct);
                if(s[i]=='W') ct--;
                i++;
            }
            j++;
        }

        cout<<ans<<endl;

        
        
    }
    return 0;
}