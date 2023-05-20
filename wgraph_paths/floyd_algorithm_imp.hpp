/**
 * @file floyd_algorithm_imp.hpp
 *
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once

#include <utility>
#include <stack>
#include "floyd_algorithm.hpp"

#ifdef __VERBOSE__
#include <iostream>
#include <iomanip>
extern int Verbose_level;
#endif

template<class T>
void floyd_algorithm(const typename WGraph<T>::Ref g, FMatrix::Ref& D,
                     IMatrix::Ref& I)
{
    D = g->weight_matrix();
    I = IMatrix::create(g->size(), g->size(), -1);

    //TODO: Codify the Floyd algorithm.
    
    for(size_t k = 0; k < g->size(); k++){

        for(size_t i = 0; i < g->size(); i++){

            for(size_t j = 0; j < g->size(); j++){

                if((D->get(i,k)+D->get(k,j)) < D->get(i,j)){

                    D->set(i, j, (D->get(i,k) + D->get(k,j)));
                    I->set(i, j, k);

                }

            }

        }

    }
    
    //
}

std::list<size_t> floyd_path(size_t src, size_t dst, IMatrix::Ref I)
{
    //Prec: distance (u,v) < inf
    std::list<size_t> path;

    //TODO: Find the path.
    //Hint: Think first. Is it necessary to build a binary tree? or it
    //is enough to do an first-depth search using an iterative approach with
    //a stack of pairs (u,v).

    std::stack<std::pair<size_t,size_t>> s;
    std::pair<size_t,size_t> p;

    path.push_back(src);
    s.push(std::make_pair(src,dst));

    while(!s.empty()){
        p = s.top();
        s.pop();

        size_t aux = I->get(p.first, p.second);

        if(aux == (size_t)-1){
            path.push_back(p.second);
        }else{
            s.push(std::make_pair(aux, p.second));
            s.push(std::make_pair(p.first, aux));
        }
    }
    
    //
    return path;
}




