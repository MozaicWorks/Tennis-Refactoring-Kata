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

std::string formatEqualScore(const Player &playerOne, EqualScoreFormatter &equalScoreFormatter);

std::string formatScoreWhenDifferentAndBeforeAdvantageOrWin(const Player &playerOne, const Player &playerTwo,
                                                            ScoreFormatter &scoreFormatter);

const std::string tennis_score(int playerOneScore, int playerTwoScore) {
    Player playerOne(playerOneScore, "player1");
    Player playerTwo(playerTwoScore, "player2");

    EqualScoreFormatter equalScoreFormatter;
    ScoreFormatter scoreFormatter;

    if (isEqualScore(playerOne, playerTwo)) {
        return formatEqualScore(playerOne, equalScoreFormatter);
    }

    if (isAdvantageOrWin(playerOne, playerTwo)) {
        return formatScoreWhenAdvantageOrWin(playerOne, playerTwo);
    }

    if (isScoreNotEqualAndBeforeAdvantageOrWin(playerOne, playerTwo)) {
        return formatScoreWhenDifferentAndBeforeAdvantageOrWin(playerOne, playerTwo, scoreFormatter);
    }

    return DEFAULT_SCORE_FORMAT;
}

std::string formatScoreWhenDifferentAndBeforeAdvantageOrWin(const Player &playerOne, const Player &playerTwo,
                                                            ScoreFormatter &scoreFormatter) {
    return scoreFormatter.formatScore(playerOne.getScore())
           + SEPARATOR
           + scoreFormatter.formatScore(playerTwo.getScore());
}

std::string formatEqualScore(const Player &playerOne, EqualScoreFormatter &equalScoreFormatter) {
    return equalScoreFormatter.getValue(playerOne.getScore());
}

bool isScoreNotEqualAndBeforeAdvantageOrWin(const Player &playerOne, const Player &playerTwo) {
    return (!(playerOne.getScore() == playerTwo.getScore()) &&
            !(playerOne.getScore() >= 4 || playerTwo.getScore() >= 4));
}

bool isAdvantageOrWin(const Player &playerOne, const Player &playerTwo) {
    return (!(playerOne.getScore() == playerTwo.getScore()) &&
            (playerOne.getScore() >= 4 || playerTwo.getScore() >= 4));
}

bool isEqualScore(const Player &playerOne, const Player &playerTwo) {
    return (playerOne.getScore() == playerTwo.getScore());
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
