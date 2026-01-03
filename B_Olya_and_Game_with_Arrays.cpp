// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         vector<int>smallest;
//         vector<int>secondsmallest;

//         for(int k=1 ; k<=n ; k++){
//             int m;
//             cin>>m;
//             vector<int>arr(m);
//             for(int i =0 ; i<m ; i++){
//                 cin>>arr[i];
//             }
//             sort(arr.begin(),arr.end());
//             smallest.push_back(arr[0]);
//             secondsmallest.push_back(arr[1]);

//             arr.clear();
//         }
//         sort(secondsmallest.begin(),secondsmallest.end());
//         int ans=0;
//         for(int i=1 ; i<secondsmallest.size() ; i++){
//             ans+=secondsmallest[i];
//         }
//         smallest.push_back(secondsmallest[0]);
//         sort(smallest.begin(),smallest.end());
//         ans+=smallest[0];
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
        int n;
        cin >> n;
        vector<int>small;
        vector<int>large;
        for(int i=0 ; i<n ; i++){
            int m;
            cin>>m;
            vector<int>arr(m);
            for(int i=0 ;i<m ; i++){
                cin>>arr[i];
            }
            sort(arr.begin(),arr.end());
            small.push_back(min(arr[0],arr[1]));
            large.push_back(max(arr[0],arr[1]));
        }

        sort(small.begin(),small.end());
        sort(large.begin(),large.end(),greater<int>());
        int sum=0;
        for(int i=0 ; i<n-1 ; i++){
            sum+=large[i];
        }
        sum+=small[0];

        cout<<sum<<endl;
    }
    return 0;
}