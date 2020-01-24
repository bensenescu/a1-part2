//lang::CwC
#pragma once
#include <iostream>
#include "object.h"

/**
 * Represents a single string of characters.
 */
class String : public Object
{
public:
    char *val_;
    size_t size_;

    String(const char *val)
    {
        size_ = strlen(val);
        val_ = new char[size_ + 1];
        // printf("size_ = %i\n", size_);
        for (size_t i = 0; i < size_ + 1; i++)
        {
            val_[i] = val[i];
        }
        // printf("%s, size = %i\n", val_, strlen(val_));
    }

    ~String()
    {
        delete val_;
    }

    /**
         * Concats e to this and then returns a new string object
         */
    String *concat(String *e)
    {
        const char *cat = strcat(this->val(), e->val());
        String *ret = new String(cat);
        delete cat;
        return ret;
    }

    void toLower()
    {
        for (int i = 0; i < this->length(); i++)
        {
            this->val_[i] = tolower(this->val_[i]);
        }
    }

    void print()
    {
        std::cout << val_;
    }

    size_t length()
    {
        return size_;
    }

    char *val()
    {
        return val_;
    }

    int compare(String *e)
    {
        return strcmp(this->val(), e->val());
    }
    /**
         * Determines if two strings are equal to eachother
         */
    virtual bool equals(Object *o)
    {
        String *e = dynamic_cast<String *>(o);
        if (e == NULL)
        {
            return false;
        }
        return this->size_ == e->size_ && this->compare(e) == 0;
    }
};
