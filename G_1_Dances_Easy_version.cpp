#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        int arr[n];
        int brr[n];
        arr[0] = 1;
        for(int i=1 ; i<n ; i++){
            cin>>arr[i];
        }
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
        }
        sort(arr,arr+n);
        sort(brr,brr+n);
        int i=0,j=0;
        while(j<n){
            if(arr[i]<brr[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        cout<<n-i<<endl;

        
    }
    return 0;
}