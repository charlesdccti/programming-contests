#include <stdio.h>
const int MAXN = 100100;
 
int n, vet[MAXN], BIT[MAXN];
void update(int idx, int v){
    while(idx<=n){
        BIT[idx]+=v;
        idx+=(idx&-idx);
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
 
int main(){
    int x;
    char c;
 
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &vet[i]);
        update(i,vet[i]);
    }
    while(scanf(" %c", &c)!=EOF){
        scanf("%d", &x);
        if(c=='a') update(x,-vet[x]);
        else printf("%d\n", query(x-1));
    }
 
    return 0;
}