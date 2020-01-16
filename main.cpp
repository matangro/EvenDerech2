
#include <iostream>
#include <vector>
#include "Searchable.h"
#include "DfsSearcherMetrix.h"
#include "StateOfMetrix.h"
#include "State.h"
#include "Searcher.h"
#include "SearchableMetrix.h"
#include "BestSearcherMetrix.h"
#include "BfsSearcherMetrix.h"

int main() {
    int size = 5;
    vector<vector<State<Point>*>*> arr(size);
    for (int i =0;i<size;i++){
        arr.at(i) =new vector<State<Point>*>(size);
        for(int j=0; j<size;j++){
            Point c(i,j);
            arr.at(i)->at(j) = new StateOfMetrix(c, i*2+j*3);
        }
    }
    Searcher<Point>* a = new BestSearcherMetrix();
    Point start(0,0);
    Point end(size-1,size-1);

    auto* b = new SearchableMetrix(arr, size, start, end);
    State<Point>* c = a->search(b);
    printf("%d",c->getCost());
    printf("\n%d",a->getMove());
    return 0;
}