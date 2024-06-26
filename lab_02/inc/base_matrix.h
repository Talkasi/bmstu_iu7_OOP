#ifndef BASE_MATRIX_H
#define BASE_MATRIX_H
#include <cstddef>

class BaseMatrix
{
public:
    BaseMatrix() noexcept;
    BaseMatrix(size_t n_rows, size_t n_cols) noexcept;

    size_t getNCols() const noexcept;
    size_t getNRows() const noexcept;

    bool isEmpty() const noexcept;
    bool isSquare() const noexcept;

    ~BaseMatrix() = default;

protected:
    size_t n_rows = 0;
    size_t n_cols = 0;
};

#endif // BASE_MATRIX_H
