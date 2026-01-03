// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int processString(string s,int n){
//     vector<int>arr(n);
//         int ct=0;
//         for(int i=0 ; i<n ; i++){
//             if(s[i]=='a'){
//                 arr[i]=ct+1;
//                 ct++;
//             }
//             else{
//                 arr[i] = ct-1;
//                 ct--;
//             }
//         }
//         int p=0,q=n-1;
//         int r=0;
//         for(int i=0 ; i<n ; i++){
//             if(arr[i]==0){
//                 p=i+1;
//                 r=i;
//             }
//         }
//         int mn=0;
//         if(p==n){
//            return mn;
//         }
        
//         int ct1=(arr[q]);
//         bool flag = false;
//         if(ct1>0){
//             for(int i=p ; i<=q ; ){
//                 int ct=0;
//                 if(s[i]=='a'){
//                     while(s[i]=='a'){
//                         ct++;
//                         i++;
//                     }
//                 }
//                 else{
//                     i++;
//                 }

//                 if(ct==abs(ct1)){
//                     flag=true;
//                     break;
//                 }
//             }
//         }
//         else{
//             for(int i=p ; i<=q ;){
//                 int ct=0;
//                 if(s[i]=='b'){
//                     while(s[i]=='b'){
//                         ct++;
//                         i++;
//                     }
//                 }
//                 else{
//                     i++;
//                 }

//                 if(ct==abs(ct1)){
//                     flag=true;
//                     break;
//                 }
//             }
//         }

//         if(flag==true){
//             mn=abs(ct1);
//         }
//         else{
//             mn = INT_MAX;
//         }

//         return mn;


// }

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;

//         int mn1 = processString(s,s.length());
//         string st = s;
//         reverse(st.begin(), st.end());
//         int mn2 = processString(st, st.length());

//         if(mn1==INT_MAX && mn2==INT_MAX){
//             cout<<-1<<endl;
//         }
//         else{
//             int mn3 = min(mn1,mn2);
//             if(mn3==s.length()){
//                 cout<<-1<<endl;
//             }
//             else cout<<mn3<<endl;
//         }


        
        
//     }
//     return 0;
// }

// int quick(string s,int n){
//     vector<int>arr(n);
//     int ct=0;
//     for(int i=0 ; i<n ; i++){
//         if(s[i]=='a'){
//             arr[i]=ct+1;
//             ct++;
//         }
//         else{
//             arr[i] = ct-1;
//             ct--;
//         }
//     }

//     int p=-1;
//     for(int i=0 ; i<n ; i++){
//         if(arr[i]==0) p=i;
//     }

//     return p;
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
        string s;
        cin >> s;

        // int mn1 = quick(s,s.length());
        // string st = s;
        // reverse(st.begin(), st.end());
        // int mn2 = quick(st, st.length());

        vector<int>arr(n);
        int ct=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='a'){
                arr[i]=ct+1;
                ct++;
            }
            else{
                arr[i] = ct-1;
                ct--;
            }
        }

        int mn1=-1;
        for(int i=0 ; i<n ; i++){
            if(arr[i]==0) mn1=i;
        }

        // vector<int> brr = arr;
        // reverse(brr.begin(), brr.end());
        vector<int>brr(n);
        ct=0;
        for(int i=n-1 ; i>=0 ; i--){
            if(s[i]=='a'){
                brr[i]=ct+1;
                ct++;
            }
            else{
                brr[i] = ct-1;
                ct--;
            }
        }

        int mn2=-1;
        for(int i=n-1 ; i>=0 ; i--){
            if(brr[i]==0) mn2=i;
        }



        if(mn1==n-1 || mn2==n-1){
            cout<<0<<endl;
        }
        else if(mn1==-1 && mn2==-1){
            cout<<-1<<endl;
        }
        else{
            if(mn1==-1) cout<<mn2<<endl;
            else if(mn2==-1) cout<<n-mn1-1<<endl;
            else{
                if(mn1<mn2){
                    cout<<mn2-mn1-1<<endl;
                }
                else{
                    cout<<min(mn2,n-1-mn1)<<endl;
                }
            }

        }
        // cout<<mn1<<" "<<mn2<<endl;
        // for(auto x: arr) cout<<x<<" ";
        // cout<<endl;
        // for(auto x: brr) cout<<x<<" ";
        // cout<<endl;
        // cout<<endl;


        



    }
    return 0;
}