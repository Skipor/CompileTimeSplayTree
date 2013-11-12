//
// Created by  Vladimir Skipor on 10/14/13.
// Copyright (c) 2013 ___FULLUSERNAME___. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __SplayTree_H_
#define __SplayTree_H_

#include "BinaryTree.h"
#include "TemplateConstructions.h"

/*
invariant:
   x
  / \
 <x  >=x
 */



template <typename T, typename B>
struct left_not_root_splay {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct left_not_root_splay< node<Left, Right, Data>, Constant<CType, Value>  > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;


public:

    typedef Nd result;


};

//  /   /   /   /   /   /   /
template <typename T, typename B>
struct right_not_root_splay {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct right_not_root_splay < node<Left, Right, Data>, Constant<CType, Value>  > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;


public:

    typedef Nd result;



};

//  /   /   /   /   /   /   /
template <typename T, typename B>
struct zig {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct zig< node<Left, Right, Data>, Constant<CType, Value>  > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;


public:

    typedef typename IF<NOT_NIL<Left>::value && is_same<typename Left::data, Cnst>::value,
    typename right_rotate<Nd>::result,
    typename IF<NOT_NIL<Right>::value && is_same<typename Right::data, Cnst>::value,
    typename left_rotate<Nd>::result,
    Nd>::result >::result result;


};

//  /   /   /   /   /   /   /


template <typename T, typename B>
struct not_root_splay {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct not_root_splay< node<Left, Right, Data>, Constant<CType, Value>  > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;

public:

    typedef typename IF<NOT_NIL<Left>::value && is_less<Data, Cnst>::value,
    typename left_not_root_splay<Nd, Cnst>::result,        // then
    typename IF<NOT_NIL<Right>::value && is_more<Data, Cnst>::value,    //else
    typename right_not_root_splay<Nd, Cnst>::result,
    Nd>::result >::result result;


};


//   /   /   /   /   /   /   /



template <typename T, typename B>
struct splay {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct splay< node<Left, Right, Data>, Constant<CType, Value>  > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;

    typedef typename not_root_splay<Nd, Cnst>::result res1;
public:
    typedef typename IF_same<typename res1::data, Cnst, res1, typename zig<res1, Cnst>::result>::result result;


};


#endif //__SplayTree_H_
