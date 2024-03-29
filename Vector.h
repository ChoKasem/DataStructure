#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>

template<class Object>
class Vector
{
    public:
        //ctor
        explicit Vector(int initSize = 0)
        : theSize{initSize}, theCapacity{initSize + SPARE_CAPACITY} {
            objects = new Object[theCapacity];
        }
        //copy ctor
        Vector(const Vector& other)
        : theSize{other.theSize}, theCapacity{other.theCapacity}, objects{nullptr} {
            objects = new Object[theCapacity];
            for(int i = 0; i < theSize; ++i){
                objects[i] = other.objects[i];
            }
        }

        //copy assignment
        Vector& operator=(const Vector& other) {
            Vector copy = other;
            std::swap(*this, copy);
            return *this;
        }

        //dtor
        ~Vector() {
            delete[] objects;
        }

        //move ctor
        Vector(Vector && other)
        : theSize(other.theSize), theCapacity(other.theCapacity), objects(other.objects) {
            other.theSize = 0;
            other.theCapacity = 0;
            other.objects = nullptr;
        }

        //move assignment
        Vector & operator=(Vector && other){
            Vector copy = other;
            std::swap(*this, other);
            other.theSize = 0;
            other.theCapacity = 0;
            other.objects = nullptr;
            return *this;
        }

        void resize(int newSize){
            if(newSize > theCapacity){
                reserve(newSize * 2);
            }
            theSize = newSize;
        }

        void reserve(int newCapacity){
            if(newCapacity < theSize)
                return;
            Object *newArray = new Object[newCapacity];
            for(int i=0; i<theSize; ++i){
                newArray[i] = std::move(objects[i]);
            }
            theCapacity = newCapacity;
            std::swap(objects, newArray);
            delete[] newArray;
        }

        Object & operator[](int index){
            return objects[index];
        }
        const Object & operator[](int index) const {
            return objects[index];
        }

        //inquiry
        bool empty() const{
            return size() == 0;
        }
        int size() const{
            return theSize;
        }
        int capacity() const {
            return theCapacity;
        }

        void push_back(const Object & x){
            if(theSize == theCapacity){
                reserve(2 * theCapacity + 1);
            }
            objects[theSize++] = x;
        }
        void push_back(Object && x){
            if(theSize == theCapacity){
                reserve(2 * theCapacity + 1);
            }
            objects[theSize++] = std::move(x);
        }

        void pop_back(){
            theSize--;
        }

        const Object & back () const {
            return objects[theSize-1];
        }

        typedef Object * iterator;
        typedef const Object * const_iterator;

        iterator begin(){
            return &objects[0];
        }
        const_iterator begin() const {
            return &objects[0];
        }

        iterator end(){
            return &objects[theSize];
        }
        const_iterator end() const {
            return &objects[theSize];
        }


        static const int SPARE_CAPACITY = 16;

    private:
        int theSize;
        int theCapacity;
        Object *objects;
};

#endif // VECTOR_H
