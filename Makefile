PROJECT_NAME=Snake

default:
	g++ SnakeGame.cpp Snake.cpp Node.cpp -o ${PROJECT_NAME}.o -lncurses

clean:
	@rm *.o

run: default
	@./${PROJECT_NAME}.o