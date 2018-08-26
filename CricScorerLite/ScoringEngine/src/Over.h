//
//  Over.h
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#ifndef __CricScorerLite__Over__
#define __CricScorerLite__Over__

#include <stdio.h>
#include "BallsThrown.h"

class Over
{
public:
    Over();
    ~Over();
    void extraBall(Extras modifier);
    void wicketFall();
    void wicketFallWithRuns(int runs);
    void setRuns(int runs);
    void setRunsAndWicket(int runs, bool isWicketFallen);
    int getRuns();
    int getLegalBalls();
    int getWicketsFallen();
    Ball* getLastBall();
    int getScoreInBall();
    const Ball* getAllBalls();
    void undoLastBall();
private:
    void resetExtra();
    int _runs;
    int _legalBallCount;
    int _wicketFall;
    Extras _extra;
    BallsThrown* _ballList;
};

#endif /* defined(__CricScorerLite__Over__) */
