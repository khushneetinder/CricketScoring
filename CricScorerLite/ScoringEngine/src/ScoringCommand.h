//
//  ScoringCommand.h
//  CricScorerLite
//
//  Created by Khushneet Inder on 20/08/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#ifndef __CricScorerLite__ScoringCommand__
#define __CricScorerLite__ScoringCommand__

#include <stdio.h>
#include "Scoreboard.h"

class ScoringCommand
{
public:
    virtual void execute() = 0;
};


class DotballCommand : public ScoringCommand
{
public:
    DotballCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};

class SinglesCommand : public ScoringCommand
{
public:
    SinglesCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};

class DoublesCommand : public ScoringCommand
{
public:
    DoublesCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};


class TriplesCommand : public ScoringCommand
{
public:
    TriplesCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};


class FoursCommand : public ScoringCommand
{
public:
    FoursCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};


class FivesCommand : public ScoringCommand
{
public:
    FivesCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};

class SixesCommand : public ScoringCommand
{
public:
    SixesCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};


class OverthrowCommand : public ScoringCommand
{
public:
    OverthrowCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};

class NoBallCommand : public ScoringCommand
{
public:
    NoBallCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};

class WideBallCommand : public ScoringCommand
{
public:
    WideBallCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};

class WicketFallCommand : public ScoringCommand
{
public:
    WicketFallCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};

class UndoActionCommand : public ScoringCommand
{
public:
    UndoActionCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};

class RunOutCommand : public ScoringCommand {
public:
    RunOutCommand(Scoreboard* b);
    virtual void execute();
private:
    Scoreboard* _board;
};
#endif /* defined(__CricScorerLite__ScoringCommand__) */
