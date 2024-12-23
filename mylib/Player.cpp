#include "Player.h"

Player::Player() {
  is_bot_ = false;
}

Player::Player(bool is_bot, size_t stage) {
  is_bot_ = is_bot;
  player_turn_ = !is_bot;
  bot_accuracity_ = 10 * stage;
}

void Player::set_field_(Field field) {
  field_ = field;
}

Field& Player::get_field_() {
  return field_;
}