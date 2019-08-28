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

    mvwaddstr(stdscr, 0, 0, "Snake v0, press q to quit.");
    mvwaddstr(stdscr, 2, 0, "== DEBUG ==");
    mvwaddstr(stdscr, 3, 0, "Press D to update the game");
    mvwaddstr(stdscr, 4, 0, "Press N to add a new node");
    Snake snake(stdscr, 50, 50);


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