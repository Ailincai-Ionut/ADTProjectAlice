#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet &m) : multime(m) {
  curr = multime.head->next;
}

void SortedSetIterator::first() { curr = multime.head->next; }

void SortedSetIterator::next() {

  if (curr == nullptr) {
    throw exception();
  }
  if (curr != nullptr)
    curr = curr->next;
}

TElem SortedSetIterator::getCurrent() {
  if (curr != nullptr)
    return curr->elem;
  else
    throw exception();
}

bool SortedSetIterator::valid() const {
  if (curr != nullptr)
    return true;
  else
    return false;
}
