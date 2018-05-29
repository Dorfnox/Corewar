/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 18:31:43 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/25 14:11:46 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WTOI_H
# define WTOI_H

typedef struct	s_wtoi
{
	char		*s;
	char		*s_save;
	char		**w;
	char		**bw;
	int			n[29];
	long long	bn[4];
	long long	final;
	long long	*section;
	long long	initial;
	int			i;
}				t_wtoi;

long long		ft_wtoi(char *num);
char			*ft_strwtoi(char *s);

# define N_WRDS1 "ten eleven twelve thirteen "
# define N_WRDS2 "fourteen fifteen sixteen seventeen "
# define N_WRDS3 "eighteen nineteen twenty thirty "
# define N_WRDS4 "forty fifty sixty seventy "
# define N_WRDS5 "eighty ninety zero one "
# define N_WRDS6 "two three four five "
# define N_WRDS7 "six seven eight nine"
# define NUMBER_WORDS N_WRDS1 N_WRDS2 N_WRDS3 N_WRDS4 N_WRDS5 N_WRDS6 N_WRDS7
# define MORE_NUMBER_WORDS " hundred thousand million billion trillion and"
# define ALL_NUMBER_WORDS NUMBER_WORDS MORE_NUMBER_WORDS

# define IS_TEN ft_strnequ(last, "ten", 3)
# define IS_ELEVEN ft_strnequ(last, "eleven", 6)
# define IS_TWELVE ft_strnequ(last, "twelve", 6)
# define IS_THIRTEEN ft_strnequ(last, "thirteen", 8)
# define IS_FOURTEEN ft_strnequ(last, "fourteen", 8)
# define IS_FIFTEEN ft_strnequ(last, "fifteen", 7)
# define IS_SIXTEEN ft_strnequ(last, "sixteen", 7)
# define IS_SEVENTEEN ft_strnequ(last, "seventeen", 9)
# define IS_EIGHTEEN ft_strnequ(last, "eighteen", 8)
# define IS_NINETEEN ft_strnequ(last, "nineteen", 8)

# define IS_TEENZ1 (IS_TEN) || (IS_ELEVEN) || (IS_TWELVE) || (IS_THIRTEEN)
# define IS_TEENZ2 (IS_FOURTEEN) || (IS_FIFTEEN) || (IS_SIXTEEN)
# define IS_TEENZ3 (IS_SEVENTEEN) || (IS_EIGHTEEN) || (IS_NINETEEN)
# define IS_TEENZ (IS_TEENZ1) || (IS_TEENZ2) || (IS_TEENZ3)

# define IS_TWENTY ft_strnequ(last, "twenty", 6)
# define IS_THIRTY ft_strnequ(last, "thirty", 6)
# define IS_FORTY ft_strnequ(last, "forty", 5)
# define IS_FIFTY ft_strnequ(last, "fifty", 5)
# define IS_SIXTY ft_strnequ(last, "sixty", 5)
# define IS_SEVENTY ft_strnequ(last, "seventy", 7)
# define IS_EIGHTY ft_strnequ(last, "eighty", 6)
# define IS_NINETY ft_strnequ(last, "ninety", 6)

# define IS_TY1 (IS_TWENTY) || (IS_THIRTY) || (IS_FORTY) || (IS_FIFTY)
# define IS_TY2 (IS_SIXTY) || (IS_SEVENTY) || (IS_EIGHTY) || (IS_NINETY)
# define IS_TY (IS_TY1) || (IS_TY2)

# define IS_ZERO ft_strnequ(last, "zero", 4)

# define IS_ONE ft_strnequ(last, "one", 3)
# define IS_TWO ft_strnequ(last, "two", 3)
# define IS_THREE ft_strnequ(last, "three", 5)
# define IS_FOUR ft_strnequ(last, "four", 4)
# define IS_FIVE ft_strnequ(last, "five", 4)
# define IS_SIX ft_strnequ(last, "six", 3)
# define IS_SEVEN ft_strnequ(last, "seven", 5)
# define IS_EIGHT ft_strnequ(last, "eight", 5)
# define IS_NINE ft_strnequ(last, "nine", 4)

# define IS_SINGLE1 (IS_ONE) || (IS_TWO) || (IS_THREE) || (IS_FOUR) || (IS_FIVE)
# define IS_SINGLE2 (IS_SIX) || (IS_SEVEN) || (IS_EIGHT) || (IS_NINE)
# define IS_SINGLE (IS_SINGLE1) || (IS_SINGLE2)

# define IS_AND ft_strnequ(last, "and", 3)

# define IS_HUNDRED ft_strnequ(last, "hundred", 7)
# define IS_THOUSAND ft_strnequ(last, "thousand", 8)
# define IS_MILLION ft_strnequ(last, "million", 7)
# define IS_BILLION ft_strnequ(last, "billion", 7)
# define IS_TRILLION ft_strnequ(last, "trillion", 8)

# define IS_HUTHMIBITR1 (IS_HUNDRED) || (IS_THOUSAND) || (IS_MILLION)
# define IS_HUTHMIBITR2 (IS_BILLION) || (IS_TRILLION)
# define IS_HUTHMIBITR (IS_HUTHMIBITR1) || (IS_HUTHMIBITR2)

/*
** For function use:
*/

# define IS_AND_OKAY (IS_HUTHMIBITR)

# define ARE_DOUBLES_OKAY (IS_HUTHMIBITR) || (IS_AND)

# define ARE_SINGLES_OKAY (IS_HUTHMIBITR) || (IS_AND) || (IS_TY)

# define IS_HUNDRED_OKAY (IS_TEENZ) || (IS_TY) || (IS_SINGLE)

# define IS_THMIBITR_OKAY (IS_HUNDRED) || (IS_TEENZ) || (IS_TY) || (IS_SINGLE)

#endif
