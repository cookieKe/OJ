#define INTMAX 2147483647
#define INTMIN -2147483648

int reverse(int x) {
    long long res = 0;
    int flag = 1;
    //不知道为什么INTMIN的值在判断里无法通过，故特殊处理
    //留意题目下的click to show spoilers. 会对题目做出说明
    if(x == INTMIN)
    {
        return 0;
    }
    if(x<0)
    {
        flag =-1;
    }
    
    x=abs(x);
    while(x)
    {
        res = (10*res)+x%10;
        if(res > INTMAX || res*flag <INTMIN)
        {
            return 0;
        }
        x/=10;
    }
    
    res=res*flag;
    return res;
}