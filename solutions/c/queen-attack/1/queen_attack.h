#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <stdint.h>
#include <stdbool.h>

typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } attack_status_t;

typedef struct {
   uint8_t row;
   uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2);
bool same_row(position_t queen_1, position_t queen_2);
bool same_column(position_t queen_1, position_t queen_2);
bool same_diagonal(position_t queen_1, position_t queen_2, int column_increment, int row_increment);
bool same_ne_diagonal(position_t queen_1, position_t queen_2);
bool same_se_diagonal(position_t queen_1, position_t queen_2);
bool same_sw_diagonal(position_t queen_1, position_t queen_2);
bool same_nw_diagonal(position_t queen_1, position_t queen_2);
bool is_hit(position_t queen, position_t position);
bool is_collision(position_t queen_1, position_t queen_2);
bool is_out_of_bounds(position_t pos);
bool is_valid_position(position_t pos);
bool is_invalid_idx(int idx);

#endif
