//
// Created by matan on 13.1.2020.
//


#include "BfsSearcherMetrix.h"
using namespace std;

BfsSearcherMetrix::BfsSearcherMetrix() = default;

State<Point>* BfsSearcherMetrix::search(Searchable<Point>* problem) {
    State<Point>* start = problem->getInisialState();
    this->nonVisit.push(start);
    State<Point>* answer = Bfs(problem,start);
    return answer;
}

State<Point>* BfsSearcherMetrix::Bfs(Searchable<Point>* problem, State<Point>* current) {
    if (problem->isGoalState(current)) {
        this->target.push_back(current);
    }
    problem->MarkVisit(current);
    while (!this->nonVisit.empty()){
        this->move++;
        State<Point>* temp = this->nonVisit.front();
        this->nonVisit.pop();
        problem->MarkVisit(temp);
        if(problem->isGoalState(temp)){
            return temp;
        }
        list<State<Point>*>* list = problem->getAllPossibleState(temp);
        for(auto c: *list){
            if(!problem->didWeVisit(c)){
               this->nonVisit.push(c);
            }
        }
    }
    /*
    State<Point>* lowestState=nullptr;
    for(auto c: this->target){
        if(c == nullptr){
            continue;
        }
        if(lowestState ==nullptr){
            lowestState = c;
        }
        else if(c->getCost()<lowestState->getCost()){
            lowestState =c;
        }
    }
    //problem->FinishVisit(current);
    return lowestState;
     */
    return NULL;
}