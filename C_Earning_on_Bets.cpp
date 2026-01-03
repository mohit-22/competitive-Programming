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
        }
        int ans=0;
        int lm=1;
        for(int i=0 ; i<n ; i++){
            lm = lcm(lm,arr[i]);
        }
        for(int i=0 ; i<n ; i++){
            ans+=(lm/arr[i]);
        }
        if(ans>=lm){
            cout<<-1<<endl;
            continue;
        }
        for(int i=0 ; i<n ; i++){
            cout<<lm/arr[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}