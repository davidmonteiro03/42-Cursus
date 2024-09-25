/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:03:58 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 10:02:26 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "consts.h"
# include "headers.h"
# include "structs.h"

void		builtins_cd(t_cmds *cmd, t_shell *shell);
void		builtins_cdspecific(char *const key, t_env *env);
char		*builtins_changedir(char *const dir, t_env *env);
void		builtins_echo(t_cmds *cmd, t_shell *shell);
void		builtins_execute(t_cmds *cmd, t_shell *shell, bool need_fork);
void		builtins_execve(t_cmds *cmd, t_shell *shell, bool need_fork);
void		builtins_exit(t_cmds *cmd, t_shell *shell);
void		builtins_export(t_cmds *cmd, t_shell *shell);
char		*builtins_getpath(char *const path, t_env *env);
void		builtins_pwd(void);
void		builtins_unset(t_cmds *cmd, t_shell *shell);

int			cmds_append(t_shell *shell, t_cmds *node, char *const value);
char		**cmds_args(t_env *env, t_tokens *const tokens);
int			cmds_checkfiles(t_env *env, t_files *files);
void		cmds_clear(t_cmds **cmds);
void		cmds_controlfds(t_cmds *iter);
void		cmds_execute(t_shell *shell);
t_cmds		*cmds_first(t_cmds *const cmds);
int			cmds_heredoc(t_shell *shell, t_cmds *node, char *const value);
t_cmds		*cmds_last(t_cmds *const cmds);
t_cmds		*cmds_new(void);
void		cmds_nopipe(t_shell *shell);
int			cmds_openclosefds(t_cmds *cmds, int option);
int			cmds_parse(t_shell *shell);
void		cmds_print(int fd, t_cmds *const cmds);
void		cmds_pushback(t_cmds **cmds, t_cmds *node);
void		cmds_pushfront(t_cmds **cmds, t_cmds *node);
int			cmds_redin(t_shell *shell, t_cmds *node, char *const value);
int			cmds_redout(t_shell *shell, t_cmds *node, char *const value);
size_t		cmds_size(t_cmds *const cmds);

char		*display_basecheck(int *upper);
void		display_case_c(const char *str, va_list args, t_tmp *tmp);
void		display_case_di(const char *str, va_list args, t_tmp *tmp);
void		display_case_p(const char *str, va_list args, t_tmp *tmp);
void		display_case_percent(const char *str, t_tmp *tmp);
void		display_case_s(const char *str, va_list args, t_tmp *tmp);
void		display_case_u(const char *str, va_list args, t_tmp *tmp);
void		display_case_xx(const char *str, va_list args, t_tmp *tmp);
void		display_checksignal(const char *str, t_tmp *tmp, int nb);
void		display_checksignal_u(const char *str, t_tmp *tmp, int nb);
void		display_cutsizenumber(int *cutsize, int number, t_tmp *tmp);
void		display_cutsizenumber_u(int *cutsize, int number, t_tmp *tmp);
void		display_cutsizenumber_xx(const char *str, va_list args, t_tmp *tmp);
int			display_digits(const char *str, t_tmp *tmp);
int			display_figures(int *d);
int			display_fprintf(int fd, const char *str, ...);
int			display_minus(const char *str, t_tmp *tmp);
int			display_nbrlen(unsigned long long int nbr, int base);
int			display_nbrlen_ten(int nbr, int base);
int			display_nbrlen_unsigned(unsigned int nbr, int base);
int			display_number(const char *str, t_tmp *tmp, int *j);
int			display_plus(const char *str, t_tmp *tmp);
int			display_precision(const char *str, t_tmp *tmp);
void		display_putchar_len(int c, t_tmp *tmp);
void		display_puthex_pre(const char *str, t_tmp *tmp, int hex);
void		display_putnbr(long n, t_tmp *tmp);
void		display_putnbr_base(unsigned long long int nb, t_tmp *tmp,
				char *base);
void		display_putnbr_base_x(unsigned int nb, t_tmp *tmp, char *base);
void		display_putnbr_unsigned(unsigned int n, t_tmp *tmp);
void		display_putstr_len(char *c, t_tmp *tmp, int *size);
void		display_putstr_lennil(t_tmp *tmp);
void		display_putstr_lennull(t_tmp *tmp);
void		display_putstr_lenspaces(t_tmp *tmp, int *strsize, int *printsize);
void		display_putstr_lenszeros(t_tmp *tmp, int *strsize, int *printsize);
void		display_screening(const char *str, va_list args, t_tmp *tmp);
void		display_searchupper(const char *str, t_tmp *tmp, int *upper);
int			display_sharp(const char *str, t_tmp *tmp);
int			display_space(const char *str, t_tmp *tmp);
int			display_sps(const char *str, t_tmp *tmp, int n);
int			display_sps_u(const char *str, t_tmp *tmp, int n);
void		display_strsizenumber(const char *str, t_tmp *tmp, int number);
void		display_strsizenumber_u(const char *str, t_tmp *tmp, int number);
void		display_strsizenumber_xx(const char *str, t_tmp *tmp, int number);
int			display_uppercheck(const char *str, t_tmp *tmp);
int			display_width(const char *str, t_tmp *tmp);
int			display_zero(const char *str, t_tmp *tmp);

