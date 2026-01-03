#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        string s;
        cin>>s;

        if(s[0]=='1' || s[n-1]=='1'){
            cout<<-1<<endl;
            continue;
        }

        // string str;
        // for(int i=0  ;i<n  ;i++){
        //     str[i] = '0';
        // }
        string str(n, '0');

        vector<pair<int,int>>v1(n);
        vector<pair<int,int>>v2(n);

        vector<pair<int,int>>v5(n);
        vector<pair<int,int>>v6(n);

        v1[0]={0,0};
        
        int mn = arr[0];
        int mx = arr[0];
        int k=0;
        int l=0;
        for(int i=1 ; i<n ; i++){
            v1[i]={mn,mx};
            v5[i] = {k,l};
            if(arr[i]>mx){
                mx = arr[i];
                l=i;
            }
            else if(arr[i]<mn){
                mn = arr[i];
                k=i;
            }
        }

        v2[n-1]={0,0};
        mn = arr[n-1];
        mx = arr[n-1];
        k=n-1;
        l=n-1;
        for(int i=n-2 ; i>=0 ; i--){
            v2[i]={mn,mx};
            v6[i] = {k,l};
           if(arr[i]>mx){
                mx = arr[i];
                l=i;
            }
            else if(arr[i]<mn){
                mn = arr[i];
                k=i;
            }
        }
        // reverse(v2.begin(),v2.end());

        vector<pair<int,int>>v3(n);
        vector<pair<int,int>>v4(n);
        vector<pair<int,int>>ans(n);
        for(int i=1 ; i<=n-2 ; i++){
            if(min(v1[i].first,v2[i].second)<arr[i] && arr[i]<max(v1[i].first,v2[i].second)){
                v3[i] = {min(v1[i].first,v2[i].second),max(v1[i].first,v2[i].second)};
                str[i]='1';
                ans[i] = {min(v5[i].first,v6[i].second),max(v5[i].first,v6[i].second)};
            }
            if(min(v2[i].first,v1[i].second)<arr[i] && arr[i]<max(v2[i].first,v1[i].second)){
                v4[i] = {min(v2[i].first,v1[i].second),max(v2[i].first,v1[i].second)};
                str[i]='1';
                ans[i] = {min(v6[i].first,v5[i].second),max(v6[i].first,v5[i].second)};
            }
        }
        bool flag=true;
        for(int i=1 ; i<n-1  ;i++){
            if(s[i]=='1'){
                if(str[i]!='1'){
                    flag=false;
                    break;
                }
            }
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }

        int ct=0;

        for(int i=0  ;i<=n-1 ; ){
            if(s[i]=='1'){
                ct++;
            }
            while(i+1<n &&  s[i]=='1' && s[i+1]=='1'){
                int a = v3[i].first;
                int b = v3[i].second;
                int c = v4[i].first;
                int d = v4[i].second;
                int e = v3[i+1].first;
                int f = v3[i+1].second;
                int g = v4[i+1].first;
                int h = v4[i+1].second;
                if((a==e && b==f) || (c==g && d==h) || (a==g && b==h) || (c==e && d==f)){
                    i++;
                }
                else break;
                // else ct++;
            }
            i++;
        }
        if(ct>5) cout<<-1<<endl;
        else{
            cout<<ct<<endl;
            for(int i=0  ;i<=n-1 ; ){
            if(s[i]=='1'){
                ct++;
                cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
            }
            while(i+1<n &&  s[i]=='1' && s[i+1]=='1'){
                int a = v3[i].first;
                int b = v3[i].second;
                int c = v4[i].first;
                int d = v4[i].second;
                int e = v3[i+1].first;
                int f = v3[i+1].second;
                int g = v4[i+1].first;
                int h = v4[i+1].second;
                if((a==e && b==f) || (c==g && d==h) || (a==g && b==h) || (c==e && d==f)){
                    i++;
                }
                else break;
                // else ct++;
            }
            i++;
        }
        }

        // for(auto it:v1){
        //     cout<<it.first<<" "<<it.second<<"   ";
        // }
        // cout<<endl;
        // for(auto it:v2){
        //     cout<<it.first<<" "<<it.second<<"   ";
        // }
        // cout<<endl;
        // cout<<endl;
        // for(auto it:v3){
        //     cout<<it.first<<" "<<it.second<<"   ";
        // }
        // cout<<endl;
        // for(auto it:v4){
        //     cout<<it.first<<" "<<it.second<<"   ";
        // }
        // cout<<endl;
        // cout<<endl;
        // for(auto it:v5){
        //     cout<<it.first<<" "<<it.second<<"   ";
        // }
        // cout<<endl;
        // for(auto it:v6){
        //     cout<<it.first<<" "<<it.second<<"   ";
        // }

    }
    return 0;
}