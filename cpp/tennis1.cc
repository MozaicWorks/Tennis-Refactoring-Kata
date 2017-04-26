#include <map>
#include "tennis.h"
#include "ScoreFormatter.h"
#include "EqualScoreFormatter.h"
#include "Player.h"
#include "EqualScoreRule.h"
#include "AdvantageOrWinRule.h"
#include "DifferentAndBeforeAdvantageRule.h"

const std::string tennis_score(int playerOneScore, int playerTwoScore) {
    Player playerOne(playerOneScore, "player1");
    Player playerTwo(playerTwoScore, "player2");

    EqualScoreFormatter equalScoreFormatter;
    EqualScoreRule equalScoreRule(equalScoreFormatter);

    AdvantageOrWinRule advantageOrWinRule;

    ScoreFormatter scoreFormatter;
    DifferentAndBeforeAdvantageRule differentAndBeforeAdvantageRule(scoreFormatter);

    if (equalScoreRule.verifies(playerOne, playerTwo)) {
        return equalScoreRule.format(playerOne);
    }

    if (advantageOrWinRule.verifies(playerOne, playerTwo)) {
        return advantageOrWinRule.format(playerOne, playerTwo);
    }

    if (differentAndBeforeAdvantageRule.verifies(playerOne, playerTwo)) {
        return differentAndBeforeAdvantageRule.format(playerOne, playerTwo);
    }

    return DEFAULT_SCORE_FORMAT;
}

