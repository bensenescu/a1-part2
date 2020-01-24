//lang::CwC
#pragma once
#include <iostream>

class Object
{
public:
    size_t hash_;
    Object()
    {
    }

    virtual ~Object()
    {
    }

    virtual bool equals(Object *enter)
    {
        return this == enter;
    }

    size_t hash()
    {
        if (hash_ == 0)
        {
            hash_ = hash_me();
        }
        return hash_;
    }

    virtual size_t hash_me()
    {
        return reinterpret_cast<size_t>(this);
    }
};
