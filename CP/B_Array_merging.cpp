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
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(int i=0 ; i<n  ;i++){
            cin>>arr[i];
        }
        int brr[n];
        for(int i=0 ;i<n ; i++){
            cin>>brr[i];
        }
        int prev = arr[0];
        int ct=0;
        for(int i=0 ; i<n ; i++){
            if(prev==arr[i]){
                ct++;
                mp1[arr[i]] = max(mp1[arr[i]],ct);
            }
            else{
                ct=1;
                mp1[arr[i]]=max(mp1[arr[i]],ct);
                prev = arr[i];
            }
        }
        // for(auto it: mp1){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        prev = brr[0];
        ct=0;
        for(int i=0 ; i<n ; i++){
            if(prev==brr[i]){
                ct++;
                mp2[brr[i]] = max(mp2[brr[i]],ct);
            }
            else{
                ct=1;
                mp2[brr[i]] = max(mp2[brr[i]],ct);;
                prev = brr[i];
            }
        }

        int mx=0;
        for(auto it : mp1){
            int x = it.first;
            mx = max(mx,it.second+mp2[x]);
        }
        for(auto it : mp2){
            int x = it.first;
            mx = max(mx,it.second+mp1[x]);
        }
        cout<<mx<<endl;
        // for(auto it: mp2){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
    }

    return 0;
}