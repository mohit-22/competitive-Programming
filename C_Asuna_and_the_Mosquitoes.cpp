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
        int ct=0;
        int s=0;
        int mx = INT_MIN;
        for(int i=0 ; i<n ;i++){
             cin>>arr[i];
             s+=arr[i];
             if(arr[i]%2!=0) ct++;
             mx = max(mx,arr[i]);
        }
        if(ct==n || ct==0) cout<<mx<<endl;
        else 
        cout<<s-(ct-1)<<endl;
        
    }
    return 0;
}
