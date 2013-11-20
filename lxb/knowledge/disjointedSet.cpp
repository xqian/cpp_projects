/*
 * Copyright 2011-2012 Lars Buitinck
 * https://gist.github.com/larsmans/1076403
 */
 
#ifndef DISJSETS_HPP_
#define DISJSETS_HPP_
 
// Disjoint set forest
class DisjSets
{
    struct Set
    {
        size_t parent;  // index of parent in vector
        unsigned rank;
 
        // Construct the i'th of an array of disjoint sets
        Set(size_t i) : parent(i), rank(0) { }
    };
 
    std::vector<Set> forest;
 
  public:
    DisjSets(size_t n)
    {
        forest.reserve(n);
        for (size_t i=0; i<n; i++)
            forest.push_back(Set(i));
    }
 
    // Find set that element i belongs to, represented as an index
    size_t find(size_t i)
    {
        if (forest[i].parent == i)
            return i;
        else {
            forest[i].parent = find(forest[i].parent);
            return forest[i].parent;
        }
    }
 
    // Union (but union is a C++ keyword)
    void merge(size_t i, size_t j)
    {
        size_t root_i = find(i);
        size_t root_j = find(j);
        if (root_i != root_j) {
            if (forest[root_i].rank < forest[root_j].rank)
                forest[root_i].parent = root_j;
            else if (forest[root_i].rank > forest[root_j].rank)
                forest[root_j].parent = root_i;
            else {
                forest[root_i].parent = root_j;
                forest[root_j].rank += 1;
            }
        }
    }
};
 
#endif
