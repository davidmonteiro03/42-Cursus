/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:53:57 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/29 15:02:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib_3.h"

int	handle_question_mark(char *path, char *ptrn)
{
	return (*path && wildcmp(path + 1, ptrn + 1));
}

int	handle_asterisk(char *path, char *ptrn)
{
	if (wildcmp(path, ptrn + 1))
		return (1);
	return (*path && wildcmp(path + 1, ptrn));
}

int	handle_square_brackets(char *path, char **ptrn, int mtch, int invt)
{
	(*ptrn)++;
	if (**ptrn == '!')
	{
		invt = 1;
		(*ptrn)++;
	}
	while (**ptrn != ']')
	{
		if (!**ptrn)
			return (0);
		if (*(*ptrn + 1) == '-' && *(*ptrn + 2) != ']')
		{
			mtch = mtch || (*path >= **ptrn && *path <= *(*ptrn + 2));
			*ptrn += 3;
		}
		else
		{
			mtch = mtch || *path == **ptrn;
			(*ptrn)++;
		}
	}
	return ((mtch ^ invt) && wildcmp(path + 1, *ptrn + 1));
}

int	wildcmp(char *path, char *ptrn)
{
	if (!*ptrn)
		return (!*path);
	if (*ptrn == '?')
		return (handle_question_mark(path, ptrn));
	if (*ptrn == '*')
		return (handle_asterisk(path, ptrn));
	if (*ptrn == '[')
		return (handle_square_brackets(path, &ptrn, 0, 0));
	return (*path == *ptrn && wildcmp(path + 1, ptrn + 1));
}
