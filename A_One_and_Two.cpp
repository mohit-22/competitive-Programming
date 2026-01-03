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
        int twoo = 0;
        for(int i = 0 ; i<n ; i++){
            cin>>arr[i];
            if(arr[i]==2) twoo++;
        }
        if(twoo%2!=0) cout<<-1<<endl;
        else {
            int ct=0;
            int k;
            for(int i = 0 ;i<n ; i++){
                if(arr[i]==2) ct++;
                if(ct==twoo/2){
                    k=i+1;
                    break;
                } 
            }
            cout<<k<<endl;
        }


    }
    return 0;
}