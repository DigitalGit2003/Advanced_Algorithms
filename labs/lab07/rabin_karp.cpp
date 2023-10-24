#include<bits/stdc++.h>
using namespace std;

int power(int a, int x, int n){
    int res = 1;
    while(x > 0){
        if(x & 1){
            res = (res * a) % n;
        }

        x = x >> 1;
        a = (a * a) % n;
    }
    return res;
}



int main(){
    string T;
    cout << "Enter Text : ";
    cin >> T;
    int n = T.size();

    string P;
    cout << "Enter Pattern : ";
    cin >> P;
    int m = P.size();

    int matches = 0;

    // Preprocessing
    int d = 10;
    int q = 13;
    int h = power(d,m-1,q);
    int p = 0, t = 0;
    for(int i = 0; i < m; i++){
        p = (d*p + (P[i] - '0')) % q;
        t = (d*t + (T[i] - '0')) % q;
    }

    // checking first window =====>  s = 0
    if(p == t){
        bool f = true;
        for(int i = 0; i < m; i++){
            if(T[i] != P[i]){
                f = false;
                break;
            }
        }
        if(f){
            matches++;
        }
    }

    for(int s = 1; s <= (n-m); s++){
        t = (t - (T[s-1] - '0')*h)*d + (T[s + (m-1)] - '0');
        while(t < 0){
            t += q;
        }
        if(t == p){
            bool f = true;
            for(int i = 0; i < m; i++){
                if(T[s+i] != P[i]){
                    f = false;
                    break;
                }
            }
            if(f){
                matches++;
            }
        }
    }

    cout << matches << endl;

    return 0;
}