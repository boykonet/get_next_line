#!/bin/bash

# len.txt gull.txt atlas_shrugged.txt empty.txt many_spaces.txt

READ=len.txt

echo "$READ"

echo "BUFFER_SIZE=1:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=2:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=3:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=3 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=4:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=5:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=6:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=6 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=7:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=7 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=8:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=8 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=32:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=1024:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=2001:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2001 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=9999:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=100000:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=100000 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out

echo "BUFFER_SIZE=1000000:"

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1000000 get_next_line.c get_next_line_utils.c main.c
./a.out
diff -qsca result.txt $READ
rm -rf result.txt a.out









# READ=147.txt

# echo "$READ"

# echo "BUFFER_SIZE=1"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=2"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=3"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=3 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=4"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=5"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=6"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=6 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=7"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=7 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=8"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=8 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=32"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=146"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=146 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=147"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=147 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=148"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=148 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=1024"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=2001"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2001 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=9999:"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=100000"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=100000 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out

# echo "BUFFER_SIZE=1000000"

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1000000 get_next_line.c get_next_line_utils.c main.c
# ./a.out
# diff -qsca result.txt $READ
# rm -rf result.txt a.out
