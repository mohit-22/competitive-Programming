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
        int sum=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        sort(arr,arr+n);

        if(arr[n-1]-arr[0]-1>k){
            cout<<"Jerry"<<endl;
            continue;
        }

        if(arr[n-1]-arr[0]-1==k){
            if(arr[n-2]==arr[n-1]){
                cout<<"Jerry"<<endl;
                continue;
            }

            if((sum-1)%2==0) cout<<"Tom"<<endl;
            else cout<<"Jerry"<<endl;
            continue;
        }

        if(sum%2!=0) cout<<"Tom"<<endl;
        else cout<<"Jerry"<<endl;

        
        
    }
    return 0;
}