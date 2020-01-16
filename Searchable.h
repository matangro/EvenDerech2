//
// Created by matan on 12.1.2020.
//

#ifndef EVENDERECH2_SEARCHABLE_H
#define EVENDERECH2_SEARCHABLE_H

#include <list>
#include "State.h"
using namespace EVEBDERECH2;
template <typename T>
class Searchable {
public:
    virtual State<T>* getInisialState() =0;
    virtual bool isGoalState(State<T>* current) =0;
    virtual std::list<State<T>*>* getAllPossibleState(State<T>* current) =0;
    virtual void MarkVisit(State<T>* v)=0;
    virtual void FinishVisit(State<T>* v) =0;
    virtual bool didWeVisit(State<T>* v) =0;
};
#endif //EVENDERECH2_SEARCHABLE_H
