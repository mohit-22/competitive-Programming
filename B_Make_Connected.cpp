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
        bool flag = true;
        for(int i=0 ; i<n ; i++){
            int ct=0;
            for(int j=0 ; j<n ; j++){
                if(v[i][j]=='#') ct++;
                else ct=0;
                if(ct==3){
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
        }
        for(int i=0 ; i<n ; i++){
            int ct=0;
            for(int j=0 ; j<n ; j++){
                if(v[j][i]=='#') ct++;
                else ct=0;
                if(ct==3){
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }

    
        // int empty_rows = 0, empty_cols = 0;
        // for(int i=0; i<n ; i++){
        //     int groups = 0;
        //     int ct=0;
        //     for(int j=0; j<n; j++){
        //         if(v[i][j]=='#' && (j==0 || v[i][j-1]=='.')){
        //             groups++;
        //         }
                    
        //         if(v[i][j]=='#') ct++;    
        //     }
        //     if(ct == 0) { empty_rows++; continue; }
        //     if(groups > 1){
        //          flag = false;
        //          break;
        //     }
            
        // }

        // for(int j=0; j<n ; j++){
        //     int groups = 0;
        //     int ct=0;
        //     for(int i=0; i<n; i++){
        //         if(v[i][j]=='#' && (i==0 || v[i-1][j]=='.')){
        //             groups++;
        //         }
                    
        //         if(v[i][j]=='#') ct++;     
        //     }
        //     if(ct == 0) { empty_rows++; continue; }
        //     if(groups > 1){
        //          flag = false;
        //          break;
        //     }
        // }

        // if(!flag){
        //     cout << "NO\n";
        //     continue;
        // }

        // int total_black = 0;
        // for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(v[i][j] == '#') total_black++;
        // if(total_black == 0){
        //     cout << "YES\n";
        //     continue;
        // }

        // // cout << (flag ? "YES\n" : "NO\n");
        // if(empty_rows == empty_cols) cout << "YES\n";
        // else cout << "NO\n";
        bool flag1 = true;
        int empty_rows = 0, empty_cols = 0;
        for(int i=0;i<n;i++){
            int first = -1, last = -1, cnt = 0;
            for(int j=0;j<n;j++){
                if(v[i][j] == '#'){
                    if(first == -1) first = j;
                    last = j;
                    cnt++;
                }
            }
            if(cnt == 0) { empty_rows++; continue; }
            if(last - first + 1 != cnt) { flag1 = false; break; }
        }
        for(int j=0;j<n && flag1;j++){
            int first = -1, last = -1, cnt = 0;
            for(int i=0;i<n;i++){
                if(v[i][j] == '#'){
                    if(first == -1) first = i;
                    last = i;
                    cnt++;
                }
            }
            if(cnt == 0) { empty_cols++; continue; }
            if(last - first + 1 != cnt) { flag1 = false; break; }
        }
        if(!flag1){
            cout << "NO\n";
            continue;
        }

        int total_black = 0;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(v[i][j] == '#') total_black++;
        if(total_black == 0){
            cout << "YES\n";
            continue;
        }

        if(empty_rows == empty_cols) cout << "YES\n";
        else cout << "NO\n";



        
    }
    return 0;
}













