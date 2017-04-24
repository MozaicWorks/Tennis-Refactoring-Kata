#include <map>
#include "tennis.h"
#include "ScoreFormatter.h"
#include "EqualScoreFormatter.h"

std::string formatScoreWhenAdvantageOrWin(int playerOneScore, int playerTwoScore);

std::string formatAdvantage(const std::string &playerName);

std::string formatWin(const std::string &playerName);

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
    int scoreDifference = playerOneScore - playerTwoScore;
    const std::string playerOneName = "player1";
    const std::string playerTwoName = "player2";

    bool playerOneHasAdvantage = (scoreDifference == 1);
    if (playerOneHasAdvantage)
        return formatAdvantage(playerOneName);

    bool playerTwoHasAdvantage = (scoreDifference == -1);
    if (playerTwoHasAdvantage)
        return formatAdvantage(playerTwoName);

    bool playerOneWins = (scoreDifference >= 2);
    if (playerOneWins)
        return formatWin(playerOneName);

    bool playerTwoWins = scoreDifference <= -2;
    if (playerTwoWins)
        return formatWin(playerTwoName);

    return DEFAULT_SCORE_FORMAT;
}

std::string formatWin(const std::string &playerName) {
    return "Win for " + playerName;
}

std::string formatAdvantage(const std::string &playerName) {
    return "Advantage " + playerName;
}