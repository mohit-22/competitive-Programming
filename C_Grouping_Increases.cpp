#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        vector<int>s,t;
        // s.push_back(arr[0]);
        for(int i=0 ; i<n ; i++){
            if(s.empty()){
                s.push_back(arr[i]);
            }
            else if(arr[i]<=s.back()){
                s.push_back(arr[i]);
            }
             else if(t.empty()){
                t.push_back(arr[i]);
            }
            else if(arr[i]<=t.back() && arr[i]>=s.back()){
                t.push_back(arr[i]);
            }
            else if(s.back()>arr[i] && t.back()>arr[i]){
                if(s.back()>t.back()){
                    t.push_back(arr[i]);
                }
                else{
                    s.push_back(arr[i]);
                }
            }
            else if(s.back()<arr[i] && t.back()<arr[i]){
                if(s.back()>t.back()){
                    t.push_back(arr[i]);
                }
                else{
                    s.push_back(arr[i]);
                }
            }
            
        }
        int ct=0;
        for(int i=0 ; i+1<s.size() ; i++){
            if(s[i]<s[i+1]) ct++;
        }
        for(int i=0 ; i+1<t.size() ; i++){
            if(t[i]<t[i+1]) ct++;
        }
        cout<<ct<<endl;
    }
    return 0;
}