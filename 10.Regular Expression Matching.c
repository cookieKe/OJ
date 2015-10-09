the code doesn't work
µ›πÈ≤ª Ï¡∑£ø

bool isMatch(char* s, char* p) {
    if(NULL == s || NULL == p)
    {
        return -1;    
    }
    int flag = 1;
    int i=0;
    int j=0;
    int starnum = 0;
    while(*(p+i)!='\0')
    {

        switch (*(p+i))
        {
            case '*':
                flag = 1;
                if(*(s+j)!=*(s+j-1) && *(p+i-1)!='.')
                {
                    return false;
                }
                else if(*(p+i-1)=='.')
                {
                    if(*(p+strlen(p)-1)!='.' && *(p+strlen(p)-1)!='*')
                    {
                        return (*(s+strlen(s)-1) == *(p+strlen(p)-1));
                    }
                    else
                    {
                        return true;
                    }
                }
                while(*(s+j)==*(s+j+1))
                {
                    j++;
                }
                starnum++;
                break;
            case '.':
                break;
            default:
                
                if(*(s+j)=='\0')
                {
                    for(int k=i;k<strlen(p);k++)
                    {
                        if(p[k]=='*')
                        {
                            return isMatch(s+strlen(s)-1,p+i);
                        }
                        else
                        {
                            if(strlen(p)-starnum*2>strlen(s))
                             {
                                 return false;
                             }
                             return true;
                        }
                        
                    }
                    
                }
                flag = (*(p+i)==*(s+j));
                if( 0 == flag && (*(p+i+1)!='*'))
                {
                    return false;
                }
                else if(0 == flag && (*(p+i+1)=='*'))//if it is going to be match,next must be *,and the * means 0 former char
                {
                    i+=2;
                    continue;
                }
                break;
        }
        i++;
        j++;
        
    }
    return (j==strlen(s));
}