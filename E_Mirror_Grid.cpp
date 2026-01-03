#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<char>>v(n,vector<char>(n));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                cin>>v[i][j];
            }
        }
        int ans=0;
        for(int i=0; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                int i1 = i,j1=j;
                int i2=j,j2=n-i-1;
                int i3=n-i-1,j3=n-j-1;
                int i4=n-j-1,j4=i;

                int ones = (v[i1][j1]-'0')+(v[i2][j2]-'0')+(v[i3][j3]-'0')+(v[i4][j4]-'0');
                if(ones<=4-ones){
                    v[i1][j1]='1';
                    v[i2][j2]='1';
                    v[i3][j3]='1';
                    v[i4][j4]='1';
                }
                else {
                    v[i1][j1]='0';
                    v[i2][j2]='0';
                    v[i3][j3]='0';
                    v[i4][j4]='0';
                }
                ans+=min(4-ones,ones);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}