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
    Snake snake(stdscr, 50, 50);


    for (;;){
        switch (getch()){
            case KEY_UP:
                mvwaddstr(stdscr, 1, 0, "UP PRESSED");
                snake.move_snake(Snake::DIRECTION::UP);
                break;
            case KEY_DOWN:
                mvwaddstr(stdscr, 1, 0, "DOWN PRESSED");
                snake.move_snake(Snake::DIRECTION::DOWN);
                break;
            case KEY_LEFT:
                mvwaddstr(stdscr, 1, 0, "LEFT PRESSED");
                snake.move_snake(Snake::DIRECTION::LEFT);
                break;
            case KEY_RIGHT:
                mvwaddstr(stdscr, 1, 0, "RIGHT PRESSED");
                snake.move_snake(Snake::DIRECTION::RIGHT);
                break;
            // TODO REPLACE WITH TIMER DRAW
            case 'd':
                clear();
                snake.draw_snake();
                break;
            case 'q':
                endwin();
                return 0;
        }
    }
}