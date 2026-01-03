#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool flag = false;

        int l=0;
        int h=n-1;
        while(l<=h){
            int i = l + (h-l)/2;
            int x = i ^ n;
            if(n+i > x && i+x > n && n+x > i){
                flag = true;
                cout<<i<<endl; 
                break;
            }
            else{
                l = i+1;
            }
        }
        // for(int i=n ; i>0 ; i--){
        //     int x = i ^ n;
        //     if(n+i > x && i+x > n && n+x > i){
        //         flag = true;
        //         cout<<i<<endl; 
        //         break;
        //     }
        // }
        
        if(flag==false) cout<<-1<<endl;
        
    }
    return 0;
}