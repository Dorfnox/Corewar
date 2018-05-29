/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 10:46:43 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/28 13:22:41 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include "ft_printf.h"
# include "wtoi.h"
# include "terminalcolors.h"
# include "utility.h"

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct		s_queue
{
	struct s_node	*first;
	struct s_node	*last;
	uint32_t		size;
}					t_queue;

typedef struct		s_stack
{
	struct s_node	*top;
	uint32_t		size;
}					t_stack;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strdupuntil(const char *s, const char c);
char				*ft_strdupfrom(const char *s, const char c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
char				*ft_strrev(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strccount(char *str, char c);
int					ft_strccountto(char *str, char c);
int					ft_atoi(const char *str);
int					*ft_intarrayfromstr(char *str_of_ints);
int					ft_isalpha(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isdigit(int c);
int					ft_isstrdigits(char *s);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isstrprints(char *s);
int					ft_iswhitespace(int c);
int					ft_striswhitespace(char *s);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_strtoupper(char **s);
void				ft_strtolower(char **s);
void				*ft_memalloc(size_t size);
void				*ft_remalloc(void *content, size_t o_size, size_t n_size);
void				*ft_rememalloc(void *content, size_t o_size, size_t n_size);
void				ft_memdel(void **ap);
void				ft_memdelplus(void ***p);
char				*ft_strnew(size_t size);
char				*ft_strfnew(char **s, size_t size);
void				ft_strdel(char **as);
void				ft_strdeltwo(char **as, char **as2);
void				ft_strdelthree(char **as, char **as2, char **as3);
void				ft_strdelfour(char **as, char **as2, char **as3,
					char **as4);
void				ft_strclr(char *s);
void				ft_strnclr(char *s, size_t len);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strfsub(char **s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strfjoin(char **s1, const char *s2);
char				*ft_strffjoin(char **s1, char **s2);
char				*ft_strfremalloc(char **s);
char				*ft_strfresize(char **s, size_t newsize);
char				*ft_strremove(char *s, char *rc);
char				*ft_strremovenobs(char *s, char *rc);
char				*ft_strcremove(char *s, char rc);
char				*ft_strcremovenobs(char *s, char rc);
char				*ft_strfremove(char **s, char *rc);
char				*ft_strofchars(const char c, size_t num);
char				*ft_strtrim(char const *s);
char				*ft_strctrim(char const *s, const char c);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplits(char const *s, char *chrctrs);
char				*ft_strfindnreplace(char *s, char f, char r, int n);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);
void				ft_putchar(char c);
size_t				ft_putchars(const char c, size_t n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_puterror(const char *error_message, int return_value);
void				*ft_putnull(const char *error_message);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_swap(int *a, int *b);
char				**ft_arraynew(int width, int height);
void				**ft_varraynew(int width, int height, size_t size);
char				***ft_arraynew4d(int width, int height, int depth);
int					ft_arraylen(void **array);
char				**ft_arraydel(char ***array);
void				ft_varraydel(void ***a, int i);
char				**ft_arraydup(char **old);
int					ft_arrayprint(char **a);
unsigned int		ft_arrayappend(char ***save, char *param);
void				ft_setdoubletozero(double *a, double *b, double *c,
					double *d);
void				ft_setunsignedinttozero(unsigned int *a, unsigned int *b,
					unsigned int *c, unsigned int *d);
void				ft_setunsignedshorttozero(unsigned short *a,
					unsigned short *b, unsigned short *c, unsigned short *d);
void				ft_setnull(void *a, void *b, void *c, void *d);
int					ft_rgb_to_hex(short r, short g, short b);
int					ft_shade_colour(int colour, double percent,
					double constant);
double				ft_percentof(double a, double percent);
int					ft_gnl(const int fd, char **line);
int					ft_abs(int n);
int					ft_sign(int n);
long long			ft_powerof(long long num, int power);
unsigned int		ft_unsignedintlen(unsigned int x);
void				ft_putunsignedint(unsigned int n);
char				*ft_sandwichjoin(char *path1, char *path2, char *sandwich);
char				*ft_sandwichfjoin(char **p1, char *p2, char *sandwich);
char				*ft_sandwichffjoin(char **p1, char **p2, char *sandwich);
int					ft_debug(char *str);
char				*ft_concat_params(int argc, char **argv);
char				*ft_strremovequotes(char *s);
char				*ft_strfremovequotes(char **s);
void				ft_clearterminal(int fd, int num);
char				*ft_strreplace(char *s, char *find, char *replace);
char				*ft_trim(char *s);
char				*ft_strsplice(char *s, int i, char *u);
char				*ft_strfsplice(char **s, int i, char *u);

void				ft_csave(void);
void				ft_crestore(void);
void				ft_cforward(int num);
void				ft_cbackward(int num);
void				ft_cmove(int num);
void				ft_cplace(int row, int column);
void				ft_cclearscreen(int num);
void				ft_cclearline(int num);

char				*ft_str128(int num, ...);
char				*ft_str256(int num, ...);
char				*ft_str1024(int num, ...);

t_queue				*initq(void);
void				enqueue(t_queue *q, void *content);
void				*dequeue(t_queue *q);
void				*peekq(t_queue *q);
int					isemptyq(t_queue *q);

t_stack				*inits(void);
void				push(t_stack *s, void *content);
void				*pop(t_stack *s);
void				*peeks(t_stack *s);
int					isemptys(t_stack *s);

size_t				getfilecontents(char *filename, char **contents);
size_t				writetofile(char *filename, char *contents);
void				printbits_little_endian(void *array, size_t size);
void				printbits_big_endian(void *array, size_t size);

char				*convert_string_to_hex_string(char *s);
char				convert_hex_char_to_4bit(uint8_t c);
char				*random_hex_string(size_t size);
uint64_t			str_to_64bit(char *s, char **s2);

uint64_t			hex_str_to_64bit_be(char *s);
uint64_t			hex_str_to_64bit_le(char *s);

#endif
