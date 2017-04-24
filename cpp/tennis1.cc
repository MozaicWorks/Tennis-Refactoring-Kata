#include <map>
#include "tennis.h"

std::string formatScoreWhenEqual(int score);

std::string formatScoreWhenAdvantageOrWin(int playerOneScore, int playerTwoScore);

std::string formatScoreWhenDifferentAndBeforeAdvantagesOrWin(int playerOneScore, int playerTwoScore);

std::string formatAdvantage(const std::string &playerName);

std::string formatWin(const std::string &playerOneName);

std::string formatScore(int score);

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

std::string formatWin(const std::string &playerOneName) {
    return "Win for " + playerOneName;
}

std::string formatAdvantage(const std::string &playerName) {
    return "Advantage " + playerName;
}

std::string formatScoreWhenDifferentAndBeforeAdvantagesOrWin(int playerOneScore, int playerTwoScore) {
    return formatScore(playerOneScore) + SEPARATOR + formatScore(playerTwoScore);
}

std::string formatScore(int score) {
    std::map<int, std::string> scoresToStrings = {
            {0, "Love"},
            {1, "Fifteen"},
            {2, "Thirty"},
            {3, "Forty"}
    };
    return scoresToStrings[score];
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