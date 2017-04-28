#include <string>
#include "Player.h"

std::string
scoreStringWhenAtLeastOnePlayerHasScoreOver40(int p1Score, int p2Score, std::string &p1Name, std::string &p2Name);

std::string
scoreStringWhenScoreIsDifferentAndBeforeAdvantages(int p1Score, int p2Score);

std::string scoreNumberToString(int scoreValue);

std::string scoreStringWhenEqualScores(int scoreValue);

const std::string tennis_score(int p1Score, int p2Score) {
    std::string p1Name = "player1";
    std::string p2Name = "player2";

    Player player1(p1Name, p1Score);
    Player player2(p2Name, p2Score);

    bool scoreIsEqual = (player1.getScore() == player2.getScore());
    bool atLeastOnePlayerHasScoreOver40 = (player1.getScore() >= 4 || player2.getScore() >= 4);
    bool scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40 = !scoreIsEqual && atLeastOnePlayerHasScoreOver40;
    bool scoreIsDifferentAndBeforeAdvantages = !scoreIsEqual && !atLeastOnePlayerHasScoreOver40;

    if (scoreIsEqual) {
        return scoreStringWhenEqualScores(player1.getScore());
    }

    if (scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40) {
        return scoreStringWhenAtLeastOnePlayerHasScoreOver40(player1.getScore(), player2.getScore(), player1.getName(), p2Name);
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
scoreStringWhenAtLeastOnePlayerHasScoreOver40(int p1Score, int p2Score, std::string &p1Name, std::string &p2Name) {
    std::string scoreString = "";
    int minusResult = p1Score - p2Score;
    if (minusResult == 1) {
        scoreString = "Advantage " + p1Name;
    }
    if (minusResult == -1) {
        scoreString = "Advantage " + p2Name;
    }
    if (minusResult >= 2) {
        scoreString = "Win for " + p1Name;
    }
    if (minusResult <= -2) {
        scoreString = "Win for " + p2Name;
    }
    return scoreString;
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
