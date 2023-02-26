void __print(int x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << x; }
void __print(const char *x) { cout << x; }
void __print(const string &x) { cout << x; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const pair<T, V> &x) {
	cout << '{';
	__print(x.first);
	cout << ", ";
	__print(x.second);
	cout << '}';
}
template<typename T>
void __print(const T &x) {
	int f = 0;
	cout << '{';
	for (auto &i : x) {
		cout << (f++ ? ", " : "");
		__print(i);
	}
	cout << "}";
}
void _print() {
	cout << "]\n";
}
template<typename T, typename... V>
void _print(T t, V... v) {
	__print(t);
	if (sizeof...(v)) {
		cout << ", ";
	}
	_print(v...);
}

#define watch(x...) cout << "[" << #x << "] = ["; _print(x)
#define lld               long double
#define INF               1000000000000000000
#define pb                push_back
#define all(x)            x.begin(),x.end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define sz(x)             (int)((x).size())
#define f1                first
#define s2                second
#define fix(x)            fixed << setprecision(x)
#define endl              "\n"
#define bigprime          1000000007
#define MOD               1000000007
#define gcd(a,b)          __gcd((a),(b))
#define lcm(a,b)          (a/gcd(a,b))*b
#define scanvec(a,n)      rep(i,0,n){cin>>a[i];}
#define fast              ios_base::sync_with_stdio(false);cin.tie(NULL);
#define makeuniq(v)       v.resize(unique(all(v)) - v.begin());
class Solution {
public:
    int helper(string s1, string s2, int i, int j, vector<vector<int>>&dp) {
        if (i < 0) {
            return j + 1;
        }
        if (j < 0) {
            return i + 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) {
            return dp[i][j] = helper(s1, s2, i - 1, j - 1, dp);
        }
        // delete [we are converting s1 -> s2 so if we delete in s1 our i pointer will dec and j will be same]
        int op1 = helper(s1, s2, i - 1, j, dp);
        // insert [here we are inserting value at index i so to make them same dec the j by 1]
        int op2 = helper(s1, s2, i, j - 1, dp);
        // replace [here we are replacing both the values with new values so dec both pointers]
        int op3 = helper(s1, s2, i - 1, j - 1, dp);

        return  dp[i][j] = 1 + min(op1, min(op2, op3));
    }
    int minDistance(string s1, string s2) {
       	vector<vector<int>> dp(sz(s1) + 1, vector<int> (sz(s2) + 1, -1));
        return helper(s1, s2, sz(s1) - 1, sz(s2) - 1, dp); 
    }
};
