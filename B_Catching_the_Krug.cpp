#include <bits/stdc++.h>
using namespace std;

using ll = long long;


bool CD_Square(ll n,ll rK,ll cK,ll rD,ll cD,ll t){

    ll r_low = max(0LL, rK - t);
    ll r_high = min(n, rK + t);
    ll cl_glob = max(0LL, cK - t);
    ll ch_glob = min(n, cK + t);

    ll rd_l=rD-t;
    ll rd_h=rD+t;
    ll cd_l=cD-t;
    ll cd_h=cD+t;

    return(r_low>=rd_l)&&(r_high<=rd_h)&&(cl_glob>=cd_l)&&(ch_glob<=cd_h);
}

int main(){

    ll tt;
    cin>>tt;
    while(tt--){

        ll n,rK,cK,rD,cD;
        cin>>n>>rK>>cK>>rD>>cD;

        ll low=0;
        ll hi=2*n;

        while(low<hi){
            ll mid=low+(hi-low)/2;
            if(CD_Square(n,rK,cK,rD,cD,mid)==true){
                hi=mid;
            }else{
                low=mid+1;
            }
        }
        
        ll ans=-1;
        if(low<=2*n&&CD_Square(n,rK,cK,rD,cD,low)==true){
            ans=low;
        }
        cout<<ans<<endl;
    }
    return 0;
}
