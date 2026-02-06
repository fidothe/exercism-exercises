#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    if (is_out_of_bounds(queen_1) || is_out_of_bounds(queen_2) || is_collision(queen_1, queen_2)) return INVALID_POSITION;
    if (same_row(queen_1, queen_2) || same_column(queen_1, queen_2) || same_diagonal(queen_1, queen_2) ) {
        return CAN_ATTACK;
    } else {
        return CAN_NOT_ATTACK;
    };
}

bool is_collision(position_t queen_1, position_t queen_2) {
    return queen_1.column == queen_2.column && queen_1.row == queen_2.row;
}

bool is_out_of_bounds(position_t pos) {
    return is_invalid_idx(pos.column) || is_invalid_idx(pos.row);
}

bool is_valid_position(position_t pos) {
    return !is_out_of_bounds(pos);
}

bool is_invalid_idx(int idx) {
    return idx < 0 || idx > 7; 
}

bool same_row(position_t queen_1, position_t queen_2) {
    return queen_1.row == queen_2.row;
}

bool same_column(position_t queen_1, position_t queen_2) {
    return queen_1.column == queen_2.column;
}

bool same_diagonal(position_t queen_1, position_t queen_2) {
    return abs(queen_1.column - queen_2.column) == abs(queen_1.row - queen_2.row);
}
