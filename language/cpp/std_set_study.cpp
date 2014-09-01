#include <iostream>
#include <cstdlib>
#include <set>

bool fncomp(int lhs, int rhs)
{
    return lhs<rhs;
}

struct classcomp {
      bool operator() ( const int &lhs, const int& rhs) const
      {
          return lhs<rhs;
      }
};


struct rma_node {
      bool flg;
      bool used;

      bool operator< ( const rma_node &lhs) const
      {
          return lhs.flg < flg;
      }    
};

struct rma_node_comp{
      bool operator() ( const rma_node& lhs , const rma_node& rhs)
      {
          return lhs<rhs;
      }
};

int main()
{
    //int myints[]= {10,20,30,40,50};
    //int myints[]= {10,20,30};
    //std::set<int> second (myints,myints+3);

    rma_node my_node[15];
    std::set<rma_node,rma_node_comp> second (my_node,my_node+5);

    return 0 ; 
}
