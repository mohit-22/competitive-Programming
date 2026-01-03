// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n>>k;
//         int arr[n];
//         for(int i=0;  i<n ; i++){
//             cin>>arr[i];
//         }
//         int i=0,j=n-1;
//         int ct1=0,ct2=0;
//         while(i<=j && k>0){
//             bool flag1 = false;
//             bool flag2 = false;
//             int x = arr[i];
//             int y = arr[j];
//             int p=0;
//             int q=0;
//             if(k%2!=0){
//                 p = (k/2)+1;
//                 q = k/2;
//             }
//             else{
//                 p = k/2;
//                 q = k/2;
//             }
//             if(x<=p){
//                 ct1++;
//                 k-=(2*x-1);
//                 arr[j]-=x;
//                 if(arr[j]<=0){
//                     j--;
//                     ct1++;
//                 }
//                 i++;
//                 flag1=true;
//             }
//             if(y<=q){
//                 ct2++;
//                 k-=y*2;
//                 arr[i]-=y;
//                 if(arr[i]<=0){
//                     i++;
//                     ct2++;
//                 }
//                 j--;
//                 flag2 = true;
//             }
//             if(!flag1 && !flag2){
//                 break;
//             }
//         }
//         cout<<max(ct1,ct2)<<endl;
        
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
        int n,k;
        cin >> n>>k;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int i=0,j=n-1;
        int ct=0;
        while(i<=j && k>0){
            if(arr[i]<arr[j]){
                if(k>=arr[i]*2-1){
                    i++;
                    ct++;
                    k-=(arr[i]*2-1);
                    arr[j] = arr[i]-1;
                }
            }
            else if(arr[i]>arr[j]){
                if(arr[i]<arr[j]){
                    if(k>=arr[i]*2-1){
                        i++;
                        ct++;
                        k-=(arr[i]*2-1);
                        arr[j] = arr[i]-1;
                    }
                }
            }
        }
        
    }
    return 0;
}