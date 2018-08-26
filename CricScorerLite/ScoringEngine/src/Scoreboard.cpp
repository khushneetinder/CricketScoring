//
//  Scoreboard.cpp
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#include "Scoreboard.h"
#include <iostream>
Scoreboard* Scoreboard::getSharedInstance() {
    static Scoreboard *sharedInstance = NULL;
    if (sharedInstance == NULL) {
        sharedInstance = new Scoreboard();
    }
    return sharedInstance;
}

Scoreboard::Scoreboard()
{
    _over = new Over();
    _modifier = kValidBall;
    _runOut = false;
}

Scoreboard::~Scoreboard()
{
    delete _over;
}

void Scoreboard::undoLastAction() {
    _over->undoLastBall();
}

void Scoreboard::dotBall()
{
    _over->setRunsAndWicket(kDot, false);
}

void Scoreboard::single()
{
    _over->setRunsAndWicket(kSingle, false);
}

void Scoreboard::doubles()
{
    _over->setRunsAndWicket(kDouble, false);
}

void Scoreboard::triples()
{
    _over->setRunsAndWicket(kTriple, false);
}

void Scoreboard::fourBoundary()
{
    _over->setRunsAndWicket(kFour, false);
}

void Scoreboard::fiveRuns()
{
    _over->setRunsAndWicket(kFive, false);
}

void Scoreboard::sixBoundary()
{
    _over->setRunsAndWicket(kSix, false);
}

void Scoreboard::dotWithWicket(bool isOut)
{
    _over->setRunsAndWicket(kDot, isOut);
}

void Scoreboard::singleWithWicket(bool isOut)
{
    _over->setRunsAndWicket(kSingle, isOut);
}

void Scoreboard::doublesWithWicket(bool isOut)
{
    _over->setRunsAndWicket(kDouble, isOut);
}

void Scoreboard::triplesWithWicket(bool isOut)
{
    _over->setRunsAndWicket(kTriple, isOut);
}

void Scoreboard::fourRunsWithWicket(bool isOut)
{
    _over->setRunsAndWicket(kFour, isOut);
}

void Scoreboard::fiveRunsWithWicket(bool isOut) {
    _over->setRunsAndWicket(kFive, isOut);
}

void Scoreboard::overThrow(int run)
{
    _over->setRuns(run);
}

void Scoreboard::playerOut() {
    _over->wicketFall();
}

void Scoreboard::runOutWithRuns(int runs) {
    _over->wicketFallWithRuns(runs);
}

void Scoreboard::noBall()
{
    _over->extraBall(kNoBall);
}

void Scoreboard::wideBall() {
    _over->extraBall(kWideBall);
}

int Scoreboard::getScore(){
    return _over->getRuns();
}

int Scoreboard::getBalls() {
    return _over->getLegalBalls();
}

int Scoreboard::getWickets()
{
    return _over->getWicketsFallen();
}

bool Scoreboard::isLastBallValid() {
    Ball* lastBall = _over->getLastBall();
    if (lastBall) {
        return lastBall->isValidBall();
    }
    return true;
}

const Ball* Scoreboard::getAllBalls() {
    return _over->getAllBalls();
}

void Scoreboard::playerRunOut(bool isOut) {
    _runOut = isOut;
}

bool Scoreboard::isPlayerRunOut() {
    return _runOut;
}

const char* Scoreboard::getLastBall(int* totalRuns) {
    std::string scoreString("");
    *totalRuns = 0;
    Ball* ball = _over->getLastBall();
    
    if (ball) {
        *totalRuns = _over->getScoreInBall();
        int runs = ball->getRuns();
        std::string runsStr = std::to_string(runs);
        
        _modifier = kValidBall;
        bool validBall = ball->isValidBall(&_modifier);
        
        if (validBall) {
            if (ball->isWicketFallen()) {
                std::string wicketStr("W");
                scoreString.append(wicketStr);
                if (runs != 0) {
                    scoreString.append("+");
                    scoreString.append(runsStr);
                }
            }
            else
            {
                scoreString.append(runsStr);
            }
        }
        else {
            if (_modifier == kNoBall) {
                std::string noBallStr("Nb");
                scoreString.append(noBallStr);
            }
            else if (_modifier == kWideBall)
            {
                std::string wideBallStr("Wd");
                scoreString.append(wideBallStr);
            }
            if (runs != 0) {
                scoreString.append("+");
                scoreString.append(runsStr);
            }
        }
    }
    
    return scoreString.c_str();
}
