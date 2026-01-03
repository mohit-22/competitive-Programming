// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int count(int x , int arr[] , int n){
//     int ct=0;
//     vector<int>v;
//     // set<int>s;
//     v.push_back(arr[x]);
//     for(int i=x ; i<n ; i+=x+1 ){
//         // s.insert(arr[i]);
//         if(arr[i]!=arr[x]) v.push_back(arr[i]);
//     }

//     if(v.size()>2){
//         ct = INT_MAX;
//     }
//     else ct = x;
//     v.clear();
//     int y = INT_MAX;
//     if(x>=2 && arr[x-(x/2)-1]!=arr[x] && v.size()==1){
//         y = max(x-(x/2)-1,1LL);
//     }
//     return min(ct,y);
// }

// int32_t main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,k;
//         cin >> n>>k;
//         int arr[n];
//         for(int i=0 ; i<n; i++){
//             cin>>arr[i];
//         }
//         int mn = INT_MAX; 
//         for(int i=0 ; i<n ; i++){
//             int x = count(i,arr,n);
//             mn = min(x,mn);
//         }
//         cout<<mn<<endl;
        
        
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
        vector<vector<int>>v(k+1);
        map<int,int>mp;
        for(int i=0 ; i<n ; i++){
            int x;
            cin>>x;
            v[x].push_back(i+1-mp[x]-1);
            mp[x] = i+1;
        }
        for(auto it:mp){
            v[it.first].push_back(n-it.second);
        }
        for(int i=0 ; i<k+1 ; i++){
            sort(v[i].begin(),v[i].end());
        }
        for(int i=1 ; i<k+1 ; i++){
            if(!v[i].empty()) {
                v[i][v[i].size()-1] = v[i][v[i].size()-1]/2;
            }
        }
        for(int i=0 ; i<k+1 ; i++){
            sort(v[i].begin(),v[i].end());
        }
        int mn = INT_MAX;
        for(int i=1 ; i<k+1 ; i++){
           if(!v[i].empty()) {
                mn = min(mn, v[i][v[i].size()-1]);
            }
        }
        cout<<mn<<endl;
        
    }
    return 0;
}