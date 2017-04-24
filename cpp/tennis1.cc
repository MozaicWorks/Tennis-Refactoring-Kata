#include <map>
#include "tennis.h"
#include "ScoreFormatter.h"
#include "EqualScoreFormatter.h"
#include "WinFormatter.h"
#include "AdvantageFormatter.h"
#include "Player.h"

std::string formatScoreWhenAdvantageOrWin(Player &playerOne, Player &playerTwo);

const std::string tennis_score(int playerOneScore, int playerTwoScore) {
    EqualScoreFormatter equalScoreFormatter;
    ScoreFormatter scoreFormatter;
    Player playerOne(playerOneScore, "player1");
    Player playerTwo(playerTwoScore, "player2");

    bool equalScore = (playerOne.getScore() == playerTwo.getScore());
    if (equalScore) {
        return equalScoreFormatter.getValue(playerOne.getScore());
    }

    bool atLeastOnePlayerHasScoreOverForty = (playerOne.getScore() >= 4 || playerTwo.getScore() >= 4);
    bool isAdvantageOrWin = (!equalScore && atLeastOnePlayerHasScoreOverForty);
    if (isAdvantageOrWin) {
        return formatScoreWhenAdvantageOrWin(playerOne, playerTwo);
    }

    bool isDifferentAndBeforeAdvantagesOrWin = (!equalScore && !atLeastOnePlayerHasScoreOverForty);
    if (isDifferentAndBeforeAdvantagesOrWin) {
        return scoreFormatter.formatScore(playerOne.getScore()) + SEPARATOR +
               scoreFormatter.formatScore(playerTwo.getScore());
    }

    return DEFAULT_SCORE_FORMAT;
}

std::string formatScoreWhenAdvantageOrWin(Player &playerOne, Player &playerTwo) {
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