void		env_clear(t_env *env);
void		env_display(t_env *env, char *const sep, bool printenvs,
				bool printexps);
void		env_init(t_env *env, char *const *envp, void (*insert)(t_vars **,
					t_vars *));
void		env_underscoreup(t_env *env, char *const newstr);
void		env_unset(t_env *env, char *const key);

void		execute_main(t_shell *shell);

void		exp_clear(t_exp *exp);
void		exp_execute(t_env *env, t_exp exp, char *const arg,
				void (*insert)(t_vars **, t_vars *));
void		exp_init(t_exp *exp, char *const str);
void		exp_print(int fd, t_exp *exp);

void		files_clear(t_files **files);
t_files		*files_first(t_files *const files);
t_files		*files_last(t_files *const files);
t_files		*files_lastin(t_files *const files);
t_files		*files_lastout(t_files *const files);
t_files		*files_new(t_type const type, char *const name);
void		files_print(int fd, size_t tabs, t_files *const files);
void		files_pushback(t_files **files, t_files *node);
void		files_pushfront(t_files **files, t_files *node);

char		**parse_expand(t_env *env, char *const str);
void		parse_heredocexpand(int fd, t_env *env, char *const str);
char		*parse_quotes(char *const str);
bool		parse_readline(t_shell *shell);
t_tokens	*parse_somefix(t_tokens *tokens);
t_tokens	*parse_vars(t_tokens *tokens, t_env *env);

t_shell		*shell_backup(t_shell *shell);
void		shell_hardreset(t_shell *shell);
void		shell_init(t_shell *shell, char *const *envp);
void		shell_softreset(t_shell *shell);

void		signals_handler(t_shell *shell, t_mode mode);
void		signals_status(pid_t pid);

int			syntax_error(t_error error_code, char *const token);
int			syntax_parse(t_tokens *tokens);
int			syntax_unexpected_eof_match(char const c);

void		temp_clear(t_temp *temp);
void		temp_init(t_temp *temp);

void		tokens_clear(t_tokens **tokens);
t_tokens	*tokens_first(t_tokens *const tokens);
char		*tokens_getoper(char *const line, size_t *i);
char		*tokens_gettext(char *const line, size_t *i);
t_tokens	*tokens_parse(char *const line, size_t i);
bool		tokens_isoper(char const c);
t_tokens	*tokens_last(t_tokens *const tokens);
t_tokens	*tokens_new(char *const value, t_type const type,
				bool const restricted);
void		tokens_print(int fd, size_t tabs, t_tokens *const tokens);
void		tokens_pushback(t_tokens **tokens, t_tokens *node);
void		tokens_pushfront(t_tokens **tokens, t_tokens *node);
size_t		tokens_size(t_tokens *const tokens);

t_tokens	*utils_atott(char *const str);
char		*utils_exportkey(char *const str);
bool		utils_exportvalidop(char const curr, char const next);
void		utils_freestrs(char **strs);
bool		utils_isspace(char const c);
char		*utils_joinfree(char *const s1, char *const s2);
char		*utils_laststr(char *const *strs);
char		**utils_listtoarray(t_vars *const vars);
int			utils_shellatoi(char *const str);
int			utils_strcmp(char *const s1, char *const s2);
char		*utils_strconstruct(char const c, size_t len);
char		*utils_strflex(char *const line, size_t *i);
int			utils_syscallerror(char *const func);
char		**utils_tokenstostrs(t_tokens *const tokens);

void		vars_clear(t_vars **vars);
t_vars		*vars_copy(t_vars *const vars, void (*insert)(t_vars **, t_vars *));
void		vars_delone(t_vars *node);
t_vars		*vars_dup(t_vars *source);
void		vars_export(t_vars **vars, t_exp exp, void (*insert)(t_vars **,
					t_vars *));
t_vars		*vars_first(t_vars *const vars);
char		*vars_getvalue(t_env *env, char *const key);
t_vars		*vars_last(t_vars *const vars);
t_vars		*vars_new(char *const str);
t_vars		*vars_new2(t_exp const exp);
void		vars_pushback(t_vars **vars, t_vars *node);
void		vars_pushfront(t_vars **vars, t_vars *node);
void		vars_remove(t_vars **vars, t_vars *node);
void		vars_resetvalue(t_vars **vars, char *const key);
size_t		vars_size(t_vars *const vars);
void		vars_sort(t_vars *vars);
void		vars_unset(t_vars **vars, char *const key);

extern int	g_exit_status;

#endif // !MINISHELL_H
