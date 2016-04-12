//
// Created by pisatel on 11.04.16.
//

#ifndef CPPALGO_ARRAY_H
#define CPPALGO_ARRAY_H
#include <memory>
#include <exception>
#include <iostream>
#include <vector>

template <class T>
class CArray {
private:
    std::vector<T> _arr;
    size_t _size;
    std::vector<T> _heap;

    void mergeSortHelper(int arrbeg, int arrend) {
        if(arrend <= arrbeg)
            return;
        auto mid = arrbeg + (arrend - arrbeg) / 2;
        mergeSortHelper(arrbeg, mid);
        mergeSortHelper(mid+1, arrend);
        merge(arrbeg, mid, arrend);
    }

    void merge(int lo, int mid, int hi) {
        T* aux = new T[hi+1];
        auto i = lo;
        auto j = mid+1;
        for (int k = lo ; k <= hi; k++) {
            aux[k] = _arr[k];
        }
        for (int k = lo ; k <= hi; k++) {
            if (i > mid)
                _arr[k] = aux[j++];
            else if (j > hi)
                _arr[k] = aux[i++];
            else if (aux[j] < aux[i])
                _arr[k] = aux[j++];
            else
                _arr[k] = aux[i++];
        }
        delete[] aux;
    }

    void qsortHelper(int lo, int hi) {
        if (hi <= lo)
            return;
        int midv = _arr[lo + (hi-lo)/2];
        int i = lo, j = hi;
        while(i <= j) {
            while(_arr[i] > midv)
                i++;
            while(_arr[j] < midv)
                j--;
            if (i <= j) {
                std::swap(_arr[i], _arr[j]);
                i++;
                j--;
            }
        if (i < hi)
            qsortHelper(i, hi);
        if (lo < j)
            qsortHelper(lo, j);
        }
    }

    void heapify(int pos, int size) {
        while(2 * pos + 1 < size) {
            int t = 2 * pos + 1;

            if(2 * pos + 2 < size && _arr[2 * pos + 1] < _arr[2 * pos + 2]) {
                t = 2 * pos + 2;
            }

            if (_arr[pos] < _arr[t]) {
                std::swap(_arr[pos], _arr[t]);
                pos = t;
            }
            else
                break;
        }
    }

    void makeHeap() {
        auto n = _size;
        for (int i = n - 1; i >= 0; i--) {
            heapify(i, n);
        }
    }

    void heapSortHelper(size_t lo, size_t hi) {
        makeHeap();
        int n = _arr.size();
        while(n > 0) {
            std::swap(_arr[0], _arr[n-1]);
            n--;
            heapify(0, n);
        }
    }
public:
    CArray(int n) {
        if (n > 0) {
            _size = n;
            for (auto i = 0; i < _size; i++)
                _arr.push_back(0);
        }
        else {
            throw std::logic_error("Size should be more then 0");
        }
    }

    void insertionSort() {
        for (auto i = 1; i < _size; i++) {
            auto j = i;
            while(_arr[j-1] > _arr[j] && j >= 1) {
                std::swap(_arr[j], _arr[j-1]);// j-1
                j--;
            }
        }
    }

    void mergeSort() {
        mergeSortHelper(0, _size-1);
    }

    void qsort() {
        qsortHelper(0, _size-1);
    }

    void heapSort() {
        heapSortHelper(0, _size-1);
    }

    T& operator[](int n) {
        if (n <= _size)
            return _arr[n];
        else
            throw std::bad_exception();
    }

    void print() {
        for (auto i = 0; i < _size; i++) {
            std::cout << _arr[i] << " ";
        }
        std::cout << std::endl;
    }

};


#endif //CPPALGO_ARRAY_H
