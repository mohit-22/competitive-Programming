    #include <bits/stdc++.h>
    using namespace std;

    #define int long long

    int32_t main(){
        // int t;
        // cin >> t;
        // while(t--){
            int n,q;
            cin >> n>>q;
            int sum=0;
            vector<pair<int,int>>v;
            for(int i=0 ; i<n ; i++){
                int x;
                cin>>x;
                v.push_back({x,0});
                sum+=v[i].first;
            }
           vector<pair<int,int>> g = { {-1, 0} };
           int t = 1;
            while(t<=q){
                int x;
                cin>>x;
                if(x==1){
                    int idx;
                    cin>>idx;
                    int num;
                    cin>>num;
                    idx--;
                    if(g[0].second>v[idx].second){
                        sum+=(num-g[0].first);
                    }
                    else{
                        sum+=(num-v[idx].first);
                       
                    }
                    v[idx].first = num;
                    v[idx].second = t;
                    cout<<sum<<endl;
                                 

                }
                else{
                    int num;
                    cin>>num;
                    sum=(n*num);
                    g[0].first = num;
                    g[0].second = t;

                    cout<<sum<<endl;
                    
                }
                t++;
            }
            
        // }
        return 0;
    }