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
        int brr[n];
        map<int,pair<int,bool>>mp;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            mp[arr[i]] = {i+1,true};
        }
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
        }
        int i=0;
        int ct=0;
        while(i<n){
            int x = arr[brr[i]-1];
            vector<pair<int,int>>v;
            if(mp[x].first==x && mp[x].second==true){
                ct++;
            }
            else{
                while(mp.find(x)!=mp.end() && mp[x].first!=x && mp[x].second ==true){
                    ct++;
                    mp[x].second = false;
                    int y = mp[x].first;
                    // mp.erase(x);
                    v.push_back({x,y});
                    x = y;
                }
                for(int i=0 ; i<v.size() ; i++){
                    mp.erase(v[i].first);
                }
                for(int j=0 ; j<v.size() ; j++){
                    mp[v[j].second].first = v[j].second;
                    mp[v[j].second].second = false;
                }
            }
            
            cout<<ct<<" ";
            i++;
        }
        cout<<endl;
    }
    return 0;
}