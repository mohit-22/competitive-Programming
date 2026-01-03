#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v;
        vector<int>pre;
        int mx = INT_MIN;
        for(int i=0 ; i<n ; i++){
            int x;
            cin>>x;
            v.push_back(x);
            mx = max(mx,x);
            pre.push_back(mx);
        }
        for(int i=1 ; i<n ; i+=2){
            v[i] = pre[i];
        }
        int ct=0;
        if(n%2!=0){
            for(int i=1 ; i<=n-2 ; i+=2){
                int x = v[i]-v[i-1];
                int y = v[i]-v[i+1];
                if(x<=0){
                    x = abs(x);
                    v[i-1] -=x+1;
                    ct+=(x+1);
                }
                if(y<=0){
                    y=abs(y);
                    v[i+1]-=y+1;
                    ct+=(y+1);
                }
            }
        }
        else{
            for(int i=1 ; i<=n-1 ; i+=2){
                int x = v[i]-v[i-1];
                int y = 1;
                if(i+1<n) y = v[i]-v[i+1];
                if(x<=0){
                    x = abs(x);
                    v[i-1] -=x+1;
                    ct+=(x+1);
                }
                if(y<=0){
                    y=abs(y);
                    v[i+1]-=y+1;
                    ct+=(y+1);
                }
            }
        }
        cout<<ct<<endl;
    }
    return 0;
}