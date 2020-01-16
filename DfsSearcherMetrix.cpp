//
// Created by matan on 12.1.2020.
//
//using namespace std;
#include "DfsSearcherMetrix.h"
#include "StateOfMetrix.h"
#include <stack>

using namespace EVEBDERECH2;

DfsSearcherMetrix::DfsSearcherMetrix() {
}

State<Point>* DfsSearcherMetrix::search(Searchable<Point>* problem) {
    State<Point>* start = problem->getInisialState();
    State<Point>* answer = Dfs(problem,start);
    return answer;
}

State<Point>* DfsSearcherMetrix::Dfs(Searchable<Point>* problem, State<Point>* current) {
    this->move++;
    if (problem->isGoalState(current)){
        return current;
    }
    problem->MarkVisit(current);
    list<State<Point>*>* list = problem->getAllPossibleState(current);
    ::list<State<Point>*>* listOfGoal = new ::list<State<Point>*>();
    State<Point>* lowestState=NULL;
    for(auto c: *list){
        if(!problem->didWeVisit(c)){
            State<Point>* a = Dfs(problem,c );
            if(a!= nullptr){
                problem->FinishVisit(current);
                return (a);
            }
//            listOfGoal->push_front(Dfs(problem,c));
        }
    }

    for(auto c: *listOfGoal){
        if(c == NULL){
            continue;
        }
        if(lowestState ==NULL){
            lowestState = c;
        }
        /*
        else if(c->getCost()<lowestState->getCost()){
            lowestState =c;
        }
         */
    }
    problem->FinishVisit(current);
    return lowestState;


}