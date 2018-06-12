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
# include <ncurses.h>
# include "libft.h"
# include "op.h"

# define USAGE "usage: ./corewar ><>"

# define CSEM "Corewar Conflict:\n"

# define GAME_SPEED 5

# define MALL_ERR_MSG(a) ft_str256(2, "Failure to malloc: ", (a))
# define MALL_ERR(a, b) !(a) ? corewar_error(MALL_ERR_MSG(b), 1) : 1

# define PROCESS_STACK_LEN 1024
# define PROCESS_STACK core->process_stack
# define CURRENT_CYCLE core->env.cycle % PROCESS_STACK_LEN

# define ZERO_AT_BAD_INSTR(a) ((a) < 17 ? (a) : 0)

# define EB0 process->encoding_byte[0]
# define EB1 process->encoding_byte[1]
# define EB2 process->encoding_byte[2]

# define REG process->reg

# define ARG0 process->args[0]
# define ARG00 process->args[0][0]
# define ARG01 process->args[0][1]
# define ARG02 process->args[0][2]
# define ARG03 process->args[0][3]

# define ARG1 process->args[1]
# define ARG10 process->args[1][0]
# define ARG11 process->args[1][1]
# define ARG12 process->args[1][2]
# define ARG13 process->args[1][3]

# define ARG2 process->args[2]
# define ARG20 process->args[2][0]
# define ARG21 process->args[2][1]
# define ARG22 process->args[2][2]
# define ARG23 process->args[2][3]

# define VIZ(a) core->flag.viz ? (a) : 0
# define NCURSES_XLIMIT 189
# define NCURSES_YLIMIT	64

struct s_corewar;

enum
{
	P1 = 1,
	P2,
	P3,
	P4,
	DF,
	P1B,
	P2B,
	P3B,
	P4B,
	INFOZ
};

enum
{
	REGISTER = 1,
	DIRECT,
	INDIRECT
};

/*
**	Flag structs
**	----------------------------------------------------------------------------
*/

typedef struct			s_flag_queue
{
	char				*flag;
	void				*flag_func;
}						t_flag_queue;

typedef struct			s_flag
{
	uint8_t				dump:1;
	uint8_t				viz:1;
}						t_flag;

/*
**	Environment
**	----------------------------------------------------------------------------
*/

typedef struct			s_env
{
	uint64_t			cycle;
	uint64_t			max_cycles;
	uint64_t			dump;
	uint8_t				num_players;
}
						t_env;
/*
**	Ncurses handling
*/

typedef struct			s_ncurses_draw_data
{
	uint8_t				*value;
	uint8_t				value_size;
	uint8_t				start_x;
	uint8_t				start_y;
}						t_ndd;

typedef struct			s_ncurses
{
	WINDOW				*bored;
	WINDOW				*playa[4];
	WINDOW				*infoz;
	char				c_array[256][3];
	t_ndd				ncur_data;
}						t_ncurses;

/*
**	Core War structs
**	----------------------------------------------------------------------------
*/

typedef struct			s_player
{
	char				*filename;
	uint8_t				player_num;
	uint16_t			num_of_processes;
	uint64_t			last_live;
	uint64_t			num_live;
	uint16_t			instruction_size;
	header_t			header;
}						t_player;

typedef struct			s_board_node
{
	uint8_t				value;
	uint16_t			index;
	struct s_board_node	*next;
	struct s_board_node	*prev;
}						t_board_node;

typedef struct			s_process
{
	t_player			*player;
	t_board_node		*curr_pc;
	WINDOW				*cursor;
	uint64_t			id;
	uint8_t				encoding_byte[3];
	uint8_t				args[3][4];
	uint8_t				carry;
	uint8_t				reg[REG_NUMBER + 1][REG_SIZE];
	void				(*instruct)(struct s_corewar *, struct s_process *);
}						t_process;

typedef struct			s_operation
{
	void				(*instruct)(struct s_corewar *, struct s_process *);
	uint16_t			wait_time;
}						t_operation;

typedef struct			s_corewar
{
	t_env				env;
	t_flag				flag;
	t_queue				flag_queue;
	t_board_node		*board;
	t_board_node		*node_addresses[MEM_SIZE];
	t_stack				process_stack[PROCESS_STACK_LEN];
	t_player			player[MAX_PLAYERS];
	char				*playerfiles[MAX_PLAYERS + 1];
	t_operation			op[17];
	t_ncurses			ncur;
}						t_corewar;

/*
** For Debugging
*/

void					print_board(t_corewar *core, t_process *p);

/*
**	Error functions
*/

void					corewar_error(char *message, int return_value);

/*
**	Flag handling
*/

