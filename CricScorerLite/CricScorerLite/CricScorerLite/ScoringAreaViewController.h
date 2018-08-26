//
//  ScoringAreaViewController.h
//  CricScorerLite
//
//  Created by Khushneet Inder on 29/04/15.
//  Copyright (c) 2015 Khushneet Inder All rights reserved.
//

#import <UIKit/UIKit.h>
class Scoreboard;
class Scorer;

@interface ScoringAreaViewController : UIViewController <UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>{
    Scoreboard* mScoreboard;
    Scorer* mScorer;
}
@property (weak, nonatomic) IBOutlet UIButton *DotBallButton;
@property (weak, nonatomic) IBOutlet UIButton *SinglesButton;
@property (weak, nonatomic) IBOutlet UIButton *DoublesButton;
@property (weak, nonatomic) IBOutlet UIButton *FoursButton;
@property (weak, nonatomic) IBOutlet UIButton *SixerButton;
@property (weak, nonatomic) IBOutlet UIButton *TriplesButton;
@property (weak, nonatomic) IBOutlet UIButton *FivesButton;
@property (weak, nonatomic) IBOutlet UIButton *UndoButton;
@property (weak, nonatomic) IBOutlet UIButton *NoBallButton;
@property (weak, nonatomic) IBOutlet UIButton *WideBallButton;
@property (weak, nonatomic) IBOutlet UIButton *WicketButton;
@property (weak, nonatomic) IBOutlet UIButton *RunOutButton;
@property (weak, nonatomic) IBOutlet UIButton *OverthrowButton;

@property (weak, nonatomic) IBOutlet UILabel *LargeTotal;
@property (weak, nonatomic) IBOutlet UICollectionView *BallListView;

- (IBAction)performAction:(id)sender;
- (IBAction)handleOverthrow:(id)sender;
- (IBAction)handleExtras:(id)sender;
- (IBAction)handleRunOut:(id)sender;

@end
