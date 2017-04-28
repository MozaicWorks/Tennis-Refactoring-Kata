#ifndef CPP_EQUALSCOREFORMATTER_H
#define CPP_EQUALSCOREFORMATTER_H


class EqualScoreFormatter {
private:
    int score;

public:
    EqualScoreFormatter(int playerScore);

    std::string format();
};


#endif //CPP_EQUALSCOREFORMATTER_H
