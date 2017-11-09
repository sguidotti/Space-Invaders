//
// Created by Scott Anthony Guidotti  on 10/26/17.
//

#ifndef GALAGA_OBSERVER_H
#define GALAGA_OBSERVER_H
class Subject;

class Observer {
public:

    virtual ~Observer() = default;
    virtual void update(Subject* theChangedSubject) = 0;
protected:
    Observer() = default;


};

#endif //GALAGA_OBSERVER_H
