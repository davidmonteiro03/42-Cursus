/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:14:41 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/10 16:42:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes/Vector2.hpp"
#include "bonus/includes/Graph.hpp"
#include <fstream>
#include <sstream>
#include <cstring>

extern "C"
{
#include <cairo/cairo.h>
}

static void drawPixel(cairo_surface_t *surface, double x, double y, double r, double g, double b, double a)
{
	cairo_t *cr = cairo_create(surface);
	cairo_set_source_rgba(cr, r, g, b, a);
	cairo_rectangle(cr, x, y, 1, 1);
	cairo_fill(cr);
	cairo_destroy(cr);
}

static void createPNG(const Graph &g)
{
	if (g.size() < 1)
		return ;
	size_t width = g.width(), height = g.height();
	cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	const std::vector<Vector2> points = g.getPoints();
	for (size_t i = 0; i < points.size(); i++)
	{
		Vector2 point = points[i];
		const float fixedX = point.getX() - g.getMinX();
		const float fixedY = point.getY() - g.getMinY();
		const long int winX = static_cast<long int>(fixedX);
		const long int winY = static_cast<long int>(height - fixedY - 1);
		drawPixel(surface, winX, winY, 255, 255, 255, 255);
	}
	cairo_surface_write_to_png(surface, "images/graph.png");
	cairo_surface_destroy(surface);
}

std::vector<std::string> ft_split(const std::string str)
{
	std::vector<std::string> splitted;
	std::stringstream ss(str);
	while (!ss.eof())
	{
		std::string word;
		ss >> word;
		if (!word.empty())
			splitted.push_back(word);
	}
	return splitted;
}

void ft_point(Graph &g, std::vector<std::string> &args)
{
	std::stringstream ss;
	for (size_t i = 0; i < args.size(); i++)
	{
		if (i > 0)
			ss << ' ';
		ss << args[i];
	}
	float x, y;
	if (ss >> x && ss >> y)
		g.addVector2(Vector2(x, y));
}

void ft_line(Graph &g, std::vector<std::string> &args)
{
	std::stringstream ss;
	for (size_t i = 0; i < args.size(); i++)
	{
		if (i > 0)
			ss << ' ';
		ss << args[i];
	}
	float x1, y1, x2, y2;
	if (ss >> x1 && ss >> y1 && ss >> x2 && ss >> y2)
		g.addLine(x1, y1, x2, y2);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./graph <file>" << std::endl;
		return 0;
	}
	Graph g;
	std::ifstream in_file(argv[1]);
	if (in_file.fail())
	{
		std::cerr << argv[0] << ": " << argv[1] << ": " << std::strerror(errno) << std::endl;
		return 1;
	}
	while (!in_file.eof())
	{
		std::string s_line;
		std::getline(in_file, s_line);
		if (s_line.empty())
			continue;
		std::vector<std::string> args = ft_split(s_line);
		if (args.empty())
			continue;
		if (args[0] != "l")
			ft_point(g, args);
		else
		{
			args.erase(args.begin());
			ft_line(g, args);
		}
	}
	createPNG(g);
	return 0;
}
