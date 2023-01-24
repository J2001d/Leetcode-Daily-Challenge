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
#define ll                   long long
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

/*
#define int long long
#undef int
*/


class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& a) {
    int n = sz(a);
    vector<vector<bool>> visited(n , vector<bool>(n));

    queue<int> q;
    q.push(1);
    visited[n - 1][0] = true;

    int ans  = 0;
    while (!q.empty())
    {
        int Qsize = sz(q);
        while (Qsize--) {

            int ele = q.front(); q.pop();

            if (ele == n * n) {
                return ans ;
            }
            // watch(ele);
            for (int i = 1; i <= 6; i++) {
                int nxtele = ele + i;
                // watch(nxtele);
                if (nxtele <= n * n) {
                    int row = n - (nxtele - 1) / n - 1;
                    int col = (nxtele - 1) % n;
                    // watch(row);
                    // watch(col);
                    if (row % 2 == n % 2){
                        col = n - col - 1;
                    }
                    if (!visited[row][col]) {
                        visited[row][col] = true;
                        if (a[row][col] != -1) {
                            q.push(a[row][col]);
                        }
                        else {
                            q.push(nxtele);
                        }
                    }
                }

            }
        }
        ans ++;
    }
    return -1;
}
};
