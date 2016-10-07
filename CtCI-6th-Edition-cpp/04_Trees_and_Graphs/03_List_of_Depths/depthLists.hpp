#ifndef DEPTHLISTS_HPP
#define DEPTHLISTS_HPP

#include <vector>
#include <list>
#include "BinaryTree.hpp"

using list_vector_t = std::vector<std::list<int>>;
list_vector_t depthLists(const p_node_t& tree);

#endif
