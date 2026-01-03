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
        for(int i = 0 ; i<n ; i++){
            cin>>arr[i];
        }
        for(int i = 0 ; i<n ; i++){
            arr[i] = abs(arr[i]-i-1);
        }
        int result = arr[0];
        for(int i = 1 ; i<n ; i++){
            result = __gcd(result,arr[i]);
        }
        cout<<result<<endl;
    
       

    }
    return 0;
}