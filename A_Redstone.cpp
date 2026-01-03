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
        bool flag = false;
        for(auto it:mp){
            if(it.second>=2){
                flag=true;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}