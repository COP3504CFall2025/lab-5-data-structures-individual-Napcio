#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"

// Technically bad, but size_t isn't likely to conflict with any client code.
using std::size_t;

template<typename T>
class ABS : public StackInterface<T> {
public:
    // Big 5 + Parameterized Constructor
    ABS();
    explicit ABS(const size_t capacity);
    ABS(const ABS& other);
    ABS& operator=(const ABS& rhs);
    ABS(ABS&& other) noexcept;
    ABS& operator=(ABS&& rhs) noexcept;
    ~ABS() noexcept override;

    // Get the number of items in the ABS
    [[nodiscard]] size_t getSize() const noexcept override;

    // Get the max size of the ABS
    [[nodiscard]] size_t getMaxCapacity() const noexcept;

    // Return underlying data for the stack
    [[nodiscard]] T* getData() const noexcept;

    // Push item onto the stack
    void push(const T& data) override;

    T peek() const override;

    T pop() override;

private:
    size_t capacity_;
    size_t curr_size_;
    T* array_;
    static constexpr size_t scale_factor_ = 2;
};

template <typename T>
ABS<T>::ABS()
{
}

template <typename T>
ABS<T>::ABS(const size_t capacity)
{
}

template <typename T>
ABS<T>::ABS(const ABS& other)
{
}

template <typename T>
ABS<T>& ABS<T>::operator=(const ABS& rhs)
{
}

template <typename T>
ABS<T>::ABS(ABS&& other) noexcept
{
}

template <typename T>
ABS<T>& ABS<T>::operator=(ABS&& rhs) noexcept
{
}

template <typename T>
ABS<T>::~ABS() noexcept
{
}

template <typename T>
size_t ABS<T>::getSize() const noexcept
{
}

template <typename T>
size_t ABS<T>::getMaxCapacity() const noexcept
{
}

template <typename T>
T* ABS<T>::getData() const noexcept
{
}

template <typename T>
void ABS<T>::push(const T& data)
{
}

template <typename T>
T ABS<T>::peek() const
{
}

template <typename T>
T ABS<T>::pop()
{
}
