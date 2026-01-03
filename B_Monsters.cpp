// // #include <bits/stdc++.h>
// // using namespace std;

// // #define int long long

// // int32_t main(){
// //     int t;
// //     cin >> t;
// //     while(t--){
// //         int n,k;
// //         cin >> n>>k;
// //         int arr[n];
// //         for(int i=0 ; i<n ; i++){
// //             cin>>arr[i];
// //         }
// //         map<int,int>m;
// //         for(int i=0 ; i<n ; i++){
// //             m[i+1] = arr[i];
// //         }
// //         vector<int>ans;
// //         while(ans.size()<n){
// //             auto largest = max_element(m.begin(), m.end(),[](const auto &a, const auto &b) { return a.second < b.second; });
// //             largest->second = largest->second - k;
// //             if(largest->second<=0){
// //                 ans.push_back(largest->first);
// //                 m.erase(largest->first);
// //             }
// //         }

// //         for(int i=0 ; i<ans.size() ; i++){
// //             cout<<ans[i]<<" ";
// //         }
// //         cout<<endl;
        
// //     }
// //     return 0;
// // }


// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n>>k;
//         int arr[n];
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//         }
//         for(int i=0 ; i<n ; i++){
//             arr[i] = (arr[i]%k==0 ? k : arr[i]%k);
//         }

//         // map<int,int>m;
//         // for(int i=0 ; i<n ; i++){
//         //     m[i+1] = arr[i];
//         // }
//         // vector<int>v;
//         // while(v.size()<n){
//         //     auto largest = max_element(m.begin(),m.end(),[](const auto &a , const auto &b) {return a.second < b.second ;});  // sort in assending order
//         //     v.push_back(largest->first);
//         //     m.erase(largest->first);
//         // }

//         // for(int i=0 ; i<v.size() ; i++){
//         //     cout<<v[i]<<" ";
//         // }
//         // cout<<endl;


//         vector<pair<int,int>>v;
//         for(int i=0 ; i<n ; i++){
//             v.push_back({i+1,arr[i]});
//         }

//         stable_sort(v.begin(),v.end(),[](const auto &a, const auto &b) {return a.second > b.second ;});  // sort in decending order

//         for(auto &p : v){
//             cout<<p.first<<" ";
//         }
//         cout<<endl;
        
        
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
        int arr[n];
        for(int i=0; i<n ; i++){
            cin>>arr[i];
            if(arr[i]%k!=0){
                arr[i] = arr[i]%k;
            }
            else arr[i] = k;
        }
        vector<pair<int,int>>v;
        for(int i=0 ; i<n ; i++){
            v.push_back({arr[i],i+1});
        }
        sort(v.begin(), v.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
            if (a.first == b.first)
                return a.second < b.second; // ascending second
            return a.first > b.first;       // descending first
        });

        for(int i=0 ; i<n ; i++){
            cout<<v[i].second<<" ";
        }
        cout<<endl;
    }
    return 0;
}








