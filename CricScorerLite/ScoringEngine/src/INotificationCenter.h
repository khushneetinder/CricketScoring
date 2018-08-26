//
//  INotificationCenter.h
//  ScoringEngine
//
//  Created by Khushneet Inder Singh on 26/01/17.
//  Copyright © 2017 Khushneet Inder Singh. All rights reserved.
//

#ifndef INotificationCenter_h
#define INotificationCenter_h

class Scoreboard;

class NotifcationObserver {
public:
    virtual void update(Scoreboard* sb) = 0;
};

class INotificationCenter {
public:
    void virtual registerObserver(NotifcationObserver* o) = 0;
    void virtual removeObserver(NotifcationObserver* o) = 0;
    void virtual notifyAll() = 0;
};

#endif /* INotificationCenter_h */
