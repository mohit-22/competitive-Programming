#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        vector<int> arr(n), brr(m);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        for(int i = 0; i < m; i++){
            cin >> brr[i];
        }

        sort(brr.begin(), brr.end());
        if(brr[m-1]-arr[n-1]>=arr[n-1]){
            arr[n-1] = brr[m-1]-arr[n-1];
        }

        bool flag = true;
        for(int i=n-2 ; i>=0 ; i--){
            // if(arr[i]>arr[i+1]){
                int y = arr[i]+arr[i+1];
                auto it = lower_bound(brr.begin(), brr.end(), y);
                
                if(it!=brr.end() && *it<=y){
                    arr[i]=*it-arr[i];
                }
                else{
                   if(it != brr.begin()){
                        it--;
                        int z = *it;
                        // if(arr[i]<=z-arr[i]){
                            // arr[i] = (z - arr[i]);
                        // }
                        // if(arr[i]>arr[i+1]) arr[i] = (z - arr[i]);
                        // else if()

                        if(arr[i]>arr[i+1]) arr[i] = (z - arr[i]);
                        else arr[i] = max(arr[i],z - arr[i]);
                                                                      
                    }
                    else{
                        if(arr[i]>arr[i+1]){
                            flag=false;
                            break;
                        }
                        
                    }
                }
            // }
            // else{
            //     int y = arr[i]+arr[i+1];
            //     auto it = lower_bound(brr.begin(), brr.end(), y);
            //     if(it!=brr.end() && *it<=y){
            //         arr[i]=*it-arr[i];
            //     }
            //     else{
            //         if(it != brr.begin()){
            //             it--;
            //             int z = *it;
            //             arr[i] = max(arr[i],z - arr[i]);
            //         }
            //         // else{
            //         //     flag=false;
            //         //     break;
            //         // }
            //     }
            // }
        }
        // for(auto it:arr) cout<<it<<" ";

        if(!flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}