//
// Created by matan on 12.1.2020.
//

#ifndef EVENDERECH2_STATE_H
#define EVENDERECH2_STATE_H
#include <utility>
#include <list>
namespace EVEBDERECH2 {
    //#include <utility>
    template <typename T>
    class State {
    protected:
    std::list<State<T>*>* father;
    public:
         State(){
         this->father = new std::list<State<T>*>();
        }
        virtual T getIndex()=0;
        virtual std::list<State<T>*>* getFather()=0;
        virtual int getCost() = 0;
        virtual void setCost(int i) =0;
    };



    class Point{
    int i;
    int j;
    /*
    int cost;
    bool weVisit;
     */
    public:
        Point(int i, int j){
          this->i = i;
          this->j = j;
          /*
          this->cost = k;
          this->weVisit = false;
           */
        }
        Point(Point& p){
            this->i = p.getIndexI();
            this->j = p.getIndexJ();
        }

        bool equal(Point p){
            return (this->i == p.getIndexI()) && (this->j == p.getIndexJ());
        }
        int getIndexI(){ return this->i;}
        int getIndexJ(){ return this->j;}
    };
}
#endif //EVENDERECH2_STATE_H
