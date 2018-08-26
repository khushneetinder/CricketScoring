//
//  Ball.h
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#ifndef __CricScorerLite__Ball__
#define __CricScorerLite__Ball__

#include <stdio.h>
#include "CommonDefaults.h"

class Ball
{
public:
    Ball();
    Ball(int runs, bool wicket, Extras modifier);
    ~Ball();
    
    //getters
    bool isValidBall(Extras* extra);
    bool isValidBall();
    bool isWicketFallen();
    int getTotalRuns();// runs + extras
    int getRuns();// runs only
    friend class BallsThrown;
private:
    int _runs;
    Extras _extra;
    bool _wicket;
    int _totalRuns;//extra info hobby
    Ball* _nextBall;
};


#endif /* defined(__CricScorerLite__Ball__) */
