// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         int arr[n];
//         int ct=0;
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//             if(arr[i]==0) ct++;
//         }
//         if(ct==n){
//             cout<<"YES"<<endl;
//             continue;
//         }
//         if(ct>=1){
//             cout<<"NO"<<endl;
//             continue;
//         }
//         int z = arr[0]-arr[1];
//         bool flag2  = true;
//         for(int i=1 ; i<n-1 ; i++){
//             if(arr[i]-arr[i+1]!=z){
//                 flag2 = false;
//                 break;
//             }
//         }
//         if(flag2 && n!=2){
//             cout<<"YES"<<endl;
//             continue;
//         }
//         int x = arr[n-1]/n;
//         int y = arr[n-1]%n;
//         bool flag = true;
//         int m=n-1;
//         int k=2;
//         for(int i=n-2 ; i>=0 ; i--){
//             int a = arr[i]-x*m;
//             int b = a-k*y;
//             if(b!=0){
//                 flag = false;
//                 break;
//             }
//             m--;
//             k++;
//         }
//         if(flag) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
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
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0 ; i<n ; i++){
            cin>>v[i];
        }
        int x,y;
        int numerator = 2 * v[0] - v[1];
        int denominator = 2 * n - (n - 1);

        if (denominator == 0 || numerator % denominator != 0) {
            cout << "NO" << endl;
            continue;
        }

        y = numerator / denominator;
        if (y < 0) {
            cout << "NO" << endl;
            continue;
        }

        x = v[0]-n*y;
        if(x<0){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag = true;
        for(int i=2 ; i<n ; i++){
            if(v[i]!=x*(i+1)+y*(n-i)){
                flag=false;
                break;
            }
        }
        if(!flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}