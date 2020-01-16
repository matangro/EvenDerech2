//
// Created by matan on 12.1.2020.
//

#ifndef EVENDERECH2_DFSSEARCHERMETRIX_H
#define EVENDERECH2_DFSSEARCHERMETRIX_H

#include "Searcher.h"

class DfsSearcherMetrix: public Searcher<Point>{


public:
    DfsSearcherMetrix();
    State<Point>* search(Searchable <Point>* problem) override ;
    State<Point>* Dfs(Searchable<Point>* problem,State<Point>* current);
};


#endif //EVENDERECH2_DFSSEARCHERMETRIX_H
