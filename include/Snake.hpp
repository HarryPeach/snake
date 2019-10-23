#include "curses.h"

class Snake{
    private:
        /**
         * A node is a segment of the snake 
         */
        struct Node {
            int x;
            int y;
            Node *next;
        };
        /**
         * Food is the object that grows the snake when it is collided with
         */
        struct Food {
            int x;
            int y;
        };
        // Pointer to the curses screen object
        WINDOW *m_scr;
        // The original (root) node
        Node m_root_node;
        // Pointer to the current tail node
        Node *m_current_tail;
        // The current food object
        Food m_food;

        // The width of the window
        int m_window_width = 0;
        // The height of the window
        int m_window_height = 0;

        // The current score of the player
        int m_score = 0;
        // The current speed of the snake
        int m_speed = 300;

        // The snakes y movement delta
        int m_y_delt = 0;
        // The snakes x movement delta
        int m_x_delt = 0;
        /**
         * Spawns a food item at a random location on the screen
         */
        void spawn_food();

        /**
         * Updates the snake, ui, food, and collision checks
         */
        void update_loop();

        /**
         * Draws all UI components such as the score and title
         */
        void draw_ui();

        /**
         * Draws the snake itself, and all of its components
         */
        void draw_snake();

        /**
         * Draws food to the screen
         */
        void draw_food();

        /**
         * Checks if the snake has collided with food, if it has the snake is extended and more food spawned
         */
        void check_food_collision();
        
    public:
        /**
         * Constructor for Snake
         * 
         * @param scr The ncurses screen object
         * @param screen_width The width of the screen
         * @param screen_height The height of the screen
         */
        Snake(WINDOW *scr, int screen_width, int screen_height);

        /**
         * Represents the four directions in which the snake can face
         */
        enum class DIRECTION : int {
            UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3
        };

        /**
         * Moves the snake in one of four dimensions
         * @param DIRECTION The four-way direction enum, indicating which direction the snake should move in
         */
        void move_snake(DIRECTION direction);

        /**
         * Adds another segment to the snake
         */
        void add_node();
};