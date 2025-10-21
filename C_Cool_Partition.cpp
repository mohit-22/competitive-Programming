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
        set<int>s;
        s.insert(arr[0]);
        vector<int>v;
        v.push_back(1);
        for(int i=1 ; i<n ;i++){
            if(s.find(arr[i])==s.end()){
                v.push_back(v[v.size()-1]+1);
                s.insert(arr[i]);
            }
            else{
                v.push_back(v[v.size()-1]);
            }
        }
        s.clear();
        int ct=0;
        for(int i=n-1 ; i>=0 ;){
            int x = v[i];
            while(i>=0 && s.size()!=x){
                s.insert(arr[i]);
                i--;
            }
            ct++;
            s.clear();
        }
        cout<<ct<<endl;
        // for(int i=0 ; i<v.size() ; i++){
        //     cout<<v[i]<<" ";
        // }
        
    }
    return 0;
}
