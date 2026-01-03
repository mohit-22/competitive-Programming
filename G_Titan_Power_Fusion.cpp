#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v;
        for(int i=1 ; i<n ; i++){
            int x = (i*(i+1))/2;
            if(x>n) break;
            v.push_back(x);
        }
        int i=0 ;
        int j=v.size()-1;
        bool flag=false;
        while(i<=j){
            if(v[i]+v[j]==n){
                flag=true;
                break;
            }
            else if(v[i]+v[j]>n){
                j--;
            }
            else i++;
        }
        if(flag==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}