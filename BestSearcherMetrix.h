//
// Created by matan on 13.1.2020.
//

#ifndef EVENDERECH2_BESTSEARCHERMETRIX_H
#define EVENDERECH2_BESTSEARCHERMETRIX_H


#include <queue>
#include "Searchable.h"
#include "Searcher.h"
class BestSearcherMetrix: public Searcher<Point>{

public:
    BestSearcherMetrix() = default;
    State<Point>* search(Searchable <Point>* problem) override ;
   // State<Point>* Dfs(Searchable<Point>* problem,State<Point>* current);
};
#endif //EVENDERECH2_BESTSEARCHERMETRIX_H
