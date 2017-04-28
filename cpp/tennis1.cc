#include <string>
#include "Player.h"

std::string
scoreStringWhenAtLeastOnePlayerHasScoreOver40(std::string &p2Name, int p2Score, Player player1);

std::string
scoreStringWhenScoreIsDifferentAndBeforeAdvantages(int p1Score, int p2Score);

std::string scoreNumberToString(int scoreValue);

std::string scoreStringWhenEqualScores(int scoreValue);

std::string formatAdvantageOrWin(const std::string &p1Name, int minusResult);

const std::string tennis_score(int p1Score, int p2Score) {

    Player player1("player1", p1Score);
    Player player2("player2", p2Score);

    bool scoreIsEqual = (player1.getScore() == player2.getScore());
    bool atLeastOnePlayerHasScoreOver40 = (player1.getScore() >= 4 || player2.getScore() >= 4);
    bool scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40 = !scoreIsEqual && atLeastOnePlayerHasScoreOver40;
    bool scoreIsDifferentAndBeforeAdvantages = !scoreIsEqual && !atLeastOnePlayerHasScoreOver40;

    if (scoreIsEqual) {
        return scoreStringWhenEqualScores(player1.getScore());
    }

    if (scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40) {
        return scoreStringWhenAtLeastOnePlayerHasScoreOver40(player2.getName(), player2.getScore(),
                                                             player1);
    }

    if (scoreIsDifferentAndBeforeAdvantages) {
        return scoreStringWhenScoreIsDifferentAndBeforeAdvantages(player1.getScore(), player2.getScore());
    }
    return "";
}

std::string
scoreStringWhenScoreIsDifferentAndBeforeAdvantages(int p1Score, int p2Score) {
    return scoreNumberToString(p1Score) + "-" + scoreNumberToString(p2Score);
}

std::string
scoreStringWhenAtLeastOnePlayerHasScoreOver40(std::string &p2Name, int p2Score, Player player1) {
    std::string scoreString = "";
    int minusResult = player1.getScore() - p2Score;
    if (minusResult > 0)
        scoreString = formatAdvantageOrWin(player1.getName(), minusResult);

    if (minusResult < 0) {
        scoreString = formatAdvantageOrWin(p2Name, -minusResult);
    }
    return scoreString;
}

std::string formatAdvantageOrWin(const std::string &p1Name, int minusResult) {
    if (minusResult == 1) {
        return "Advantage " + p1Name;
    }
    if (minusResult >= 2) {
        return "Win for " + p1Name;
    }
    return "";
}

std::string scoreNumberToString(int scoreValue) {
    switch (scoreValue) {
        case 0:
            return "Love";
        case 1:
            return "Fifteen";
        case 2:
            return "Thirty";
        case 3:
            return "Forty";
        default:
            return "";
    }
}

std::string scoreStringWhenEqualScores(int scoreValue) {
    switch (scoreValue) {
        case 0:
            return "Love-All";
        case 1:
            return "Fifteen-All";
        case 2:
            return "Thirty-All";
        default:
            return "Deuce";
    }
}
