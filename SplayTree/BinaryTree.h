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

/*
invariant:
   x
  / \
 <x  >=x
 */




template <typename Left, typename Right, typename Data>
struct node {
    typedef Left left;
    typedef Right right;
    typedef Data data;
};

template <typename Data>
struct new_tree {
    typedef node<nil, nil, Data> result;
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
        print_type<Data>::print();
        std::cout <<  " ";
        internal_print_tree<Right>::print();
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

    static void print() {
        std::cout << "(";
        debug_internal_print_tree<Left, depth + 1>::print();
        std::cout << " {" << depth << "_";

        print_type<Data>::print();
        std::cout << "} ";
        debug_internal_print_tree<Right, depth + 1>::print();
        std::cout << ") ";
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
template <>
struct debug_print_tree<nil> {
    static void print(){
        print_type<nil>::print();
    }
};

template <typename Left, typename Right, typename Data>
struct debug_print_tree < node<Left, Right, Data> > {

    static void print() {

        debug_internal_print_tree< node<Left, Right, Data>, (size_t)0> ::print();

    }
};

//  /   /   /   /   /

template <typename Type>
struct structured_print_tree {
    static void print(){
        print_type<Type>::print();
        assert(false && "Incorrect node type");
    }
};
template <>
struct structured_print_tree<nil> {
    static void print(){
        std::cout << "";
    }
};

template <typename Left, typename Right, typename Data>
struct structured_print_tree < node<Left, Right, Data> > {

    static void print() {
        std::cout << "(";
        print_type<Data>::print();
        structured_print_tree<Left>::print();
        std::cout << " | ";

        structured_print_tree<Right>::print();
        std::cout << ")";


    }
};

/// ////////    /////   /   /   /   /   /   /   /   /


template <typename T>
struct left_rotate {
    typedef typename Error<T>::result result;

};

template <typename Right, typename Data>
struct left_rotate<node<nil, Right, Data>> {
    typedef nil result;
};

template <typename Left, typename Right, typename Data>
struct left_rotate<node<Left, Right, Data>> {
    typedef node< node<Left, typename Right::left, Data>, typename Right::right, typename Right::data> result;
};


template <typename T>
struct right_rotate {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Data>
struct right_rotate<node<Left, nil, Data>> {
    typedef nil result;
};

template <typename Left, typename Right, typename Data>
struct right_rotate<node<Left, Right, Data>> {
    typedef node<typename Left::left, node<typename Left::right, Right, Data>, typename Left::data> result;
};


//  /   /   /   /   /   /   //  /   /

template <typename A, typename B>
struct node_data_is_same  {
    static bool const value = false;
};

template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct node_data_is_same  < node<Left, Right, Data>, Constant<CType, Value>  > {

    static bool const value = is_same<Data, Constant<CType, Value>>::value ;
};
////////////


template <typename T>
struct get_min {
     typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data>
struct get_min < node<Left, Right, Data> > {
    typedef typename get_min<Left>::result result;
};
template <typename Right, typename Data>
struct get_min < node<nil, Right, Data> > {
    typedef Data result;
};
////////////


template <typename T>
struct get_max {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data>
struct get_max < node<Left, Right, Data> > {
    typedef typename get_max<Right>::result result;
};
template <typename Left, typename Data>
struct get_max < node<Left, nil, Data> > {
    typedef Data result;
};
////////////

template <typename T, typename B>
struct get_next {
    typedef typename Error<T>::result result;
};
template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct get_next  < node<Left, Right, Data>, Constant<CType, Value>  > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;
    typedef typename get_next<Left, Cnst>::result LeftCase;
    typedef typename get_next<Right,Cnst>::result RightCase;

   public:
    typedef typename IF<is_more<Data, Cnst>::value,
    typename IF<NOT_NIL<LeftCase>::value, LeftCase, Data>::result,
    RightCase>::result result;

};


////////////

template <typename T, typename B>
struct get_prev {
    typedef typename Error<T>::result result;
};
template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct get_prev  < node<Left, Right, Data>, Constant<CType, Value>  > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;
    typedef typename get_prev<Left, Cnst>::result LeftCase;
    typedef typename get_prev<Right,Cnst>::result RightCase;

public:
    typedef typename IF<is_less<Data, Cnst>::value,
    typename IF<NOT_NIL<RightCase>::value, RightCase, Data>::result,
    LeftCase>::result result;
};















#endif //__BinaryTree_H_
