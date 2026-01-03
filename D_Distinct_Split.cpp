#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin>>s;
        vector<bool>v(26,false);
        int ct=0;
        vector<int>x;
        for(int i=0 ; i<n ; i++){
            if(v[s[i]-'a']==false){
                ct++;
                v[s[i]-'a']=true;
            }
            x.push_back(ct);
        }
        ct=0;
        vector<int>y;
        v.assign(26, false);
        for(int i=n-1 ; i>=0 ; i--){
            if(v[s[i]-'a']==false){
                ct++;
                v[s[i]-'a']=true;
            }
            y.push_back(ct);
        }
        reverse(y.begin(),y.end());
        int ans=INT_MIN;
        for(int i=0 ; i<n-1 ; i++){
                ans = max(ans,x[i]+y[i+1]);
        }
        // cout<<ans<<endl;
        for(int i=0 ; i<x.size() ; i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
        
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
//         string s;
//         cin>>s;
//         unordered_map<char,int>mp1;
//         for(int i=0 ; i<n ; i++){
//             mp1[s[i]]++;
//         }
//         unordered_map<char,int>mp2;
//         int ans = INT_MIN;
//         for(int i=0 ; i<n ; i++){
//             mp1[s[i]]--;
//             if(mp1[s[i]]==0){
//                 mp1.erase(s[i]);
//             }
//             mp2[s[i]]++;
//             int x = (mp1.size()+mp2.size());
//             ans=max(ans,x);
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }