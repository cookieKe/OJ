//感觉跟逻辑题差不多，学习一下其他思路
int myAtoi(char* str) {
    if(NULL == str)
    {
        return -1;
    }
    if("" == str)
    {
        return 0;
    }
    
    long long res = 0;
    int flag = 0;
    
    
    while(*str!='\0')
    {
        if(*str==' ')
        {
            if(res!=0)
            {
                break;
            }
            if(flag)
            {
                return 0;
            }
        }
        else if((*str<'0')||(*str>'9'))
        {
            if((1 == flag || -1 == flag)&&(*str=='+'||*str=='-'))
            {
				return 0;
                
            }
			if( 0 == flag && (*str=='+'||*str=='-'))
			{
				if(*str=='-')
				{
					flag = -1;
				}
				else
				{
					flag = 1;
				}
			}
			else if(*str!='+'&& *str!='-')
			{
				break;
			}
            
        }
        else
        {
            res = 10*res+(*str-'0');
            if(res > 2147483647 || res<0)
			{
				break;
			}
        }
        str++;
    }
    
    if(res > 2147483647 || res<0)
    {
        if(1==flag || 0==flag)
        {
            res = 2147483647;
        }
        else
        {
            res = 2147483648;
        }
    }
    
    if(0==flag)
	{
		flag = 1;
	}
    return res*flag;
}