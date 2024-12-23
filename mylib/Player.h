#ifndef LAB1_MYLIB_PLAYER_H_
#define LAB1_MYLIB_PLAYER_H_

#include "Field.h"
#include "IOManager.h"

class Player {
 public:
  Player();
  Player(bool is_bot, size_t stage);

  void set_field_(Field field);
  Field& get_field_();


 private:
  bool is_bot_;
  int bot_accuracity_;

  bool player_turn_;

  Field field_;


};

#endif
