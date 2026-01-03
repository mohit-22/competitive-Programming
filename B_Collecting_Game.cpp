#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0 ; i<n ; i++){
            cin>>v[i];
        }
        vector<int>brr = v;
        sort(v.begin(),v.end());
        vector<int>prev(n,-1);
        prev[0] = v[0];
        for(int i=1 ; i<n ; i++){
            prev[i] = prev[i-1]+v[i]; 
        }

        unordered_map<int,int>mp;
        mp[v[n-1]] = n-1;
        for(int i=n-2 ; i>=0 ; i--){
            if(prev[i]>=v[i+1]){
                mp[v[i]] = mp[v[i+1]];
            }
            else{
                mp[v[i]] = i;
            }
        }

        for(int i=0 ; i<n ; i++){
            cout<<mp[brr[i]]<<" ";
        }
        cout<<endl;
    }
    return 0;
}