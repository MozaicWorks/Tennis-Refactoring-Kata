//
#ifndef CPP_ADVANTAGEORWINRULE_H
#define CPP_ADVANTAGEORWINRULE_H


class AdvantageOrWinRule {
public:
    std::string format(Player &playerOne, Player &playerTwo);

    bool verifies(const Player &playerOne, const Player &playerTwo);

};

#endif //CPP_ADVANTAGEORWINRULE_H
