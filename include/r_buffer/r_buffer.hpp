#pragma once

#include <array>

/*
* It is a buffer that automatically wraps to the beginning of the buffer once the buffer has reached its end.
*/

namespace R_BUFFER
{
    template <typename T, std::size_t size>
    class Ring_buffer
    {
        private:
            //const std::size_t size;
            std::array<T, size> Darray;

            //std::size_t counter{0};
            std::size_t last_pos{0};
        
        public:
            // element access function, returns the oldest element appended to the buffer, read only
            const T end()
            {
                return Darray[(last_pos + 1) % size];
            }

            // element access function, returns the latest element appended to the buffer, read only
            const T last()
            {
                return Darray[last_pos % size];
            }

            // element access function, read only
            const T at(std::size_t index)
            {
                return Darray[index];
            }

            // modifier function, clears the contents of the buffer
            void clear()
            {
                Darray.clear();
            }

            // modifier function, adds element to the next index space
            void append(const T& element)
            {
                Darray[last_pos % size] = element;
                ++last_pos;
            }

            // modifier function
            void assign(std::size_t index, const T& element)
            {
                Darray[index] = element;
            }

    };

} // end of namespace