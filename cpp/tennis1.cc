#include <map>
#include "tennis.h"
#include "ScoreFormatter.h"

std::string formatScoreWhenEqual(int score);

std::string formatScoreWhenAdvantageOrWin(int playerOneScore, int playerTwoScore);

std::string formatScoreWhenDifferentAndBeforeAdvantagesOrWin(int playerOneScore, int playerTwoScore);

std::string formatAdvantage(const std::string &playerName);

std::string formatWin(const std::string &playerName);

const std::string tennis_score(int playerOneScore, int playerTwoScore) {
    bool equalScore = (playerOneScore == playerTwoScore);
    if (equalScore) {
        return formatScoreWhenEqual(playerOneScore);
    }

    bool atLeastOnePlayerHasScoreOverForty = (playerOneScore >= 4 || playerTwoScore >= 4);
    bool isAdvantageOrWin = (!equalScore && atLeastOnePlayerHasScoreOverForty);
    if (isAdvantageOrWin) {
        return formatScoreWhenAdvantageOrWin(playerOneScore, playerTwoScore);
    }

    bool isDifferentAndBeforeAdvantagesOrWin = (!equalScore && !atLeastOnePlayerHasScoreOverForty);
    if (isDifferentAndBeforeAdvantagesOrWin) {
        return formatScoreWhenDifferentAndBeforeAdvantagesOrWin(playerOneScore, playerTwoScore);
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

std::string formatScoreWhenDifferentAndBeforeAdvantagesOrWin(int playerOneScore, int playerTwoScore) {
    ScoreFormatter scoreFormatter;
    return scoreFormatter.formatScore(playerOneScore) + SEPARATOR + scoreFormatter.formatScore(playerTwoScore);
}

std::string formatScoreWhenEqual(int score) {
    static std::map<int, std::string> equalScoreValuesToStrings = {
            {0, "Love"},
            {1, "Fifteen"},
            {2, "Thirty"}
    };

    bool scoreNotFound = (equalScoreValuesToStrings.find(score) == equalScoreValuesToStrings.end());
    if (scoreNotFound) return "Deuce";
    return equalScoreValuesToStrings[score] + SEPARATOR + "All";
}