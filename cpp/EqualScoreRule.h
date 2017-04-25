#ifndef CPP_EQUALSCORERULE_H
#define CPP_EQUALSCORERULE_H


class EqualScoreRule {
public:
    EqualScoreRule(EqualScoreFormatter &formatter);

    bool verifies(const Player &playerOne, const Player &playerTwo);

    std::string format(const Player &playerOne);

private:
    EqualScoreFormatter formatter;
};

#endif //CPP_EQUALSCORERULE_H
