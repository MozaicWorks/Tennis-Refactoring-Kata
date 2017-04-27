#include <string>

std::string scoreStringWhenAtLeastOnePlayerHasScoreOver40(int p1Score, int p2Score);

std::string
scoreStringWhenScoreIsDifferentAndBeforeAdvantages(int p1Score, int p2Score);

std::string scoreNumberToString(int scoreValue);

std::string scoreStringWhenEqualScores(int scoreValue);

const std::string tennis_score(int p1Score, int p2Score) {
    bool scoreIsEqual = (p1Score == p2Score);
    bool atLeastOnePlayerHasScoreOver40 = (p1Score >= 4 || p2Score >= 4);
    bool scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40 = !scoreIsEqual && atLeastOnePlayerHasScoreOver40;
    bool scoreIsDifferentAndBeforeAdvantages = !scoreIsEqual && !atLeastOnePlayerHasScoreOver40;

    if (scoreIsEqual) {
        return scoreStringWhenEqualScores(p1Score);
    }
    if (scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40) {
        return scoreStringWhenAtLeastOnePlayerHasScoreOver40(p1Score, p2Score);
    }

    if (scoreIsDifferentAndBeforeAdvantages) {
        return scoreStringWhenScoreIsDifferentAndBeforeAdvantages(p1Score, p2Score);
    }
    return "";
}

std::string
scoreStringWhenScoreIsDifferentAndBeforeAdvantages(int p1Score, int p2Score) {
    return scoreNumberToString(p1Score) + "-" + scoreNumberToString(p2Score);
}

std::string scoreStringWhenAtLeastOnePlayerHasScoreOver40(int p1Score, int p2Score) {
    std::string scoreString = "";
    int minusResult = p1Score - p2Score;
    if (minusResult == 1) scoreString = "Advantage player1";
    else if (minusResult == -1) scoreString = "Advantage player2";
    else if (minusResult >= 2) scoreString = "Win for player1";
    else scoreString = "Win for player2";
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
    }
    return "";
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
