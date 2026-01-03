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
        vector<pair<int,int>>v;
        for(int i=0 ; i<n ; i++){
            v.push_back({arr[i],i});
        }
        sort(arr,arr+n,greater<int>());
        sort(v.begin(),v.end(),[](const auto &a,const auto &b){return a.first>b.first;});
        int i=0;
        int j=1;
        int ct=1;
        int sum=0;
        while(i<n){
            v[i].first=ct;
            if(j<n) v[j].first=-ct;
            sum+=2*(abs(v[i].first))*arr[i];
            if(j<n) sum+=2*(abs(v[j].first))*arr[j];
            i+=2;
            j+=2;
            ct++;
        }

        sort(v.begin(),v.end(),[](const auto &a,const auto &b) {return  a.second<b.second;});
        cout<<sum<<endl;
        cout<<0<<" ";
        for(auto x:v){
            cout<<x.first<<" "; 
        }
        cout<<endl;
    }
    return 0;
}