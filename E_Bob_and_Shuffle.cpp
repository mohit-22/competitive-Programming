// #include <bits/stdc++.h>
// using namespace std;
// #include<stack>
// #include<algorithm>
// #include<cmath>

// int main() {
    
    
//         int n;
//         cin >> n;
//         vector<string> arr(n);
        
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }
//         int ct=0;
//         for (int i = 0; i < n; i++)
//         {
//             /* code */
//             string chek=arr[i];
//             reverse(chek.begin(),chek.end());
//             string geck=arr[i];
//             if(chek==geck){
//                 ct++;
//                 arr[i]="123!@#";
//                 arr[i] += to_string(i);
//             }
//         }
//         unordered_map<string,int>mapp;
//         for (int i = 0; i < n; i++)

//         {
//             mapp[arr[i]]++;

//         }


        
//         for(auto it : mapp){
//             string a = it.first;
//             string b = it.first;
//             reverse(a.begin(),a.end());
//             if(mapp.find(a)!=mapp.end()){
//                 ct+=2;
//                 mapp.erase(a);
//                 mapp.erase(b);

//             }

//         }
//         cout<<n-ct<<endl;

// }

#include <iostream>
#include <vector>

using namespace std;

void sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Print all prime numbers
    cout << "Prime numbers up to " << n << " are:\n";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    sieve(n);

    return 0;
}
