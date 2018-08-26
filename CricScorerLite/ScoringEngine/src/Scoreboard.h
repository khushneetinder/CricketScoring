//
//  Scoreboard.h
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#ifndef __CricScorerLite__Scoreboard__
#define __CricScorerLite__Scoreboard__

#include <stdio.h>
#include "Over.h"

class Scoreboard
{
public:
    
    static Scoreboard* getSharedInstance();
    
    void dotBall();
    void single();
    void doubles();
    void triples();
    void fourBoundary();
    void fiveRuns();
    void sixBoundary();

    void dotWithWicket(bool isOut);
    void singleWithWicket(bool isOut);
    void doublesWithWicket(bool isOut);
    void triplesWithWicket(bool isOut);
    void fourRunsWithWicket(bool isOut);
    void fiveRunsWithWicket(bool isOut);
    
    void overThrow(int runs);
    void playerRunOut(bool isOut);
    void noBall();
    void wideBall();
    void playerOut();
    void runOutWithRuns(int runs);
    void undoLastAction();
    
    //Getter
    bool isLastBallValid();
    int getScore();
    int getBalls();
    int getWickets();
    const char* getLastBall(int* runs);
    const Ball* getAllBalls();
    bool isPlayerRunOut();
private:
    Over* _over;
    Extras _modifier;
    bool _runOut;
    Scoreboard();
    ~Scoreboard();
    
};

#endif /* defined(__CricScorerLite__Scoreboard__) */
