//
//  BallsThrown.h
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#ifndef __CricScorerLite__BallsThrown__
#define __CricScorerLite__BallsThrown__

#include <stdio.h>
#include "Ball.h"

class BallsThrown
{
public:
    BallsThrown();
    ~BallsThrown();
    void BallPlayed(int runs, bool wicket, Extras modifier);
    Ball* GetLastBall();
    int getScoreInBall();
    void UndoBallPlayed();
    const Ball* getAllBallList();
private:
    Ball* _ball;
    int _ballsThrewCount;
    int _validBallCount;
};

#endif /* defined(__CricScorerLite__BallsThrown__) */
