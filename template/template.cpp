#include <bits/stdc++.h>
using namespace std;

template <typename TType>
void print_vector(const std::vector<TType>& vec)
{
    typename  std::vector<TType>::const_iterator it;
    std::cout << "(";
    for(it = vec.begin(); it != vec.end(); it++)
    {
        if(it!= vec.begin()) std::cout << ",";
        std::cout << (*it);
    }
    std::cout << ")";
}

template <typename T2>
void print_vector(const std::vector< std::vector<T2> >& vec)
{
    for( auto it= vec.begin(); it!= vec.end(); it++)
    {
        print_vector(*it);
    }
}

#define ll long long

int main(){


    return 0;

}
