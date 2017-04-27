#include <string>

void scoreStringWhenEqualScores(int p1Score, std::string &score);

std::string &scoreStringWhenAtLeastOnePlayerHasScoreOver40(int p1Score, int p2Score, std::string &score);

std::string &
scoreStringWhenScoreIsDifferentAndBeforeAdvantages(int p1Score, int p2Score, std::string &score);

std::string &getSomeScoreString(std::string &score, int tempScore);

const std::string tennis_score(int p1Score, int p2Score) {
    std::string score = "";
    bool scoreIsEqual = (p1Score == p2Score);
    bool atLeastOnePlayerHasScoreOver40 = (p1Score >= 4 || p2Score >= 4);
    bool scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40 = !scoreIsEqual && atLeastOnePlayerHasScoreOver40;
    bool scoreIsDifferentAndBeforeAdvantages = !scoreIsEqual && !atLeastOnePlayerHasScoreOver40;

    if (scoreIsEqual) {
        scoreStringWhenEqualScores(p1Score, score);
    }
    if (scoreIsDifferentAndAtLeastOnePlayerHasScoreOver40) {
        score = scoreStringWhenAtLeastOnePlayerHasScoreOver40(p1Score, p2Score, score);
    }

    if (scoreIsDifferentAndBeforeAdvantages) {
        score = scoreStringWhenScoreIsDifferentAndBeforeAdvantages(p1Score, p2Score, score);
    }
    return score;
}

std::string &
scoreStringWhenScoreIsDifferentAndBeforeAdvantages(int p1Score, int p2Score, std::string &score) {
    score = getSomeScoreString(score, p1Score);
    score += "-";
    score = getSomeScoreString(score, p2Score);
    return score;
}

std::string &getSomeScoreString(std::string &score, int tempScore) {
    switch (tempScore) {
        case 0:
            score += "Love";
            break;
        case 1:
            score += "Fifteen";
            break;
        case 2:
            score += "Thirty";
            break;
        case 3:
            score += "Forty";
            break;
    }
    return score;
}

std::string &scoreStringWhenAtLeastOnePlayerHasScoreOver40(int p1Score, int p2Score, std::string &score) {
    int minusResult = p1Score - p2Score;
    if (minusResult == 1) score = "Advantage player1";
    else if (minusResult == -1) score = "Advantage player2";
    else if (minusResult >= 2) score = "Win for player1";
    else score = "Win for player2";
    return score;
}


void scoreStringWhenEqualScores(int p1Score, std::string &score) {
    switch (p1Score) {
        case 0:
            score = "Love-All";
            break;
        case 1:
            score = "Fifteen-All";
            break;
        case 2:
            score = "Thirty-All";
            break;
        default:
            score = "Deuce";
            break;
    }
}