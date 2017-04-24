#include <map>
#include "tennis.h"
#include "ScoreFormatter.h"
#include "EqualScoreFormatter.h"
#include "WinFormatter.h"
#include "cmake-build-debug/AdvantageFormatter.h"

std::string formatScoreWhenAdvantageOrWin(int playerOneScore, int playerTwoScore);

const std::string tennis_score(int playerOneScore, int playerTwoScore) {
    EqualScoreFormatter equalScoreFormatter;
    ScoreFormatter scoreFormatter;

    bool equalScore = (playerOneScore == playerTwoScore);
    if (equalScore) {
        return equalScoreFormatter.getValue(playerOneScore);
    }

    bool atLeastOnePlayerHasScoreOverForty = (playerOneScore >= 4 || playerTwoScore >= 4);
    bool isAdvantageOrWin = (!equalScore && atLeastOnePlayerHasScoreOverForty);
    if (isAdvantageOrWin) {
        return formatScoreWhenAdvantageOrWin(playerOneScore, playerTwoScore);
    }

    bool isDifferentAndBeforeAdvantagesOrWin = (!equalScore && !atLeastOnePlayerHasScoreOverForty);
    if (isDifferentAndBeforeAdvantagesOrWin) {
        return scoreFormatter.formatScore(playerOneScore) + SEPARATOR + scoreFormatter.formatScore(playerTwoScore);
    }

    return DEFAULT_SCORE_FORMAT;
}

std::string formatScoreWhenAdvantageOrWin(int playerOneScore, int playerTwoScore) {
    WinFormatter winFormatter;
    AdvantageFormatter advantageFormatter;

    int scoreDifference = playerOneScore - playerTwoScore;
    const std::string playerOneName = "player1";
    const std::string playerTwoName = "player2";

    bool playerOneHasAdvantage = (scoreDifference == 1);
    if (playerOneHasAdvantage) {
        return advantageFormatter.format(playerOneName);
    }

    bool playerTwoHasAdvantage = (scoreDifference == -1);
    if (playerTwoHasAdvantage) {
        return advantageFormatter.format(playerTwoName);
    }

    bool playerOneWins = (scoreDifference >= 2);
    if (playerOneWins) {
        return winFormatter.format(playerOneName);
    }

    bool playerTwoWins = scoreDifference <= -2;
    if (playerTwoWins) {
        return winFormatter.format(playerTwoName);
    }

    return DEFAULT_SCORE_FORMAT;
}
