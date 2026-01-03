#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int w,h,a,b;
        cin >> w>>h>>a>>b;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        int x=x1+a;
        int y=y1+b;
        if(x<=x2){
            if((x2-x)%a==0){
                cout<<"YES"<<endl;
            }
            else if(y2-y>=1){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else{
            
            if((y2-y)%b==0){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        
    }
    return 0;
}