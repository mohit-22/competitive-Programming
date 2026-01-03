#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n>>q;
        string s1;
        string s2;
        cin>>s1>>s2;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        map<int, vector<int>> mp;
        for(int i=0 ; i<n ; i++){
            v1[s1[i]-'a']++;
            mp[i] = v1;
        }
        map<int,vector<int>>mp2;
        for(int i=0 ; i<n ; i++){
            v2[s2[i]-'a']++;
            mp2[i] = v2;
        }

        while(q--){
            int i,j;
            cin>>i>>j;
            int ct=0;
            i--,j--;

            vector<int> A(26,0);
            if(i-1>=0) A = mp[i-1];
            vector<int> &B = mp[j]; 
            vector<int>c(26,0);
            
            for(int k=0 ; k<26 ;k++){
                if(i-1>=0) c[k] = B[k]-A[k];
                else c[k] = B[k];
            }

            vector<int> D(26,0);
             if(i-1>=0) D =  mp2[i-1];   
            vector<int> &E = mp2[j]; 
            vector<int>f(26,0);
            
            for(int k=0 ; k<26 ;k++){
                if(i-1>=0) f[k] = E[k]-D[k];
                else f[k] = E[k];
            }

            for(int k=0 ; k<26 ; k++){
                ct+= abs(f[k]-c[k]);
            }
            cout<<ct/2<<endl;

        
        }
        
    }
    return 0;
}