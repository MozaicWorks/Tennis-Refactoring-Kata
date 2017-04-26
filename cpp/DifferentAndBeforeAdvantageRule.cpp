#include "Player.h"
#include "ScoreFormatter.h"
#include <map>
#include "DifferentAndBeforeAdvantageRule.h"
#include "tennis.h"

std::string DifferentAndBeforeAdvantageRule::format(const Player &playerOne,
                                                    const Player &playerTwo) {
    return this->scoreFormatter.formatScore(playerOne.getScore())
           + SEPARATOR
           + this->scoreFormatter.formatScore(playerTwo.getScore());
}

bool DifferentAndBeforeAdvantageRule::verifies(const Player &playerOne,
                                               const Player &playerTwo) {
    return (!(playerOne.getScore() == playerTwo.getScore()) &&
            !(playerOne.getScore() >= 4 || playerTwo.getScore() >= 4));
}

DifferentAndBeforeAdvantageRule::DifferentAndBeforeAdvantageRule(ScoreFormatter &formatter) {
    this->scoreFormatter = formatter;
}
