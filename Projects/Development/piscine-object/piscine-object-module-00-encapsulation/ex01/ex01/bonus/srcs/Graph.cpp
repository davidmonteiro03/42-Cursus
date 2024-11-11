/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:39:05 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/11 07:40:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Graph.hpp"

Graph::Graph(void) : _points(std::vector<Vector2>()) {}

Graph::Graph(const Graph &copy) : _points(copy._points) {}

Graph &Graph::operator=(const Graph &other)
{
	if (this != &other)
		this->_points = other.getPoints();
	return *this;
}

Graph::~Graph() { this->_points.clear(); }

const std::vector<Vector2> Graph::getPoints(void) const { return this->_points; }

void Graph::addVector2(const Vector2 &v) { _points.push_back(v); }

void Graph::addLine(float x1, float y1, float x2, float y2)
{
	float diffX = x2 - x1, diffY = y2 - y1;
	if (diffX == 0)
	{
		float startY = std::min(y1, y2), endY = std::max(y1, y2);
		for (float y = startY; y <= endY; y++)
			this->addVector2(Vector2(x1, y));
	}
	else if (diffY == 0)
	{
		float startX = std::min(x1, x2), endX = std::max(x1, x2);
		for (float x = startX; x <= endX; x++)
			this->addVector2(Vector2(x, y1));
	}
	else
	{
		float a = diffY / diffX;
		float startX = std::min(x1, x2), endX = std::max(x1, x2);
		float b = y1 - a * x1;
		float precision = std::abs(a) <= 0 ? 1.0 : 1.0 / std::abs(a);
		this->addVector2(Vector2(x1, y1));
		for (float x = startX + 1; x <= endX; x += precision)
			this->addVector2(Vector2(x, a * x + b));
	}
}

float Graph::getMinX(void) const
{
	if (this->_points.size() < 1)
		return std::numeric_limits<float>::max();
	float minX = this->_points[0].getX();
	for (size_t i = 0; i < this->_points.size(); i++)
		minX = std::min(minX, this->_points[i].getX());
	return minX;
}

float Graph::getMinY(void) const
{
	if (this->_points.size() < 1)
		return std::numeric_limits<float>::max();
	float minY = this->_points[0].getY();
	for (size_t i = 0; i < this->_points.size(); i++)
		minY = std::min(minY, this->_points[i].getY());
	return minY;
}

float Graph::getMaxX(void) const
{
	if (this->_points.size() < 1)
		return std::numeric_limits<float>::min();
	float maxX = this->_points[0].getX();
	for (size_t i = 0; i < this->_points.size(); i++)
		maxX = std::max(maxX, this->_points[i].getX());
	return maxX;
}

float Graph::getMaxY(void) const
{
	if (this->size() < 1)
		return std::numeric_limits<float>::min();
	float maxY = this->_points[0].getY();
	for (size_t i = 0; i < this->_points.size(); i++)
		maxY = std::max(maxY, this->_points[i].getY());
	return maxY;
}

size_t Graph::size(void) const { return this->_points.size(); }

size_t Graph::width(void) const { return static_cast<size_t>(std::floor(this->getMaxX())) - static_cast<size_t>(std::floor(this->getMinX())) + 1; }

size_t Graph::height(void) const { return static_cast<size_t>(std::floor(this->getMaxY())) - static_cast<size_t>(std::floor(this->getMinY())) + 1; }

static int getLen(long int n)
{
	int len = n > 0 ? 0 : 1;
	n = std::abs(n);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return len;
}

static bool pointExists(const std::vector<Vector2> &points, const float x, const float y)
{
	for (size_t i = 0; i < points.size(); i++)
		if (points[i].getX() == x && points[i].getY() == y)
			return true;
	return false;
}

std::ostream &operator<<(std::ostream &os, const Graph &g)
{
	if (g.size() < 1)
		return os;
	const std::vector<Vector2> points = g.getPoints();
	const long int maxY = static_cast<long int>(std::floor(g.getMaxY()));
	const long int minY = static_cast<long int>(std::floor(g.getMinY()));
	const long int minX = static_cast<long int>(std::floor(g.getMinX()));
	const long int maxX = static_cast<long int>(std::floor(g.getMaxX()));
	const int maxLenX = std::max(getLen(minX), getLen(maxX + 1));
	const int maxLenY = std::max(getLen(minY), getLen(maxY + 1));
	for (long int y = maxY + 1; y >= minY; y--)
	{
		os << std::right << std::setw(maxLenY) << y << ' ';
		for (int x = minX; x <= maxX + 1; x++)
		{
			bool result = pointExists(points, static_cast<float>(x), static_cast<float>(y));
			const int setwValue = x == minX ? getLen(x) : maxLenX;
			os << std::right << std::setw(setwValue) << (result ? 'X' : '.');
			if (x <= maxX)
				os << ' ';
		}
		os << std::endl;
	}
	os << std::right << std::setw(maxLenY + 1) << ' ';
	for (int x = minX; x <= maxX + 1; x++)
	{
		const int setwValue = x == minX ? getLen(x) : maxLenX;
		os << std::right << std::setw(setwValue) << x;
		if (x <= maxX)
			os << ' ';
	}
	return os;
}
