/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:52:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/29 09:33:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_error_bonus(t_check *check, t_list **list_a, t_list **list_b)
{
	if (check != NULL)
	{
		ft_free(&check->buffer);
		ft_free(&check->line);
		ft_free(&check->tmp);
	}
	ft_lstclear(list_a, &free_content);
	ft_lstclear(list_b, &free_content);
	ft_error();
}

void	ft_display_stacks(t_list **list_a, t_list **list_b, bool has_flag, \
	int original_size)
{
	if (has_flag == false)
		return ;
	ft_putendl_fd(" __________________ __________________", 1);
	ft_putendl_fd("|                  |                  |", 1);
	ft_putendl_fd("|       a          |       b          |", 1);
	ft_putendl_fd("|__________________|__________________|", 1);
	ft_putendl_fd("|                  |                  |", 1);
	ft_putstacks(*list_a, *list_b, original_size);
	ft_putendl_fd("|__________________|__________________|\n", 1);
}

void	ft_putstacks(t_list *list_a, t_list *list_b, int original_size)
{
	t_tmpdisp	tmpdisp[2];

	tmpdisp[0].flag = false;
	tmpdisp[0].tmp = list_a;
	tmpdisp[1].flag = false;
	tmpdisp[1].tmp = list_b;
	while (original_size-- > 0)
	{
		ft_putstr_fd("|       ", 1);
		ft_check_stack(&tmpdisp[0], list_a, original_size);
		ft_putstr_fd("|       ", 1);
		ft_check_stack(&tmpdisp[1], list_b, original_size);
		ft_putendl_fd("|", 1);
	}
}

void	ft_checker_bonus(t_check *check, t_list **list_a, \
	t_list **list_b, bool has_flag)
{
	ft_display_stacks(list_a, list_b, has_flag, check->original_size);
	check->buffer = ft_strdup("");
	check->ret = read(STDIN_FILENO, check->buf, sizeof(check->buf));
	while (check->ret > 0)
	{
		check->buf[check->ret] = '\0';
		check->buffer = ft_joinfree(check->buffer, ft_strdup(check->buf));
		check->line = NULL;
		if (ft_strchr(check->buffer, '\n') == NULL)
			return (ft_error_bonus(check, list_a, list_b));
		while (ft_getline(&check->buffer, &check->line) > 0)
		{
			check->tmp = ft_strtrim(check->line, "\n");
			ft_free(&check->line);
			if (check->tmp == NULL)
				return (ft_error_bonus(check, list_a, list_b));
			if (ft_execute(check->tmp, list_a, list_b, false) == false)
				return (ft_error_bonus(check, list_a, list_b));
			ft_free(&check->tmp);
			ft_display_stacks(list_a, list_b, has_flag, check->original_size);
		}
		check->ret = read(STDIN_FILENO, check->buf, sizeof(check->buf));
	}
	ft_free(&check->buffer);
}
