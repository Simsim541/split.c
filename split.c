#include <stdlib.h>

//static int	ft_check(const char *string, char c)
//{
	//int	i;
	//int yes;

	//i = 0;
	//yes = 0;
	//while (string[i] != '\0')
	//{
		//if (string[i] != c)
			//yes++;
		//i++;
	//}
	//return (yes);
//}

static int	count_word(const char *str, char n)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (str[0] != n)
		count++;
	while (str[i] != '\0')
	{
		if (str[i] != n && str[i - 1] == n)
			count++;
		i++;
	}
	return (count);
}

static int	check(const char *str, int i, char a)
{
	int	x;

	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return (x);
		x++;
		i++;
	}
	return (x);
}

char	*ft_dup(char *str, char x, int d, const char *string)
{
	int	i;
	int	index;

	index = d;
	i = 0;
	while (string[index] != x && string[index])
	{
		str[i] = string[index];
		i++;
		index++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_return(const char *word, int x, char h)
{
	while (word[x] != h && word[x])
		x++;
	return (x);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		k;
	int		number_of_word;

	if (!s)
		return (0);
	number_of_word = count_word(s, c);
	ptr = (char **)malloc((number_of_word + 1) * sizeof(char *));
	if (!ptr)
		return (0);
	k = 0;
	i = 0;
	while (i < number_of_word && s[k])
	{
		while (s[k] == c && s[k])
			k++;
		ptr[i] = (char *)malloc((check(s, k, c) + 1) * sizeof(char));
		ptr[i] = ft_dup(ptr[i], c, k, s);
		k = ft_return(s, k, c);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

