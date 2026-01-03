#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isdivide(int n){
    int temp = n;
    while(n>0){
        int num = n%10;
        n = n/10;
        if(num!=0 && temp%num!=0){
            return false;
        }
    }
    return true;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        while(isdivide(n)==false){
            n++;
        }
        cout<<n<<endl;
    }
    return 0;
}