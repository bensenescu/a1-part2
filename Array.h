
#ifndef SOFTWARE_DEV_A1_ARRAY_H
#define SOFTWARE_DEV_A1_ARRAY_H

#include "object.h"
class Array : Object
{
public:
    Object **arr;
    int cap_;
    int len_;

    Array()
    {
        arr = new Object *[1];
        cap_ = 1;
        len_ = 0;
    }

    /** Destructor */
    virtual ~Array()
    {
        delete[] arr;
    }

    /**
     * Allocates memory onto the Heap depending on the size of cap
     */
    void allocate_()
    {
    }

    void deallocate_()
    {
    }

    /**
     * Gets the element at given idx
     * @param idx index
     *
     */
    Object *at(size_t idx)
    {
    }

    /**
     * Returns the index of the given Object.
     *
     */
    size_t index_of(Object *o)
    {
    }

    /**
     * Returns the last element in the Array
     */
    Object *back()
    {
    }

    /**
     * Gets the first element of the Array
     */
    Object *begin()
    {
    }

    /**
      * Returns the size of this Array
      *
      */
    size_t size()
    {

    }

    /**
      * Determines whether the list is empty
      *
      */
    bool empty()
    {
    }

    /**
     * Appends Object e to the end of this Array
     *
     */
    void add(Object *e)
    {

    }

    /**
     * Inserts given Object e at index i in the Array
     *
     */
    void add(size_t i, Object *e)
    {

    }

    /**
     * Returns and removes the item and index i of this Array
     *
     */
    Object *remove(size_t i)
    {
 
    }

    /**
     * Removes all of elements from this list
     */
    void clear()
    {
    }
};

#endif //SOFTWARE_DEV_A1_ARRAY_H
