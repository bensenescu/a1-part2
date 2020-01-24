
#ifndef SOFTWARE_DEV_A1_ARRAY_H
#define SOFTWARE_DEV_A1_ARRAY_H

#include "object.h"
class Array : Object {
public:
    Object** arr;
    int cap_;
    int len_;

    Array() {
        arr = new Object*[1];
        cap_ = 1;
        len_ = 0;
    }

    /** Destructor */
    virtual ~Array() {
        delete[] arr;
    }

    /**
     * Allocates memory onto the Heap depending on the size of cap
     */
    void allocate_() {
        if (len_ == cap_) {
            Object** temp = new Object*[2 * cap_];

            for (int i = 0; i < cap_; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            cap_ *= 2;
            arr = temp;
        }
    }

    void deallocate_() {
        if (len_ < cap_ / 2) {
            Object** temp = new Object*[cap_ / 2];

            for (int i = 0; i < cap_; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            cap_ /= 2;
            arr = temp;
        }
    }

    /**
     * Gets the element at given idx
     * @param idx index
     *
     */
    Object* at(size_t idx) {

    }

    /**
     * Returns the last element in the Array
     */
    Object* back() {

    }

    /**
     * Gets the first element of the Array
     */
     Object* begin() {

     }

     /**
      * Returns the size of this Array
      *
      */
     size_t size() {
         return this->len_;
     }

     /**
      * Determines whether the list is empty
      *
      */
     bool empty() {

     }

    /**
     * Appends Object e to the end of this Array
     *
     */
    void add(Object* e) {
        arr[len_] = e;
        len_++;
        this->allocate_();
    }

    /**
     * Inserts given Object e at index i in the Array
     *
     */
    void add(size_t i, Object* e) {
        if (i == cap_) {
            add(e);
        }
        else {
            len_++;
            this->allocate_();
            for (size_t j = len_; j > i; j++) {
                arr[j] = arr[j-1];
            }
            arr[i] = e;
        }
    }

    /**
     * Returns and removes the item and index i of this Array
     *
     */
    Object* remove(size_t i) {
        Object* elem = arr[i];
        for (int j = i; j < len_ - 1; j++) {
            arr[j] = arr[j+1];
        }
        len_--;
        this->deallocate_();
        return elem;
    }

    /**
     * Removes all of elements from this list
     */
    void clear() {
        while (len_ != 0) {
            this->remove(0);
        }
    }
};


#endif //SOFTWARE_DEV_A1_ARRAY_H
