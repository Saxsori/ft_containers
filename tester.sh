# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 13:57:31 by aaljaber          #+#    #+#              #
#    Updated: 2023/02/26 19:41:33 by aaljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Define array of sizes to test
declare -a sizes=("1000" "10000" "100000" "1000000" "10000000")

# Print header of table

function speed_header {
	echo -e "\n\n\e[36m"
	echo -e "\t========================================================================================\n"
    echo -e "\t  _____           __                                            _______        _    "
    echo -e "\t |  __ \         / _|                                          |__   __|      | |   "
    echo -e "\t | |__) |__ _ __| |_ ___  _ __ _ __ ___   __ _ _ __   ___ ___     | | ___  ___| |_  "
	echo -e "\t |  ___/ _ \ '__|  _/ _ \| '__| '_ \` _ \ / _\` | '_ \ / __/ _ |    | |/ _ \/ __| __|"
    echo -e "\t | |  |  __/ |  | || (_) | |  | | | | | | (_| | | | | (_|  __/    | |  __/\__ \ |_  "
    echo -e "\t |_|   \___|_|  |_| \___/|_|  |_| |_| |_|\__,_|_| |_|\___\___|    |_|\___||___/\__| "
	echo -e "\n\t======================================================================================\033[0m\n"
}

function func_header {
	printf "\n\n\e[36m"
	printf "\t=====================================================================================================\n"
    printf "\t  _____                 _                           _        _   _               _______        _    \n"
    printf "\t |_   _|               | |                         | |      | | (_)             |__   __|      | |   \n"
    printf "\t   | |  _ __ ___  _ __ | | ___ _ __ ___   ___ _ __ | |_ __ _| |_ _  ___  _ __      | | ___  ___| |_  \n"
	echo -e "\t   | | | '_ \` _ \| '_ \| |/ _ \ '_ \` _ \ / _ \ '_ \| __/ _  | __| |/ _ \| '_ \     | |/ _ \/ __| __|"
    printf "\t  _| |_| | | | | | |_) | |  __/ | | | | |  __/ | | | || (_| | |_| | (_) | | | |    | |  __/\__ \ |_  \n"
    printf "\t |_____|_| |_| |_| .__/|_|\___|_| |_| |_|\___|_| |_|\__\__,_|\__|_|\___/|_| |_|    |_|\___||___/\__| \n"
    printf "\t                 | |                                                                                 \n"
	printf "\t                 |_|                                                                                 \n"
	printf "\n\t====================================================================================================\033[0m\n\n\n"
}

function test_speed {
	
	make $2
	std_prog=$3
    ft_prog=$4
   
    # Print test name
	printf "\n\n\n\033[33m\tTest the speed of %s\033[0m\n\n\n\t" "$1"
	printf "\033[1m%-23s %-20s %-20s\n\n\033[0m" "Size" "FT version" "Standard version"
	
	# Loop through sizes
	for size in "${sizes[@]}"
	do
	  printf "\t%-20d " $size
	  
	  # Run ft version and print time taken
	  	ft_time=$($ft_prog $size)
		printf "\t\033[0;32m%-20s\033[0m" "$ft_time"

	  # Run standard version and print time taken
		std_time=$($std_prog $size)
		printf "\t\033[0;32m%-20s\033[0m" "$std_time"
	  
	  # Print newline
	  	printf "\n"
	done
	printf "\n"
}

function test_func {
	
	std_log="./MYTESTER/LOG/std."$1".log"
	ft_log="./MYTESTER/LOG/ft."$1".log"
	diff_txt="./MYTESTER/LOG/"$1".diff"
	std_prog="./std_"$1
	ft_prog="./ft_"$1

	make $1"_test"
	
	printf "\n\033[33m\tTest the implementation of %-20s\033[0m\t\t" "$1"
	
	$std_prog > $std_log
	$ft_prog > $ft_log
	diff $std_log $ft_log > $diff_txt
	if [ ! -s "${diff_txt}" ]; then
    printf "Pass ✅\n\n"
	else
	    printf "Fail ❌\n\n"
	fi
	make fclean

}

function start {
	speed_header
	test_speed "Vector" "vector_speed" "./std_vector" "./ft_vector"
	test_speed "Stack" "stack_speed" "./std_stack" "./ft_stack"
	test_speed "Map" "map_speed" "./std_map" "./ft_map"
	test_speed "Set" "set_speed" "./std_set" "./ft_set"
	make fclean
	func_header
	test_func "map"
	test_func "set"
	test_func "vector"
	test_func "stack"
	make fclean
	printf "\n\n\n"
}



start
