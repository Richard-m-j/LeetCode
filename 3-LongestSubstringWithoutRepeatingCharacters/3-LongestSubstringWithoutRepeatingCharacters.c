// Last updated: 7/24/2025, 8:36:58 AM


int lengthOfLongestSubstring(char * s){

	int i=0,j,len=0,beg,end;
	int lastindex[128];

	memset(lastindex, -1, sizeof(lastindex));
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