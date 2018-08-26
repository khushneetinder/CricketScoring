//
//  BallsThrown.cpp
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#include "BallsThrown.h"
BallsThrown::BallsThrown()
{
    _ball = NULL;
    _ballsThrewCount = 0;
    _validBallCount = 0;
}


BallsThrown::~BallsThrown()
{
    _ball = NULL;
}

void BallsThrown::BallPlayed(int runs, bool wicket, Extras modifier) {
    Ball* newBall = new Ball(runs, wicket, modifier);
    if (_ball == NULL){
        _ball = newBall;
    }
    else {
        Ball* currentBall = _ball;
        while (currentBall->_nextBall != NULL) {
            currentBall = currentBall->_nextBall;
        }
        currentBall->_nextBall = newBall;
    }
    _ballsThrewCount++;
    if (modifier == kValidBall) {
        _validBallCount++;
    }
}

void BallsThrown::UndoBallPlayed() {
    Ball* lastBall = _ball;
    if (lastBall->_nextBall != NULL) {
        for (int i = 1; i < _ballsThrewCount-1; i++) {
            lastBall = lastBall->_nextBall;
        }
        if (lastBall->isValidBall()) {
            _validBallCount--;
        }
        lastBall->_nextBall = NULL;
    }
    else {
        if (lastBall->isValidBall()) {
            _validBallCount--;
        }
        _ball = NULL;
    }
    _ballsThrewCount--;
}

Ball* BallsThrown::GetLastBall(){
    Ball* lastBall = _ball;
    for (int i = 1; i < _ballsThrewCount; i++) {
        lastBall = lastBall->_nextBall;
    }
    return lastBall;
}

int BallsThrown::getScoreInBall() {
    Ball* lastBall = _ball;
    int runs = 0;
    for (int i = 0; i < _validBallCount - 1; i++) {
        if (lastBall->isValidBall())
            lastBall = lastBall->_nextBall;
    }
    runs = lastBall->_totalRuns;
    /*if (lastBall->isValidBall()) {
     if (lastBall->_nextBall == NULL) {
     runs = lastBall->_totalRuns;
     }
     else {
     while (lastBall->_nextBall) {
     runs += lastBall->_nextBall->_totalRuns;
     lastBall = lastBall->_nextBall;
     }
     }
     }
     else {
     if (lastBall->_nextBall == NULL) {
     runs = lastBall->_totalRuns;
     }
     else {
     while (lastBall) {
     runs += lastBall->_totalRuns;
     lastBall = lastBall->_nextBall;
     }
     }
     }*/
    return runs;
}

const Ball* BallsThrown::getAllBallList() {
    return _ball;
}
