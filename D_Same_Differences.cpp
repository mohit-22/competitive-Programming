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
            arr[i] = arr[i]-i+1;
        }
        unordered_map<int,int>mp;
        for(int i=0 ; i<n ; i++){
            mp[arr[i]]++;
        }
        int sum=0;
        for(auto it:mp){
            if(it.second>=2){
                sum+=((it.second)*(it.second-1))/2;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}