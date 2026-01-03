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
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int brr[n];
        for(int i=0 ; i<n ; i++){
            brr[i] = arr[i];
        }
        sort(brr,brr+n);

        if(brr[0]==brr[n-1]){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        int j=-1;
        for(int i=0 ; i<n ; i++){
            if(arr[i]==brr[n-1]){
                cout<<2<<" ";
                j=i;
                break;
            }
            else{
                cout<<1<<" ";
            }
        }
        for(int i=j+1 ; i<n ; i++){
            cout<<1<<" ";
        }
        cout<<endl;



    }
    return 0;
}