// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// bool isprime(int n){
//     bool flag = true;
//     for(int i=2 ; i<=sqrt(n) ; i++){
//         if(n%i==0){
//             flag = false;
//             break;
//         }
//     }
//     return flag;
// }

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n>>k;
//         bool flag = isprime(n);
//         if(k>=n){
//             cout<<1<<endl;
//         }
//         else if(flag){ 
//             cout<<n<<endl;
//         }
//         else{
//             priority_queue<int> pq;
//             for(int i=1 ; i<=sqrt(n) ; i++){
//                 if(n%i==0){
//                     pq.push(i);
//                 }
//             }
//             priority_queue<int> pq3;
//             priority_queue<int> pq2;
//             while (!pq.empty()) {
//                 int it = pq.top();  
//                 pq.pop();

//                 if (n % it == 0) {
//                     pq2.push(n / it);
//                 }
//             }
//             while(!pq2.empty()){
//                 pq.push (pq2.top());
//                 pq2.pop();
//             }
//             while(!pq.empty()){
//                 int it = pq.top();
//                 pq.pop();

//                 if(it<=k){
//                     cout<<n/it<<endl;
//                     break;
//                 }
//             }
//         }
        
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
        int n,k;
        cin >> n>>k;
        vector<int>v;
        for(int i=1 ; i<=sqrt(n) ; i++){
            if(n%i==0){
                v.push_back(i);
                v.push_back(n/i);
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans=0;
        for(int i=0 ; i<v.size() ; i++){
            if(v[i]<=k){
                ans=n/v[i];
                break;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}   