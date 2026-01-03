#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,n;
        cin >> a>>b>>n;

        int arr[n];
        for(int i = 0; i<n ; i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int sum = b;
        for(int i = 0; i<n ; i++){
            if(arr[i]<a)sum+=arr[i];
        }
        for(int i = 0 ;i<n ; i++){
            if(arr[i]>=a) sum+=(a-1);
        }

        cout<<sum<<endl;

    }
    return 0;
}