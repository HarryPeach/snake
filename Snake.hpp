#include "curses.h"
#include "Node.cpp"

class Snake{
    private:
        Node m_root_node;
        Node *m_current_tail;
    public:
        void draw_snake(WINDOW *scr);
        void add_node();
};