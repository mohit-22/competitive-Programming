#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n>>s;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        if((s<=arr[0] && s<=arr[n-1]) || s>=arr[0] && s>=arr[n-1]){
            if(s<=arr[0] && s<=arr[n-1]){
                cout<<abs(arr[n-1]-s)<<endl;
            }else{
                cout<<abs(arr[0]-s)<<endl;
            }
        }
        else{
            int m1 = abs(s-arr[0]);
        int m2 = abs(s-arr[n-1]);

        int y = min(m1,m2);
        if(y==m1){
            cout<<2*y+m2<<endl;
        }else{
            cout<<2*y+m1<<endl;
        }
        }
        


        
    }
    return 0;
}