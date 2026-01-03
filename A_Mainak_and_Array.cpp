#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==0){
            cout<<0<<endl;
            continue;
        }
        int arr[n];
        int mn=INT_MAX;
        int mx= INT_MIN;
        for(int i = 0 ; i<n ; i++){
            cin>>arr[i];
            mx = max(arr[i],mx);
            mn = min(arr[i],mn); 
        }
        int ma = arr[n-1] - mn;
        int mr = mx-arr[0];
        mr = max(ma,mr);
        
        if(arr[0]==mn) cout<<mx-mn<<endl;
        else{
            int mx2 = INT_MIN;
            for(int i = 0 ; i<n-1 ; i++){
                mx2 = max(mx2,abs(arr[i]-arr[i+1]));
            }
            cout<<max(mr,mx2)<<endl;
            
        }
    }
    return 0;
}







