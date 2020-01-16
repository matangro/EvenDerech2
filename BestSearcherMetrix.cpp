//
// Created by matan on 13.1.2020.
//
#include "Searcher.h"
#include "Searchable.h"
#include "BestSearcherMetrix.h"


State<Point>* BestSearcherMetrix::search(Searchable <Point>* problem) {
    auto cmp = [](State<Point>* left, State<Point>* right) { return left->getCost()-right->getCost(); };
    std::priority_queue<State<Point>*,std::vector<State<Point>*>,decltype(cmp)> priorityQueue(cmp);
    State<Point>* temp = problem->getInisialState();
    problem->MarkVisit(temp);
    priorityQueue.push(temp);
    while (!priorityQueue.empty()){
        this->move++;
        temp = priorityQueue.top();
        priorityQueue.pop();
        if(problem->isGoalState(temp)){
            return temp;
        } else{
            auto list = problem->getAllPossibleState(temp);
            for(auto c: *list){
                if(!problem->didWeVisit(c)){
                    problem->MarkVisit(c);
                    priorityQueue.push(c);
                }
            }
        }
    }
    return nullptr;

}

