//
//  Scorer.cpp
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#include "Scorer.h"

Scorer::Scorer()
{
    _command = NULL;
    _scoreBoard = NULL;
}

Scorer::Scorer(Scoreboard* sb)
{
    _command = NULL;
    _scoreBoard = sb;
}

Scorer::Scorer(ScoringCommand* cmd, Scoreboard* sb)
{
    _command = cmd;
    _scoreBoard = sb;
}

Scorer::~Scorer()
{
    
}

void Scorer::doScoring() {
    _command->execute();
}

void Scorer::doScoring(ScoringCommand* cmd) {
    _command = cmd;
    this->doScoring();
    scoreChanged();
}

void Scorer::registerObserver(NotifcationObserver *o) {
    mObservers.push_back(o);
}

void Scorer::removeObserver(NotifcationObserver *o) {
    mObservers.erase(std::remove(mObservers.begin(), mObservers.end(), o), mObservers.end());
}

void Scorer::notifyAll() {
    for (auto & observer : mObservers) {
        observer->update(_scoreBoard);
    }
}

void Scorer::scoreChanged() {
    notifyAll();
}

void Scorer::setScore() {
    
    scoreChanged();
}
