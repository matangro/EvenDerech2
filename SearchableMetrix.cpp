//
// Created by matan on 12.1.2020.
//

#include <vector>
#include "StateOfMetrix.h"
#include "SearchableMetrix.h"
#include "State.h"
#include "list"

SearchableMetrix::SearchableMetrix(vector<vector<State<Point>*>*> metrix, int n, Point &start, Point &goal) : goal(goal) , start(start) {
    this->metrix = metrix;
    this->n = n;
    this->runTimeMetrix = new vector<vector<bool>*>(n);
    for (int i =0; i<n;i++){
        this->runTimeMetrix->at(i) =new vector<bool >(n);
        for(int j=0; j<n;j++){

            this->runTimeMetrix->at(i)->at(j) = false;
        }
    }

}

 State<Point>* SearchableMetrix::getInisialState(){
    State<Point>* state1 = (new StateOfMetrix(this->start, 0));

    return state1;
}

 bool SearchableMetrix::isGoalState(State<Point>* current){
    return current->getIndex().equal(this->goal);

}
 list<State<Point>*>* SearchableMetrix::getAllPossibleState(State<Point>* current){
    list<State<Point>*>* arr = new list<State<Point>*>();

    // check if we can move down
    if((current->getIndex().getIndexI()!=this->n-1)){
        if (!this->runTimeMetrix->at(current->getIndex().getIndexI()+1)->at(current->getIndex().getIndexJ())){
            Point a(current->getIndex().getIndexI() + 1, current->getIndex().getIndexJ());
            arr->push_front(new StateOfMetrix(a, current->getCost() + this->metrix.at(a.getIndexI())->at(a.getIndexJ())->getCost(),current));
        }

    }
    // check if we can move up
    if((current->getIndex().getIndexI()!=0)){
        if (!this->runTimeMetrix->at(current->getIndex().getIndexI()-1)->at(current->getIndex().getIndexJ())) {
            Point a(current->getIndex().getIndexI() - 1, current->getIndex().getIndexJ());
            arr->push_front(new StateOfMetrix(a, current->getCost() + this->metrix.at(a.getIndexI())->at(a.getIndexJ())->getCost(),current));
        }
    }
    // check if we can move right
    if((current->getIndex().getIndexJ()!=this->n-1)){
        if (!this->runTimeMetrix->at(current->getIndex().getIndexI())->at(current->getIndex().getIndexJ()+1)) {
            Point a(current->getIndex().getIndexI(), current->getIndex().getIndexJ() + 1);
            arr->push_front(
                    new StateOfMetrix(a, current->getCost() + this->metrix.at(a.getIndexI())->at(a.getIndexJ())->getCost(),current));
        }
    }
    // check if we can move left
    if((current->getIndex().getIndexJ()!=0)){
        if (!this->runTimeMetrix->at(current->getIndex().getIndexI())->at(current->getIndex().getIndexJ()-1)) {
            Point a(current->getIndex().getIndexI(), current->getIndex().getIndexJ() - 1);
            arr->push_front(
                    new StateOfMetrix(a, current->getCost() + this->metrix.at(a.getIndexI())->at(a.getIndexJ())->getCost(),current));
        }
    }
    return arr;
}

void SearchableMetrix::MarkVisit(State<Point>* v){
    int i = v->getIndex().getIndexI();
    int j = v->getIndex().getIndexJ();
    this->runTimeMetrix->at(i)->at(j)= true;
}
void SearchableMetrix::FinishVisit(State<Point>* v){
    int i = v->getIndex().getIndexI();
    int j = v->getIndex().getIndexJ();
    this->runTimeMetrix->at(i)->at(j) = false;
}
bool SearchableMetrix::didWeVisit(State<Point>* v){
    int i = v->getIndex().getIndexI();
    int j = v->getIndex().getIndexJ();
    return this->runTimeMetrix->at(i)->at(j);
}








/*
 if((current.getIndex().getIndexI()!=this->n)&&(this->metrix[current.getIndex().getIndexI()+1][current.getIndex().getIndexJ()]!=-1)){
        Point a(current.getIndex().getIndexI()+1,current.getIndex().getIndexJ());
        arr->push_front(new StateOfMetrix(a, current.getCost()+ this->metrix[a.getIndexI()][a.getIndexJ()]));
    }
    // check if we can move up
    if((current.getIndex().getIndexI()!=0)&&(this->metrix[current.getIndex().getIndexI()-1][current.getIndex().getIndexJ()]!=-1)){
        Point a(current.getIndex().getIndexI()-1,current.getIndex().getIndexJ());
        arr->push_front(new StateOfMetrix(a, current.getCost()+ this->metrix[a.getIndexI()][a.getIndexJ()]));
    }
    // check if we can move right
    if((current.getIndex().getIndexJ()!=this->n)&&(this->metrix[current.getIndex().getIndexI()][current.getIndex().getIndexJ()+1]!=-1)){
        Point a(current.getIndex().getIndexI(),current.getIndex().getIndexJ()+1);
        arr->push_front(new StateOfMetrix(a, current.getCost()+ this->metrix[a.getIndexI()][a.getIndexJ()]));
    }
    // check if we can move left
    if((current.getIndex().getIndexI()!=0)&&(this->metrix[current.getIndex().getIndexI()][current.getIndex().getIndexJ()-1]!=-1)){
        Point a(current.getIndex().getIndexI(),current.getIndex().getIndexJ()-1);
        arr->push_front(new StateOfMetrix(a, current.getCost()+ this->metrix[a.getIndexI()][a.getIndexJ()]));
    }
 */