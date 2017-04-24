#include <map>
#include "ScoreFormatter.h"

std::string ScoreFormatter::formatScore(int score) {
    std::map<int, std::string> scoresToStrings = {
            {0, "Love"},
            {1, "Fifteen"},
            {2, "Thirty"},
            {3, "Forty"}
    };
    return scoresToStrings[score];
}
