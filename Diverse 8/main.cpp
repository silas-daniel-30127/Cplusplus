#include <stdio.h>
#include <string.h>

int main()
{
	int t, klen, i, inc;
	char k[1000002];
	scanf("%d\n", &t);
	while(t--)
	{
		gets(k);
		klen = strlen(k) - 1;
		inc = 1;
		for(i = 0; i <= klen; i++)
		{
			if(k[i] != '9')
			{
				inc = 0;
				break;
			}
		}
		if(inc)
		{
			k[0] = k[klen + 1] = '1';
			k[klen + 2] = '\0';
			memset(k + 1, '0', klen);
			printf("%s\n", k);
			continue;
		}
		i = inc = 0;
		while(i < klen)
		{
			if(k[klen] < k[i]) inc = 1;
			else if(k[klen] > k[i]) inc = 0;
			k[klen--] = k[i++];
		}
		if(i > klen)
		{
			i--;
			klen++;
		}
		if(!inc)
		{
			while(k[i] == '9')
			{
				k[i--] = k[klen++] = '0';
			}
			k[i] = k[klen] = k[i] + 1;
		}
		printf("%s\n", k);
	}
	return 0;
}
