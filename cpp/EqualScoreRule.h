#ifndef CPP_EQUALSCORERULE_H
#define CPP_EQUALSCORERULE_H


class EqualScoreRule {
public:
    bool isEqualScore(const Player &playerOne, const Player &playerTwo);

    std::string formatEqualScore(const Player &playerOne, EqualScoreFormatter &equalScoreFormatter);

};

#endif //CPP_EQUALSCORERULE_H
