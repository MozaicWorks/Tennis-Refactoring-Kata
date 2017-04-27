#include <string>

std::string &scoreStringWhenAtLeastOnePlayerHasScoreOver40(int p1Score, int p2Score, std::string &score);

std::string
scoreStringWhenScoreIsDifferentAndBeforeAdvantages(int p1Score, int p2Score);

std::string scoreNumberToString(int scoreValue);

std::string scoreStringWhenEqualScores(int scoreValue);

const std::string tennis_score(int p1Score, int p2Score) {
    std::string score = "";
    bool scoreIsEqual = (p1Score == p2Score);
    bool atLeastOnePlayerHasScoreOver40 = (p1Score >= 4 || p2Score >= 4);
    bool scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40 = !scoreIsEqual && atLeastOnePlayerHasScoreOver40;
    bool scoreIsDifferentAndBeforeAdvantages = !scoreIsEqual && !atLeastOnePlayerHasScoreOver40;

    if (scoreIsEqual) {
        score = scoreStringWhenEqualScores(p1Score);
    }
    if (scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40) {
        score = scoreStringWhenAtLeastOnePlayerHasScoreOver40(p1Score, p2Score, score);
    }

    if (scoreIsDifferentAndBeforeAdvantages) {
        score = scoreStringWhenScoreIsDifferentAndBeforeAdvantages(p1Score, p2Score);
    }
    return score;
}

std::string
scoreStringWhenScoreIsDifferentAndBeforeAdvantages(int p1Score, int p2Score) {
    return scoreNumberToString(p1Score) + "-" + scoreNumberToString(p2Score);
}

std::string &scoreStringWhenAtLeastOnePlayerHasScoreOver40(int p1Score, int p2Score, std::string &score) {
    int minusResult = p1Score - p2Score;
    if (minusResult == 1) score = "Advantage player1";
    else if (minusResult == -1) score = "Advantage player2";
    else if (minusResult >= 2) score = "Win for player1";
    else score = "Win for player2";
    return score;
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
