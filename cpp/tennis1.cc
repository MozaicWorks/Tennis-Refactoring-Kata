#include <map>
#include "tennis.h"

std::string getEqualScoreName(int score);

const std::string tennis_score(int p1Score, int p2Score) {
    std::string score = "";
    int tempScore=0;
    bool equalScore = (p1Score == p2Score);
    if (equalScore)
    {
        score = getEqualScoreName(p1Score);
    }
    else if (p1Score>=4 || p2Score>=4)
    {
        int minusResult = p1Score-p2Score;
        if (minusResult==1) score ="Advantage player1";
        else if (minusResult ==-1) score ="Advantage player2";
        else if (minusResult>=2) score = "Win for player1";
        else score ="Win for player2";
    }
    else
    {
        for (int i=1; i<3; i++)
        {
            if (i==1) tempScore = p1Score;
            else { score+="-"; tempScore = p2Score;}
            switch(tempScore)
            {
                case 0:
                    score+="Love";
                    break;
                case 1:
                    score+="Fifteen";
                    break;
                case 2:
                    score+="Thirty";
                    break;
                case 3:
                    score+="Forty";
                    break;
            }
        }
    }
    return score;
}

std::string getEqualScoreName(int score) {
    static std::map<int,std::string> equalScoreValuesToStrings = {
            {0, "Love-All"},
            {1, "Fifteen-All"},
            {2, "Thirty-All"},
            {3, "Deuce"}
    };

    if(equalScoreValuesToStrings.find(score) == equalScoreValuesToStrings.end()) return "Deuce";
    return equalScoreValuesToStrings[score];
}
