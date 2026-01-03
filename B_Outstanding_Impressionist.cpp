#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr;
        set<int>s;
        map<int,int>mp;
        int mx=INT_MIN;
        int mn = INT_MAX;
        for(int i=0 ; i<n ; i++){
            int x,y;
            cin>>x>>y;
            mn = min(mn,x);
            mx = max(mx,y);
            if(x==y){
                s.insert(x);
                mp[x]++;
            }
            arr.push_back(x);
            arr.push_back(y);

        }
        vector<int>v;
        for(int i=mn ; i<=mx ; i++){
            if(s.find(i)==s.end()){
                v.push_back(i);
            }
        }
        sort(v.begin(),v.end());

        for(int i=0 ; i<2*n ; i+=2){
            if(arr[i]==arr[i+1]){
                if(mp[arr[i]]>1) cout<<0;
                else cout<<1;
            }
            else{
                auto it = lower_bound(v.begin(),v.end(),arr[i]);
                if(it==v.end()){
                    cout<<0;
                }
                else{
                    if(*it>=arr[i] && *it<=arr[i+1]) cout<<1;
                    else cout<<0;
                }
            }
        }
        cout<<endl;
        
    }
    return 0;
}