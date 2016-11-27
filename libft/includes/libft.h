/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:49:04 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/27 13:25:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_xattr.h"
# include "mytime.h"
# include "lst.h"
# include "dlst.h"
# include "btree.h"
# include "color.h"

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>

# define FT_WS(x) (x == ' ' || x == '\t' || x == '\n')
# define FT_ABS(x) (((x) < 0) ? -(x) : (x))
# define FT_NEG(x) (((x) < 0) ? 1 : 0)
# define FT_POS(x) (((x) > 0) ? 1 : 0)
# define FT_MIN(a, b) ((a) < (b) ? (a) : (b))
# define FT_MAX(a, b) ((a) > (b) ? (a) : (b))
# define FT_DIST(a, b) (FT_ABS((a) - (b)))

typedef struct s_stof	t_stof;

struct	s_stof
{
	char	*name;
	int		(*f)();
};

void	ft_debug(void);

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
int		ft_putchar(int c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putaddr(void *a);

char	*ft_strrev(char *str);
char	**ft_strsplit(char const *s, char c);
char	*ft_str3join(char const *s1, char const *s2, char const *s3);
char	*ft_strcut(char *str, char *cut);
char	**ft_split_whitespaces(char *str);
char	*ft_convert_base(
		char *str, char *base_from, char *base_to, char *flags);
char	*ft_strcatf(char *s1, const char *s2);
char	*ft_strinsert(char *str, char c, int n);

char	*ft_itoa_base(int nbr, char *base, char *flags);
char	*ft_lltoa_base(long long nbr, char *base, char *flags);
char	*ft_ulltoa_base(unsigned long long nbr, char *base);
char	*ft_uitoa_base(unsigned int nbr, char *base);
size_t	ft_ilen(int n);
size_t	ft_ilen_base(int n, int base);
size_t	ft_uilen(unsigned int n);
size_t	ft_lllen(long long n);
size_t	ft_lllen_base(long long n, int base);
int		ft_addrcmp(void *a, void *b);

char	**ft_sstradd(char **list, char *new);
void	ft_sstrsort(char **list, int (*cmp)());
void	ft_sstrprint(char **list, char sep);
char	**ft_sstrdup(char **list);
void	ft_sstrdel(char **sstr, int index);
void	ft_sstrfree(char **sstr);

char	*ft_path_notdir(char *path);

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);

char	*ft_getenv(char **env, char *key);

void	*ft_realloc(void *data, int size);
#endif
