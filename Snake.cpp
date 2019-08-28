#include "Snake.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void Snake::update_loop(){
    for (;;){
        clear();
        draw_ui();
        draw_snake();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

Snake::Snake(WINDOW *scr, int screen_width, int screen_height){
    m_scr = scr;

    // Begin the update loop
    std::thread(&Snake::update_loop, this).detach();

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
    mvwaddstr(stdscr, 0, 0, "Snake v0, press q to quit.");
    mvwaddstr(stdscr, 2, 0, "== DEBUG ==");
    mvwaddstr(stdscr, 3, 0, "Press D to update the game");
    mvwaddstr(stdscr, 4, 0, "Press N to add a new node");
}

void Snake::add_node(){
    Node* node = new Node();

    node->x = (*m_current_tail).x;
    node->y = (*m_current_tail).y;
    node->next = m_current_tail;

    m_current_tail = node;
}