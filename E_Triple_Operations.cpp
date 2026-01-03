#include <bits/stdc++.h>
using namespace std;

#define int long long


int32_t main(){
    vector<int>v;
    int x = 1;
    v.push_back(x);
    while(x<1e12){
        x = x*3;
        v.push_back(x);
    }
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a>>b;
        int sum=0;
        int z = 0;
        int ct=0;
        for(int i=a ; i<=b ; ){
            // int ct=0;
            int x = i;
            // while(x!=0){
            //     x = x/3;
            //     ct++;
            // }
            // sum+=ct;
            auto it = lower_bound(v.begin(),v.end(),x);
            int val = *it;
            int idx = it-v.begin();
            if(val!=i){
                int y = min(b-i+1,val-i);
                sum+=(y)*(idx);
                i+=(val-i);
            }
            else{
                sum+=(idx+1);
                i++;
            }
            // if(ct==0) z = sum;
            ct++;
        }
        
        auto it = lower_bound(v.begin(),v.end(),a);
        int val = *it;
        int idx = it-v.begin();
        if(val!=a){
            // int y = min(b-i+1,val-i);
            sum+=(idx);
            // i+=(val-i);
        }
        else{
            sum+=(idx+1);
            // i++;
        }

        cout<<sum<<endl;
        
    }
    return 0;
}




