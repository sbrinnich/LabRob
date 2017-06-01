NAME:=labrob
FLAGS:=-ggdb -g -Wall -Werror -O -std=c++11
CC:=g++

all: ${NAME}

${NAME}: *.cpp
	${CC} ${FLAGS} -o ${NAME} *.cpp

run: ${NAME}
	drmemory -- ${NAME}

clean:
	rm -f ${NAME}.exe ${NAME} *.o