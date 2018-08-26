//
//  ScoringAreaViewController.m
//  CricScorerLite
//
//  Created by Khushneet Inder on 29/04/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#import "ScoringAreaViewController.h"
#include "ScoringEngine/Scoreboard.h"
#include "ScoringEngine/ScoringCommand.h"
#include "ScoringEngine/Scorer.h"

//Temp
#include <iostream>
using namespace std;

@implementation ScoringAreaViewController {
//TODO: ballList
    NSMutableArray* ballList;
}
static bool isExtrasButtonEnabled = YES;
static bool isOverthrowButtonEnabled = YES;
static bool isRunOutButtonEnabled = YES;

-(void)awakeFromNib {
    [super awakeFromNib];
    mScoreboard = mScoreboard->getSharedInstance();
    mScorer = new Scorer();
    ballList = [NSMutableArray new];
}

- (IBAction)performAction:(id)sender {
    
    ScoringCommand* cmd = NULL;
    cmd = [self getCommandFromSender:sender];
    if (cmd) {
        mScorer->doScoring(cmd);
    }
    [self resetButtons];
    [self.LargeTotal setText:[NSString stringWithFormat:@"%d", mScoreboard->getScore()]];// Later clean up

    BOOL needsUndo = (!mScoreboard->isLastBallValid() ||0 != mScoreboard->getBalls());
    [self.UndoButton setEnabled:needsUndo];

}
- (IBAction)handleRunOut:(id)sender {
    isRunOutButtonEnabled = !isRunOutButtonEnabled;
    ScoringCommand* cmd = NULL;
    cmd = [self getCommandFromSender:sender];
    if (cmd) {
        mScorer->doScoring(cmd);
    }
    [self.RunOutButton setEnabled:isRunOutButtonEnabled];
    [self.NoBallButton setEnabled:isRunOutButtonEnabled];
    [self.WideBallButton setEnabled:isRunOutButtonEnabled];
    [self.WicketButton setEnabled:isRunOutButtonEnabled];
}

- (IBAction)handleOverthrow:(id)sender {
    isOverthrowButtonEnabled = !isOverthrowButtonEnabled;
    [self.OverthrowButton setEnabled:isOverthrowButtonEnabled];
    // Create buttons
}

- (IBAction)handleExtras:(id)sender {
    isExtrasButtonEnabled = !isExtrasButtonEnabled;
    ScoringCommand* cmd = NULL;
    cmd = [self getCommandFromSender:sender];
    if (cmd) {
        mScorer->doScoring(cmd);
    }
    [self.NoBallButton setEnabled:isExtrasButtonEnabled];
    [self.WideBallButton setEnabled:isExtrasButtonEnabled];
    [self.WicketButton setEnabled:isExtrasButtonEnabled];
}

- (void)resetButtons {
    isExtrasButtonEnabled = YES;
    isOverthrowButtonEnabled = YES;
    isRunOutButtonEnabled = YES;
    [self.NoBallButton setEnabled:isExtrasButtonEnabled];
    [self.WideBallButton setEnabled:isExtrasButtonEnabled];
    [self.OverthrowButton setEnabled:isOverthrowButtonEnabled];
    [self.WicketButton setEnabled:isExtrasButtonEnabled];
    [self.RunOutButton setEnabled:isExtrasButtonEnabled];
}

- (ScoringCommand*) getCommandFromSender:(id)sender {
    ScoringCommand* cmd = NULL;

    if (sender == self.DotBallButton) {
        cmd = new DotballCommand(mScoreboard);
    }
    if (sender == self.SinglesButton) {
        cmd = new SinglesCommand(mScoreboard);
    }
    if (sender == self.DoublesButton) {
        cmd = new DoublesCommand(mScoreboard);
    }
    if (sender == self.TriplesButton) {
        cmd = new TriplesCommand(mScoreboard);
    }
    if (sender == self.FoursButton) {
        cmd = new FoursCommand(mScoreboard);
    }
    if (sender == self.FivesButton) {
        cmd = new FivesCommand(mScoreboard);
    }
    if (sender == self.SixerButton) {
        cmd = new SixesCommand(mScoreboard);
    }
    if (sender == self.WicketButton) {
        cmd = new WicketFallCommand(mScoreboard);
    }
    if (sender == self.NoBallButton) {
        cmd = new NoBallCommand(mScoreboard);
    }
    if (sender == self.WideBallButton) {
        cmd = new WideBallCommand(mScoreboard);
    }
    if (sender == self.UndoButton) {
        cmd = new UndoActionCommand(mScoreboard);
    }
    if (sender == self.RunOutButton) {
        cmd = new RunOutCommand(mScoreboard);
    }
    return cmd;
}

@end
