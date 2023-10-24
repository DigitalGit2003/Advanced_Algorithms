#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define int long long
#define scan(arr,n) for(int i = 0; i < n; i++){ cin >> arr[i]; }
#define print(arr,n) for(int i = 0; i < n; i++){ cout << arr[i] << " "; }cout << endl;
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fastios                           \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);
// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
//  |^^^^^^^^^^^       /\      |         | ^^^^^|^^^^^       /\       |\      /|
//  |                 /  \     |         |      |           /  \      | \    / |
//  |                /    \    |         |      |          /    \     |  \  /  |
//  |   ^^^^^^^|    /______\   |         |      |         /______\    |   \/   |
//  |          |   /        \  |         |      |        /        \   |        |
//  |__________|  /          \ |_________|      |       /          \  |        |

bool ispow2(int i){
    return i && (i & -i) == i;
}

bool isPalindrome(string s){
    string temp = s;
    reverse(all(s));
    return temp == s;
}

int kadane(vector<int> &nums){
    int ans = INT_MIN;
    int sum = 0;
    for(auto i : nums){
        sum += i;
        ans = max(ans,sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return ans;
}

string ceasar_cipher(string s, int key){
    for(int i = 0; i < s.size(); i++){
        if('a' <= s[i] && 'z' >= s[i])
            s[i] = (s[i] - 'a' + key) % 26 + 'a';
        else if('A' <= s[i] && 'Z' >= s[i])
            s[i] = (s[i] - 'A' + key) % 26 + 'A';
        else if('0' <= s[i] && '9' >= s[i])
            s[i] = (s[i] - '0' + key) % 10 + '0';
    }
    return s;
}

int comparisions = 0;

int32_t main() {
	// your code goes here
	fastios
	int t = 1;
// 	cin >> t;
	while(t--){
	    string text = "this is an apple.I like apple.";
        cout << "Enter text string : ";
        cin >> text;
        
        string pattern = "apple";
        cout << "Enter pattern string : ";
        cin >> pattern;
        
        int n = text.size();
        int m = pattern.size();
        // shift table starts
        map<char,int> shift;
        for(char i = 'a'; i <= 'z'; i++){
            shift[i] = m;
        }
        for(int i = 0; i < n; i++){
            shift[text[i]] = m;
        }
        for(int i = 0; i < m-1; i++){
            shift[pattern[i]] = m-i-1;
        }
        // for(auto i : shift){ cout << i.first << " " << i.second << " | ";}
        // shift table ends
//--------------------------------------------------------------------------------------------    
        // horsepool stars
        vector<int> vs;
        int s = 0;
        while((s+m) <= n){
            int it = m-1;
            while(it >= 0 && text[s+it] == pattern[it]){
                comparisions++;
                it--;
            }
            if(it < 0){
                vs.push_back(s+1);
            }else{
                comparisions++;
            }
            s += shift[text[s+m-1]];
        }
        cout << "Total comparisions : " << comparisions << endl;
        cout << "s : ";
        for(auto i : vs){
            cout << i << ", ";
        }
        // horsepool ends
	}
	
	return 0;
}


        // prefix suffix sum :)
/*

    vector<long long> prefix(n),suffix(n);
    prefix[0] = a[0];
    suffix[0] = a[n-1];
    for(int i = 1; i < n; i++){
        prefix[i] = a[i] + prefix[i-1];
        suffix[i] = a[n-i-1] + suffix[i-1];
    }

*/

       // all root to leaves paths in a tree :)
/*
    // in initial call, node = root, temp = empty vector, v = empty vector of vector
    // after completion, we will have all paths in 'v'.
    
    void allRootToLeafPaths(int node, vi &temp, vvi &adj, vvi &v){
        temp.push_back(node);
        if(adj[node].size() == 0){
            v.push_back(temp);
        }else{
            for(auto i : adj[node]){
                allRootToLeafPaths(i,temp,adj,v);
            }
        }
        temp.pop_back();
    }
    
*/