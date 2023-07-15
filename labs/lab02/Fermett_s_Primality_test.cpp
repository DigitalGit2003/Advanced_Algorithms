#include <bits/stdc++.h>
using namespace std;
#define int unsigned long
// 100000004987
int gcd(int a,int b){
    while(b != 0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int power(int a, int x, int n){
    int res = 1;
    while(x > 0){
        if(x%2){
            res = (res*a)%n;
        }
        x /= 2;
        a = (a*a)%n;
    }
    return res;
}

int RPT(int n, int k){
    if(n <= 1 | n == 4){
        return 0;
    }
    if(n == 2 || n == 3){
        return 1;
    }
    
    int i = 1;
    while(i <= k){
        //  p = 2 to q = n-2
        srand(time(0));
        int a = 2 + rand()%(n-3);
        if(gcd(a,n) != 1){
            return 0;
        }
        if(power(a,n-1,n) != 1){
            return 0;
        }
        
        i++;
    }
    return 1;
}

signed main() {
	// your code goes here
	int n, k;
	cin >> n >> k;
	
	if(RPT(n, k)){
	    cout << "it is a prime\n";
	}else{
	    cout << "it is not a prime\n";
	}
	
	return 0;
}
