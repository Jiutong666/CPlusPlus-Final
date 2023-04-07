
/*                                           */
/* DO NOT MOFIFY ANY CODE IN THIS FILE       */
/*                                           */

#ifndef BST_NODE_H
#define BST_NODE_H

#include <memory>
#include <iostream>

using std::string;
using std::cout;
using std::endl;


template<typename T>
class BST_Node {
public:

   BST_Node(T data);
   BST_Node(const BST_Node<T>& other);
   ~BST_Node();

   T   data;

   std::shared_ptr<BST_Node<T>> left;
   std::shared_ptr<BST_Node<T>> right;
};


template<typename T>
BST_Node<T>::BST_Node(T data) :
   data(data),
   left(nullptr),
   right(nullptr)
{
}

template<typename T>
BST_Node<T>::BST_Node(const BST_Node<T>& other) :
   data(other.data),
   left(other.left),
   right(other.right)
{
}

template<typename T>
BST_Node<T>::~BST_Node() {
   left = nullptr;
   right = nullptr;
}


#endif // BST_NODE_H
