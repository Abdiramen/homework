#!/bin/bash
#Author: Abdirahman Ahmed Osman
#File: os_tree.bash
#Purpose: Implements process ancestry tree, shows unique users online, and lists
#process by selected user.

function print_history {
  PID=$(ps -ef | awk -v var="$$" '{if($2 == var) print $2}')
  PNAME=$(ps -ef | awk -v var="$$" '{if ($2 == var) print $8 " " $9}')
  echo "$PID" "$PNAME"
  until [[ "$PID" == "1" ]]; do
    PID=$(ps -ef | awk -v var="$PID" '{if($2 == var) print $3}')
    PNAME=$(ps -ef | awk -v var="$PID" '{if($2 == var) print $8 " " $9}')
    echo "  |"
    echo "$PID" "$PNAME"
  done
}

function print_online {
  user=$(who | awk '{print $1}'| awk '!seen[$1]++')
}

function print_running {
  PS3="select user: "
  print_online
  list=($user)
  select ele in "${list[@]}"
  do
    ps -ef | awk -v var=$ele '$1 == var'
    break
  done
  PS3="menu option: "
}

clear
options=("ancestry history" "who is online" "what process any user is running" "exit")
PS3="menu option: "

select opt in "${options[@]}"
do
  case $opt in
    "${options[0]}")
      print_history
    ;;
    "${options[1]}")
      print_online
      echo "$user"
    ;;
    "${options[2]}")
      print_running
    ;;
    "${options[3]}")
      break
    ;;
    *)
      echo "Invalid option"
    ;;
  esac
  echo "-------------------------------------------------------------------------------"
done
