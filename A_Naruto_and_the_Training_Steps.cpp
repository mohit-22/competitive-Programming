#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
ios_base::sync_with_stdio(false); cin.tie(NULL);    
    int t;
    cin>>t;
    while(t--){
    int n;
    cin >> n;
    int sum=0;
    for(int i=1 ; i<n; i++){
        sum+=i;
    }
    sum+=1;
    int s=sum;
    for(int i=1 ; i<n ; i++){
        sum+=s+i;
    }
    cout<<sum<<endl;
    }
        
    
    return 0;
}