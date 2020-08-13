#pragma once

#include <utility>

namespace ds
{
   template<typename TYPE>
   class vector
   {
   public:
      vector()
      {
         reallocate(2);
      }

      ~vector()
      {
         clear();
         ::operator delete(m_data, m_capacity * sizeof(TYPE));
      }

      void push_back(const TYPE& value)
      {
         if (m_size >= m_capacity)
         {
            reallocate(2 * m_capacity);
         }

         m_data[m_size++] = value;
      }

      template<typename... ARGS>
      TYPE& emplace_back(ARGS&&... args)
      {
         if (m_size >= m_capacity)
         {
            reallocate(2 * m_capacity);
         }
         new(&m_data[m_size]) TYPE(std::forward<ARGS>(args)...);
         return m_data[m_size++];
      }

      void push_back(TYPE&& value)
      {
         if (m_size >= m_capacity)
         {
            reallocate(2 * m_capacity);
         }

         m_data[m_size++] = std::move(value);
      }

      void pop_back()
      {
         if (m_size > 0)
         {
            m_size--;
            m_data[m_size].~TYPE();
         }
      }

      // TODO: Erase

      void clear()
      {
         for (size_t i = 0; i < m_size; ++i)
         {
            m_data[i].~TYPE();
         }
         m_size = 0;
      }

      // TODO: Debug assertions checks on out of bounds indexing
      const TYPE& operator[](size_t index) const { return m_data[index]; }
      TYPE& operator[](size_t index) { return m_data[index]; }

      size_t size() const { return m_size; }

      // TODO: Iterators

   private:
      void reallocate(size_t capacity)
      {
         TYPE* new_block = (TYPE*)::operator new(capacity * sizeof(TYPE));

         if (capacity < m_size)
         {
            m_size = capacity;
         }

         for (size_t i = 0; i < m_size; ++i)
         {
            new_block[i] = std::move(m_data[i]);
         }

         for (size_t i = 0; i < m_size; ++i)
         {
            m_data[i].~TYPE();
         }

         ::operator delete(m_data, m_capacity * sizeof(TYPE));
         m_data = new_block;
         m_capacity = capacity;
      }

   private:
      TYPE* m_data = nullptr;

      size_t m_size = 0;
      size_t m_capacity = 0;
   };
}