#include<stdio.h>
#define MOD 998244353L

typedef long long ll;

ll count(int a, int b, int c)
{
    if((a == 0 && b == 0) || (a == 0 && c == 0) || (b == 0 && c == 0))
    {
        return 1;
    }
    ll ans = 0;
    if(a > 0)
    {
        ans = ans + count(a-1, b, c);
    }
    if(b > 0)
    {
        ans = (ans + count(a, b-1, c))%MOD;
    }
    if(c > 0)
    {
        ans = (ans + count(a, b, c-1))%MOD;
    }
 
	return ans;
}
int main()
{
	int X1,Y1,Z1;
	int X2,Y2,Z2;
	scanf("%d %d %d", &X1, &Y1, &Z1);
	scanf("%d %d %d", &X2, &Y2, &Z2);
	int a = X2-X1;
	int b = Y2-Y1;
	int c = Z2-Z1;
	if(a<0)
		a = -1*a;
	if(b<0)
		b = -1*b;
	if(c<0)
		c = -1*c;
	

	printf("%lld", count(a,b,c));
	return 0;

}