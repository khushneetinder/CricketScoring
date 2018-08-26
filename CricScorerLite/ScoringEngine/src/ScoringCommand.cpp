//
//  ScoringCommand.cpp
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#include "ScoringCommand.h"

DotballCommand::DotballCommand(Scoreboard* b) {
    _board = b;
}

void DotballCommand::execute() {
    bool out = _board->isPlayerRunOut();
    _board->dotWithWicket(out);
    if (out) {
        _board->playerRunOut(false);
    }
}

SinglesCommand::SinglesCommand(Scoreboard* b) {
    _board = b;
}

void SinglesCommand::execute() {
    bool out = _board->isPlayerRunOut();
    _board->singleWithWicket(out);
    if (out) {
        _board->playerRunOut(false);
    }
}

DoublesCommand::DoublesCommand(Scoreboard* b) {
    _board = b;
}

void DoublesCommand::execute() {
    bool out = _board->isPlayerRunOut();
    _board->doublesWithWicket(out);
    if (out) {
        _board->playerRunOut(false);
    }
}

TriplesCommand::TriplesCommand(Scoreboard* b) {
    _board = b;
}

void TriplesCommand::execute() {
    bool out = _board->isPlayerRunOut();
    _board->triplesWithWicket(out);
    if (out) {
        _board->playerRunOut(false);
    }
}

FoursCommand::FoursCommand(Scoreboard* b) {
    _board = b;
}

void FoursCommand::execute() {
    bool out = _board->isPlayerRunOut();
    _board->fourRunsWithWicket(out);
    if (out) {
        _board->playerRunOut(false);
    }
}

FivesCommand::FivesCommand(Scoreboard* b) {
    _board = b;
}

void FivesCommand::execute() {
    bool out = _board->isPlayerRunOut();
    _board->fiveRunsWithWicket(out);
    if (out) {
        _board->playerRunOut(false);
    }
}

SixesCommand::SixesCommand(Scoreboard* b) {
    _board = b;
}

void SixesCommand::execute() {
    _board->sixBoundary();
}

OverthrowCommand::OverthrowCommand(Scoreboard* b) {
    _board = b;
}

void OverthrowCommand::execute() {
    int throwRuns = 0;
    _board->overThrow(throwRuns);
}

NoBallCommand::NoBallCommand(Scoreboard* b) {
    _board = b;
}

void NoBallCommand::execute() {
    _board->noBall();
}

WideBallCommand::WideBallCommand(Scoreboard* b) {
    _board = b;
}

void WideBallCommand::execute() {
    _board->wideBall();
}

WicketFallCommand::WicketFallCommand(Scoreboard* b) {
    _board = b;
}

void WicketFallCommand::execute() {
    _board->playerOut();
}

RunOutCommand :: RunOutCommand (Scoreboard* b){
    _board = b;
}

void RunOutCommand::execute() {
    _board->playerRunOut(true);
}

UndoActionCommand::UndoActionCommand(Scoreboard* b) {
    _board = b;
}

void UndoActionCommand::execute() {
    _board->undoLastAction();
//    int runs;
//    const char* a = _board->getLastBall(&runs);
//    std::cout << "Last Total:	" << runs << std::endl;
//    std::cout << "Total:		" << _board->getScore() << std::endl;
//    std::cout << "Balls:		" << _board->getBalls() << std::endl;
//    std::cout << "Wickets Fall:	" << _board->getWickets() << std::endl;
}


