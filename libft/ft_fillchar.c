
#include "libft.h"

char 	*ft_fillchar(long width, long len, char c)
{
	char	*new;
	long	i;
	
//	if (!size)
		
	i = -1;
	if (!(new = (char *)malloc(sizeof(char) * (width + 1))))
		return (NULL);
	while (++i < width - len)
		new[i] = c;
	new[i] = '\0';
	return (new);
}
