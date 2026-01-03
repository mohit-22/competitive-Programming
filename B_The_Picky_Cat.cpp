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
        for(int i=0  ;i<n ; i++){
            cin>>arr[i];
        }
        int x = (n-1)/2;
        int y = n-1-x;
        int ct=0;
        int ct1=0;
        for(int i=1 ; i<n ; i++){
            if(abs(arr[i])>=arr[0]){
                ct++;
            }
            if(abs(arr[i])>=(-arr[0])){
                ct1++;
            }
        }
        if(ct>=y || ct1>=y){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}