#ifndef CPP_PLAYER_H
#define CPP_PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int score;

public:
    Player(std::string name, int score);

    int getScore();

    std::string &getName();
};


#endif //CPP_PLAYER_H
