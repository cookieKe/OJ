//是否所有可能会溢出的场景都可以考虑用一个更大的数据类型存放
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