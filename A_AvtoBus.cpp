#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2!=0 || n<4) cout<<-1<<endl;
        else if(n==4 || n==6) cout<<1<<" "<<1<<endl;
        else{
           if(n%4==2 && n%6==2 ) cout<<(n/6)+1<<" "<<n/4<<endl;
           else if(n%4==0 && n%6==4) cout<<(n/6)+1<<" "<<n/4<<endl;
           else if(n%4==2 && n%6==0) cout<<n/6<<" "<<n/4<<endl;
           else if(n%4==0 && n%6==2) cout<<(n/6)+1<<" "<<n/4<<endl;
           else if(n%4==2 && n%6==4) cout<<(n/6)+1<<" "<<n/4<<endl;
           else if(n%4==0 && n%6==0) cout<<(n/6)<<" "<<n/4<<endl;
            
        }
    }
    return 0;
}