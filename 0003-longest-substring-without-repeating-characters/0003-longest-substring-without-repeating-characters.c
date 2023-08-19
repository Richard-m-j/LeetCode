

int lengthOfLongestSubstring(char * s){

	int i=0,j,len=0,beg,end;
	int lastindex[128];

	for(j=0;j<128;j++)
		lastindex[j]=-1;
	for(j=0;s[j]!='\0';j++)
	{
		if(i<lastindex[s[j]]+1)
			i=lastindex[s[j]]+1;
		if(len<j-i+1)
		{
			len=j-i+1;
			beg=i;
			end=j;
		}
		lastindex[s[j]]=j;
	}
	return len;
}