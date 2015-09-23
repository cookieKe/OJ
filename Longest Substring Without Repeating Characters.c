int containsChar(char c,char *s,int len)
{
    for(int i=0;i<len;i++)
    {
        if(*(s+i) == c)
        {
            return 0;
        }
    }
    return 1;
}

int getOneDirectLen(char* temp)
{
    int res = 0;
    int max = 0;
    char *str = NULL;
    
    str = temp;
    while(*temp!='\0')
    {
        if(containsChar(*temp,str,temp-str))
        {
            max++;
        }
        else
        {
            res = max>res?max:res;
            max = 1;
            temp = str;
            temp++;
			str = temp;
        }
        temp++;
    }
    
    
    return (res>max?res:max);
}

int lengthOfLongestSubstring(char* s) {
    int max = 0;
    char *temp = NULL;
	char *str = NULL;
    
    if(NULL == s)
    {
        return -1;
    }

    max = getOneDirectLen(s);
    
    return max;
}