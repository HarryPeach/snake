#include <iostream>
#include "curses.h"
#include "Snake.hpp"

int main(){
    initscr();
    // Disable buffering of typing characters
    cbreak();
    // Suppress automatic echoing of typed characters
    noecho();
    // Remove the cursor
    curs_set(0);
    // Captures special keys such as the arrow keys
    keypad(stdscr, true);
    // Stop getch() from blocking
    timeout(0);
    
    // TODO handle window resize
    // int wx, wy;
    // getmaxyx(stdscr, wy, wx);

    Snake snake(stdscr, 20, 20);

    snake.add_node();
    snake.add_node();

    for (;;){
        switch (getch()){
            case KEY_UP:
                snake.move_snake(Snake::DIRECTION::UP);
                break;
            case KEY_DOWN:
                snake.move_snake(Snake::DIRECTION::DOWN);
                break;
            case KEY_LEFT:
                snake.move_snake(Snake::DIRECTION::LEFT);
                break;
            case KEY_RIGHT:
                snake.move_snake(Snake::DIRECTION::RIGHT);
                break;
            // TODO REPLACE WITH FOOD TO GROW THE SNAKE
            case 'n':
                snake.add_node();
                break;
            case 'q':
                endwin();
                return 0;
        }
    }
}