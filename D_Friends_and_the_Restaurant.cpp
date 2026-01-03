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
        int brr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int ct1=0;
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
            brr[i] = brr[i]-arr[i];
            if(brr[i]>=0) ct1++;
        }
        ct1 = ct1/2;

        sort(brr,brr+n);
        int i=0;
        int j=n-1;
        int ct2=0;
        while(i<j){
            if(brr[i]+brr[j]>=0){
                ct2++;
                i++;
                j--;
            }
            else i++;
        }
        cout<<max(ct1,ct2)<<endl;

    }
    return 0;
}