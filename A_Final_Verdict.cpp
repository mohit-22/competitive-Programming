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
        int sum=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        if((double)sum/n==x)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        
    }
    return 0;
}