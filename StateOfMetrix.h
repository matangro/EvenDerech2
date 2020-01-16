//
// Created by matan on 12.1.2020.
//

#ifndef EVENDERECH2_STATEOFMETRIX_H
#define EVENDERECH2_STATEOFMETRIX_H

#include "State.h"
#include <utility>
#include <vector>

using namespace std;
using namespace EVEBDERECH2;
//template <typedef char**>
class StateOfMetrix :public EVEBDERECH2::State<Point> {
    Point p;
    int costUntilHere;
public:

    Point getIndex() override {
        return p;
    }
    int getCost() override {
        return costUntilHere;
    }
    std::list<State<Point>*>* getFather()  override {
        return this->father;
    }
    void setCost(int i) override {
        this->costUntilHere = i;
    }

    StateOfMetrix(Point p, int cost) :p(p){
        costUntilHere = cost;

    }
    StateOfMetrix(Point p, int cost, State<Point>* s) :p(p){
        costUntilHere = cost;
        auto a = s->getFather();
        for(auto & it : *a){
            this->father->push_back(it);
        }
        this->father->push_front(s);
    }


};
#endif //EVENDERECH2_STATEOFMETRIX_H
