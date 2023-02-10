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
    int isvalid(vector<vector<int>> &M, int row, int col,vector<vector<int>> &visited){
        return (row >= 0) && (row < sz(M)) && (col >= 0) && (col < sz(M[0])) && !visited[row][col];
    }
    int maxDistance(vector<vector<int>>& a) {
        int n = sz(a);

        // from every 1(land) do bfs at same time
        queue<pair<int,int>> q;
        rep(i,0,n){
            rep(j,0,n){
                if(a[i][j] == 1){
                    q.push({i,j});
                }
            }            
        }
        if(sz(q) == n*n){
            return -1;
        }
        int ans = -1;
        vector<vector<int>> visited(n,vector<int>(n,0));
        int dx[] = { -1, 0, 1, 0};
        int dy[] = { 0, -1, 0, 1};
        
        while(!q.empty()){
            int qsize = sz(q);

            while(qsize --){
                auto ele = q.front(); q.pop();


                for (int k = 0; k < 4; k++) {
                    if (isvalid(a, ele.f1 + dx[k], ele.s2 + dy[k],visited)) {
                        q.push({ele.f1 + dx[k] , ele.s2 + dy[k]});
                        visited[ele.f1 + dx[k]][ele.s2 + dy[k]] = 1;
                    }
                }
            }
            ans++;
        }
    
       return ans;
    }
};
