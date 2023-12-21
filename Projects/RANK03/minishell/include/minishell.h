/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:43:35 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:45:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <dirent.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_exp
{
	char			*key;
	struct s_exp	*next;
}	t_exp;

typedef struct s_command
{
	char				*cmd;
	char				**args;
	struct s_command	*next;
}	t_command;

typedef struct s_input
{
	char			*line;
	char			*heardoc;
	int				with_out;
	char			**args;
	t_command		*command;
	struct s_input	*next;
}	t_input;

typedef struct s_mini
{
	char		*line;
	char		**envp;
	t_env		*env;
	t_exp		*exp;
	t_input		*input;
}	t_mini;

//-------------------Utils---------------------//
//ft_fprintf
int		ft_fprintf(int fd, const char *format, ...);
//general
char	*retkey(char *str);
char	*retval(char *str);
char	*struct_to_str(char *key, char *value);
char	*struct_to_str_env(char *key, char *value);
char	*ft_strtok(char *s, char *sep);
int		list_len_input(t_input *list);
char	*ft_joint_free(char *s1, char *s2);
char	*expand_arg_adv(char *arg, int i, int j);
//line
int		check_line(char *line);
int		skip(char *line, char c);
void	skip_space(char *line, int *i);
int		check_heardoc(t_mini *mini, int i);
int		check_special(char *line);
//init
t_input	*init_input(void);
void	init_mini(char **envp);
//signal
void	sig_handler(int sig);
void	sig_heardoc(int sig);
void	sig_fork(int sig);

//exp
int		list_len_exp(t_exp *list);
void	print_export(t_mini *mini);
void	add_exp(t_mini *mini, char *key);
void	ft_del_exp(t_exp **lst, char *key);
//env
int		list_len_env(t_env *list);
void	print_env(t_mini *mini);
void	add_env(t_mini *mini, char *key, char *value);
void	ft_del_env(t_env **lst, char *key);
//free
void	free_split(char **split);
void	free_arrays(char ***arrays);
void	free_input(t_input *input);
void	exit_minishell(t_mini *mini);
char	*trim_quotes(char *s);
char	**trim_args(char **args);
//error
void	no_path_err(char *str);
void	cd_err(char *str);
int		exec(t_input *input);
int		check_exp(t_mini *mini, char *check);
int		check_env(t_mini *mini, char *str, char *check);
char	*retpwd(t_mini *mini);
char	*retoldpwd(t_mini *mini);
//Process
int		handle_error(pid_t pid);

//-----------------------------------------------//

//-------------------Builtin---------------------//
int		exec_builtin(t_mini	*mini, t_input *input);
char	*read_file(int fd);
void	send_to_file(char *str, char *path, int append);

int		ft_pwd(t_input *input);
int		ft_cd(void);
int		ft_env(t_input *input);
int		ft_exit(void);
int		ft_echo(t_command *cmd);
int		ft_export(t_mini *mini, t_input *input);
int		ft_execve(t_mini *mini, t_input *input);
int		ft_unset(char **args, t_env **env, t_exp **exp);
void	pipe_exec(t_mini *mini);
//-----------------------------------------------//

//-------------------Parser----------------------//
char	*expand(char *line);
int		parser(void);
char	*verify_access(char *cmd);
char	**split_args(char *line, int i);
char	*ft_getenv(char *key);
//-----------------------------------------------//

//-----------------HEARDOC-----------------------//
int		call_heardoc(char **line, char **args, t_input *input);
int		call_heardoc_pipe(t_mini *mini);
int		handle_heardoc(int pid);
int		call_heardoc_quotes(char **line, char c);
//-----------------------------------------------//

//-------------------Redirects-------------------//
int		exec_red1(char **args, t_input *input);
int		exec_red2(char **args);
int		handle_redirect(t_input *input, int i);

//-----------------------------------------------//

char	*handle_quotes(char *line);
int		handle_quotes_count(char *line);
int		exec2(t_input *input);
void	redirects_heardoc(t_input *input);
void	s_exit_minishell(void);
t_mini	*get_mini(t_mini *mini);
void	free_env(t_env *env);

//-------------------API-------------------------//
t_env	*get_env(t_env *env);
t_exp	*get_exp(t_exp *exp);
t_mini	*get_mini(t_mini *mini);
int		get_exit_code(int code, int change);
//-----------------------------------------------//

//-------------------Wildcard---------------------//

typedef struct s_wild
{
	char	***sstrs;
	int		total;
}	t_wild;

//utils
int		ft_strscmp(const char *s1, const char *s2);
char	*ft_strlow(char *str);
int		strs_size(char **strs);
//args_utils
char	*new_args_util(const char *src);
char	**ft_new_args(char **src, int size);
void	sort_strs(char ***old, char **new, int i);
//wildcard
int		wild_question_mark(char *path, char *pattern);
int		wild_asterisk(char *path, char *pattern);
int		wild_brackets(char *path, char *pattern);
int		wild_match(char *path, char *pattern);
//get_wild_args
char	**wild_args(char **strs);
//-----------------------------------------------//

int		check_options(char **args, char *str);

#endif
