#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        if(k%2!=0){
            for(int i=0 ; i<n ; i++){
                if(arr[i]%2==0){
                    cout<<k*(k-1)+arr[i]<<" ";
                }
                else cout<<k*k+arr[i]<<" ";
            }
        }else{
            // k = k+1;
            for(int i=0 ; i<n ; i++){
                cout<<arr[i] + k*
            }
        }
        cout<<endl;
        
    }
    return 0;
}