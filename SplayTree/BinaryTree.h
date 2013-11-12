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




template <typename Left, typename Right, typename Data>
struct node {
    typedef Left left;
    typedef Right right;
    typedef Data data;
};


  ////////////////////////////////

template <typename Type>
struct internal_print_tree {
    static void print(){
        print_type<Type>::print();
        assert(false && "Incorrect node type");
    }
};

template <typename Left, typename Right, typename Data>
struct internal_print_tree < node<Left, Right, Data> > {

    static void print(){
        internal_print_tree<Left>::print();
        std::cout <<  " ";
        print_type<Data>::print();
        std::cout <<  " ";
        internal_print_tree<Right>::print();
        std::cout <<  " ";
    }
};

template <>
struct internal_print_tree<nil> {
    static void print() {
    }
};

//  /   /   /   /   /



template <typename Type>
struct print_tree {
    static void print(){
       print_type<Type>::print();
       assert(false && "Incorrect node type");
    }
};

template <typename Left, typename Right, typename Data>
struct print_tree < node<Left, Right, Data> > {

    static void print() {

        internal_print_tree< node<Left, Right, Data> > ::print();

    }
};



template <>
struct print_tree<nil> {
    static void print(){
        std::cout << "nil";
    }
};



//   /   /   /   /   /   /   /


template <typename Type, size_t depth>
struct debug_internal_print_tree {
    static void print(){
        print_type<Type>::print();
        assert(false && "Incorrect node type");
    }
};

template <typename Left, typename Right, typename Data, size_t depth>
struct debug_internal_print_tree < node<Left, Right, Data>,  depth> {

    static void print(){
        debug_internal_print_tree<Left, depth + 1>::print();
        std::cout << " " << depth << "_";

        print_type<Data>::print();
        std::cout <<  " ";
        debug_internal_print_tree<Right, depth + 1>::print();
        std::cout <<  " ";
    }
};

template <size_t depth>
struct debug_internal_print_tree<nil, depth> {
    static void print() {
        std::cout << depth << "_nil";
    }
};


template <typename Type>
struct debug_print_tree {
    static void print(){
        print_type<Type>::print();
        assert(false && "Incorrect node type");
    }
};

template <typename Left, typename Right, typename Data>
struct debug_print_tree < node<Left, Right, Data> > {

    static void print() {

        debug_internal_print_tree< node<Left, Right, Data>, (size_t)0> ::print();

    }
};

//  /   /   /   /   /



/// ////////    /////   /   /   /   /   /   /   /   /


template <typename T>
struct left_rotate {
    typedef typename Error<T>::result result;

};

template <typename Left, typename Right, typename Data>
struct left_rotate<node<Left, Right, Data>> {
    typedef node< node<Left, typename Right::left, Data>, typename Right::right, typename Right::data> result;
};


template <typename T>
struct right_rotate {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data>
struct right_rotate<node<Left, Right, Data>> {
    typedef node<typename Left::left, node<typename Left::right, Right, Data>, typename Left::data> result;
};

//  /   /   /   /   /   /   //  /   /









#endif //__BinaryTree_H_
