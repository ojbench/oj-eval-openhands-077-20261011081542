namespace sjtu {
    class CrossArray{
    private:
        int** arrays;
        int* sizes;
        int capacity;
        int count;
    public:
        explicit CrossArray(int lines);

        CrossArray(const CrossArray & o);

        CrossArray & WhichGreater(CrossArray & o);

        bool IsSame(const CrossArray & o);

        bool InsertArrays(const int * Input, int size);

        void AppendArrays(const int * Input,int Line,int size);

        void DoubleCrossLength();

        const int * AtArray(int i);

        int & At(int i , int j);

        ~CrossArray();

    };

    CrossArray::CrossArray(int lines) : capacity(lines), count(0) {
        arrays = new int*[capacity];
        sizes = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            arrays[i] = nullptr;
            sizes[i] = 0;
        }
    }

    CrossArray::CrossArray(const CrossArray & o) : capacity(o.capacity), count(o.count) {
        arrays = new int*[capacity];
        sizes = new int[capacity];
        
        for (int i = 0; i < capacity; i++) {
            if (o.arrays[i] != nullptr) {
                sizes[i] = o.sizes[i];
                arrays[i] = new int[sizes[i]];
                for (int j = 0; j < sizes[i]; j++) {
                    arrays[i][j] = o.arrays[i][j];
                }
            } else {
                arrays[i] = nullptr;
                sizes[i] = 0;
            }
        }
    }

    CrossArray & CrossArray::WhichGreater(CrossArray & o) {
        int thisTotal = 0;
        int oTotal = 0;
        
        for (int i = 0; i < capacity; i++) {
            if (arrays[i] != nullptr) {
                thisTotal += sizes[i];
            }
        }
        
        for (int i = 0; i < o.capacity; i++) {
            if (o.arrays[i] != nullptr) {
                oTotal += o.sizes[i];
            }
        }
        
        if (thisTotal >= oTotal) {
            return *this;
        } else {
            return o;
        }
    }

    bool CrossArray::IsSame(const CrossArray & o) {
        return (arrays == o.arrays) && (sizes == o.sizes) && (capacity == o.capacity) && (count == o.count);
    }

    bool CrossArray::InsertArrays(const int * Input, int size) {
        if (count >= capacity) {
            return false;
        }
        
        arrays[count] = new int[size];
        sizes[count] = size;
        
        for (int i = 0; i < size; i++) {
            arrays[count][i] = Input[i];
        }
        
        count++;
        return true;
    }

    void CrossArray::AppendArrays(const int * Input, int Line, int size) {
        int oldSize = sizes[Line];
        int newSize = oldSize + size;
        
        int* newArray = new int[newSize];
        
        for (int i = 0; i < oldSize; i++) {
            newArray[i] = arrays[Line][i];
        }
        
        for (int i = 0; i < size; i++) {
            newArray[oldSize + i] = Input[i];
        }
        
        delete[] arrays[Line];
        arrays[Line] = newArray;
        sizes[Line] = newSize;
    }

    void CrossArray::DoubleCrossLength() {
        int newCapacity = capacity * 2;
        int** newArrays = new int*[newCapacity];
        int* newSizes = new int[newCapacity];
        
        for (int i = 0; i < newCapacity; i++) {
            if (i < capacity) {
                newArrays[i] = arrays[i];
                newSizes[i] = sizes[i];
            } else {
                newArrays[i] = nullptr;
                newSizes[i] = 0;
            }
        }
        
        delete[] arrays;
        delete[] sizes;
        
        arrays = newArrays;
        sizes = newSizes;
        capacity = newCapacity;
    }

    const int * CrossArray::AtArray(int i) {
        return arrays[i];
    }

    int & CrossArray::At(int i, int j) {
        return arrays[i][j];
    }

    CrossArray::~CrossArray() {
        for (int i = 0; i < capacity; i++) {
            if (arrays[i] != nullptr) {
                delete[] arrays[i];
            }
        }
        delete[] arrays;
        delete[] sizes;
    }
}