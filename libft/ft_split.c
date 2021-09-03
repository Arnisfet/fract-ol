//
// Created by Mickey Rudge on 5/8/21.
//
// Функция итерируется по строке, подсчитывая слова при нахождении
// разделительного символа с. Создает массив указателей куда записывается
// каждое слово по отдельности.
//
//return: Указатель на начало массива arr_2 (arr_2 - massiv) сделано для
// возрата к нулевому указателю, так как запись идет по адресам.
//
//Use function: ft_count_words - подсчет слов; ft_strndup - выделение памяти
// для н символов.

#include "libft.h"

static char	**ft_free(char **arr)
{
	int	i;

	i = 0;
	if (arr[i])
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
		arr = NULL;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	counter;
	char	**arr_2;
	int		len;
	int		len_s;

	len = 0;
	counter = ft_count_words(s, c);
	arr_2 = (char **) malloc(sizeof(char *) * (counter + 1));
	if (!arr_2)
		return (NULL);
	while (s[len])
	{
		while (s[len] == c)
			len++;
		len_s = len;
		while (s[len] && s[len] != c)
			len++;
		if (len > len_s)
			*arr_2++ = ft_strndup(&s[len_s], (len - len_s));
		if (!*arr_2)
			return (ft_free(arr_2));
	}
	*arr_2 = (NULL);
	return (arr_2 - counter);
}
