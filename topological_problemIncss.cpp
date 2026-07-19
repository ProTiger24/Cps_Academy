#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a, b) memset(a, b, sizeof(a))
#define sqr(a) ((a) * (a))

#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(10);           \
    cout.setf(ios::fixed, ios::floatfield);
#define file()                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

#define dbg(args...)            \
    do                          \
    {                           \
        cerr << #args << " : "; \
        faltu(args);            \
    } while (0)
void faltu() { cerr << endl; }
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest)
{
    cerr << arg << ' ';
    faltu(rest...);
}

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
const int mx = 2000005;
vi adj[mx];
int vis[mx];
vi topo_or;

int n, m;

void bfs(int u)
{
    vis[u] = 1;

    for (auto v : adj[u])
    {
        if (vis[v])
        {
            continue;
        }
        bfs(v);
    }

    topo_or.push_back(u);
}
void topological_sort()
{
    topo_or.clear();

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            bfs(i);
        }
    }

    reverse(topo_or.begin(), topo_or.end());
}
void solve()
{

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    topological_sort();

    int ans[n + 2];
    memset(ans, 0, sizeof(ans));

    ans[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int u = topo_or[i];

        if (u == n)
        {
            continue;
        }

        int sum = 0;

        for (auto it : adj[u])
        {
            sum += ans[it];
            sum %= 1000000007;
        }

        ans[u] = sum;
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }

    cout << endl;

    cout << ans[1] << endl;
}
int main()
{
    optimize();

    solve();

    return 0;
}
