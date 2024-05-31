/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:56:47 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/29 09:33:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

void	ft_putnbr_ultimate(int nbr)
{
	int	len;

	ft_putnbr_fd(nbr, 1);
	len = 11 - ft_len(nbr);
	while (len-- > 0)
		ft_putchar_fd(' ', 1);
}

void	ft_check_stack(t_tmpdisp *tmpdisp, t_list *list, int original_size)
{
	if (original_size == ft_lstsize(list) - 1)
		tmpdisp->flag = true;
	if (tmpdisp->flag == true)
	{
		tmpdisp->nbr = ((t_element *)(tmpdisp->tmp->content))->number;
		ft_putnbr_ultimate(tmpdisp->nbr);
		tmpdisp->tmp = tmpdisp->tmp->next;
	}
	else
		ft_putstr_fd("NULL       ", 1);
}

void	ft_fill_bonus(t_list **list, char **args)
{
	char		**tmp;
	int			i;
	t_element	*tmp_element;
	t_list		*tmp_node;

	if (list == NULL)
		return ;
	tmp = ft_acumulate(args);
	if (tmp == NULL)
		return ;
	i = -1;
	while (tmp[++i] != NULL)
	{
		if (ft_strcmp(tmp[i], "-d") == 0)
			continue ;
		tmp_element = new_element(ft_atoi(tmp[i]));
		tmp_node = ft_lstnew(tmp_element);
		ft_lstadd_back(list, tmp_node);
	}
	free_strs(tmp);
}

int	ft_getline(char **buff, char **line)
{
	char	*newbuf;
	int		i;

	*line = 0;
	if (*buff == 0)
		return (0);
	i = 0;
	while ((*buff)[i])
	{
		if ((*buff)[i] == '\n')
		{
			newbuf = ft_calloc(1, sizeof(*newbuf) * \
				(ft_strlen(*buff + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			ft_strlcpy(newbuf, *buff + i + 1, (ft_strlen(*buff + i + 1)));
			*line = *buff;
			(*line)[i + 1] = 0;
			*buff = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}
