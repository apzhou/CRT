#include<cstdio>
#define LL long long
#define in(x) scanf("%lld",x)
#define add(a,b) a=(a+b)%s
LL k,a[11],b[11],i,x,y,t,s=1,ans=0;
void exgcd(LL a,LL b){//扩欧
    if(!b){x=1;y=0;return;}
    exgcd(b,a%b);
    t=x;x=y;y=t-a/b*y;
}
LL mul(LL a,LL b){//快速乘
    LL r=0;
    while(b){
        if(b&1)add(r,a);
        add(a,a);
        b>>=1;
    }
    return r;
}
int main(){
    in(&k);
    for(i=1;i<=k;++i)in(a+i);
    for(i=1;i<=k;++i)in(b+i),s*=b[i];//求lcm
    for(i=1;i<=k;++i){
        exgcd(s/b[i],b[i]);
        x=(x%b[i]+b[i])%b[i];//求xi最小非负整数解
        add(ans,mul(s/b[i]*x,(a[i]%b[i]+b[i])%b[i]));//别忘处理ai
    }
    printf("%lld\n",ans);
    return 0;
}
