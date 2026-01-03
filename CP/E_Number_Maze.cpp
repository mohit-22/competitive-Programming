#include <bits/stdc++.h>
using namespace std;

#define int long long

void permute(string s, int l, int r,vector<string>&v) {
    if(l == r) {
        // cout << s << endl;
        v.push_back(s);
        return;
    }
    for(int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r,v);
        swap(s[l], s[i]);  
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n>>a>>b;
        vector<string>v;
        
        string s = to_string(n);
        permute(s,0,s.length()-1,v);
        sort(v.begin(),v.end());

        // for(string &p :v){
        //     cout<<p<<" ";
        // }
        // cout<<endl;
        string s1 = v[a-1];
        string s2 = v[b-1];
        int ct=0;
        for(int i=0 ; i<s1.size() ; i++){
            if(s1[i]==s2[i]) ct++;
        }  
        cout<<ct<<'A'<<s.size()-ct<<'B'<<endl; 
        
    }
    return 0;
}





// #include <bits/stdc++.h>
// using namespace std;

// vector<string> generatePermutations(string n) {
//     vector<string> perms;

//     sort(n.begin(), n.end());           
//     do {
//         perms.push_back(n);         
//     } while (next_permutation(n.begin(), n.end()));

//     return perms;
// }


// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    int n,j,k;
// 	    cin>>n>>j>>k;
// 	    string s = to_string(n);
// 	    vector<string> vec = generatePermutations(s);
// 	    string a = vec[j-1];
// 	    string b = vec[k-1];
// 	    int same = s.length();
// 	    for(int i = 0;i<s.length();i++){
// 	        if(a[i]==b[i]) same--;
// 	    }
// 	    cout<<(s.length()-same)<<"A"<<same<<"B"<<endl;
// 	}

// }