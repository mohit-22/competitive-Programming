// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int dp(vector<int>&v , int i, int n,int c,vector<vector<int>>&dpp){
//     if(i>=n){
//         return c;
//     }
//     if(dpp[i][c]!=-1){
//         return dpp[i][c];
//     }
//     int take = dp(v,i+1,n,c+v[i],dpp);
//     int nott = dp(v,i+1,n,abs(c+v[i]),dpp);

//     // int take = 

//     return dpp[i][c] =  max(take,nott);
// }

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         vector<int>v;
//         int sum =0;
//         for(int i=0 ; i<n ; i++){
//             int x;
//             cin>>x;
//             v.push_back(x);
//             sum+=abs(x);
//         }
 

//         vector<vector<int>>dpp(n,vector<int>(2*sum+1,-1));
//         cout<<dp(v,0,v.size(),0,dpp)<<endl;;
        
//     }
//     return 0;
// }







#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp(vector<int>&v , int i, int n,int c){
    if(i>=n){
        return c;
    }
    int take = dp(v,i+1,n,c+v[i]);
    int nott = dp(v,i+1,n,abs(c+v[i]));

    return max(take,nott);
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        // int c=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            // c=abs(c+arr[i]);
        }
        // cout<<c<<endl;
        vector<int>v;
        // int i=0;
        // while(i<n){
        //     int s=0;
        //     while(arr[i]<=0){
        //         s+=arr[i];
        //     }

        // }
        for(int i=0 ; i<n ; ){
            int s=0;
            if(arr[i]<=0){
                while(i<n && arr[i]<=0){
                    s+=arr[i];
                    i++;
                }
                v.push_back(s);
            }
            else{
                while(i<n && arr[i]>0){
                    s+=arr[i];
                    i++;
                }
                v.push_back(s);
            }
        }
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
        int c=0;
        if(v.size()>0) c = v[0];
        for(int i=1 ; i<v.size() ; i++){
            // c = c+v[i];
            // if(i+1<v.size()){
            //     if(v[i+1]>=0){
            //         c=abs(c);
            //     }
            // }
            
        }
        cout<<abs(c)<<endl;
        
    }
    return 0;
}