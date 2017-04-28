#include <string>
#include <map>
#include "EqualScoreFormatter.h"


std::string EqualScoreFormatter::scoreStringWhenEqualScores(int scoreValue) {
    std::map<int, std::__cxx11::string> equalScoresToStrings = {
            {0, "Love-All"},
            {1, "Fifteen-All"},
            {2, "Thirty-All"},
            {3, "Deuce"}
    };
    bool foundScoreValue = equalScoresToStrings.find(scoreValue) != equalScoresToStrings.end();
    return foundScoreValue ? equalScoresToStrings[scoreValue] : "Deuce";
}