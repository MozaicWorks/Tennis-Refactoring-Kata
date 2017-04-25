#include "Player.h"
#include <map>
#include "AdvantageOrWinRule.h"
#include "WinFormatter.h"
#include "AdvantageFormatter.h"
#include "tennis.h"

bool AdvantageOrWinRule::verifies(const Player &playerOne, const Player &playerTwo) {
    return (!(playerOne.getScore() == playerTwo.getScore()) &&
            (playerOne.getScore() >= 4 || playerTwo.getScore() >= 4));
}

std::string AdvantageOrWinRule::format(Player &playerOne, Player &playerTwo) {
    WinFormatter winFormatter;
    AdvantageFormatter advantageFormatter;

    int scoreDifference = playerOne.getScore() - playerTwo.getScore();

    bool playerOneHasAdvantage = (scoreDifference == 1);
    if (playerOneHasAdvantage) {
        return advantageFormatter.format(playerOne.getName());
    }

    bool playerTwoHasAdvantage = (scoreDifference == -1);
    if (playerTwoHasAdvantage) {
        return advantageFormatter.format(playerTwo.getName());
    }

    bool playerOneWins = (scoreDifference >= 2);
    if (playerOneWins) {
        return winFormatter.format(playerOne.getName());
    }

    bool playerTwoWins = scoreDifference <= -2;
    if (playerTwoWins) {
        return winFormatter.format(playerTwo.getName());
    }

    return DEFAULT_SCORE_FORMAT;
}