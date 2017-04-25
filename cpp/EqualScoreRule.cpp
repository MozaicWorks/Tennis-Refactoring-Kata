#include "Player.h"
#include "EqualScoreFormatter.h"
#include <map>
#include "EqualScoreRule.h"

std::string EqualScoreRule::format(const Player &playerOne) {
    return formatter.getValue(playerOne.getScore());
}

bool EqualScoreRule::verifies(const Player &playerOne, const Player &playerTwo) {
    return (playerOne.getScore() == playerTwo.getScore());
}

EqualScoreRule::EqualScoreRule(EqualScoreFormatter &formatter) {
    this->formatter = formatter;
}
