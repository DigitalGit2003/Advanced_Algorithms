// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// Quick Sort
int partition(int p, int r, vector<int> &v, int& swaps){
    // random number
    srand(time(0));
    int random = (rand() % (r-p+1)) + p;
    swap(v[random], v[r]);

    // actual  
    int x = v[r];
    int i = p-1;
    for(int k = p; k < r; k++){
        if(v[k] < x){
            swaps++;
            i++;
            swap(v[i], v[k]);
        }
    }
    swaps++;
    swap(v[i+1], v[r]);
    return (i+1);
}
void qs(int p, int r, vector<int> &v, int& swaps){
    if(p < r){
        int q = partition(p,r,v,swaps);
        qs(p,q-1,v,swaps);
        qs(q+1,r,v,swaps);
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = i;
    }
    
    int swaps = 0;
    qs(0,n-1,v,swaps);
    
    cout << swaps;
    return 0;
}