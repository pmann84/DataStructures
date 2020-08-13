#pragma once

namespace ds
{
   template<typename TYPE, size_t SIZE>
   class array
   {
   public:
      array() = default;
      ~array() = default;

      constexpr size_t size() const { return SIZE; }

      // TODO: Debug assertions checks on out of bounds indexing
      const TYPE& operator[](size_t index) const { return m_data[index]; }
      TYPE& operator[](size_t index) { return m_data[index]; }

      TYPE* data() { return m_data; }
      const TYPE* data() const { return m_data; }

      // TODO: Iterators
      // TODO: Swap

   private:
      TYPE m_data[SIZE];
   };
}