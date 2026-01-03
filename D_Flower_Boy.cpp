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
        for(int i=0  ;i<n ; i++){
            cin>>arr[i];
        }
        for(int i=0 ; i<m ; i++){
            cin>>brr[i];
        }

        int p=0;
        int ct=0;
        int val=0;
        for(int i=0 ; i<m ; i++){
            bool flag = false;
            for(int j=p ; j<n ; j++){
                if(brr[i]<=arr[j] ){
                    p = j+1;
                    flag = true;
                    break;
                }
            }

            if(flag==false){
                val = brr[i];
                ct++;
            }
            if(ct>=2) break;
        }

        if(ct==0) cout<<0<<endl;
        else if(ct>=2) cout<<-1<<endl;
        else {
            cout<<val<<endl;
        }
        
    }
    return 0;
}