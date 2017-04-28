#include "Player.h"

Player::Player(std::string name, int score): name(name), score(score) {

}

int Player::getScore() {
    return score;
}

std::string &Player::getName() {
    return name ;
}
