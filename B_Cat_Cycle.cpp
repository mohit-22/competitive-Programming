#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;

        if(n%2==0){
            if(k%n==0){
                cout<<n<<endl;
            }else{
                cout<<k%n<<endl;
            }
        }
        else{
            int x = n/2;
            int y = n*x;
            int m = k/n;
            k = k%y;
            int l = k%n;
               
            if(l==0){
                cout<<2*m<<endl;
            }
            else{
                x = n/2-m;
                if(l<=x){
                    cout<<2*m+l<<endl;
                }
                else if(x<l && l<=2*x){
                    cout<<2*m+l+1<<endl;    
                }
                else if(l>2*x){
                    int a = n-2*x;
                    l = l-2*x;
                    int z = a/2;
                    if(l<=z){
                        cout<<l<<endl;
                    }
                    else{
                        cout<<l+1<<endl;
                    }
                }
            }

        }

        
    }
    return 0;
}