// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         string str;
//         cin>>str;

//         stack<char>s;
//         for(int i=0 ; i<n ; i++){
//             if(s.size()==0) s.push(str[i]);
//             else if(str[i]==')' && s.top()=='(') s.pop();
//             else if(s.size()>0 && str[i]==')') s.push(str[i]);
//             else if(s.size()>0 && str[i]=='(') s.push(str[i]);

//         }
//         cout<<s.size()/2<<endl; 
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

        stack<char>st;
        for(char ch:s){
            if(ch == '('){
                st.push('(');
            }
            else if(ch==')'){
                if(!st.empty()){
                    st.pop();
                }
            }
        }

        cout<<st.size()<<endl;
    }
    return 0;
}




