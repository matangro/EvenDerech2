//
// Created by matan on 12.1.2020.
//

#ifndef EVENDERECH2_SEARCHABLEMETRIX_H
#define EVENDERECH2_SEARCHABLEMETRIX_H

#include "Searchable.h"
#include "StateOfMetrix.h"
#include "list"

class SearchableMetrix: public Searchable<Point> {
    vector<vector<State<Point>*>*> metrix;
    vector<vector<bool>*>* runTimeMetrix;
    Point start;
    Point goal;
    int n;
public:
    SearchableMetrix(vector<vector<State<Point>*>*> metrix, int n, Point &start, Point &goal);
    State<Point>* getInisialState() override ;
    bool isGoalState(State<Point>* current) override ;
    list<State<Point>*>* getAllPossibleState(State<Point>* current) override ;
    void MarkVisit(State<Point>* v) override ;
    void FinishVisit(State<Point>* v) override ;
    bool didWeVisit(State<Point>* v) override ;
};
#endif //EVENDERECH2_SEARCHABLEMETRIX_H
