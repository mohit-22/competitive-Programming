

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0 ; i<n ; i++){
            cin>>v[i];
        }
        int x,y;
        int numerator = 2 * v[0] - v[1];
        int denominator = 2 * n - (n - 1);

        if (denominator == 0 || numerator % denominator != 0) {
            cout << "NO" << endl;
            continue;
        }

        y = numerator / denominator;
        if (y < 0) {
            cout << "NO" << endl;
            continue;
        }

        x = v[0]-n*y;
        if(x<0){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag = true;
        for(int i=2 ; i<n ; i++){
            if(v[i]!=x*(i+1)+y*(n-i)){
                flag=false;
                break;
            }
        }
        if(!flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}