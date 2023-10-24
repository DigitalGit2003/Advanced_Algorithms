#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<vector<int>> &T, int n, int m, vector<int>profit, vector<int>weight) {
    for(int i=0; i<=n; i++) {
        T[i][0] = 0;
    }
    
    for(int j=1; j<=m; j++) {
        T[0][j] = 0;
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(j < weight[i-1]) T[i][j] = T[i-1][j];
            else T[i][j] = max(T[i-1][j], profit[i-1] + T[i-1][j - weight[i-1]]);
        }
    }
    return T[n][m];
}

void print_sol(vector<vector<int>> &T, int n, int m, vector<int> profit, vector<int> weight) {
    int i = n, j = m;
    vector<int> x(n);
    while(i > 0 and j > 0) {
        if(T[i][j] != T[i-1][j]) {
            x[i-1] = 1;
            j -= weight[i-1];
        } else {
            x[i-1] = 0;
        }
        i--;
    }
    
    for(int i=0; i<n; i++) {
        if(x[i] == 1) {
            cout << weight[i] << " ";
        }
    }
}

int main() {
    int n;
    cout << "Enter a size of an array :\n";
    cin >> n;
    
    vector<int> a(n);
    cout << "Enter an array :\n";
    
    for(int i=0; i<n; i++) cin >> a[i];
    
    int sum;
    cout << "Enter target sum:\n";
    cin >> sum;
    
    //Reducing it to 0/1 Knapsack.

    vector<int> profit(n), weight(n);
    
    profit = a;
    weight = a;
    
    int capacity = sum;
    vector<vector<int>> T(n + 1, vector<int>(capacity + 1));
    
    int p = knapsack(T, n, capacity, profit, weight);
    // cout << p << endl;
    if(p < sum) {
        cout << "Not possible\n";
    } else {
        print_sol(T, n, capacity, profit, weight);
    }
    return 0;
}