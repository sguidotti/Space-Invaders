//
// Created by Scott Anthony Guidotti  on 10/26/17.
//

#include "Subject.h"

void Subject::notify()
{
    std::list<Observer*>::iterator i;
    for(i = observers.begin(); i != observers.end(); ++i) {
        (*i)->update(this);
    }
}

void Subject::detach(Observer* o)
{
    observers.remove(o);
}

void Subject::attach(Observer* o)
{
    observers.push_back(o);
}

Subject::~Subject() = default;
