//�Ƿ����п��ܻ�����ĳ��������Կ�����һ��������������ʹ��
bool isPalindrome(int x) {
    if(x<0)
    {
        return 0;
    }
    if(0==x)
    {
        return 1;
    }
    long res = 0;
    int temp = x;
    while(x)
    {
        res=res*10+x%10;
        x=x/10;
    }
    return (temp == res);
}