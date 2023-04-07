
#ifndef BST_H
#define BST_H

#include "BST_Node.h"

#include <memory>
#include <iostream>
#include <string>

#include "Card.h"

template<typename T>
class BST {
public:

   BST();
   ~BST();

   void clear();

   // Contract: contains function should not chage the data given to it
               // the function should not change the BST
   bool contains(const T data) const;


   // Contract: add function should not chage the data given to it
   void add(const T data);

   // Contract: dfs function should not change the BST
   void dfs() const;

   // Contract: depth function should not change the BST
   unsigned int depth() const;

private:
   std::shared_ptr<BST_Node<T>> root;


   std::shared_ptr<BST_Node<T>> add(std::shared_ptr<BST_Node<T>> node, 
                                       const T data);
   bool contains(std::shared_ptr<BST_Node<T>> node, 
                                       const T data) const;
   void dfs(std::shared_ptr<BST_Node<T>> node) const;

   unsigned int depth(std::shared_ptr<BST_Node<T>> node) const;
};

template<typename T>
BST<T>::BST() {
   root = nullptr;
}

template<typename T>
BST<T>::~BST() {
   clear();
}

template<typename T>
unsigned int BST<T>::depth(std::shared_ptr<BST_Node<T>> node) const {
   if(node==nullptr) return 0;
   unsigned int left = depth(node->left);
   unsigned int right = depth(node->right);
   if(left>right){
      return left+1;
   }else{
      return right+1;
   }
}

template<typename T>
unsigned int BST<T>::depth() const {
   return depth(root);
}

template<typename T>
void BST<T>::clear() {
   root = nullptr;
}

template<typename T>
bool BST<T>::contains(std::shared_ptr<BST_Node<T>> node, const T data) const {
   bool retVal = false;

   if(node == nullptr){
      //base case 1
      retVal = false;
   }else if (node->data == data){
      //base case 2
      retVal = true;
   }else{
      if(data <  node->data){
         retVal = contains(node->left, data);
      }else{
         retVal = contains(node->right, data);
      }
   }

   return retVal;
}

template<typename T>
bool BST<T>::contains(const T data) const {
   return contains(root, data);
}

template<typename T>
std::shared_ptr<BST_Node<T>> BST<T>::add(std::shared_ptr<BST_Node<T>> node, const T data) {
   std::shared_ptr<BST_Node<T>> retNode = nullptr;

   if(node == nullptr){
      //base case
      retNode = std::make_shared<BST_Node<T>>(data);
   }else{
      //recursive step
      if(data <node->data){
         std::shared_ptr<BST_Node<T>> subtree = add(node->left, data);
         node->left = subtree;
         retNode = node;
      }
      else if (data == node->data) {
          retNode = node;
      }
      else{
         std::shared_ptr<BST_Node<T>> subtree = add(node->right, data);
         node->right = subtree;
         retNode = node;
      }
   }

   return retNode;
}

template<typename T>
void BST<T>::add(const T data) {
   root = add(root, data);
}

template<typename T>
void BST<T>::dfs(std::shared_ptr<BST_Node<T>> node) const{
   
   if(node !=nullptr){
      // go left
      dfs(node->left);

      //process node
      std::cout << " " << node->data << std::endl;
      // printData(node->data);

      //go right
      dfs(node->right);
   }

}

template<typename T>
void BST<T>::dfs() const{
   dfs(root);
}

#endif // BST_H
