#ifndef CPP_DIFFERENTANDBEFOREADVANTAGERULE_H
#define CPP_DIFFERENTANDBEFOREADVANTAGERULE_H


class DifferentAndBeforeAdvantageRule {
public:
    DifferentAndBeforeAdvantageRule(ScoreFormatter &formatter);

    std::string format(const Player &playerOne,
                       const Player &playerTwo);

    bool verifies(const Player &playerOne, const Player &playerTwo);

private:
    ScoreFormatter scoreFormatter;
};

#endif //CPP_DIFFERENTANDBEFOREADVANTAGERULE_H
