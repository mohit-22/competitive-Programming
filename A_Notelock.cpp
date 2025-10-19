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
        vector<bool>v(n,false);
        // if(s[0]=='1') ct++;
        for(int i=0 ; i<n ; i++){
            for(int j=max(i-k+1,0LL); j<=i ; j++){
                // if(v[j]==true) break;
                if(s[j]=='1' && j==i){
                    ct++;
                    v[j] = true;
                    break;
                }
                if(s[j]=='1') break;
            }
        }
        cout<<ct<<endl;

    }
    return 0;
}