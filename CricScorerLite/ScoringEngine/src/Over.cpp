//
//  Over.cpp
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#include "Over.h"
#include <iostream>
Over::Over()
{
    _runs = 0;
    _legalBallCount = 0;
    _wicketFall = 0;
    _extra = kValidBall;
    _ballList = new BallsThrown();
}

Over::~Over()
{
    delete _ballList;
}

void Over::setRuns(int runs)
{
    this->setRunsAndWicket(runs, false);
}

void Over::extraBall(Extras modifier)
{
    if (_extra == kValidBall) {
        _extra = modifier;
        _runs++;
    }
}

void Over::resetExtra()
{
    _extra = kValidBall;
}

void Over::wicketFall()
{
    this->wicketFallWithRuns(0);
}

void Over::wicketFallWithRuns(int runs)
{
    this->setRunsAndWicket(runs, true);
}

void Over::setRunsAndWicket(int runs, bool isWicketFallen)
{
    if (_extra == kValidBall) {
        if (isWicketFallen) {
            ++_wicketFall;
        }
        ++_legalBallCount;
    }
    _ballList->BallPlayed(runs, isWicketFallen, _extra);
    _runs += runs;
    std::cout<<"runs "<<_runs<<" legalBallCount "<< _legalBallCount<<" wicketFall "<<_wicketFall<<" extra " << _extra<<std::endl;
    resetExtra();
}

void Over::undoLastBall()
{
    Ball* lastBall = this->getLastBall();
    if (lastBall != NULL) {
        Extras extra = kValidBall;
        if (lastBall->isValidBall(&extra)) {
            _runs = _runs - lastBall->getRuns();
            _legalBallCount--;
        }
        else {
            _runs = _runs - lastBall->getTotalRuns();
            _extra = kValidBall;
            
        }
        if (lastBall->isWicketFallen()) {
            _wicketFall--;
        }
        
        _ballList->UndoBallPlayed();
        lastBall = this->getLastBall();        
    }
    else if (_extra != kValidBall) {
        _runs--;
        _extra = kValidBall;

    }
    std::cout<<"runs "<<_runs<<" legalBallCount "<< _legalBallCount<<" wicketFall "<<_wicketFall<<" extra " << _extra<<std::endl;
}

int Over::getRuns()
{
    return _runs;
}

int Over::getLegalBalls()
{
    return _legalBallCount;
}

int Over::getWicketsFallen()
{
    return _wicketFall;
}

Ball* Over::getLastBall ()
{
    return _ballList->GetLastBall();
}

int Over::getScoreInBall()
{
    return _ballList->getScoreInBall();
}

const Ball* Over::getAllBalls()
{
    return _ballList->getAllBallList();
}
