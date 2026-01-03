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
        for(int i=0 ;i<n ; i++){
            cin>>arr[i];
        }

        unordered_map<int,int>mp;

        int ct1=0;
        int ct2=0;
        // bool flag = true;
        for(int i=0 ; i<n-1 ; i++){
            if(arr[i]!=arr[i+1] ){
                ct1=i+1;
                // flag = false;
                break;
            }
            // if(arr[i]!=arr[i+1]){
            //     ct2 = n-i-1;
            // }
        }
        for(int i=n-1;i>0 ; i--){
            if(arr[i]!=arr[i-1]){
                ct2 = n-i;
                break;
            }
        }
        // int ct3=0;
        // for(int i=1 ; i<n-1 ; i+=2){
        //     if((arr[i-1]==arr[i+1]) && arr[i-1]!=arr[i]){
        //         ct3++;
        //         arr[i] = arr[i+1];
        //     }
        // }
        // cout<<min({ct1, ct2, ct3})<<endl;
        vector<int>b;
        for(int i=0 ; i<n ; i++){
            b.push_back(arr[i]);
            mp[arr[i]]++;
        }

        int maxFreq = 0;
        int num = -1;

        for (auto &p : mp) {
            if (p.second > maxFreq) {
                maxFreq = p.second;
                num = p.first;
            }
        }
        vector<int>xrr;
        for(int i=0 ; i<n ; i++){
            if(arr[i]!=num) xrr.push_back(i);
        }
        int ct3=INT_MAX;
        if (xrr.size() > 1) {
            for (int i=0 ; i+1 < (int)xrr.size() ; i++){
                ct3 = min(ct3, xrr[i+1]-xrr[i]-1);
            }
        }

        for(int i=1  ;i<n-1 ; i++){
            if((arr[i]!=arr[i-1]) && (arr[i]!=arr[i+1]) && (arr[i-1]==arr[i+1])){
                arr[i] = arr[i+1];
                i++;
            }
        }
        bool flag3 = false;
        for(int i=0 ; i<n-1 ; i++){
            if(arr[i]!=arr[i+1]){
                flag3 = true;
                break;
            }
        }
        if(flag3){
            cout<<0<<endl;
            continue;
        }

        sort(b.begin(),b.end());
        if(b[0]==b[n-1]){
            cout<<-1<<endl;
            continue;
        }
        
        cout<<min({ct1,ct2,ct3})<<endl;
        // cout<<ct1<<" "<<ct2<<endl;
    }
    return 0;
}