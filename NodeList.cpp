#include "NodeList.h"

NodeList::NodeList() {                       // constructor
    n = 0;                                   // initially empty 
    header = new Node;                       // create sentinels
    trailer = new Node;                 
    header->next = trailer;                  // hava them pointing to each other
    trailer->prev = header;   
}

int NodeList::size() const                   // list size
    { return n; }

bool NodeList::empty() const                 // is list empty?
    { return (n == 0); }

NodeList::Iterator NodeList::begin() const  // begin position of the first item
    { return Iterator(header->next); }

NodeList::Iterator NodeList::end() const    // end position is just beyond last
    { return Iterator(trailer); }

void NodeList::insert(const NodeList::Iterator& p, const Elem& e) { // insert e before p
    Node* w = p.v;                          // p's node
    Node* u = w->prev;                      // p's predecessor
    Node* v = new Node;                     // new node to insert
    v->elem = e;
    v->next = w; w->prev = v;               // link in v before w
    v->prev = u; u->next = v;               // link in v after u
    n++;                                    // one more element
}

void NodeList::insertFront(const Elem& e)   // insert at front
    { insert(begin(), e); }

void NodeList::insertBack(const Elem& e)    // insert at rear
    { insert(end(), e); }

void NodeList::erase(const Iterator& p) {   // remove p
    Node* v = p.v;                          // node to remove
    Node* w = v->next;                      // sucessor
    Node* u = v->prev;                      // predecessor
    u->next = w; w->prev = u;               // unlink p
    delete v;                               // delete this node
    n--;                                    // one fewer element
}

void NodeList::eraseFront()                 // remove first
    { erase(begin()); }

void NodeList::eraseBack()                  // remove last
    { erase(--end()); }