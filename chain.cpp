#include "chain.h"
#include <cmath>
#include <iostream>


// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain() {
  /* your code here */
}

/**
 * Inserts a new node after the node pointed to by p in the
 * chain (so p->next is the new node) and returns a pointer to
 * the newly created node.
 * If p is NULL, inserts a new head node to the chain.
 * This function **SHOULD** create a new Node and increase length_.
 *
 * @param p = The new node should be pointed to by p->next.
 *            If p is NULL, the new node becomes the head of the chain.
 * @param ndata = The data to be inserted.
 */
Chain::Node * Chain::insertAfter(Node * p, const Block &ndata) {

  // allocate new node 
  Node *newNode = new Node(ndata);

  // The chain is empty
  if(head_ == NULL) {
    head_ = newNode;
    length_++;
    return newNode;
  }

  // If p is NULL, inserts a new head node to the chain.
  if (p == NULL) {
    newNode->next = head_;
    // set prev of head to newNode
    if(head_ != NULL) {
      head_->prev = newNode;
    }
    head_ = newNode;
    length_++;
    return newNode;

  } else {
    // set next of new node to next of prev node
    newNode->next = p->next;
    // set next of prev node to new node
    p->next = newNode;
    // now set prev of new node to  prev node
    newNode->prev = p;
    // set prev of new node's next node to newNode
    if(newNode->next != NULL) {
      newNode->next->prev = newNode;
    }
  }

  //increase length_
  length_++;
  return newNode;
}

/**
 * Swaps the position in the chain of the two nodes pointed to
 * by p and q.
 * If p or q is NULL or p==q, do nothing.
 * Change the chain's head pointer if necessary.
 */
void Chain::swap(Node *p, Node *q) {
  // If p or q is NULL or p==q, do nothing.
  if(p==q || p==NULL || q==NULL) {
    return;
  }
  // p and q are right next to each other (p on left, q on right)
  if (p->next == q) { 
    
      p->next = q->next;
      q->prev = p->prev;

      if (p->next != NULL) {
        p->next->prev = p;
      }

      if (q->prev != NULL) {
        q->prev->next = q;
      }

      q->next = p;
      p->prev = q;
  // p and q are right next to each other (q on left, p on right)
  } else if(q->next == p){
    
      q->next = p->next;
      p->prev = q->prev;

      if (q->next != NULL) {
        q->next->prev = q;
      }

      if (p->prev != NULL) {
        p->prev->next = p;
      }

      p->next = q;
      q->prev = p;

  } else {

      Node *prevTemp = q->prev;
      Node *nextTemp = q->next;

      q->prev = p->prev;
      q->next = p->next;

      p->prev = prevTemp;
      p->next = nextTemp;

      if (q->next != NULL) {
        q->next->prev = q;
      }

      if (q->prev != NULL) {
        q->prev->next = q;
      }

      if (p->next != NULL) {
        p->next->prev = p;
      }

      if (p->prev != NULL) {
        p->prev->next = p; 
      }
 
  }
}
/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear() {

  // while current node is not null, store next node in temp, free memory in current node,
  // and assign as next node.
  Node *p = head_;

  while(p != NULL) {
    Node *temp = p->next;
    delete p;
    p = temp;
  }
  // derefernce head
  head_ = NULL;
}

/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other) {
  /* your code here */
}

/* Modifies the current chain: 
 * 1) Find the node with the first (leftmost) block in the unscrambled
 *    image and move it to the head of the chain.
 *	This block is the one whose closest match (to the left) is the
 *	largest.  That is, the distance (using distanceTo) to this block 
 *	is big for all other blocks.
 *	For each block B, find the distanceTo B from every other block
 *	and take the minimum of these distances as B's "value".
 *	Choose the block B with the maximum value over all blocks and
 *	swap its node to the head of the chain.
 *
 * 2) Starting with the (just found) first block B, find the node with
 *    the block that is the closest match to follow B (to the right)
 *    among the remaining blocks, move (swap) it to follow B's node,
 *    then repeat to unscramble the chain/image.
 */
void Chain::unscramble() {
  /* your code here */
}
