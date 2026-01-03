#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x,n;
        cin >>x>>n;

        if(x%2==0){
            if(n%4==0) cout<<x<<endl;
            else if(n%4==3) cout<<x+n+1<<endl;
            else if(n%4==2) cout<<x+1<<endl;
            else if(n%4==1) cout<<x-n<<endl;
        }
        else{
            if(n%4==0) cout<<x<<endl;
            else if(n%4==3) cout<<x-(n+1)<<endl;
            else if(n%4==2) cout<<x-1<<endl;
            else if(n%4==1) cout<<x+n<<endl;
        }
        
    }
    return 0;
}