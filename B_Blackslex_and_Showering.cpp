#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n],brr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
        }
        vector<int>v;
        int ma=0,mb=0;
        for(int i=0  ;i<n ; i++){
            if(arr[i]==brr[i]) v.push_back(arr[i]);
            else if(arr[i]>brr[i]) ma+=arr[i];
            else mb+=brr[i];
        }

        sort(v.begin(),v.end());
        int ct0=0,ct1=0,ct11=0;
        for(int i=0 ; i<v.size() ; i++){
            if(v[i]==-1) ct11++;
            else if(v[i]==0) ct0++;
            else ct1++;
        }
        if(mb>ma){
            // mb = min(mb-ma,ct11);
            if(mb-ma>=ct11){
                mb-=ct11;
                ct11=0;
            }else{
                ct11-=(mb-ma);
                mb-=(mb-ma);
                
            }

        }
        else{
            if(ma-mb>=ct11){
                ma-=ct11;
                ct11=0;
            }else{
                ct11-=(ma-mb);
                ma-=(ma-mb);
                
            }
        }
        int q = ct11/2;
        int r = ct11%2;
        if(q>=1){
            ma-=q;
            mb-=q;
        }
        if(r==1){
            // ma-=1;
            if(mb>ma) mb-=1;
            else ma-=1;
        }
        


        if(mb>ma){
            // mb = min(mb-ma,ct11);
            if(mb-ma>=ct1){
                ma+=ct1;
                ct1=0;
            }else{
                ct1-=(mb-ma);
                ma+=(mb-ma);
                
            }

        }
        else{
            if(ma-mb>=ct1){
                mb+=ct1;
                ct1=0;
            }else{
                ct1-=(ma-mb);
                mb+=(ma-mb);
                
            }
        }
        int q1 = ct1/2;
        int r1 = ct1%2;
        if(q1>=1){
            ma+=q1;
            mb+=q1;
        }
        if(r1==1){
            if(mb>=ma) ma+=1;
            else mb+=1;
        }
        cout<<min(ma,mb)<<endl;

    }
    return 0;
}