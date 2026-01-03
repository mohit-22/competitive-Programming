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
        for(int i = 0 ;i<n ; i++){
            cin>>arr[i];
        }
        if(n==1) cout<<0<<endl;
        else{
             bool flag = true;
        for(int i = 0 ; i<n-1 ; i++){
            if(arr[i]>=arr[i+1]){
                flag=false;
                break;
            }
        }
        if(flag==true) cout<<0<<endl;
        else{
            int ct=0;
            bool possible = true;
            for(int i=n-2 ; i>=0 ; i--){
                
                while(arr[i]>=arr[i+1]) {
                    if(i!=0 &&  arr[i+1]==0 ||  arr[i]==0){
                        possible=flag;
                        break;
                    }
                    arr[i]=arr[i]/2;
                    ct++;
                }
                
            }
               if(possible) cout<<ct<<endl;
               else cout<<-1<<endl;
        }
        }
    }
    return 0;
}