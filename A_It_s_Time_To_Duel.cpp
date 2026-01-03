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
        int ct0=0;
        int ct1=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            if(arr[i]==0) ct0++;
            else ct1++;
        }
        if(ct1==n || ct0==n){
            cout<<"YES"<<endl;
        }
        else{
            bool flag=false;
            for(int i=0 ; i<n-1 ; i++){
                if(arr[i]==0 && arr[i+1]==0){
                    flag=true;
                    break;
                }
            }
            if(flag==true) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

        

    }
    return 0;
}