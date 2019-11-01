#include<stdio.h>
#include<string.h>

#define maxn 10000001

bool flag[maxn];
int prime[1000000];
int num=0;

void init()
{
    unsigned long i,j;
    memset(flag,0,sizeof(flag));
    flag[1]=true;
    flag[0]=true;
    for(i=2;i<maxn;i++)
    {
        if(!flag[i])
        {
            prime[num++]=i;
            for(j=i*i;j<maxn;j=j+i)
                flag[j]=true;
        }
    }
}

int main()
{
    int i,a,b,c,d,n;
    init();
    while(scanf("%d",&n)!=EOF)
    {
        if(n<=7)
        {
            printf("Impossible./n");
            continue;
        }
        if(n&1)
        {
            a=2;
            b=3;
            n=n-5;
            for(i=0;i<num;i++)
            {
                if(!flag[n-prime[i]])
                {
                    c=prime[i];
                    d=n-prime[i];
                    break;
                }
            }
            printf("%d %d %d %d/n",a,b,c,d);
        }
        else
        {
            a=2;
            b=2;
            n=n-4;
            for(i=0;i<num;i++)
            {
                if(!flag[n-prime[i]])
                {
                    c=prime[i];
                    d=n-prime[i];
                    break;
                }
            }
            printf("%d %d %d %d/n",a,b,c,d);
        }
    }
    return 0;
}