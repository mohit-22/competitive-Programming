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
        bool flag = false;
        int x=-1;
        for(int i=1 ; i<n-1 ; i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                x=i;
                flag=true;
                break;
            }
        }
        if(flag==false) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<x<<" "<<x+1<<" "<<x+2<<endl;
        }
    }
    return 0;
}