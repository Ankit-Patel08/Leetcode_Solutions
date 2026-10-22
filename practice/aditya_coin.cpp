// Advitiya Coin

// void solve() {
//     ll n, k;
//     cin >> n >> k;
//     vector<ll> p(n);
//     for(int i = 0; i < n; i++) cin >> p[i];
//     ll cnt = 0;
//     ll mini = 1e18, maxi = -1e18;
//     for (int i = 0; i < n; i++){
//         if (p[i] - mini > k || maxi - p[i] > k) {
//             cnt++;
//             mini = 1e18;
//             maxi = -1e18;
//         } 
//         else{
//             mini = min(mini, p[i]);
//             maxi = max(maxi, p[i]);
//         }
//     }
//     cout << cnt << endl;
// }


//

// const ll MOD=998244353;

// const int MAXN = 200000;
// vel fact(MAXN + 1),pow2(MAXN + 1);

// void precompute() {
//   fact[0] = 1;
//   for (int i=1;i<=MAXN;i++){
//     fact[i]=fact[i-1]*i%MOD;
//   }
//   pow2[0]=1;
//   for (int i=1;i<=MAXN;i++) {
//     pow2[i]=pow2[i-1]*2%MOD;
//   }
// }

// void solve(){
//   ll n;
//   cin>>n;
//   vel a(n);
//   get(n,a);
//   sort(all(a));
//   ll mx=0,c=0;
//   for(ll i=0;i<n;){
//     ll j=i;
//     while(j+1<n&&a[j+1]==a[j]+1)j++;
//     ll len=j-i+1;
//     if(len>mx){
//       mx=len;
//       c=1;
//     }else if(len==mx)c++;
//     i=j+1;
//   }
//   ll ans=c*pow2[mx-1]%MOD;
//   ans=ans*fact[n-mx]%MOD;
//   cout<<ans<<endl;
// }