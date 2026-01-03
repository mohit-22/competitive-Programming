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
        int brr[n];
        for(int i=0  ;i<n  ;i++){
            cin>>arr[i];
        }
        map<int,int>mp;
        map<int,int>mp3;
        for(int i=0 ; i<n; i++){
            cin>>brr[i];
            if(brr[i]!=arr[i]) mp[brr[i]]++;
            mp3[brr[i]]++;
        }
        int k;
        cin>>k;
        int drr[k];
        map<int,int>mp2;
        // int u=0;
        for(int i=0 ; i<k ; i++){
            cin>>drr[i];
            mp2[drr[i]]++;
            // if(mp3[drr[i]]>0){
            //     u=i;
            // }
        }
        bool flag = true;
        for(auto it :mp){
            if(mp2[it.first]<it.second){
                flag = false;
                break;
            }
        }
        if(!flag || mp3[drr[k-1]]==0){
            cout<<"NO"<<endl;
        }else cout<<"YES"<<endl;
    }
    return 0;
}