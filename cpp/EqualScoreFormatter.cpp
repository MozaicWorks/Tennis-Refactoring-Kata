#include <string>
#include <map>
#include "EqualScoreFormatter.h"


std::string EqualScoreFormatter::format() {
    std::map<int, std::string> equalScoresToStrings = {
            {0, "Love-All"},
            {1, "Fifteen-All"},
            {2, "Thirty-All"},
            {3, "Deuce"}
    };
    bool foundScoreValue = equalScoresToStrings.find(score) != equalScoresToStrings.end();
    return foundScoreValue ? equalScoresToStrings[score] : "Deuce";
}

EqualScoreFormatter::EqualScoreFormatter(int playerScore, int secondScore) : score(playerScore),
                                                                             secondScore(secondScore) {
}

bool EqualScoreFormatter::applies() {
    return score == secondScore;
}
