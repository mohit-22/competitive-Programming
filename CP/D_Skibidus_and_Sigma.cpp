    #include <bits/stdc++.h>
    using namespace std;

    #define int long long

    int32_t main(){
        int t;
        cin >> t;
        while(t--){
            int n,m;
            cin >> n>>m;
            vector<vector<int>>v(n,vector<int>(m));
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<m ; j++){
                    cin>>v[i][j];
                }
            }
            vector<pair<int,int>>vp;
            for(int i=0 ; i<n ; i++){
                int sum=0;
                for(int j=0 ; j<m ; j++){
                    sum+=v[i][j];
                }
                vp.push_back({sum,i});
            }
            sort(vp.begin(), vp.end(), [](pair<int,int> &a, pair<int,int> &b) {
                return a.first > b.first; 
            });

            int x = n*m;
            int sum=0;
            for(auto it:vp){
                for(int i=0 ; i<m ; i++){
                    sum+=(v[it.second][i]*x);
                    x--;
                }
            }
            cout<<sum<<endl;
            
        }
        return 0;
    }






// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,m;
//         cin >> n>>m;
//         vector<vector<int>>arr(n,vector<int>(m));
//         for(int i=0 ; i<n ; i++){
//             for(int j=0 ; j<m ; j++){
//                 cin>>arr[i][j]; 
//             }
//         }
//         vector<pair<int, vector<int>>> v;
//         for(int i=0 ; i<n ; i++){
//             int sum=0;
//             vector<int>p;
//             for(int j=0 ; j<m ; j++){
//                 p.push_back(arr[i][j]);
//                 sum+=arr[i][j];
//             }
//             v.push_back({sum,p});
//             p.clear();
//         }
//         sort(v.begin(),v.end(),[](const pair<int,vector<int>>&a , const pair<int,vector<int>>&b){
//             return a.first>b.first;
//         });
//         int sum=0;
//         int ans=0;
//         for(auto it:v){
//             for(auto itt : it.second){
//                 sum = sum+itt;
//                 ans+=sum;
//             }
//         }
//         cout<<ans<<endl;
        
//     }
//     return 0;
// }















