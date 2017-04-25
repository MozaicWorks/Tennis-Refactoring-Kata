#include "Player.h"
#include "EqualScoreFormatter.h"
#include <map>
#include "EqualScoreRule.h"

std::string EqualScoreRule::formatEqualScore(const Player &playerOne, EqualScoreFormatter &equalScoreFormatter) {
    return equalScoreFormatter.getValue(playerOne.getScore());
}

bool EqualScoreRule::isEqualScore(const Player &playerOne, const Player &playerTwo) {
    return (playerOne.getScore() == playerTwo.getScore());
}