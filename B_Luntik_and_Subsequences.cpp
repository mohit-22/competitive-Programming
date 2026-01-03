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
        int ct1=0,ct0=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            if(arr[i]==1) ct1++;
            else if(arr[i]==0) ct0++;
        }
        cout<<(long long)(ct1*(pow(2,ct0)))<<endl;

    }
    return 0;
}