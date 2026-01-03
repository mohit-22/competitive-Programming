#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n>>m>>k;
        int x=0;
        int y=0;
        int ct1 = (n*m)/k;
        int ct11=ct1;
        int ct2 = (n*m)/k;
        int ct22 = ct2;
        if((n*m)%2==0){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<m ; j++){
                    if((i+j)%2==0){
                        cout<<1+x<<" ";
                        x++;
                    }
                    else{
                        cout<<k-y<<" ";
                        ct22--;
                        if(ct22==0){
                            ct22 = ct2;
                            y-=1;
                        }

                    }
                }
                cout<<endl;
            }
            // cout<<endl;
        }
        else{
            for(int i=0 ; i<n-1 ; i++){
                for(int j=0 ; j<m ; j++){
                    if((i+j)%2==0){
                        cout<<1+x<<" ";
                        ct11--;
                        if(ct11==0){
                            ct11 = ct1;
                            x+=1;
                        }
                    }
                    else {
                        cout<<k-y<<" ";
                        ct22--;
                        if(ct22==0){
                            ct22 = ct2;
                            y-=1;
                        }
                    }
                }
                cout<<endl;
            }
            for(int i=0 ; i<m-1 ; i++){
                if(i%2==0) cout<<1<<" ";
                else cout<<k<<" ";
            
            }
            cout<<2<<" ";
            // cout<<endl;
        }
        
    }
    return 0;
}