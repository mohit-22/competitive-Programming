#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,j,k;
        cin >> n>>j>>k;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int x = arr[j-1];
        sort(arr,arr+n);
        int mx = arr[n-1];
        if(k==1 && mx==x){
            cout<<"YES"<<endl;
            continue;
        }

        if(k>=2){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;

        
        
    }
    return 0;
}