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
        // bool flag = false;
        // for(auto it:mp){
        //     bool found = false;
        //     if(it.second>=2){
        //         it.second -=2;
        //         found = true;
        //     }
        //     if(found){
        //         if(it.second>=1) flag = true;
        //     }
            
        // }
        int ct1=0;
        int ct2=0;
        for(auto it:mp){
            if(it.second>=2){
                it.second-=2;
                ct1+=it.second;
            }
            else{
                ct2+=it.second;
            }
        }
        if((ct1+ct2)%2==0 && ct1>=ct2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        
    }
    return 0;
}