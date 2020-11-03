/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_str.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 22:07:14 by hlin          #+#    #+#                 */
/*   Updated: 2020/11/02 22:23:27 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test_strlen(char *str)
{
	int		res1;
	int		res2;

	res1 = strlen(str);
	res2 = ft_strlen(str);
	printf("str:       %s\n", (*str == '\0' ? "\\0" : str));
	printf("strlen:    %d\n", res1);
	printf("ft_strlen: %d\n", res2);
	if (res1 == res2)
		printf("" BLUE "test: OK" RESET "\n");
	else
		printf("" RED "test: KO" RESET "\n");
}

static void	test_strcpy(char *str)
{
	char	res1[200];
	char	res2[200];

	bzero(res1, 200);
	bzero(res2, 200);
	strcpy(res1, str);
	ft_strcpy(res2, str);
	printf("src_str:   %s\n", (*str == '\0' ? "\\0" : str));
	printf("strcpy:    %s\n", (*res1 == '\0' ? "\\0" : res1));
	printf("ft_strcpy: %s\n", (*res2 == '\0' ? "\\0" : res2));
	if (!strcmp(res1, res2))
		printf("" BLUE "test: OK" RESET "\n");
	else
		printf("" RED "test: KO" RESET "\n");
}

static void	test_strcmp(char *s1, char *s2)
{
	int		res1;
	int		res2;

	res1 = strcmp(s1, s2);
	res2 = ft_strcmp(s1, s2);
	printf("s1:        %s\n", (*s1 == '\0' ? "\\0" : s1));
	printf("s2:        %s\n", (*s2 == '\0' ? "\\0" : s2));
	printf("strcmp:    %d\n", res1);
	printf("ft_strcmp: %d\n", res2);
	if (res1 == res2)
		printf("" BLUE "test: OK" RESET "\n");
	else
		printf("" RED "test: KO" RESET "\n");
}

static void	test_strdup(char *str)
{
	char	*res1;
	char	*res2;
	int		err1;
	int		err2;

	res1 = strdup(str);
	err1 = errno;
	res2 = ft_strdup(str);
	err2 = errno;
	printf("src_str:         %s\n", (*str == '\0' ? "\\0" : str));
	printf("strdup:          %s\n", (*res1 == '\0' ? "\\0" : res1));
	printf("ft_strdup:       %s\n", (*res2 == '\0' ? "\\0" : res2));
	printf("errno strdup:    %d\n", err1);
	printf("errno ft_strdup: %d\n", err2);
	if (!strcmp(res1, res2) && (size_t)str != (size_t)res2 && err1 == err2)
		printf("" BLUE "test: OK" RESET "\n");
	else
		printf("" RED "test: KO" RESET "\n");
	free(res1);
	free(res2);
}

void		str_testing(void)
{
	printf("" YELLOW "====== testing strlen ======" RESET "\n");
	test_strlen("This is a string test");
	test_strlen("");
	test_strlen("This is a \0 string test");
	test_strlen("1234567890qwertyuiop[]");
	printf("" YELLOW "====== testing strcpy ======" RESET "\n");
	test_strcpy("This is a string test");
	test_strcpy("");
	test_strcpy("This is a \0 string test");
	test_strcpy("1234567890qwertyuiop[]");
	printf("" YELLOW "====== testing strcmp ======" RESET "\n");
	test_strcmp("This is a string test", "This is a string test");
	test_strcmp("", "");
	test_strcmp("Test", "");
	test_strcmp("", "Test");
	test_strcmp("This is a \0 string test", "This is a ");
	test_strcmp("1234567890qwertyuiop[]", "1234567890qwertyuiop");
	printf("" YELLOW "====== testing strdup ======" RESET "\n");
	test_strdup("This is a string test");
	test_strdup("");
	test_strdup("\0");
	test_strdup("\n");
	test_strdup("This is a \0 string test");
	test_strdup("1234567890qwertyuiop[]");
}
