//
//  Scorer.h
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#ifndef __CricScorerLite__Scorer__
#define __CricScorerLite__Scorer__

#include <stdio.h>
#include <iostream>
#include <vector>

#include "ScoringCommand.h"
#include "Scoreboard.h"
#include "INotificationCenter.h"

class Scorer : public INotificationCenter
{
public:
    Scorer();
    Scorer(Scoreboard* sb);
    Scorer(ScoringCommand* cmd, Scoreboard* sb);
    virtual ~Scorer();
    void doScoring();
    void doScoring(ScoringCommand* cmd);
    
    void scoreChanged();
    void setScore();
    
    void virtual registerObserver(NotifcationObserver *o);
    void virtual removeObserver(NotifcationObserver *o);
    void virtual notifyAll();
    
private:
    ScoringCommand* _command;
    Scoreboard* _scoreBoard;
    std::vector<NotifcationObserver*> mObservers;
};

#endif /* defined(__CricScorerLite__Scorer__) */
