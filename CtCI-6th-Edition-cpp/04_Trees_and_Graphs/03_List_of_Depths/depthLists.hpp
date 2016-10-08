#ifndef CTCI_6TH_EDITION_CPP_04_TREES_AND_GRAPHS_03_LIST_OF_DEPTHS_DEPTHLISTS_HPP_
#define CTCI_6TH_EDITION_CPP_04_TREES_AND_GRAPHS_03_LIST_OF_DEPTHS_DEPTHLISTS_HPP_

#include <vector>
#include <list>
#include "BinaryTreeUnique.hpp"

using list_vector_t = std::vector<std::list<int>>;
list_vector_t depthLists(const p_node_t& tree);

#endif  // CTCI_6TH_EDITION_CPP_04_TREES_AND_GRAPHS_03_LIST_OF_DEPTHS_DEPTHLISTS_HPP_
