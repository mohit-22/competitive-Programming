#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int l1,b1,l2,b2,l3,b3;
        cin >> l1>>b1>>l2>>b2>>l3>>b3;

       

       int a1=l1*b1;
       int a2 = l2*b2;
       int a3= l3*b3;

       int a = a1+a2+a3;

       int root = sqrt(a);
       if(root*root==a){
        cout<<"YES"<<endl;
       }else cout<<"NO"<<endl;

        
        
    }
    return 0;
}