#ifndef FOO_HPP
#define FOO_HPP

#include <iostream>

class Paper {
    public:
        Paper(char c);
        Paper(const Paper&);
        ~Paper();
        
        void fold();
        void glue();
        void setName(char c);
        
    private:
        char name;
        int n_fold;
};

#endif