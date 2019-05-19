//! \file


#ifndef VECTOR_H
#define VECTOR_H

#include<cstdlib>
#include<stdexcept> 
#include<cstring>
#include<initializer_list>

namespace sc
{
    //! Vector object, made as a replication of std::vector.
    /*!
      Replicates the vector in std::vector, with the same methods.
    */
    template<typename T>
    class Vector
    {
        private:
            T *data; //!< Base array of the vector.
            size_t count; //!< Amount of elements in the vector.
            size_t capSize; //!< Number of T elements allocated for the vector.
        public:
            //! Default constructor
            /*! Default constructor. Will allocate the memory for the vector.
                \param size - Number of elements to initially allocate for the vector. 
            */
            Vector(size_t size=0)
            {
                data = new T[size];
                count = size;
                capSize = size;
            }
            //! Clone constructor
            /*! Clone constructor, allocating the same memory as the passed vector and taking the same elements.
                \param other - Vector to be cloned from. 
            */
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
            //! Asignment constructor
            /*!
                Assigns the data, size and capacity the same values as the passed vector.
                \param other - Vector to be used in the assignment.
            */
            Vector & operator=( Vector & other)
            {
                count = other.size();
                capSize = other.capacity();
                data = new T[capSize];
                for (size_t i = 0; i < count; i++)
                {
                    data[i] = other.at(i);
                }
                
                return *this;
            }

            /*Vector & operator=(std::initializer_list<T> &ilist)
            {
                count = ilist.size();
                capSize = ilist.size();
                data = new T[capSize];
                size_t newCount = 0;
                for (auto &val : ilist)
                {
                    data[newCount] = val;
                    count++; 
                }
                
                
            }*/

            //! Returns the number of elements in the vector.
            size_t size() { return count; }
            //! Returns how much memory the vector is currently using.
            size_t capacity() { return capSize; }
            //! Returns the element in the passed position of the vector without checking for bounds.
            T & operator[](size_t pos){ return data[pos]; }
            //! Returns true if the vector has no elements in it, even if memory was allocated.
            bool empty() { return count > 0; }

            //! Returns the element at the passed position, checking if it is bound within the allocated space
            T & at (size_t pos) 
            {
                if(pos < count)
                    return data[pos];
                else 
                {
                    throw std::out_of_range("Value not inside vector range");
                }
            }
            //! Adds an element to the front of the vector (the [0] position), allocating more space, if necessary.
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
            //! Adds an element to the back of the vector (the [size() - 1] position), allocating more space, if necessary.
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
            //! Makes the vector have n copies of x.
            /*!
                \param valCount - Number of copies.
                \param value - Value to be assigned.
            */
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
            //! Makes the vector have n spaces of memory. Does nothing if passed value is below or equal to the current capacity.
            /*! 
                \param newCap - New size of the vector.
            */
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
            //! Makes the vector have the allocated memory space equal to the number of elements.
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
            //! Removes the element at the front of the vector, without deallocating memory.
            void pop_front()
            {
                count--;
                std::memcpy(data, data+1, count * sizeof(T));
            }
            //! Removes the element at the back of the vector, without deallocating memory.
            void pop_back()
            {
                count--;
            }
            //! Returns the element at the back of the vector (the [size() - 1] position).
            const T & back() const
            {
                return data[count - 1];
            }
            //! Returns the element at the front of the vector (the [0] position).
            const T & front() const
            {
                return data[0];
            }
            //! Makes the vector have 0 elements, without deallocating memory.
            void clear()
            {
                count = 0;
            }
            //! Returns true if the vectors are equal.
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
            //! Returns true if the vectors are unequal.
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
