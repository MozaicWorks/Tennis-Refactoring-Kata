#ifndef CPP_EQUALSCOREFORMATTER_H
#define CPP_EQUALSCOREFORMATTER_H


class EqualScoreFormatter {
private:
    int score;
    int secondScore;

public:
    EqualScoreFormatter(int playerScore, int secondScore);

    std::string format();

    bool applies();
};


#endif //CPP_EQUALSCOREFORMATTER_H
