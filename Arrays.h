//
// Created by spect on 11/21/2026.
//

#ifndef ARRAYLATE_ARRAYS_H
#define ARRAYLATE_ARRAYS_H

#pragma once

#include <iostream>
#include <memory>

template <typename T>

class DynamicGenericArrayADT
{
public:
    virtual void pushBack(T itemToPush) = 0;

    virtual ~DynamicGenericArrayADT() = default;
};


template <typename T>

class RawDynamicGenericArray : public DynamicGenericArrayADT<T>
{
private:
    int max_capacity = 5;
    T* rawPtrToDynamicList = new T[max_capacity];
    int current_size = 0;

public:
    RawDynamicGenericArray() = default;

    void pushBack(T itemToPush) override
    {
        // Resize if full
        if (current_size == max_capacity)
        {
            max_capacity *= 2;
            T* tempPtr = new T[max_capacity];

            for (int i = 0; i < current_size; ++i)
            {
                tempPtr[i] = rawPtrToDynamicList[i];
            }

            delete[] rawPtrToDynamicList;
            rawPtrToDynamicList = tempPtr;
        }

        rawPtrToDynamicList[current_size] = itemToPush;
        current_size++;
    }

    void print() const
    {
        for (int i = 0; i < current_size; ++i)
        {
            std::cout << rawPtrToDynamicList[i] << " ";
        }
        std::cout << std::endl;
    }

    ~RawDynamicGenericArray() override
    {
        delete[] rawPtrToDynamicList;
    }
};

template <typename T>

class SmartDynamicGenericArray : public DynamicGenericArrayADT<T>
{
private:
    int max_capacity = 5;
    int current_size = 0;
    std::unique_ptr<T[]> smartPtrToDynamicList = std::make_unique<T[]>(max_capacity);

public:
    SmartDynamicGenericArray() = default;

    void pushBack(T itemToAddToEnd) override
    {
        if (current_size == max_capacity)
        {
            max_capacity *= 2;
            std::unique_ptr<T[]> tempPtr = std::make_unique<T[]>(max_capacity);

            for (int i = 0; i < current_size; ++i)
            {
                tempPtr[i] = smartPtrToDynamicList[i];
            }

            smartPtrToDynamicList = std::move(tempPtr);
        }

        smartPtrToDynamicList[current_size] = itemToAddToEnd;
        current_size++;
    }

    void print() const
    {
        for (int i = 0; i < current_size; ++i)
        {
            std::cout << smartPtrToDynamicList[i] << " ";
        }
        std::cout << std::endl;
    }

    size_t sequentialSearch(T target)
    {
        for (size_t i = 0; i < current_size; ++i)
        {
            if (smartPtrToDynamicList[i] == target)
            {
                std::cout << target << " found at index: " << i << std::endl;
                return i;
            }
        }

        std::cout << target << " not found" << std::endl;
        return -1;

    }

    void swap(size_t lhsIndex, size_t rhsIndex)
    {
        //Insert bounds checks
        T temporaryCopy = smartPtrToDynamicList[lhsIndex];
        smartPtrToDynamicList[lhsIndex] = smartPtrToDynamicList[rhsIndex];
        smartPtrToDynamicList[rhsIndex] = temporaryCopy;
    }

    void ascendingNaiveSort()
    {
        for (size_t leftPos = 0; leftPos < current_size - 1; leftPos++)
        {
            for (size_t rightPos = leftPos + 1; rightPos < current_size; rightPos++)
            {
                if (smartPtrToDynamicList[leftPos] > smartPtrToDynamicList[rightPos])
                {
                    swap(leftPos, rightPos);
                }
            }
        }
    }
};


#endif //ARRAYLATE_ARRAYS_H
