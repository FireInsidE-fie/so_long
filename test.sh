#!/bin/sh

echo "[!] - Recompiling..."

make re

echo "[!] - Beginning invalid syntax checks..."

read -r meh

valgrind --leak-check=full ./so_long
valgrind --leak-check=full ./so_long assets/
valgrind --leak-check=full ./so_long assets/ladfj
valgrind --leak-check=full ./so_long assets/maps/valid_map5

echo "[!] - Beginning invalid maps checks..."

read -r meh

valgrind --leak-check=full ./so_long assets/maps/invalid_map1.ber
valgrind --leak-check=full ./so_long assets/maps/invalid_map2.ber
valgrind --leak-check=full ./so_long assets/maps/invalid_map3.ber
valgrind --leak-check=full ./so_long assets/maps/invalid_map4.ber
valgrind --leak-check=full ./so_long assets/maps/invalid_map5.ber
valgrind --leak-check=full ./so_long assets/maps/invalid_map6.ber
valgrind --leak-check=full ./so_long assets/maps/invalid_map7.ber
valgrind --leak-check=full ./so_long assets/maps/invalid_map8.ber
valgrind --leak-check=full ./so_long assets/maps/invalid_map9.ber

read -r meh

sleep 2

valgrind --leak-check=full ./so_long assets/maps/valid_map1.ber
valgrind --leak-check=full ./so_long assets/maps/valid_map2.ber
valgrind --leak-check=full ./so_long assets/maps/valid_map3.ber
valgrind --leak-check=full ./so_long assets/maps/valid_map4.ber
valgrind --leak-check=full ./so_long assets/maps/valid_map5.ber

echo "[!] - Compiling bonus..."

make bonus

read -r meh

echo "[!] - Checking bonus error checks..."

valgrind --leak-check=full ./so_long_bonus assets/maps/invalid_map1.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/invalid_map2.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/invalid_map3.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/invalid_map4.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/invalid_map5.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/invalid_map6.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/invalid_map7.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/invalid_map8.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/invalid_map9.ber

read -r meh

echo "[!] - Beginning valid maps checks (bonus)..."

valgrind --leak-check=full ./so_long_bonus assets/maps/bonus/valid_map1.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/bonus/valid_map2.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/bonus/valid_map3.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/bonus/valid_map4.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/bonus/valid_map5.ber
valgrind --leak-check=full ./so_long_bonus assets/maps/bonus/test.ber
