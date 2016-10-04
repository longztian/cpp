#include "catch.hpp"
#include "detectLoop.hpp"

TEST_CASE("no loop", "[detectLoop]") {
  REQUIRE(detectLoop(nullptr) == nullptr);
  REQUIRE(detectLoop(LL::create({1,2,3})) == nullptr);
}

TEST_CASE("loop", "[detectLoop]") {
  auto head = LL::create({1});
  head->next = head;
  REQUIRE(detectLoop(head) == head);

  head = LL::create({1,2});
  head->next->next = head;
  REQUIRE(detectLoop(head) == head);
  head->next->next = head->next;
  REQUIRE(detectLoop(head) == head->next);

  head = LL::create({1,2,3,4,5,6});
  head->next->next->next->next->next->next = head->next->next;
  REQUIRE(detectLoop(head) == head->next->next);
}
