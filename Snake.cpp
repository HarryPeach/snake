#include "Snake.hpp"
#include <cstring>
#include <string>

Snake::Snake(WINDOW *scr, int screen_width, int screen_height){
    m_scr = scr;
    
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
    // mvwaddstr(m_scr, 5, 5, std::to_string(m_root_node.x).c_str());
    m_root_node.x += m_x_delt;
    m_root_node.y += m_y_delt;

    Node current_node = *m_current_tail;
    do{
        mvwaddch(m_scr, current_node.y, current_node.x, '#');
    }while(current_node.next != nullptr);
}

void Snake::add_node(){
    // Add a node
    // set m_current_tail to the new node
    // Node *node = new Node();
    // node->
}