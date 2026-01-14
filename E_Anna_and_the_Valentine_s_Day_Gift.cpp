#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        vector<int>v;
        vector<int>arr;
        for(int i=0 ; i<n ; i++){
            int x;
            cin>>x;
            arr.push_back(x);
            int ct=0;
            while(x%10==0){
                ct++;
                x = x/10;
            }
            if(ct!=0) v.push_back(ct);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ct=0;
        for(int i=0 ; i<v.size() ; i+=2){
            ct+=v[i];
        }
        int tt = 0;
        for(int i=0 ; i<arr.size() ; i++){
            int x = arr[i];
            while(x>0){
                tt++;
                x = x/10;
            }
        }
        int y = tt-ct;
        if(y>=m+1) cout<<"Sasha"<<endl;
        else cout<<"Anna"<<endl;
        

        
    }
    return 0;
}