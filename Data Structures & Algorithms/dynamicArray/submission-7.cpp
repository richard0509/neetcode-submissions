class DynamicArray {
private:
    int* values;
    int capacity;
    int length;
public:

    DynamicArray(int capacity) : capacity{capacity}, length{0} {
        this->values = new int[capacity];
    }

    ~DynamicArray() {
        delete[] values;
    }

    int get(int i) {
        return this->values[i];
    }

    void set(int i, int n) {
        this->values[i] = n;
    }

    void pushback(int n) {
        if (length == capacity) {
            resize();
        }
        this->values[length] = n;
        length++;
    }

    int popback() {
        int num = values[length - 1];
        length--;
        return num;
    }

    void resize() {
        capacity *= 2;
        int* newValues{new int[capacity]};
        for (int i = 0; i < length; ++i) {
            newValues[i] = values[i];
        }
        delete[] values;
        values = newValues;
    }

    int getSize() {
        return this->length;
    }

    int getCapacity() {
        return this->capacity;
    }
    
};
