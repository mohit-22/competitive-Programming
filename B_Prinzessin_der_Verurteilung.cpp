// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         string s;
//         cin>>s;
//         string ans="";
//         bool flag = false;
//         for(char i='a' ; i<='z' ; i++){
//             string temp = "";
//             temp.push_back(i);
//             if(ans=="" &&  s.find(temp)==string::npos){
//                 ans=temp;
//                 flag=true;
//                 // break;
//             }
//             // if(flag) break;

//         }
//         if(flag==true){
//             cout<<ans<<endl;
//             continue;
//         }
//         for(char i='a' ; i<='z' ; i++){
//             for(char j='a' ; j<='z' ; j++ ){
//                 string temp = "";
//                 temp.push_back(i);
//                 temp.push_back(j);
//                 if(ans=="" && s.find(temp)==string::npos){
//                     ans=temp;
//                     flag=true;
//                     // break;
//                 }
//             }
//             // if(flag) break;
//         }

//         if(flag==true){
//             cout<<ans<<endl;
//             continue;
//         }
//         for(char i='a' ; i<='z' ; i++){
//             for(char j='a' ; j<='z' ; j++ ){
//                 for(char k='a' ; k<='z' ; k++){
//                     string temp = "";
//                     temp.push_back(i);
//                     temp.push_back(j);
//                     temp.push_back(k);
//                     if(ans=="" && s.find(temp)==string::npos){
//                         ans=temp;
//                         flag=true;
//                         // break;
//                     }
//                 }
//             }
//             // if(flag) break;
//         }
//         cout<<ans<<endl;
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
        string s;
        cin>>s;
        string ans="";
        bool flag = false;
        for(char i='a' ; i<='z' ; i++){
            string temp = "";
            temp.push_back(i);
            if( s.find(temp)==string::npos){
                ans=temp;
                flag=true;
                break;
            }

        }
        if(flag==true){
            cout<<ans<<endl;
            continue;
        }
        for(char i='a' ; i<='z' ; i++){
            for(char j='a' ; j<='z' ; j++ ){
                string temp = "";
                temp.push_back(i);
                temp.push_back(j);
                if(s.find(temp)==string::npos){
                    ans=temp;
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }

        if(flag==true){
            cout<<ans<<endl;
            continue;
        }
        for(char i='a' ; i<='z' ; i++){
            for(char j='a' ; j<='z' ; j++ ){
                for(char k='a' ; k<='z' ; k++){
                    string temp = "";
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(k);
                    if(s.find(temp)==string::npos){
                        ans=temp;
                        flag=true;
                        break;
                    }
                }
               if(flag) break; 
            }
            if(flag) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}



