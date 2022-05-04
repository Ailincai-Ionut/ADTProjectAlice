#include "SortedSet.h"
#include "SortedSetIterator.h"

// Complexity O(1)
SortedSet::SortedSet(Relation r) {
  rel = r;
  head = new Node;
  head->next = nullptr;
  head->prev = nullptr;
  head->elem = NULL_TELEM;
  numberOfElements = 0;
}

// Best case is when element is smaller than the first element = thetha(1)
// Worst case is when is bigger than the last element = thetha(n)
// Complexity O(n)
bool SortedSet::add(TComp elem) {
  Node *curr = head->next;
  Node *prevNode = head;
  while (curr != nullptr && rel(curr->elem, elem)) {
    prevNode = curr;
    curr = curr->next;
  }

  if (curr == nullptr) {
    if (prevNode->elem == elem)
      return false;
    Node *newNode = new Node;

    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = nullptr;

    newNode->elem = elem;
    numberOfElements++;

    return true;
  } else {
    if (prevNode->elem == elem || curr->elem == elem)
      return false;
    Node *newNode = new Node;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = curr;
    curr->prev = newNode;

    newNode->elem = elem;
    numberOfElements++;

    return true;
  }
}

// Best case is when element is the first element = thetha(1)
// Worst case is when element is not in the set = thetha(n)
// Complexity O(n)
bool SortedSet::remove(TComp elem) {
  Node *curr = head->next;
  Node *prev = head;
  while (curr != nullptr && curr->elem != elem) {
    prev = curr;
    curr = curr->next;
  }
  if (curr == nullptr)
    if (prev->elem == elem) {
      prev->prev->next = nullptr;
      delete prev;
      numberOfElements--;
      return true;
    } else {
      return false;
    }
  else {
    prev->next = curr->next;
    // we need to check if there is another element next
    if (curr->next != nullptr)
      curr->next->prev = prev;
    delete curr;
    numberOfElements--;
    return true;
  }
}

// Best case is when element is the first element = thetha(1)
// Worst case is when element is not in the set = thetha(n)
// Complexity O(n)
bool SortedSet::search(TComp elem) const {
  Node *curr = head->next;
  while (curr != nullptr && curr->elem != elem) {
    curr = curr->next;
  }
  if (curr == nullptr)
    return false;
  else
    return true;
}

// Complexity O(1)
int SortedSet::size() const { return numberOfElements; }

// Complexity O(1)
bool SortedSet::isEmpty() const {
  if (head->next == nullptr)
    return true;
  else
    return false;
}

SortedSetIterator SortedSet::iterator() const {
  return SortedSetIterator(*this);
}

// Complexity O(n)
SortedSet::~SortedSet() {
  Node *curr = head->next;
  Node *prev = head;
  while (curr != nullptr) {
    delete curr->prev;
    prev = curr;
    curr = curr->next;
  }
  delete prev;
}
