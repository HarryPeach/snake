#include <curses.h>
#include <string>

class CursesHelper{
    public:
        static void draw_centered_str(WINDOW *scr, int x, int y, std::string str);
};