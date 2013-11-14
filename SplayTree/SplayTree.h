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

template <typename T>
struct left_zig_zig {

    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data>     //not null
struct left_zig_zig < node<Left, Right, Data> > {
private:
    typedef node<Left, Right, Data> Nd;
    typedef  typename right_rotate<Nd>::result res1;
    typedef typename right_rotate<res1>::result res2;

public:
    typedef res2 result;

};

// /   /   /   /   /   /   /   /


template <typename T>
struct right_zig_zig {

    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data>     //not null
struct right_zig_zig < node<Left, Right, Data> > {
private:
    typedef node<Left, Right, Data> Nd;
    typedef  typename left_rotate<Nd>::result res1;
    typedef typename left_rotate<res1>::result res2;

public:
    typedef res2 result;

};

// /   /   /   /   /   /   /   /
template <typename T>
struct left_zig_zag {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data>     //not null
struct left_zig_zag < node<Left, Right, Data> > {
private:
    typedef  node<typename left_rotate<Left>::result, Right, Data> res1;
    typedef typename right_rotate<res1>::result res2;

public:
    typedef res2 result;

};

// /   /   /   /   /   /   /   /

template <typename T>
struct right_zig_zag {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data>     //not null
struct right_zig_zag < node<Left, Right, Data> > {
private:
    typedef  node<Left, typename right_rotate<Right>::result, Data> res1;
    typedef typename left_rotate<res1>::result res2;

    public:
    typedef res2 result;

};

 // /   /   /   /   /   /   /   /
template <typename T, typename B>
struct left_not_root_splay {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct left_not_root_splay< node<Left, Right, Data>, Constant<CType, Value>  > {
private:
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;

    typedef typename Left::left LLeft;
    typedef typename Left::right LRight;



public:
    typedef typename IF< node_data_is_same<LLeft, Cnst>::value,
    typename left_zig_zig<Nd>::result,
    typename IF<node_data_is_same<LRight, Cnst>::value,
    typename left_zig_zag<Nd>::result,
    Nd>::result >::result result;


};

//  /   /   /   /   /   /   /
template <typename T, typename B>
struct right_not_root_splay {
    typedef typename Error<T>::result result;
};

template <typename Left, typename Right, typename Data, typename CType, CType Value>     //right not null
struct right_not_root_splay < node<Left, Right, Data>, Constant<CType, Value> > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;

    typedef typename Right::left RLeft;
    typedef typename Right::right RRight;



public:
    typedef typename IF<node_data_is_same<RLeft, Cnst>::value,
    typename right_zig_zag<Nd>::result,
    typename IF<node_data_is_same<RRight, Cnst>::value,
    typename right_zig_zig<Nd>::result,
    Nd>::result >::result result;



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

    typedef typename IF<node_data_is_same<Left, Cnst>::value,
    typename right_rotate<Nd>::result,
    typename IF<node_data_is_same<Right, Cnst>::value,
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

    typedef node<typename not_root_splay<Left, Cnst>::result, Right, Data> LeftCase;
    typedef node<Left, typename not_root_splay<Right, Cnst>::result, Data> RightCase;



public:

    typedef typename IF<NOT_NIL<Left>::value && is_less<Cnst, Data>::value,
    typename left_not_root_splay<LeftCase, Cnst>::result,        // then
    typename IF<NOT_NIL<Right>::value && is_more<Cnst, Data>::value,    //else
    typename right_not_root_splay<RightCase, Cnst>::result,
    Nd>::result >::result result;


};


//   /   /   /   /   /   /   /



template <typename T, typename B>
struct splay {
    typedef typename Invalid_argument<T>::result result;
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


//template <typename T, typename B>
//struct split {
//    typedef typename Error<T>::result result1;
//    typedef typename Error<T>::result result2;
//};
//
//template <typename Left, typename Right, typename Data, typename CType, CType Value>
//struct splay< node<Left, Right, Data>, Constant<CType, Value>  > {
//private:
//    typedef Constant<CType, Value> Cnst;
//    typedef node<Left, Right, Data> Nd;
//
//    typedef typename splay<Nd, Cnst>::result res1;
////    typedef
//public:
//    typedef typename IF_same<typename res1::data, Cnst, res1, typename zig<res1, Cnst>::result>::result result;
//};




#endif //__SplayTree_H_
