/**
 * @file ring_buffer.hpp
 * @brief A fixed-capacity, wraparound buffer.
 * 
 * More information about the design rationale and implementation,
 * as well as a general overview of ring buffer (cicurlar buffer) as
 * a container, can be found in the project's README.
 *
 */

#pragma once

#include <array>

namespace ring_buffer
{

/**
 * @brief A fixed-capacity, wraparound buffer.
 *
 * @tparam T Element type. Must be default-constructible, since it uses
 *          (`std::array<T, N>`) internally to construct the elements
 *          at compile time.
 * @tparam SZ Fixed size of the ring buffer.
 */
    template <typename T, std::size_t SZ>
    class ring_buffer
    {
        private:
            //const std::size_t size;
            std::array<T, SZ> Darray;

            //std::size_t counter{0};
            std::size_t last_pos{0};
        
        public:

            // element access function, returns the latest element appended to the buffer, read only
            const T front()
            {
                //auto temp_last = (last_pos + Darray.size() - 1) % Darray.size();
                //return Darray[temp_last];
            }

            // element access function, returns the latest element appended to the buffer, read only
            const T back()
            {
                auto temp_last = (last_pos + Darray.size() - 1) % Darray.size();
                return Darray[temp_last];
            }

            // element access function, read only
            const T at(std::size_t index)
            {
                //assert (index <= Darray.size());
                //assert (index >= 0);

                return Darray[index];
            }

            // capacity assessment
            const std::size_t size_of() 
            {   
                return Darray.size();
            };

            
            // modifier function, clears the contents of the buffer
            void clear()
            {
                Darray.clear();
            }
            

            // modifier function, adds element to the next index space
            void push_back(const T& element)
            {
                Darray[last_pos % Darray.size()] = element;
                ++last_pos;
            }

            // modifier function
            void assign(std::size_t index, const T& element)
            {
                //assert (index <= Darray.size() && "Index outside of bounds");
                //assert (index >= 0 && "Index must be positive value");
                Darray[index] = element;
            }

    };

} // end of namespace