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
        int brr[k];
        for(int i=0 ; i<k; i++){
            cin>>brr[i];
        }
        sort(arr,arr+n,greater<int>());
        sort(brr,brr+k);

        int i=0;
        int sum=0;
        for(int j=0 ; j<k ; j++){
            if(brr[j]==1) i++;
            else{
                if(brr[j]<=n-i){
                    int ct=1;
                    while(ct<brr[j]){
                        sum+=arr[i];
                        i++;
                        ct++;
                    }
                    i++;
                }
                else{
                    while(i<n){
                        sum+=arr[i];
                        i++;
                    }
                }
            }
        }
        // cout<<i<<endl;
        while(i<n){
            sum+=arr[i];
            i++;
        }
        cout<<sum<<endl;
        
    }
    return 0;
}