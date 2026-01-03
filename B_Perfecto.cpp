#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==8 || n==49 || n==1) cout<<"-1"<<endl;
        else{
            vector<int>v;
            if(n>1 && n<8){
                for(int i=2 ; i<=n ; i++){
                    v.push_back(i);
                }
                v.insert(v.begin()+1, 1);
                for(int i=0 ; i<v.size() ; i++){
                    cout<<v[i]<<" ";
                }
                cout<<endl;
            }
            else if(n>8 && n<49){
                for(int i=2 ; i<=n ; i++){
                    v.push_back(i);
                }
                v.insert(v.begin()+1, 1);
                swap(v[7],v[8]);
                for(int i=0 ; i<v.size() ; i++){
                    cout<<v[i]<<" ";
                }
                cout<<endl;
            }
            else{
                for(int i=2 ; i<=n ; i++){
                    v.push_back(i);
                }
                v.insert(v.begin()+1, 1);
                swap(v[7],v[8]);
                swap(v[48],v[49]);
                for(int i=0 ; i<v.size() ; i++){
                    cout<<v[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}