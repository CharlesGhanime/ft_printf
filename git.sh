# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    git.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/08 15:03:27 by cghanime          #+#    #+#              #
#    Updated: 2019/03/25 10:35:59 by cghanime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! /bin/sh/

echo "---------------------------GIT ADD .-------------------------------------"
git add .
echo "---------------------------GIT COMMIT -m $1------------------------------"
git commit -m $1
echo "---------------------------GIT PUSH--------------------------------------"
git push
echo "---------------------------END OF GIT PUSH-------------------------------"
