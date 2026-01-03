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
        int sum=0;
        int neg = 0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            sum+=abs(arr[i]);
            if(arr[i]<0) neg++;
        }
        // int ct=0;
        // for(int i=0 ; i<n-1 ; i++){
        //     if(arr[i]<0 && arr[i+1]<0){
        //         ct++;
        //         i++;
        //     }
        // }
        // int y = neg-2*ct;
        int y = neg%2;
        int brr[n];
        for(int i=0 ; i<n ; i++){
            brr[i] = abs(arr[i]);
        }
        sort(brr,brr+n);
        for(int i=0 ; i<y ; i++){
            sum-=2*brr[i];
        }
        cout<<sum<<endl;


    }
    return 0;
}