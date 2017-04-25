#include <map>
#include "tennis.h"
#include "ScoreFormatter.h"
#include "EqualScoreFormatter.h"
#include "Player.h"
#include "EqualScoreRule.h"
#include "AdvantageOrWinRule.h"

bool isScoreNotEqualAndBeforeAdvantageOrWin(const Player &playerOne, const Player &playerTwo);

std::string formatScoreWhenDifferentAndBeforeAdvantageOrWin(const Player &playerOne, const Player &playerTwo,
                                                            ScoreFormatter &scoreFormatter);

const std::string tennis_score(int playerOneScore, int playerTwoScore) {
    Player playerOne(playerOneScore, "player1");
    Player playerTwo(playerTwoScore, "player2");

    EqualScoreFormatter equalScoreFormatter;
    EqualScoreRule equalScoreRule(equalScoreFormatter);

    AdvantageOrWinRule advantageOrWinRule;
    ScoreFormatter scoreFormatter;


    if (equalScoreRule.verifies(playerOne, playerTwo)) {
        return equalScoreRule.format(playerOne);
    }

    if (advantageOrWinRule.verifies(playerOne, playerTwo)) {
        return advantageOrWinRule.format(playerOne, playerTwo);
    }

    if (isScoreNotEqualAndBeforeAdvantageOrWin(playerOne, playerTwo)) {
        return formatScoreWhenDifferentAndBeforeAdvantageOrWin(playerOne, playerTwo, scoreFormatter);
    }

    return DEFAULT_SCORE_FORMAT;
}

std::string formatScoreWhenDifferentAndBeforeAdvantageOrWin(const Player &playerOne, const Player &playerTwo,
                                                            ScoreFormatter &scoreFormatter) {
    return scoreFormatter.formatScore(playerOne.getScore())
           + SEPARATOR
           + scoreFormatter.formatScore(playerTwo.getScore());
}

bool isScoreNotEqualAndBeforeAdvantageOrWin(const Player &playerOne, const Player &playerTwo) {
    return (!(playerOne.getScore() == playerTwo.getScore()) &&
            !(playerOne.getScore() >= 4 || playerTwo.getScore() >= 4));
}