void					init_flag_queue(t_queue *q);
void					add_flag(t_queue *q, char *flag, void *flag_func);
unsigned int			flag_handler(t_corewar *c, char ***av);
void					*search_flag_queue(t_node *n, char *flag);
void					clean_flag_queue(t_queue *q);

/*
**	Initializing data
*/

void					retrieve_data(t_corewar *core, char **argv);
unsigned int			flag_dump(t_corewar *core, char ***argv);
unsigned int			flag_n(t_corewar *core, char ***argv);
unsigned int			flag_viz(t_corewar *core, char ***argv);
unsigned int			add_player_file(t_corewar *core, char *filename);
uint64_t				get_max_cycles(uint64_t init);

void					init_board(t_corewar *core);

void					init_operations(t_operation *core);
void					init_wait_times(t_operation *core);

void					init_c_array(t_corewar *core);

/*
**	NCurses Functionality
*/

void					init_ncurses(t_corewar *core);
void    				init_ncurses_colors(void);
void    				init_ncurses_bored(t_corewar *core);
void    				init_ncurses_playa(t_corewar *core);
void					init_ncurses_infoz(t_corewar *core);
void					terminate_ncurses(t_corewar *core);
void    				draw_process(t_ncurses *n, t_process *process);
void    				capture_ncur_data(t_ncurses *n, uint16_t index,
							uint8_t *value, uint8_t value_size);
void    				draw_to_bored(t_ncurses *n, uint8_t player_num);

void					print_process_info(t_ncurses *n, t_process *p);
void					print_game_info(t_corewar *core);

/*
**	Players
*/

void					add_new_player(t_corewar *core, char *f, uint8_t p_num);
size_t					import_player_file(char *filename, uint8_t **contents);
void					parse_player_name(t_player *p, uint8_t *contents);
void					parse_player_comment(t_player *p, uint8_t *contents);
void					init_player_processes(t_corewar *core);

/*
**	Processes
*/

t_process				*new_process(t_corewar *c, t_player *p, t_board_node *b,
							t_process *cpy);
void					insert_process(t_stack *s, t_process *p);
void					new_process_cursor(t_corewar *core, t_process *p);
void					move_process_cursor(t_corewar *core, t_process *p);

/*
** Instructions
*/
void					first_(t_corewar *core, t_process *process);
void					bad_(t_corewar *core, t_process *process);

void					live_(t_corewar *core, t_process *process);
void					exec_live(uint32_t args, t_process *p, t_env *env);

void					ld_(t_corewar *core, t_process *process);

void					st_(t_corewar *core, t_process *process);

void					add_(t_corewar *core, t_process *process);

void					sub_(t_corewar *core, t_process *process);

void					and_(t_corewar *core, t_process *process);
uint32_t				get_and_args(t_corewar *c, t_process *process,
							uint16_t index, uint8_t arg_num);

void					or_(t_corewar *core, t_process *process);
uint32_t				get_or_args(t_corewar *c, t_process *process,
							uint16_t index, uint8_t arg_num);

void					xor_(t_corewar *core, t_process *process);
uint32_t				get_xor_args(t_corewar *c, t_process *process,
							uint16_t index, uint8_t arg_num);

void					zjmp_(t_corewar *core, t_process *process);

void					ldi_(t_corewar *core, t_process *process);

void					sti_(t_corewar *core, t_process *process);

void					fork_(t_corewar *core, t_process *process);

void					lld_(t_corewar *core, t_process *process);

void					lldi_(t_corewar *core, t_process *process);

void					lfork_(t_corewar *core, t_process *process);

void					aff_(t_corewar *core, t_process *process);

/*
**	Loop and Stack
*/

void					loop(t_corewar *core);
void					loop_viz(t_corewar *core);
uint8_t					cycle_handle(t_corewar *core);
void    				game_speed(uint8_t speed);

/*
** Utilities
*/

uint8_t					parse_encoding_byte(t_process *process);
uint8_t					parse_arguments(t_process *process);
uint32_t				smash_bytes(uint8_t *reg);
uint8_t					*unsmash_bytes(uint32_t nbr);

/*
** Write Bytes
*/

uint16_t 				get_index(uint16_t pc, uint8_t idx_byte1, uint8_t idx_byte2);
void					write_number_to_board(t_board_node *board, uint8_t *number);
void					write_board_to_register(uint8_t *reg, t_board_node *board);
void					write_number_to_register(uint8_t *reg, uint32_t nbr);
void					write_reg_to_reg(uint8_t *dst_reg, uint8_t *src_reg);
uint32_t				read_from_board(t_board_node *board, uint8_t bytes);

#endif
