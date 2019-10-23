#include <curses.h>
#include <string>

class CursesHelper{
    public:
        /**
         * Draws a centered string to the screen
         * 
         * @param scr Pointer to the curses screen object
         * @param x The x co-ordinate to draw the string at
         * @param y The y co-ordinate to draw the string at
         * @param str The string to be drawn
         */
        static void draw_centered_str(WINDOW *scr, int x, int y, std::string str);
};