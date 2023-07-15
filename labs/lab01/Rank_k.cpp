// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// Quick Sort
int partition(int p, int r, vector<int> &v){
    // random number
    srand(time(0));
    int random = (rand() % (r-p+1)) + p;
    swap(v[random], v[r]);

    // actual  
    int x = v[r];
    int i = p-1;
    for(int k = p; k < r; k++){
        if(v[k] < x){
            i++;
            swap(v[i], v[k]);
        }
    }
    swap(v[i+1], v[r]);
    return (i+1);
}
int rank_k(int p, int r, vector<int> &v, int k){
    if(p < r){
        int q = partition(p,r,v);
        if((k-1) == q){
            return v[q];
        }
        if((k-1) < q){
            return rank_k(p,q-1,v,k);
        }else{
            return rank_k(q+1,r,v,k-q-1);
        }
    }
    return 0;
}


int main() {
    vector<int> v = {14,8,2,6,7,1,4,11,10,3};
    // arr : 1 2 3 4 6 7 8 10 11 14
    // idx : 1 2 3 4 5 6 7  8  9 10
    int n = v.size();
    
    int k = 9;
    int kth_element = rank_k(0,n-1,v,k);
    cout << kth_element << endl;
    for(auto i : v){
        cout << i << " ";
    }
    return 0;
}