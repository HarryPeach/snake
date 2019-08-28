#include <CursesHelper.hpp>

void CursesHelper::draw_centered_str(WINDOW *scr, int x, int y, std::string str){
    int len = str.length();
    int len2 = len / 2;
    mvwaddstr(scr, y, x - len2, str.c_str());
}