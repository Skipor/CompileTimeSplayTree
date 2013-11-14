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
    typedef typename Error<T>::result result;
};
template <typename Left, typename Right, typename Data>

struct splay< node<Left, Right, Data>, nil>  {
    typedef typename Error<nil>::result result;
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

//   /   /   /   /   /   /   /
//   /   /   /   /   /   /   /
//   /   /   /   /   /   /   /

template <typename T, typename B>
struct split {
    typedef typename Error<T>::result result1;
    typedef typename Error<T>::result result2;
};

template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct split< node<Left, Right, Data>, Constant<CType, Value>  > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;
    typedef typename get_prev<Nd, Cnst>::result prev;
    typedef typename IF<NOT_NIL<prev>::value, typename splay<Nd, prev>::result, nil>::result prev_splayed;
public:
    typedef typename IF<NOT_NIL<prev>::value, node<typename prev_splayed::left, nil, typename prev_splayed::data>, nil>::result result1;
    typedef typename IF<NOT_NIL<prev>::value, typename prev_splayed::right, Nd>::result result2;
};

//   /   /   /   /   /   /   /

template <typename T1, typename T2>
struct merge {
    typedef typename Error<T1>::result result1;
};

template <typename Left, typename Right, typename Data>
struct merge<nil, node<Left, Right, Data> > {
    typedef node<Left, Right, Data> result;
};
template <typename Left, typename Right, typename Data>
struct merge<node<Left, Right, Data>, nil > {
    typedef node<Left, Right, Data> result;
};

template <>
struct merge<nil,nil > {
    typedef nil result;
};


template <typename Left1, typename Right1, typename Data1, typename Left2, typename Right2, typename Data2>
struct merge< node<Left1, Right1, Data1>, node<Left2, Right2, Data2>  > {
private:
    typedef node<Left1, Right1, Data1> T1;

    typedef node<Left2, Right2, Data2> T2;
    typedef typename splay<T2, typename get_min<T2>::result>::result T2_transformed;  // left == nil
public:
    typedef node<T1, typename T2_transformed::right, typename T2_transformed::data> result;
};

//   /   /   /   /   /   /   /



template <typename T, typename B>
struct contains{
    static const bool value =  Error<T>::value;
    typedef typename Error<T>::result result;

};

template <typename B>
struct contains<nil,B>{
    static const bool value = false;
    typedef nil result;
};

template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct contains < node<Left, Right, Data>, Constant<CType, Value>  > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;

public:
    typedef typename splay<Nd, Cnst>::result result;
    static const bool value = is_same<typename result::data, Cnst>::value;
};

//      /   /   /   /   /   /   /

template <typename T, typename B>
struct insert {
    typedef typename Error<T>::result result;
};
template <typename Left, typename Right, typename Data>

struct  insert< node<Left, Right, Data>, nil>  {
    typedef  node<Left, Right, Data> result;
};

template <typename CType, CType Value>

struct  insert<nil, Constant<CType, Value>>  {
    typedef  node<nil, nil, Constant<CType, Value> > result;
};



template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct insert < node<Left, Right, Data>, Constant<CType, Value>  > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;

    typedef split<Nd, Cnst> splited;

public:
    typedef node<typename splited::result1, typename splited::result2, Cnst> result;
};




//   /   /   /   /   /   /   /

template <typename T, typename B>
struct erase_once {
    typedef typename Error<T>::result result;
};
template <typename Left, typename Right, typename Data>

struct  erase_once < node<Left, Right, Data>, nil>  {
    typedef  node<Left, Right, Data> result;
};

template <typename T>

struct  erase_once <nil, T>  {
    typedef  nil result;
};



template <typename Left, typename Right, typename Data, typename CType, CType Value>
struct erase_once  < node<Left, Right, Data>, Constant<CType, Value>  > {
private:
    typedef Constant<CType, Value> Cnst;
    typedef node<Left, Right, Data> Nd;

    typedef contains<Nd, Cnst> Contains;


public:
    typedef typename IF<Contains::value ,
    typename merge<typename Contains::result::left, typename Contains::result::right>::result,
    Nd>::result result;

};


//   /   /   /   /   /   /   /

template <typename Nd, typename Cnst>
struct erase {
private:

    typedef typename erase_once<Nd, Cnst>::result erased;

public:
    typedef typename IF<contains<erased, Cnst>::value, typename erase_once<erased, Cnst>::result, erased>::result result;
};

//   /   /   /   /   /   /   /









#endif //__SplayTree_H_
