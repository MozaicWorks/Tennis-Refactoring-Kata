#include <string>
#include <map>
#include "Player.h"

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

    int scoreDifference = (player1.getScore() - player2.getScore());
    if (scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40 && (scoreDifference > 0))
        return formatAdvantageOrWin(player1.getName(), scoreDifference);

    if (scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40 && scoreDifference < 0) {
        return formatAdvantageOrWin(player2.getName(), -scoreDifference);
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
    std::map<int, std::string> scoreToScoreStrings = {
            {0, "Love"},
            {1, "Fifteen"},
            {2, "Thirty"},
            {3, "Forty"}
    };
    return scoreToScoreStrings[scoreValue];
}

std::string scoreStringWhenEqualScores(int scoreValue) {
    std::map<int, std::string> equalScoresToStrings = {
            {0, "Love-All"},
            {1, "Fifteen-All"},
            {2, "Thirty-All"},
            {3, "Deuce"}
    };
    bool foundScoreValue = equalScoresToStrings.find(scoreValue) != equalScoresToStrings.end();
    return foundScoreValue ? equalScoresToStrings[scoreValue] : "Deuce";
}
