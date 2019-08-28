PROJECT_NAME=Snake

default:
	g++ SnakeGame.cpp Snake.cpp CursesHelper.cpp -o ${PROJECT_NAME}.o -lncurses -pthread -Wall -Wextra -Iinclude

clean:
	@rm *.o

run: default
	@./${PROJECT_NAME}.o