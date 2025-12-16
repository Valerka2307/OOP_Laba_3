#pragma once


template<class T>
class Array {
  public:
    Array() {
        data_ = nullptr;
        size_ = 0;
        cap_ = 0;
    }

    Array(const Array& other) {
        data_ = new T[other.cap_];
        for (int i = 0; i < other.size_; ++i) {
            data_[i] = other.data_[i];
        }
        size_ = other.size_;
        cap_ = other.cap_;
    }

    Array& operator=(const Array& other) {
        if (this == &other) { return *this; }

        if (data_ != nullptr) {
            delete[] data_;
        }
        data_ = new T[other.cap_];
        for (int i = 0; i < other.size_; ++i) {
            data_[i] = other.data_[i];
        }
        size_ = other.size_;
        cap_ = other.cap_;
        return *this;
    }

     Array(Array&& other) noexcept {
        data_ = other.data_;
        size_ = other.size_;
        cap_ = other.cap_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.cap_ = 0;
    }

    Array& operator=(Array&& other) noexcept {
        if (this == &other) return *this;

        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        cap_ = other.cap_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.cap_ = 0;

        return *this;
    }

    void Push(T value) {
        if (cap_ == 0) {
            cap_ = 10;
            data_ = new T[cap_];
            data_[size_++] = value;
            return;
        }

        if (size_ == cap_) {
            cap_ *= 2;
            T* new_data = new T[cap_];
            for (int i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
        }
        data_[size_++] = value;
    }

    void Pop() {
        if (size_ == 0) { return; }

        --size_;

        if (cap_ > 10 && size_ < cap_ / 4) {
            size_t new_cap = cap_ / 2;
            if (new_cap < 10) new_cap = 10;

            T* new_data = new T[new_cap];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }

            delete[] data_;
            data_ = new_data;
            cap_ = new_cap;
        }
    }

    size_t Size() { return size_;}

    bool IsEmpty() { return (size_ == 0);}

    ~Array() {
        delete[] data_;
        size_ = 0;
        cap_ = 0;
    }

    T& operator[](size_t index) {
        return data_[index];
    }

    const T& operator[](size_t index) const {
        return data_[index];
    }

  private:
    T* data_;
    size_t size_;
    size_t cap_;
};