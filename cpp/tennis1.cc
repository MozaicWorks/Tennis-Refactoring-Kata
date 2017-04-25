#include <map>
#include "tennis.h"
#include "ScoreFormatter.h"
#include "EqualScoreFormatter.h"
#include "WinFormatter.h"
#include "AdvantageFormatter.h"
#include "Player.h"

std::string formatScoreWhenAdvantageOrWin(Player &playerOne, Player &playerTwo);

bool isEqualScore(const Player &playerOne, const Player &playerTwo);

bool isAdvantageOrWin(const Player &playerOne, const Player &playerTwo);

bool isScoreNotEqualAndBeforeAdvantageOrWin(const Player &playerOne, const Player &playerTwo);

const std::string tennis_score(int playerOneScore, int playerTwoScore) {
    Player playerOne(playerOneScore, "player1");
    Player playerTwo(playerTwoScore, "player2");

    EqualScoreFormatter equalScoreFormatter;
    ScoreFormatter scoreFormatter;

    if (isEqualScore(playerOne, playerTwo)) {
        return equalScoreFormatter.getValue(playerOne.getScore());
    }

    if (isAdvantageOrWin(playerOne, playerTwo)) {
        return formatScoreWhenAdvantageOrWin(playerOne, playerTwo);
    }

    if (isScoreNotEqualAndBeforeAdvantageOrWin(playerOne, playerTwo)) {
        return scoreFormatter.formatScore(playerOne.getScore())
               + SEPARATOR
               + scoreFormatter.formatScore(playerTwo.getScore());
    }

    return DEFAULT_SCORE_FORMAT;
}

bool isScoreNotEqualAndBeforeAdvantageOrWin(const Player &playerOne, const Player &playerTwo) { return (!(playerOne.getScore() == playerTwo.getScore()) && !(playerOne.getScore() >= 4 || playerTwo.getScore() >= 4)); }

bool isAdvantageOrWin(const Player &playerOne, const Player &playerTwo) { return (!(playerOne.getScore() == playerTwo.getScore()) && (playerOne.getScore() >= 4 || playerTwo.getScore() >= 4)); }

bool isEqualScore(const Player &playerOne, const Player &playerTwo) { return (playerOne.getScore() == playerTwo.getScore()); }

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
