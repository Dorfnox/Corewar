/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/29 13:23:27 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <sys/stat.h>
# include "libft.h"
# include "op.h"

# define USAGE "usage: ./corewar ><>"

# define PROCESS_STACK_LEN 1000

# define CSEM "Corewar Conflict:\n"
/*
**	Flag structs
*/

struct					s_corewar;

typedef struct			s_flag_queue
{
	char				*flag;
	void				*flag_func;
}						t_flag_queue;

typedef struct			s_flag
{
	uint8_t				dump:1;
}						t_flag;

/*
**	Environment
*/

typedef struct			s_env
{
	uint64_t			cycle;
	uint64_t			max_cycles;
	uint64_t			dump;
	uint8_t				num_players;
}						t_env;

/*
**	Corezy Warzy structs
*/

typedef struct			s_player
{
	char				*filename;
	uint8_t				player_num;
	header_t			header;
	uint64_t			last_live;	// The cycle the last live was called
	uint64_t			num_live;	// num of times live was called
}						t_player;

typedef struct			s_process
{
	t_player			*player;
	uint8_t				reg[REG_NUMBER + 1][4];
	void				(*instr)(struct s_corewar *);
}						t_process;

typedef struct			s_corewar
{
	t_queue				*flag_queue;
	t_flag				flag;
	t_env				env;
	t_stack				process_stack[PROCESS_STACK_LEN];
	uint8_t				board[MEM_SIZE];
	t_player			player[MAX_PLAYERS + 1];
	char				*playerfiles[MAX_PLAYERS + 1];
	void				(*instr[16])(struct s_corewar *);
}						t_corewar;

/*
**	Error functions
*/

void					corewar_error(char *message, int return_value);

/*
**	Flag handling
*/

void					add_flag(t_queue **q, char *flag, void *flag_func);
unsigned int			flag_handler(t_corewar *c, char ***av);
void					*search_flag_queue(t_node *n, char *flag);
void					clean_flag_queue(t_queue **q);

/*
**	Retrieving data
*/

void					retrieve_data(t_corewar *core, char **argv);
unsigned int			flag_dump(t_corewar *core, char ***argv);
unsigned int			flag_n(t_corewar *core, char ***argv);
unsigned int			add_player_file(t_corewar *core, char *filename);
uint64_t				get_max_cycles(uint64_t init);

/*
**	Players
*/

void					add_new_player(t_corewar *core, char *f, uint8_t p_num);
size_t					import_player_file(char *filename, uint8_t **contents);
void					parse_player_name(t_player *p, uint8_t *contents);
void					parse_player_comment(t_player *p, uint8_t *contents);
void					init_player_processes(t_corewar *core);
void					writeinstructions_to_map(uint8_t location, uint8_t *instructions, uint8_t *board, uint16_t instr_size);

/*
**	Processes
*/

t_process				*new_process(t_player *player, uint32_t start);

#endif
