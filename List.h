#ifndef LIST_H
#define LIST_H

template <class Object>
class List
{


    private:
        struct Node{

        };

    public:
        class const_iterator{

        };

        class iterator:public const_iterator{

        };

    public:
        List() {}
        List(const List& other) {}
        ~List() {}
        List& operator=(const List& other) { return *this; }
        List(List && other){}
        List & operator=(List && other){}

        iterator begin(){
        }
        const_iterator begin() const{
        }
        iterator end(){
        }
        const_iterator end() const{
        }

        int size() const{}
        bool empty() const {}

        void clear(){
        }

        Object & front(){
        }
        const Object & front() const{
        }
        Object & back(){
        }
        const Object & back() const{
        }
        void push_front(const Object & x){
        }
        void push_front(Object && x){
        }
        void push_back(const Object & x){
        }
        void push_back(Object && x){
        }
        void pop_front(){
        }
        void pop_back(){
        }

        iterator insert (iterator itr,const Object & x){
        }
        iterator insert(iterator itr, Object && x){
        }

        iterator erase(iterator itr){
        }
        iterator erase(iterator from, iterator to){
        }
    private:
        int theSize;
        Node *head;
        Node *tail;

        void init(){
        }
};

#endif // LIST_H
