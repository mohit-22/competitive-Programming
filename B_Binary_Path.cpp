#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s1,s2;
        cin>>s1>>s2;
        string ans="";
        ans+=s1[0];
        bool flag = false;
        for(int i=0 ; i<n ; i++){
            if(i+1<n &&  s1[i+1]<=s2[i]) ans+=s1[i+1];
            else{
                ans+=s2.substr(i,n-i);
                flag = true;
                break;
            }
        }

        // int ct=0;
        // for(int i=0 ; i<n ; i++){
        //     if( s2[i]==ans[i+1]){
        //         string p =ans.substr(i+1,ans.size()-(i+1));
        //         string q = s2.substr(i,n-i);
        //         string x = ans.substr(0,i+1);
        //         string y = s1.substr(0,i+1);
        //         if((p==q) && (x==y))ct++;
        //     }
        // }
        // cout<<ans<<endl;
        // cout<<ct<<endl;

        for(int i=0 ; i<n ; i++){
            // if(s1[i+1]==)
        }
    }
    return 0;
}

