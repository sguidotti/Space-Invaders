//
// Created by Scott Anthony Guidotti  on 10/26/17.
//

#ifndef GALAGA_SUBJECT_H
#define GALAGA_SUBJECT_H

#include <list>
#include "Observer.h"

class Subject {
public:
    virtual ~Subject();

    virtual void attach(Observer*);
    virtual void detach(Observer*);
    virtual void notify();

protected:
    Subject() = default;
private:
    std::list<Observer*> observers;
};

#endif //GALAGA_SUBJECT_H
