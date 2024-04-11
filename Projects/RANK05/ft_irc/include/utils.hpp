/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:35:49 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/10 15:50:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

std::string ft_strtrim(std::string str);
std::vector<std::string> splitString(const std::string &str);
int isValidName(std::string line);
int isValidChannelName(std::string line);
bool checkPassword(std::string password);
bool processUserName(int fd, std::string line);
bool processPassword(int fd, std::string password);
void sendToClient(int fd, const char *msg, bool isError);
void sendMessage(Client *sender, Client *receiver, std::vector<std::string> args, int mode);
void sendInfo(Client *sender, Client *receiver, std::vector<std::string> args);

#endif
