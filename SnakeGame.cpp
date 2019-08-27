#include <iostream>
#include "curses.h"
#include "Node.cpp"

int main(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);

    mvwaddstr(stdscr, 0, 0, "Snake v0, press q to quit.");


    for (;;){
        switch (getch()){
            case KEY_UP:
                mvwaddstr(stdscr, 1, 0, "UP PRESSED");
                break;
            case KEY_DOWN:
                mvwaddstr(stdscr, 1, 0, "DOWN PRESSED");
                break;
            case KEY_LEFT:
                mvwaddstr(stdscr, 1, 0, "LEFT PRESSED");
                break;
            case KEY_RIGHT:
                mvwaddstr(stdscr, 1, 0, "RIGHT PRESSED");
                break;
            case 'q':
                endwin();
                return 0;
        }
    }
}