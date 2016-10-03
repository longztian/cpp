#include "deleteMiddleNode.hpp"

void deleteMiddleNode(p_node_t& node) {
  node->data = node->next->data;
  node->next.reset(node->next->next.release());
}
