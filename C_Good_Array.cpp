    #include <bits/stdc++.h>
    using namespace std;

    #define int long long

    int32_t main(){
        // int t;
        // cin >> t;
        // while(t--){
            int n;
            cin >> n;
            int arr[n];
            int sum=0;
            vector<pair<int,int>>v;
            map<int, vector<int>> mp;
            for(int i=0 ; i<n ; i++){
                cin>>arr[i];
                sum+=arr[i];
                v.push_back({arr[i],i+1});
                mp[arr[i]].push_back(i+1);
            }
            
            sort(v.begin(),v.end());
            vector<int>ans;
            int x = sum;
            for(int i=0 ; i<n ; i++){
                sum = sum-v[i].first;
                if(sum%2==0){
                    int z = sum/2;
                    if(mp.find(z)!=mp.end()){
                        // ans.push_back(v[i].second);
                        if(z==v[i].first ){
                            if(mp[v[i].first].size()>1){
                                ans.push_back(v[i].second);
                            }
                        }
                        else{
                            ans.push_back(v[i].second);
                        }
                    }

                }
                sum = x;
            }
            cout<<ans.size()<<endl;
            for(int i=0 ; i<ans.size() ; i++){
                cout<<ans[i]<<" ";
            }
            // cout<<endl;



        // }
        return 0;
    }