/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:14:17 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/10 16:18:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_HPP
#define MACROS_HPP

/* ERRORS */
#define WRONG_PASS "Wrong password"
#define INVALID_USER "Invalid username"
#define INVALID_PWD "Invalid password"
#define DUPLICATE "User already exists"
#define UNKNOWN "Unknown command"
#define BAD_USAGE "Bad usage of command"
#define DOESNT_EXIST "This user doesn't exist"
#define USERNOT_INCHANNEL "User not found in this channel"
#define ALREADY_LOGGED "This user is already logged in"
#define CHANNEL_NOTFOUND "Channel not found"
#define ALREADY_INCHANNEL "You're already in channel"
#define NOTIN_CHANNEL "You're not in channel"
#define DUPLICATE_CHANNEL "Channel already exists"
#define INVALID_CHANNEL "Invalid username"
#define REQUIRED_PWD "A password is required"
#define SELF_MESSAGE "Talking to yourself uh... need a hug?"
#define CLIENT_OFFLINE "User is offline"
#define NOTAN_OPERATOR "You're not an operator for this channel"
#define NOTFOUND_INCHANNEL "User not found in this channel"
#define CANNOTKICK_OPERATOR "You can't kick an operator"
#define ISAN_OPERATOR "This user is an operator of this channel"
#define SELF_PRIVILEGE "You can't change your own privilege"
#define CHANNEL_FULL "This channel is full"
#define INVALID_LIMIT "You need to put an higher limit"
#define INVITEONLY_MODE "You need an invite to enter this channel"
#define USERISINCHANNEL "User already in channel"
#define ALREADYINVITED "User already invited"
#define ADMIN_CHANNEL "This user is the channel admin"
#define TOPICRESTRICTIONS "The TOPIC command is restricted to channel operators"

#define LOGIN_MSG "/login or /create: "
#define REQ_PASS "Type server password: "
#define CREATED "user created successfully"
#define WELCOME "\n=== WELCOME TO THE SERVER,"
#define WELCOME_BACK "\n=== WELCOME BACK,"
#define CONFIG "Time to configure your profile..."
#define PROMPT "[SERVER]> "
#define JOINED " has joined the server!"
#define BYE "Goodbye!"
#define KICKEDFROM_CHANNEL "You were kicked from the channel\n"
#define INVITESENT "Invite sent!\n"
#define INVITERECIVED "You were invited to "

#endif
