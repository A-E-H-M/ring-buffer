#pragma once

#include <string>
#include <vector>

namespace R_BUFFER
{
    template <typename T, std::size_t size>
    class Ring_buffer
    {
        private:
            std::size_t size;
            std::vector<T> Darray;
            //std::string temp_string;

            std::size_t counter{0};
            std::size_t last_pos{0};
        
        public:
            // element access function
            std::size_t find_empty(std::size_t index);
            // element access function
            T at(std::size_t index)
            {
                return Darray[index];
            }

            // modifier function
            void pop_range(std::size_t num)
            {
                // 
            };

            // modifier function
            // Clears the contents of the buffer
            void clear()
            {
                Darray.clear();
            }

            // modifier function
            bool erase(std::size_t temp_index);
            // modifier function
            bool append(std::string_view temp_str);
            // modifier function
            void pop_back(std::size_t num_elements);
            // modifier function
            void assign(std::size_t temp_str);

    };

} // end of namespace

