#include <cstring>

class DynamicArray {
public:

    DynamicArray(int capacity) : capacity(capacity), curIdx(0) {
        arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (isFull()) {
            this->resize();
        }

        arr[curIdx++] = n;
    }

    int popback() {
        return arr[--curIdx];
    }

    void resize() {
        int *tmp = arr;
        capacity *= 2;
        int *newArr = new int[capacity];
        memcpy(newArr, arr, sizeof(int) * curIdx);
        arr = newArr;
        delete[] tmp;
    }

    int getSize() {
        return curIdx;
    }

    int getCapacity() {
        return capacity;
    }

private:
    int *arr{nullptr};
    int capacity;
    int curIdx;

    inline bool isFull() {return curIdx >= capacity;}
};
