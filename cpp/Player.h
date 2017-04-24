#ifndef CPP_PLAYER_H
#define CPP_PLAYER_H

#include <string>

class Player {
private:
    int score;
    std::string name;

public:

    Player(int score, std::string name) : score(score), name(name) {

    }

    int getScore() const { return score; }

    std::string getName() const { return name; }
};


#endif //CPP_PLAYER_H
