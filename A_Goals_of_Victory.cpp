#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n-1];
        int pos=0;
        int neg=0;
        for(int i = 0 ; i<n-1 ; i++){
            int x;
            cin>>x;
            if(x>=0) pos+=x;
            else neg+=x;
        }
        cout<<-(pos+neg)<<endl;
    }
    return 0;
}
