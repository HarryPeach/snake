#include "include/Snake.hpp"
#include "include/CursesHelper.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>

void Snake::update_loop(){
    for (;;){
        clear();
        check_food_collision();
        draw_ui();
        draw_food();
        draw_snake();
        std::this_thread::sleep_for(std::chrono::milliseconds(m_speed));
    }
}

Snake::Snake(WINDOW *scr, int screen_width, int screen_height){
    m_scr = scr;

    // Begin the update loop
    std::thread(&Snake::update_loop, this).detach();

    m_window_width = screen_width;
    m_window_height = screen_height;

    // Seed the random generator
    srand(time(nullptr));
    spawn_food();
    
    // Start the snake in the middle of the screen
    m_root_node.x = screen_width / 2;
    m_root_node.y = screen_height / 2;
    m_root_node.next = nullptr;

    m_current_tail = &m_root_node;
}

void Snake::move_snake(DIRECTION direction){
    switch(direction){
        case DIRECTION::UP:
            m_y_delt = -1;
            m_x_delt = 0;
            break;
        case DIRECTION::DOWN:
            m_y_delt = 1;
            m_x_delt = 0;
            break;
        case DIRECTION::LEFT:
            m_x_delt = -1;
            m_y_delt = 0;
            break;
        case DIRECTION::RIGHT:
            m_x_delt = 1;
            m_y_delt = 0;
            break;
    }
}

void Snake::draw_snake(){
    m_root_node.x += m_x_delt;
    m_root_node.y += m_y_delt;

    Node *current_node = m_current_tail;
    do {
        mvwaddch(m_scr, (*current_node).y, (*current_node).x, '#');
        // mvwaddch(m_scr, 1, 1, '#');
        if (current_node != &m_root_node){
            (*current_node).x = (*current_node).next->x;
            (*current_node).y = (*current_node).next->y;
        }
        current_node = (*current_node).next;
    } while (current_node != nullptr);
}

void Snake::draw_ui(){
    CursesHelper::draw_centered_str(stdscr, m_window_width / 2, 2, "Snake v0, press q to quit.");
    std::ostringstream score_str_stream;
    score_str_stream << "Score: " << m_score << " Speed: " << m_speed;
    CursesHelper::draw_centered_str(stdscr, m_window_width / 2, 3, score_str_stream.str());
    CursesHelper::draw_centered_str(stdscr, m_window_width / 2, 5, "=== Debug Information ===");
    CursesHelper::draw_centered_str(stdscr, m_window_width / 2, 6, "Press N to add a new node.");
    std::ostringstream food_str_stream;
    food_str_stream << "Current food location: (x " << m_food.x << ", y " << m_food.y << ")"; 
    CursesHelper::draw_centered_str(stdscr, m_window_width / 2, 7, food_str_stream.str());
    std::ostringstream snake_str_stream;
    snake_str_stream << "Current snake location: (x " << m_root_node.x << ", y " << m_root_node.y << ")"; 
    CursesHelper::draw_centered_str(stdscr, m_window_width / 2, 8, snake_str_stream.str());
}

void Snake::draw_food(){
    mvwaddch(m_scr, m_food.y, m_food.x, '+');
}

void Snake::add_node(){
    Node* node = new Node();

    node->x = (*m_current_tail).x;
    node->y = (*m_current_tail).y;
    node->next = m_current_tail;

    m_current_tail = node;
}

void Snake::spawn_food(){
    m_food.x = rand() % m_window_width;
    m_food.y = rand() % m_window_height;
}

void Snake::check_food_collision(){
    if( m_root_node.x == m_food.x && m_root_node.y == m_food.y ){
        add_node();
        m_score += 100;
        if((m_speed - (m_score) / 20) > 0){
            m_speed -= (m_score) / 20;
        }
        spawn_food();
    }
}