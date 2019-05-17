#ifndef VECTOR_H
#define VECTOR_H

#include<cstdlib>
#include<stdexcept> 
#include<cstring>

namespace sc
{
    template<typename T>
    class Vector
    {
        private:
            T *data;
            size_t count;
            size_t capSize;
        public:
            //typename myType;
        public:
            Vector(size_t size=0)
            {
                data = new T[size];
                count = size;
                capSize = size;
            }

            Vector(Vector & other)
            {
                count = other.size();
                capSize = other.capacity();
                data = new T[capSize];
                for(size_t i = 0; i < count; i++)
                {
                    data[i] = other[i];
                }
            }

            size_t size() { return count; }
            size_t capacity() { return capSize; }
            T & operator[](size_t pos){ return data[pos]; }
            bool empty() { return count > 0; }


            T & at (size_t pos) 
            {
                if(pos < count)
                    return data[pos];
                else 
                {
                    throw std::out_of_range("Value not inside vector range");
                }
            }

            void push_front( const T & value )
            {
                count++;
                if(count > capSize)
                {
                    capSize = count;
                    T *buffer = new T[capSize];
                    std::memcpy(buffer + 1, data, count * sizeof(T));
                    delete[] data;
                    data = buffer;
                }
                else
                {
                    std::memcpy(data + 1, data, count * sizeof(T));
                }

                data[0] = value;
            }

            void push_back( const T & value )
            {
                count++;
                if(count > capSize)
                {
                    capSize = count;
                    T *buffer = new T[capSize];
                    std::memcpy(buffer, data, count  * sizeof(T));
                    delete[] data;
                    data = buffer;
                }

                data[count - 1] = value;
            }

            void assign(size_t valCount, const T & value)
            {
                count = valCount;
                if(count > capSize)
                {
                    capSize = count;
                    T *buffer = new T[capSize];
                    delete[] data;
                    data = buffer;
                }
                
                for (size_t i = 0; i < count; i++)
                {
                    data[i] = value;
                }
            }

            void reserve(size_t newCap )
            {
                if(newCap <= capSize)
                    return;
                
                capSize = newCap;
                T *buffer = new T[capSize];
                std::memcpy(buffer, data, count  * sizeof(T));
                delete[] data;
                data = buffer;
            }

            void shrink_to_fit()
            {
                if(capSize == count)
                    return;

                capSize = count;
                T *buffer = new T[capSize];
                std::memcpy(buffer, data, count * sizeof(T));
                delete[] data;
                data = buffer;
            }

            void pop_front()
            {
                count--;
                std::memcpy(data, data+1, count * sizeof(T));
            }

            void pop_back()
            {
                count--;
            }

            const T & back() const
            {
                return data[count - 1];
            }

            const T & front() const
            {
                return data[0];
            }

            void clear()
            {
                count = 0;
            }

            bool operator==(Vector & rhs)
            {
                if(count != rhs.size())
                    return false;
                else
                {
                    for (size_t i = 0; i < count; i++)
                    {
                        if(data[i] != rhs.at(i))
                            return false;
                    }
                    
                }

                return true;
                
            }

            bool operator!=(Vector & rhs)
            {
                if(count != rhs.size())
                    return true;
                else
                {
                    for (size_t i = 0; i < count; i++)
                    {
                        if(data[i] != rhs.at(i))
                            return true;
                    }
                    
                }

                return false;
                
            }

    };
}

#endif












/*
template <typename T>
class vector {
    public:
        using size_type = unsigned long; //!< The size type.
        using value_type = T;
        //!< The value type.
        using pointer = value_type*;
        //!< Pointer to a value stored in the container.
        using reference = value_type&;
        //!< Reference to a value stored in the container using const_reference = const value_type&; //!< Const reference to a value stored  using iterator = MyIterator< T > // See Code 3
        using const_iterator = MyIterator< const T > // See Code 3

        //=== [I] SPECIAL MEMBERS
        explicit vector( size_type = 0 );
        virtual ~vector( void );
        vector( const vector & );
        vector( std::initializer_list<T> );
        vector( vector && );
        template < typename InputItr >
        vector( InputItr, InputItr );
        vector& operator=( const vector& );
        vector& operator=( vector && );

        //=== [II] ITERATORS
        iterator begin( void );
        iterator end( void );
        const_iterator cbegin( void ) const;
        const_iterator cend( void ) const;

        // [III] Capacity
        size_type size( void ) const;
        size_type capSize( void ) const;
        bool empty( void ) const;

        // [IV] Modifiers
        void clear( void );
        void push_front( const_reference );
        void push_back( const_reference );
        void pop_back( void );
        void pop_front( void );
        iterator insert( iterator, const_reference );
        template < typename InputItr >
        iterator insert( iterator , InputItr, InputItr );
        iterator insert( iterator , const std::initializer_list< value_type >& );
        void reserve( size_type );
        void shrink_to_fit( void );

        void assign( size_type, const_reference );
        void assign( const std::initializer_list<T>& );
        template < typename InputItr >
        void assign( InputItr, InputItr );
        iterator erase( iterator, iterator );
        iterator erase( iterator );

        // [V] Element access
        const_reference back( void ) const;
        reference back( void );
        const_reference front( void ) const;
        reference front( void );
        const_reference operator []( size_type ) const;
        reference operator []( size_type );
        const_reference at( size_type ) const;
        reference at( size_type );
        pointer data( void );
        const_reference data( void ) const;

        // [VII] Friend functions.
        friend std::ostream& operator <<( std::ostream&, const vector<T>& );
        friend void swap( vector<T>&, vector<T>& );
    private:
        size_type m_end;
        //!< Current list size (or index past-last valid element).
        size_type m_capacity;
        //!< List’s storage capSize.
        //std::unique_ptr<T[]> m_storage; //!< Data storage area for the dynamic array.
        T *m_storage; //!< Data storage area for the dynamic array.
 };

 */
