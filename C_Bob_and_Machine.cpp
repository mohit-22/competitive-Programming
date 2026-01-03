#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int pow[n];
        bool pose = true;
        int max = INT_MIN;
        for(int i = 0;i<n;i++){
            cin>>pow[i];
            if(pow[i]>max){
                max = pow[i];
            }
        }
        int life[n];
        for(int i = 0;i<n;i++){
            cin>>life[i];
        }
        int programs[m];
        int pcopy[m];
        int capreq = 0;
        int c = 0;
        for(int i = 0;i<m;i++){
            cin>>programs[i];
            pcopy[i] = programs[i];
            capreq += programs[i];
            if(programs[i]>max && c==0){
                pose = false;
                c++;
            }
        }
        

        
        
    }
}