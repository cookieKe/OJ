#define INTMAX 2147483647
#define INTMIN -2147483648

int reverse(int x) {
    long long res = 0;
    int flag = 1;
    //��֪��ΪʲôINTMIN��ֵ���ж����޷�ͨ���������⴦��
    //������Ŀ�µ�click to show spoilers. �����Ŀ����˵��
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