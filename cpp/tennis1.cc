#include <map>
#include "tennis.h"

std::string formatScoreWhenEqual(int score);

std::string formatScore(int tempScore);

std::string formatScore(int playerOneScore, int playerTwoScore);

std::string formatScoreWhenAdvantageOrWin(int playerOneScore, int playerTwoScore);

std::string formatScoreWhenEqual(std::string firstScore);

std::string formatAdvantage(const std::string &playerName);

std::string formatWin(const std::string &playerOneName);

const std::string tennis_score(int playerOneScore, int playerTwoScore) {
    std::string score;

    bool equalScore = (playerOneScore == playerTwoScore);
    if (equalScore) {
        score = formatScoreWhenEqual(playerOneScore);
    }

    bool atLeastOnePlayerHasScoreOverForty = (playerOneScore >= 4 || playerTwoScore >= 4);
    bool isAdvantageOrWin = (!equalScore && atLeastOnePlayerHasScoreOverForty);
    if (isAdvantageOrWin) {
        score = formatScoreWhenAdvantageOrWin(playerOneScore, playerTwoScore);
    }

    bool isDifferentAndBeforeAdvantagesOrWin = (!equalScore && !atLeastOnePlayerHasScoreOverForty);
    if (isDifferentAndBeforeAdvantagesOrWin) {
        score = formatScore(playerOneScore, playerTwoScore);
    }
    return score;
}

std::string formatScoreWhenAdvantageOrWin(int playerOneScore, int playerTwoScore) {
    std::string score;
    int scoreDifference = playerOneScore - playerTwoScore;
    const std::string playerOneName = "player1";
    const std::string playerTwoName = "player2";

    bool isAdvantagePlayerOne = (scoreDifference == 1);
    bool isAdvantagePlayerTwo = (scoreDifference == -1);
    bool playerOneWins = (scoreDifference >= 2);
    bool playerTwoWins = scoreDifference <= -2;

    if (isAdvantagePlayerOne) score = formatAdvantage(playerOneName);
    if (isAdvantagePlayerTwo) score = formatAdvantage(playerTwoName);
    if (playerOneWins) score = formatWin(playerOneName);
    if (playerTwoWins) score = formatWin(playerTwoName);
    return score;
}

std::string formatWin(const std::string &playerOneName) {
    return "Win for " + playerOneName;
}

std::string formatAdvantage(const std::string &playerName) {
    return "Advantage " + playerName;
}

std::string formatScore(int playerOneScore, int playerTwoScore) {
    return formatScore(playerOneScore) + SEPARATOR + formatScore(playerTwoScore);
}

std::string formatScore(int tempScore) {
    std::map<int, std::string> scoresToStrings = {
            {0, "Love"},
            {1, "Fifteen"},
            {2, "Thirty"},
            {3, "Forty"}
    };
    return scoresToStrings[tempScore];
}

std::string formatScoreWhenEqual(int score) {
    static std::map<int, std::string> equalScoreValuesToStrings = {
            {0, "Love"},
            {1, "Fifteen"},
            {2, "Thirty"}
    };

    if (equalScoreValuesToStrings.find(score) == equalScoreValuesToStrings.end()) return "Deuce";
    return formatScoreWhenEqual(equalScoreValuesToStrings[score]);
}

std::string formatScoreWhenEqual(std::string firstScore) {
    return firstScore + SEPARATOR + "All";
}
