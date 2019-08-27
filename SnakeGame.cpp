#include <iostream>
#include "curses.h"
#include "Snake.hpp"

int main(){
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    mvwaddstr(stdscr, 0, 0, "Snake v0, press q to quit.");
    mvwaddstr(stdscr, 2, 0, "== DEBUG ==");
    mvwaddstr(stdscr, 3, 0, "Press D to update the game");
    mvwaddstr(stdscr, 4, 0, "Press N to add a new node");
    Snake snake(stdscr, 50, 50);


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
            // TODO REPLACE WITH TIMER DRAW
            case 'd':
                snake.draw_snake();
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