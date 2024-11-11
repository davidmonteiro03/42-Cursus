/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:37:09 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/08 17:03:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>
#include "Vector2.hpp"

class Graph
{
public:
	Graph(void);
	Graph(const Graph &);
	Graph &operator=(const Graph &);
	~Graph();
	const std::vector<Vector2> getPoints(void) const;
	void addVector2(const Vector2 &);
	float getMinX(void) const;
	float getMinY(void) const;
	float getMaxX(void) const;
	float getMaxY(void) const;
	size_t size(void) const;

private:
	std::vector<Vector2> _points;
};

std::ostream &operator<<(std::ostream &, const Graph &);

#endif // !GRAPH_HPP
