#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int tt=n*n;
        if(k==tt-1){
            cout<<"NO"<<endl;
            continue;
        }
        if(n==2){
            if(k==3){
                cout<<"NO"<<endl;
            } else {
                cout<<"YES"<<endl;
                char grid[2][2];
                if(k==0){ 
                    grid[0][0]='R'; grid[0][1]='D'; grid[1][0]='U'; grid[1][1]='L'; 
                }
                else if(k==1){ 
                    grid[0][0]='U'; grid[0][1]='D'; grid[1][0]='R'; grid[1][1]='U';
                 }
                else if(k==2){ 
                    grid[0][0]='D'; grid[0][1]='U'; grid[1][0]='U'; grid[1][1]='U'; 
                }
                else { 
                    grid[0][0]='U'; grid[0][1]='U'; grid[1][0]='U'; grid[1][1]='U'; 
                }
                for(int i=0;i<2;i++){
                    for(int j=0;j<2;j++) cout<<grid[i][j];
                    cout<<endl;
                }
            }
            continue;
        }
        cout<<"YES"<<endl;
        vector<int> a(n,0);
        int rem11=k;
        int column=0;

        int full=rem11/n;

        if(full>n) full=n;

        int filled = 0;
        while(filled < full && column < n){
            a[column] = n;
            ++column;
            ++filled;
        }
        rem11-=full*n;

        if(column<n&&rem11>0){
            
            int r=rem11;
            if(r == n-1){
                if(column+1 < n){
                    a[column] = n-2;
                    a[column+1] = 1;
                    column+= 2;
                } 
                else{
                    a[column++] = r;
                }
            } 
            else{
                a[column++] = r;
            }
        }
        vector<string> grridd(n,string(n,'D'));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<a[j]||i==n-1) grridd[i][j]='U';
                else grridd[i][j]='D';
            }
        }
        for(int i=0;i<n;i++){
            cout<<grridd[i]<<endl;
        }
    }
    return 0;
}
