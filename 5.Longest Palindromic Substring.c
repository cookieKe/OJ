//算法复杂度太高，推荐的后缀树的方法没有看懂，看一下算法书学习一下
char* longestPalindrome(char* s) {
    int maxLen[1000]={1};
    int maxLength = 0;
    int strLen = strlen(s);
    int temp = 0;
    int max = 0;
    char *res = 0;
    int j = 0;
    int right = 0;
    int flag = 0;
    int mid = 0;
    int mid_index = 0;
    char *start = NULL;
    
    start = s;
    
    for(int i=0;i<strLen;i++)
    {
        for(j=strLen-1;j>temp;j--)
        {
			temp = i;
			
			for(int k = j;k>temp;k--)
			{
        			    
				if(s[temp] == s[k])
				{
				    
					temp++;
					if(!flag)
					{
						right = j;
						flag = 1;
					}
				}
				else if(flag)
				{
					right = 0;
					break;
				}
				else if(!flag)
				{
					break;
				}
				
			}

			if(right>i)
			{
			    if(right-i+1 > maxLength)
			    {
				    maxLength=right-i+1;
				    start = s+i;
			    }
				break;
			}

			flag = 0;
            
        }
        
        
    }
    
    res = (char*)malloc(maxLength+1);
    strncpy(res,start,maxLength);
    return res;
}

