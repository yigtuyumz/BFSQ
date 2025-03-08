#!/usr/bin/env bash

LOG_FILE='dev.log'

check_args() {
	if [ -z "${1}" ]; then
		echo "Error! argv[1] is the log message.!"
		exit 1
	fi
}

get_info() {
	local timestamp
	local user
	user="$(whoami)@$(hostname)"
	timestamp="$(date +'%d/%m/%Y %H:%M:%S')"
	printf "[%s - %s]" "${user}" "${timestamp}"
}

print_wrapped() {
	local input
	local max_len
	local curr_pos

	curr_pos=0
	max_len=80
	input="${1}"
	while [ "${curr_pos}" -lt "${#input}" ]; do
		printf "%s\n" "${input:$curr_pos:$max_len}"
		curr_pos=$((curr_pos + max_len))
	done
	printf "\n"
}

main() {
	check_args "${1}"
	local logger
	logger=$(get_info)
	if ! [ -f ${LOG_FILE} ]; then
		echo "Warning! '${LOG_FILE}' not found. Creating a new one.."
		touch "${LOG_FILE}"
	fi
	print_wrapped "${logger} ${1}" >> "${LOG_FILE}"
}

main "${1}"