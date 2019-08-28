#include "curses.h"

class Snake{
    private:
        struct Node {
            int x;
            int y;
            Node *next;
        };
        struct Food {
            int x;
            int y;
        };
        WINDOW *m_scr;
        Node m_root_node;
        Node *m_current_tail;
        Food m_food;

        int m_window_width = 0;
        int m_window_height = 0;

        int m_score = 0;
        int m_speed = 300;

        int m_y_delt = 0;
        int m_x_delt = 0;
        void spawn_food();
        void update_loop();
        void draw_ui();
        void draw_snake();
        void draw_food();
        void check_food_collision();
        
    public:
        Snake(WINDOW *scr, int screen_width, int screen_height);

        enum class DIRECTION : int {
            UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3
        };

        void move_snake(DIRECTION direction);
        void add_node();
};