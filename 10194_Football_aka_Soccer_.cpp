#include <bits/stdc++.h>
#define ll long long
#define rep(I,N) for(I=0;I<N;I++)
#define repp(I,A,B) for(I=A;I<=B;I++)
#define rrep(N,I) for(I=N;I>=0;I--)
#define rrepp(A,B,I) for(I=A;I>=B;I--)
#define MS0(X) memset(X,0,sizeof(X))
#define MS1(X) memset(X,-1,sizeof(X))
#define F first
#define S second
#define mp make_pair
#define Mod 1000000007
#define pb push_back
#define RF freopen("riyad.txt","r",stdin)
#define WF freopen("out.txt","w",stdout)
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define all(n) (n).begin(),(n).end()
#define vi vector < int >
#define vll vector < long long int >

using namespace std;

typedef unsigned long long ull;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
map < string , int > earned , scored , concede , played , wins , draw;
map < string , int > :: iterator it;
struct Tournament{
    string team;
    int point;
    int g_scored;
    int g_diff;
    int m_wins;
    int m_played;
}a[50];

void init(){
    earned.clear() , scored.clear() , concede.clear(),
    played.clear() , draw.clear() , wins.clear();
    for(int i=0;i<50;i++){
        a[i].point = a[i].g_scored = a[i].g_diff = 0;
        a[i].m_wins = a[i].m_played = 0;
    }
}
bool cmp(Tournament &x , Tournament &y){
    string one , two;
    one = x.team , two = y.team;
    transform(one.begin(),one.end(),one.begin(),::tolower);
    transform(two.begin(),two.end(),two.begin(),::tolower);
    if(x.point == y.point){
        if(x.m_wins == y.m_wins){
            if(x.g_diff == y.g_diff){
                if(x.g_scored == y.g_scored){
                    if(x.m_played == y.m_played)
                        return one < two;
                    return x.m_played < y.m_played;
                }
                return x.g_scored > y.g_scored;
            }
            return x.g_diff > y.g_diff;
        }
        return x.m_wins > y.m_wins;
    }
    return x.point > y.point;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //RF;
    //WF;
    ll i,tc,cs=1,n,m,k,cnt=0,j,q,c , g,t;
    char ch;
    string Tournament_name , match , team1 , team2 , temp;
    cin>>tc;
    cin.ignore();
    while(tc--){
        getline(cin,Tournament_name);
        cout<<Tournament_name<<endl;
        cin>>t;
        cin.ignore();
        for(i = 0 ; i < t ; i++){
            getline(cin,a[i].team);
        }
        cin>>cs;
        cin.ignore();
        for(i=0;i<cs;i++){
            getline(cin,match);
            team1 = team2 = "";
            k = q = 0;
            n = match.size();
            for(j = 0 ; j < n and match[j] != '#'; j++)
                team1 += match[j];
            j++;
            while(match[j] >= '0' and match[j] <='9' and j < n)q = q * 10 + match[j] - '0',j++;
            j++;
            while(match[j] >= '0' and match[j] <='9' and j < n)k = k * 10 + match[j] - '0',j++;
            while(j < n - 1)team2 += match[++j];
            concede[team2] += q , scored[team1] += q;
            concede[team1] += k , scored[team2] += k;
            played[team1]++ , played[team2]++;
            if(q > k)
                earned[team1] += 3 , wins[team1]++;
            else if(q < k)
                earned[team2] += 3 , wins[team2]++;
            else
                earned[team1]++,earned[team2]++,draw[team1]++,draw[team2]++;
        }
        for(i=0;i<t;i++){
            a[i].point = earned[a[i].team];
            a[i].g_scored = scored[a[i].team];
            a[i].g_diff = scored[a[i].team] - concede[a[i].team];
            a[i].m_played = played[a[i].team];
            a[i].m_wins = wins[a[i].team];
        }
        sort(a,a+t,cmp);
        for(i=0;i<t;i++){
            cout<<i+1<<") "<<a[i].team<<' '<<a[i].point<<"p, "<<a[i].m_played<<"g (";
            cout<<a[i].m_wins<<'-'<<draw[a[i].team]<<'-'<<a[i].m_played - (a[i].m_wins + draw[a[i].team]);
            cout<<"), "<<a[i].g_diff<<"gd ("<<a[i].g_scored<<'-'<<concede[a[i].team]<<')'<<endl;
        }
        if(tc)
            cout<<endl;
        init();
    }
    return 0;
}
