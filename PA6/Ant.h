#include "Organism.h"
#ifndef ANT_H_
#define ANT_H_
class Ant : public Organism{
public:
    Ant();
    Ant(int _x, int _y);
    Ant(int _x, int _y, int _step);
    //Ant(const Ant& a);
    ~Ant();
    
    
    //overriding
    void breed(int row, int col, Organism** B[]);
    void print();
    

};
#endif