#include <bits/stdc++.h>
using namespace std;

#define int long long

pair<int, int> dfs(int u,vector<vector<int >>&v,string &s,vector<pair<int,int>>&node){

    int b=0,w=0;

    if(s[u-1]=='B') b++;
    else w++;

    for(auto it:v[u]){
         node[it-1]= dfs(it,v,s,node);
         b+=node[it-1].first;
         w+=node[it-1].second;
    }
    // if(b==w) ct++;
    return node[u-1]={b,w};
    
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0 ; i<n-1 ; i++){
            cin>>arr[i];
        }
        string s;
        cin>>s;

        vector<vector<int >>v(n+1);
        for(int i=1 ; i<=n ; i++){
            for(int j=0 ; j<n-1 ; j++){
                if(arr[j]==i) v[i].push_back(j+2);
            }
        }
        int ct=0;
        vector<pair<int,int>>node(n);
        // for(int i=1 ; i<=n ; i++){
        //     int b=0;
        //     int w=0;
            dfs(1,v,s,node);
            // if(b==w) ct++;
        // }
        for(auto it:node){
            if(it.first==it.second) ct++;
        }
        cout<<ct<<endl;
    }
    return 0;
}





