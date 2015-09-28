char* convert(char* s, int numRows) {
    int len = strlen(s);
    int zigNum = numRows - 2;
    char *res = NULL;
    int increase = 0;
    
    res = (char*)malloc(len+1);
    
    if(numRows<=1)
    {
        return s;
    }
    
    int index = 0;
    
    //中间行,temp_line:之前的个数；
	int temp_increase = 0;
    for(int i = 0;i<numRows && i<len;i++)
    {
		temp_increase = i;
		res[index++] = s[temp_increase];
		
        for(int j=1;temp_increase<len;j++)
        {
			if(0==i|| i == numRows - 1)
			{
				temp_increase += 2 * numRows - 2;;
			}
			else 
			{
			    if(j%2 == 1)
			    {
				    temp_increase += 2*(numRows-1-i);
			    }
			    else
    			{
    				temp_increase+=2*i;
    			}
    				
			}
			
			if(temp_increase<len)
			{
			    res[index++]=s[temp_increase];
			}
        }
    }

    
    res[len]='\0';
    return res;
}