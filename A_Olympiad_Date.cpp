#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin>>a[i];
        }
        int ct=0;
        int ct0=0,ct1=0,ct2=0,ct3=0,ct5=0;
        bool flag=false;
        for(int i=0 ; i<n ;i++){
            if(a[i]==0) ct0++;
            else if(a[i]==1) ct1++;
            else if(a[i]==2) ct2++;
            else if(a[i]==3) ct3++;
            else if(a[i]==5) ct5++;
            ct++;
            if(ct0>=3 && ct1>=1 && ct2>=2 && ct3>=1 && ct5>=1){
                flag=true;
                break;
            }
        }
        if(flag==true) cout<<ct<<endl;
        else cout<<0<<endl;
    }
    return 0;
}