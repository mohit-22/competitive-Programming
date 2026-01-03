#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        int arr[n][m];
        
        for (int i = 0; i < n; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < m; j++) {
                arr[i][j] = line[j] - '0';  
            }
        }
        int ct=0;
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=m-1 ; j>=0 ; j--){
                ct=0;
                if(arr[i][j]==1){
                    for(int k=0 ; k<j ; k++){
                        if(arr[i][k]==0){
                            ct++;
                            break;
                        }
                    }
                    for(int l=0 ; l<i ; l++){
                        if(arr[l][j]==0){
                            ct++;
                            break;
                            
                        }
                    }                   
                }
                if(ct==2) break;
            }
            if(ct==2) break;
        }

        if(ct==2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

        
        
    }
    return 0;
}