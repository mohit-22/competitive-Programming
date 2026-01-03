#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n>>x;

        int arr[n];
        int mnsum=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            mnsum+=arr[i];
        }
        int mn=0;
        if(mnsum%x==0) mn=(mnsum/x);
        else mn=(mnsum/x)+1;

        int mx=0;
        for(int i=0; i<n ; i++){
            if(arr[i]%x==0){
                mx+=(arr[i]/x);
            }
            else{
                mx+=(arr[i]/x)+1;
            }
        }
        cout<<mn<<" "<<mx<<endl;
        
    }
    return 0;
}