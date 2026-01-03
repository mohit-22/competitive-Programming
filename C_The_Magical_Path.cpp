#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int b,h;
        cin >> b>>h;

        if(b==1){
            cout<<0<<endl;
            continue;
        }
        long long sum = 0;
        if(b>2) sum+=b-2;
        for(int i=2 ; i<=h ; i++){
            int x = pow(b,i);
            int y = x-2;
            
             if(y>0){
                sum += 2*b-2;
                y = y - ((2*b)-2);
                if(y>0)sum += i*y;
             } 
             
        }

        cout<<sum<<endl;
        
    }
    return 0;
}