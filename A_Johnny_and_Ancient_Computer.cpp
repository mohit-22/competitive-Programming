// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// bool check(int x){
//    while(x%2==0 && x>0){
//     x=x/2;
//    }
//    return x==1;
// }

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int a,b;
//         cin >> a>>b;
//         int ct=0;
        
//         if(a>=b){
//             if(a%b!=0) cout<<-1<<endl;
//             else{
//                 int x = a/b;
//                 if(check(x)==false) cout<<-1<<endl;
//                 else{
//                     while(x!=1){
//                         int r=8;
//                         while(x%r!=0){
//                             r = r/2;
//                         }
//                         x = x/r;
//                         ct++;
//                     }
//                     cout<<ct<<endl;
//                 }
//             }
            
            
//         }
//         else{
//             if(b%a!=0) cout<<-1<<endl;
//             else{
//                 int x = b/a;
//                 if(check(x)==false) cout<<-1<<endl;
//                 else{
//                     while(x!=1){
//                         int r=8;
//                         while(x%r!=0){
//                             r = r/2;
//                         }
//                         x = x/r;
//                         ct++;
//                     }
//                     cout<<ct<<endl;
//                 }
//             }
//         }

        
        
//     }
//     return 0;
// }



































// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         int a,b;
//         cin>>a>>b;
//         int ct=0;
//         bool flag = true;
//         if(a%b==0){
//             int x = a/b;
//             while(x!=1){
//                 if(x%8==0){
//                     ct++;
//                     x = x/8;
//                 }
//                 else if(x%4==0){
//                     ct++;
//                     x =x/4;
//                 }
//                 else if(x%2==0){
//                     ct++;
//                     x = x/2;
//                 }
//                 else{
//                     flag = false;
//                     break;
//                 }
//             }
//         }
//         else if(b%a==0){
//             int x = b/a;
//             while(x!=1){
//                 if(x%8==0){
//                     ct++;
//                     x = x/8;
//                 }
//                 else if(x%4==0){
//                     ct++;
//                     x =x/4;
//                 }
//                 else if(x%2==0){
//                     ct++;
//                     x = x/2;
//                 }
//                 else{
//                     flag = false;
//                     break;
//                 }
//             }
//         }
//         else flag = false;

//         if(flag==true) cout<<ct<<endl;
//         else cout<<-1<<endl;
//     }
//     return 0;
// }