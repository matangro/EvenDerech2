//
// Created by matan on 12.1.2020.
//

#ifndef EVENDERECH2_SEARCHER_H
#define EVENDERECH2_SEARCHER_H

#include "State.h"
#include "Searchable.h"
using namespace EVEBDERECH2;
template <typename T>
class Searcher{
protected:
    int move =0;
public:
    virtual State<T>* search(Searchable <T>* problem) =0;
    int getMove(){
        return this->move;
    }
};
#endif //EVENDERECH2_SEARCHER_H
