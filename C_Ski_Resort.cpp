// ---------method 1----------

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k,q;
//         cin >> n>>k>>q;
//         int arr[n];
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//         }
//         int ct=0;
//         int sum=0;
//         int x=0;
//         bool flag = false;
//         for(int i=0 ; i<n ; i++){
//             if(arr[i]<=q){
//                 ct++;
//                 flag=false;
//             }
//             else{
//                 if(ct>=k){
//                     x = ct-k+1;
//                     sum+= (x*(x+1))/2;
//                 }
//                 ct=0;
//                 flag=true;
                
//             }
//         }
//         if(flag==false){
//             if(ct>=k) {
//                 x = ct-k+1;
//                 sum+= (x*(x+1))/2;
//             }
//         }
//         cout<<sum<<endl;
        
//     }
//     return 0;
// }


// //-------method 2-------
// #include <bits/stdc++.h>
// using namespace std;
 
// #define int long long
 
 
 
// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k,q;
//         cin >> n>>k>>q;
//         int arr[n];
//         int x=k;
//         int ct=0;
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//             if(arr[i]<=q) ct++;
//         }
//         unordered_map<int,int>m;
//         for(int i=0 ; i<n ; i++){
//            if(arr[i]<=q) m[i+1] = arr[i];
//         }
//         int ans=0;
//         for(int i=1 ; i<=n ; ){
//             bool flag = false;
//             int ct1=i;
//             while(i<=n && m.find(i)!=m.end()){
//                 i++;
//                 flag=true;
//             }
//             if(flag==true){
//                 while(k<=i-1-ct1+1){
//                     ans += (i-1)-ct1+1-k+1;
//                     k++; 
//                 }
//             }
//             i++;
//             k=x;
//         }
//         cout<<ans<<endl;
 
 
//     }
//     return 0;
// }
















#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,q;
        cin >> n>>k>>q;
        int arr[n];

        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            
        }
        int j=0;
        int i=0;

        int ans=0;
        while(j<n){
            if(arr[j]>q){
                if(j-i>=k){
                    int x = j-i-k+1;
                    ans+=((x)*(x+1))/2;
    
                }
                i=j+1;
                
            }
            j++;
        }
        if(i!=n && j-i>=k){
            int x = j-i-k+1;
            ans+=((x)*(x+1))/2;
          
        }
        cout<<ans<<endl;
        // cout<<i<<endl;
        
    }
    return 0;
}