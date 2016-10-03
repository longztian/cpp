#ifndef INTERSECTION_HPP
#define INTERSECTION_HPP

struct Node {
  int data;
  Node* next;
};

Node* intersection(const Node* head1, const Node* head2);

#endif
