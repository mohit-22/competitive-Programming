#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        vector<vector<int>>v(n,vector<int>(n));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                cin>>v[i][j];
            }
        }
        if(n==1){
            cout<<"YES"<<endl;
            continue;
        }
        int ct=0;
        for(int i=0 ; i<n/2; i++){
            for(int j=0 ; j<n ; j++){
                if(v[n-i-1][n-j-1]!=v[i][j]){
                    ct++;
                }
            }
        }
        if(n%2==0){
            if(ct<=k && (k-ct)%2==0){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else{
            int x = (n/2);
            for(int i=0 ; i<n/2 ; i++){
                if(v[x][i]!=v[x][n-i-1]){
                    ct++;
                }
            }
            if(ct<=k){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        

    }
    return 0;
}