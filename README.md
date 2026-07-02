# Ring Buffer

A fixed-capacity, wraparound (circular) buffer written as a template for C++.

## Overview

`Ring_Buffer` stores up to `SZ` elements in a contiguous, fixed-size block of
memory. When elements are pushed past the last element in the buffer, the
buffer wraps around and continues writing to the beginning of the block - overwriting
storage slots.

If you're not familiar with the general ring buffer structure see the
[Wikipedia article on circular buffers](https://en.wikipedia.org/wiki/Circular_buffer)
for a general overview of how they work.

## Fixed size, Not dynamic

`Ring_Buffer` does **not** grow or shrink at runtime like a `std::vector`. 
Its size is set when it is constructed. Therefore, it never allocates memory on the
heap. This has been achieved by implementing `std::array` as the underlying
container type.

It has been designed for applications where heap allocation is a concern or where there is
a desire for a container with compiled-time fixed capacity.

## One Type, One size

It is imporant to note that two buffers of the same element but of different sizes
are not the same **type**. This means `ring_buffer<int, 8>` and `ring_buffer<int, 16>` are distinct,
unrelated types, not two instances of the same type with different runtime
sizes.