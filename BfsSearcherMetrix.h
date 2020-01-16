//
// Created by matan on 13.1.2020.
//

#ifndef EVENDERECH2_BFSSEARCHERMETRIX_H
#define EVENDERECH2_BFSSEARCHERMETRIX_H

#include <vector>
#include <queue>
#include "Searcher.h"
#include "Searchable.h"
using namespace std;
class BfsSearcherMetrix: public Searcher<Point>{
    vector<State<Point>*> target;
    queue<State<Point>*> nonVisit;

public:
    BfsSearcherMetrix();
    State<Point>* search(Searchable <Point>* problem) override ;
    State<Point>* Bfs(Searchable<Point>* problem,State<Point>* current);
};
#endif //EVENDERECH2_BFSSEARCHERMETRIX_H
