//
// Created by  Vladimir Skipor on 10/5/13.
// Copyright (c) 2013 ___FULLUSERNAME___. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __BinaryTree_H_
#define __BinaryTree_H_

#include <iostream>
#include "TemplateConstructions.h"
#include <cassert>


struct nil {
};

template <typename Left, typename Right, typename Data>
struct node {
    typedef Left left;
    typedef Right right;
    typedef Data data;
};


  ////////////////////////////////

template <typename Type>
struct print_tree {
    static void print(){
       print_type<Type>::print();
       assert(false && "Incorrect node type");
    }
};

template <typename Left, typename Right, typename Data>
struct print_tree < node<Left, Right, Data> > {

    static void print(){
        print_tree<Left>::print();
        print_type<Data>::print();
        print_tree<Right>::print();
    }
};

template <>
struct print_tree<nil> {
    static void print(){
    }
};



/// ////////    /////   /   /   /   /   /   /   /   /


template <typename T>
struct left_rotate {
    typedef typename Error<T>::result result;

};

template <typename Left, typename Right, typename Data>
struct left_rotate<node<Left, Right, Data>> {
    typedef node< node<Left, typename Right::Left, Data>, typename Right::Right, typename Right::Data> result;
};


template <typename T>
struct right_rotate {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data>
struct right_rotate<node<Left, Right, Data>> {
    typedef node<typename Left::Left, node<typename Left::Right, Right, Data>, typename Left::Data> result;
};

//  /   /   /   /   /   /   //  /   /









#endif //__BinaryTree_H_
