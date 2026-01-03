#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n>>x;
        int arr[n];
        int brr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int ctn=0;
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
            if(brr[i]<0) ctn++;
        }
        

        int maxVal1 = INT_MIN, minVal1 = INT_MAX;
        int maxIdx1 = -1;
        int minIdx1 = -1;

        for (int i = 0; i <n; i++) {

                if (arr[i] > maxVal1) {
                    maxVal1 = arr[i];
                    maxIdx1 = i;
                }
                if (arr[i] < minVal1) {
                    minVal1 = arr[i];
                    minIdx1 = i;
                }
            
        }

        bool conflict = false;
        int S = -1;
        for(int i = 0; i < n; i++){
            if(brr[i] != -1){
                int want = arr[i] + brr[i];
                if(S == -1) S = want;
                else if(S != want){
                    conflict = true;
                    break;
                }
            }
        }
        if(conflict){
            cout << 0 << "\n";
            continue;
        }

        if(S != -1){
            int ways = 1;
            for(int i = 0; i < n; i++){
                if(brr[i] == -1){
                    int bi = S - arr[i];
                    if(bi < 0 || bi > x){
                        ways = 0;
                        break;
                    }
                }
            }
            cout << ways << "\n";
            continue;
        }


                int p = arr[minIdx1]+x;
                cout<<p-arr[maxIdx1]+1<<endl;

        



        
    }
    return 0;
}