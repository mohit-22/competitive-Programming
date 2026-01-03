#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n>>x;
        vector<int>v;
        for(int i=0 ; i<n ; i++){
           if(i!=x) v.push_back(i);
        }
         if(x<n)v.push_back(x);
        for(int i=0 ; i<v.size() ; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}