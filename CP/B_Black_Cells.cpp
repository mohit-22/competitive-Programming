#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n ; i++){
            cin>>arr[i];
        }
        vector<pair<int,int>>v;
        vector<int>v2;
        for(int i=0 ; i<n-1 ; i++){
            v.push_back({i,arr[i+1]-arr[i]});
        }
        if(n%2==0){
            for(int i=0 ; i<n ; i+=2){
            v2.push_back(arr[i+1]-arr[i]);
            }
        }
        sort(v2.begin(),v2.end());
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });

        if(v.size()==0){
            cout<<1<<endl;
        }
        else{
            if(n%2==0){
                cout<<v2[v2.size()-1]<<endl;
            }
            else{
                // for(auto it:v){
                //     cout<<it.first<<" "<<it.second<<endl;
                // }
                if(v[0].first%2!=0){
                    // for(int i=1 ; i<v.size() ; i++){
                    //     if(v[i].first!=v[0].first+1){
                    //         cout<<v[i].second<<endl;
                    //         break;
                    //     }
                    // }
                    int mx = 1;
                    for(int i=0 ; i<=v[0].first ; i+=2){
                        mx = max(mx,arr[i+1]-arr[i]);
                    }
                    for(int i=v[0].first+2 ; i<n ; i+=2){
                        mx = max(mx,arr[i+1]-arr[i]);
                    }
                    cout<<mx<<endl;
                }
                else{
                    // for(int i=1 ; i<v.size() ; i++){
                    //     if(v[i].first!=v[0].first-1){
                    //         cout<<v[i].second<<endl;
                    //         break;
                    //     }
                    // }
                    int mx = 1;
                    for(int i=0 ; i<v[0].first ; i+=2){
                        mx = max(mx,arr[i+1]-arr[i]);
                    }
                    for(int i=v[0].first+1 ; i<n ; i+=2){
                        mx = max(mx,arr[i+1]-arr[i]);
                    }
                    cout<<mx<<endl;
                }

            }
        }
    }
    return 0;
}