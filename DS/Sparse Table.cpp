  
// Finding max , min , gcd , and , or etc. in a range for a static array.
// 1-indexed array
const int LG = 20; // 1e6
int P[N][LG];



for(int i = 1;i <= n;i++) P[i][0] = arr[i];
for(int i = 1; i < LG; i++){
        for(int j = 1;j + (1<<i) - 1 <= n;j++)
                P[j][i] = max(P[j][i - 1] , P[j + (1<<(i - 1))][i - 1]);
}

int query(int l , int r){
  int lg;  
  int len = r - l + 1;
  for(lg = 0; (1<<lg) <= len; lg++); lg--;
  //2^lg <= len of that range
  return max(P[l][lg] , P[r - (1<<lg) + 1][lg]);
} 
