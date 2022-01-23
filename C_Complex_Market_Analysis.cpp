#include <bits/stdc++.h>
#define ll long long
#define fr(i, k, n) for (int i = k; i < n; i++)
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long double ld;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define endl "\n"
#define coutt(x) cout<<x<<endl
#define kroot(n,k) pow(n,(long double)1.0/k)//for finding kth root of a number. If the result of this function is is x due to truncating it is possible that (x+1) is the real answer  
#define mod 1000000007
// always use __gcd(x,y) for finding gcd,its way faster
#define debug(x) cout<<#x<<" "<<x<<endl;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define Precision(a) cout << fixed << setprecision(a)
ll inf = 1e18;
#define all(a) a.begin(),a.end()
const int N=1000000+2;
int     dx []    =  {-1 , 0 , 1 , 0 ,-1,-1, 1,  1};
int     dy []    =  { 0 , 1 , 0 ,-1 ,-1, 1, 1, -1};
char    dir[]    =  {'U','R','D','L'};
 
 
int bPow(ll a, ll b){
    int res = 1;
    while(b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        b >>= 1;
        a = (a * a) % mod;
    }
    return res % mod;
}
 
int gcd(ll a, ll b){
    if(a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
 
}
 
vector<ll> fact(N, 0ll);
void factorial(){
    fact[0] = 1, fact[1] = 1;
    for(int i = 2; i < N; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
 
int ncr(ll n, ll r){
    if(r > n)
        return 0;
    int ans = fact[n] % mod;
    ans *= bPow(fact[r], mod - 2) % mod;
    ans %= mod;
    ans *= bPow(fact[n - r], mod - 2) % mod;
    ans %= mod;
    return ans;
}
 

vector<bool> is_prime(N+1, true);
void sieve(){ 
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= N; i++) {
    if (is_prime[i] && (long long)i * i <= N) {
        for (int j = i * i; j <= N; j += i)
            is_prime[j] = false;
    }
}
}
 
int add(ll a, ll b){
    a %= mod, b %= mod;
    return ((a + b) % mod + mod) % mod;
}
int mul(ll a, ll b){
    a %= mod, b %= mod;
    return ((a * b) % mod + mod) % mod;
}

 vector<ll> pos[1000000+2];
void solve()
{   
 

   ll n,ee;
   cin>>n>>ee;
   vector<ll> ar(n+2);
   
  
   fr(i,0,n)
   {cin>>ar[i];
   
    pos[ar[i]].PB(i);
   }

   ll ans=0;
   
   fr(i,0,n)
   {
       if(is_prime[ar[i]] && pos[ar[i]].size()>0)
       {  
          for(auto x:pos[ar[i]])
          {
              ll j=x-ee;
              ll t1=0;
              while(j>=0 && ar[j]==1)
              {   t1++;
              
                  j-=ee;
              }
              j=x+ee;
              ll t2=0;
              while(j<n && ar[j]==1)
              {t2++;
             
              j+=ee;}

              ans+=t1;
              ans+=t2;
              ans+=(t1*t2);
          }
          pos[ar[i]].clear();
          
       }
       }
   
   
   cout<<ans<<endl;
   
}
int main()
{    
    fast;
    ll t;
    cin>>t;
    sieve();
  
    while (t--)
    {
        solve();
    }
    return 0;
}