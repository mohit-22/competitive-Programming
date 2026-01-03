#include <bits/stdc++.h>

using namespace std;


string commas_seperation(string s) {



    string hello;

    int n = s.size(); 

    int c = 0;


    for(int i=n-1;i>=0;i--){

        hello.push_back(s[i]);

        c++;

        if(c==3 && i){

            hello.push_back(',');
            c = 0;
        }
    }

    reverse(hello.begin(), hello.end());


    return hello;
}

int main(){

    string x;

    cin>>x;

    bool neg = false;
    if(x[0]=='-') {

        neg = true;
        x = x.substr(1);
    }

    string a,b;

    int p=x.find('.');

    
    if (p==-1) {
        a=x;
        b="00";
    }
    else{
        a=x.substr(0, p);
        b=x.substr(p + 1);
        if(b.size()<2){
            while (b.size() < 2){
                b.push_back('0');
            }
        }
        else if(b.size() > 2){
            b = b.substr(0, 2);
        }
    }

    a = commas_seperation(a);

    string answer_5="$" + a + "." + b;

    if(neg){
        answer_5 = "(" + answer_5 + ")";
    }
    cout << answer_5 << "\n";
}