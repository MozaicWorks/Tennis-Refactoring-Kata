#include <map>
#include "EqualScoreFormatter.h"
#include "tennis.h"

std::string EqualScoreFormatter::getValue(int score) {
    static std::map<int, std::string> equalScoreValuesToStrings = {
            {0, "Love"},
            {1, "Fifteen"},
            {2, "Thirty"}
    };

    bool scoreNotFound = (equalScoreValuesToStrings.find(score) == equalScoreValuesToStrings.end());
    if (scoreNotFound) return "Deuce";
    return equalScoreValuesToStrings[score] + SEPARATOR + "All";
}