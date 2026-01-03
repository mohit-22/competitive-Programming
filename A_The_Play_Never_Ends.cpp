// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         if(n==1 || n%4==0) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
   int n=500;
 
   vector<int>v;
   for(int j=1 ; j<=n ; j++){
   int sum=0;
   for(int i=1 ; i<=j ; i++){
    sum+=i;
   }
   v.push_back(sum);
}
   for(int i=0 ; i<v.size() ; i++){
    cout<<v[i]<<" ";
   }
    return 0;
}