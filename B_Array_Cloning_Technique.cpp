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
        for(int i = 0 ; i<n ; i++){
            cin>>arr[i];
        }
        if(n==1) cout<<0<<endl;
        else{
            bool flag = true;
            for(int i=0 ; i<n-1 ; i++){
                if(arr[i]!=arr[i+1]){
                flag = false;
                }
            }
            if(flag==true) cout<<0<<endl;
            else{
                sort(arr,arr+n);
                int count=1;
                int mx=1;
                for(int i=0 ; i<n-1 ; ){
                    while(i<n-1 && arr[i]==arr[i+1]){
                        count++;
                        i++;
                    }
                    mx = max(count,mx);
                    count = 1;
                    i++;
                }
                int ct = 1;
                while(mx<n){
                    if(n-mx>mx) {
                        ct+=mx;
                        mx *=2;
                    }
                    else{
                        ct+=(n-mx);
                        mx *=2;
                    }
                    if(mx<n)ct+=1;

                }
                cout<<ct<<endl;
            }
            
        }
    }
    return 0;
}