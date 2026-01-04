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
        map<int,int>mp;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        vector<int>v;
        for(auto it:mp){
            for(int i=0 ; i<it.second/2 ; i++){
                v.push_back(it.first);
            }
        }
        if(v.size()<4){
            cout<<"NO"<<endl;
            continue;
        }
        sort(v.begin(),v.end());
        cout<<"YES"<<endl;
        
        cout<<v[0]<<" "<<v[v.size()-1]<<" "<<v[0]<<" "<<v[1]<<" "<<v[v.size()-2]<<" "<<v[1]<<" "<<v[v.size()-2]<<" "<<v[v.size()-1]<<endl;


        
        
    }
    return 0;
}