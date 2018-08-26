//
//  Ball.cpp
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#include "Ball.h"

Ball::Ball()
{
    _extra = kValidBall;
    _runs = 0;
    _totalRuns = 0;
    _wicket = false;
    _nextBall = NULL;
}

Ball::Ball(int runs, bool wicket, Extras modifier)
{
    _extra = modifier;
    _runs = runs;
    _wicket = wicket;
    if (modifier == kValidBall) {
        _totalRuns = runs;
    }
    else {
        _wicket = false;
        _totalRuns = runs + 1;
    }
    _nextBall = NULL;
}

Ball::~Ball()
{
    _nextBall = NULL;
}

bool Ball::isValidBall(Extras* extra) {
    bool isValid = this->isValidBall();
    *extra = _extra;
    return isValid;
}

bool Ball::isValidBall() {
    bool isValid = false;
    if (_extra == kValidBall) {
        isValid = true;
    }
    return isValid;
}

bool Ball::isWicketFallen() {
    return _wicket;
}

int Ball::getTotalRuns() {
    return _totalRuns;
}

int Ball::getRuns() {
    return _runs;
}
