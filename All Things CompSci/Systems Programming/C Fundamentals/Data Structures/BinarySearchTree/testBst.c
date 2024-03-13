#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "bst.h"

// Implement and test a binary search tree
//   - http://en.wikipedia.org/wiki/Binary_search_tree
//   - don’t worry about making it balanced
//   - implement key insert( ) and lookup( ) functions
//   - implement it as a C module
//      - bst.c, bst.h
//   - implement test_bst.c
//      - contains main( ), tests out your BST

typedef struct bst_el_st {
    int key;
    char value[10];
} BSTElement;

// This helper function is the comparator we provide
// for comparing BSTElement structures.
static int BSTElComparator(void *el1, void *el2) {
    BSTElement *e1 = (BSTElement *) el1;
    BSTElement *e2 = (BSTElement *) el2;

    if (e1->key > e2->key)
        return 1;
    
    if (e1->key < e2->key)
        return -1;
    
    return 0;
}

int main(int argc, char **argv) {
    TreeNode *tree = NULL;
    BSTElement *el, lookupel;

    // Malloc and push in a few elements
    el = (BSTElement *) malloc(sizeof(BSTElement));
    assert(el != NULL);

    el->key = 100;
    snprintf(el->value, 10, "Val 100");
    
    assert(Insert(tree, el, &BSTElComparator, &tree) == 1);
    assert(Insert(tree, el, &BSTElComparator, &tree) == -1);

    el = (BSTElement *) malloc(sizeof(BSTElement));
    assert(el != NULL);
    el->key = 110;
    snprintf(el->value, 10, "Val 110");
    assert(Insert(tree, el, &BSTElComparator, &tree) == 1);
    assert(Insert(tree, el, &BSTElComparator, &tree) == -1);

    el = (BSTElement *) malloc(sizeof(BSTElement));
    assert(el != NULL);
    el->key = 105;
    snprintf(el->value, 10, "Val 105");
    assert(Insert(tree, el, &BSTElComparator, &tree) == 1);
    assert(Insert(tree, el, &BSTElComparator, &tree) == -1);

    el = (BSTElement *) malloc(sizeof(BSTElement));
    assert(el != NULL);
    el->key = 107;
    snprintf(el->value, 10, "Val 107");
    assert(Insert(tree, el, &BSTElComparator, &tree) == 1);
    assert(Insert(tree, el, &BSTElComparator, &tree) == -1);

    // Do some lookups
    lookupel.key = 105;
    assert(Lookup(tree, (void *) &lookupel, &BSTElComparator,
                (void **) &el) == 1);
    assert(strcmp(el->value, "Val 105") == 0);

    lookupel.key = 107;
    assert(Lookup(tree, &lookupel, &BSTElComparator,
                (void **) &el) == 1);
    assert(strcmp(el->value, "Val 107") == 0);

    lookupel.key = 100;
    assert(Lookup(tree, &lookupel, &BSTElComparator,
                (void **) &el) == 1);
    assert(strcmp(el->value, "Val 100") == 0);

    lookupel.key = 110;
    assert(Lookup(tree, &lookupel, &BSTElComparator,
                (void **) &el) == 1);
    assert(strcmp(el->value, "Val 110") == 0);

    // Try a lookup that should fail.
    lookupel.key = 10;
    assert(Lookup(tree, &lookupel, &BSTElComparator,
                (void **) &el) == 0);

    return EXIT_SUCCESS;
}