/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once


#include <sstream>
#include <stdexcept>
#include <cassert>

#include "slist.hpp"

template <class T>
SNode<T>::SNode (T const& it)
{
    //TODO
    _item = it;
    _next = nullptr
    //
    assert(!has_next());
}

template <class T>
SNode<T>::SNode (T const& it, SNode<T>::Ref& next)
{
    //TODO
    _item = it;
    _next = next;
    //
}

template <class T>
SNode<T>::~SNode()
{
    //TODO
    //hint: if std::shared_ptr is used for the references, nothing todo.

    //
}

template <class T>
typename SNode<T>::Ref SNode<T>::create(T const& it, SNode<T>::Ref next)
{
    return std::make_shared<SNode<T>> (it, next);
}

template <class T>
T SNode<T>::item() const
{
    T it;
    //TODO
    it = _item;
    //
    return it;
}

template <class T>
bool SNode<T>::has_next() const
{
    bool has = false;
    //TODO
    if(_next != nullptr)
         has = true;
    //
    return has;
}

template <class T>
typename SNode<T>::Ref SNode<T>::next() const
{
    SNode<T>::Ref n;
    //TODO
    n = _next;
    //
    return n;
}

template <class T>
void SNode<T>::set_item(const T& new_it)
{
    //TODO
    _item = new_it;
    //
    assert(item()==new_it);
}

template <class T>
void SNode<T>::set_next(SNode<T>::Ref n)
{
    //TODO
    _next = n;
    //
    assert(n == next());
}

template<class T>
SList<T>::SList ()
{
    //TODO
    _head = nullptr;
    _current = _head;
    _size = 0;
    _prev = nullptr;
    //
    assert(is_empty());
}

template<class T>
SList<T>::~SList()
{
    //TODO



    //

}

template<class T>
typename SNode<T>::Ref SList<T>::head() const
{
    typename SNode<T>::Ref h;
    //TODO
    h = _head;
    //
    return h;
}

template<class T>
typename SList<T>::Ref SList<T>::create()
{
    return std::make_shared<SList<T>> ();
}

template<class T>
typename SList<T>::Ref SList<T>::create(std::istream& in) noexcept(false)
{
    auto list = SList<T>::create();
    std::string token;
    in >> token;
    //std::cout << "token: " << token << std::endl;
    //TODO
    //Hint: use std::istringstream to convert from "string" to template
    // parameter T type.
    // Throw std::runtime_error("Wrong input format.") exception when an input
    // format error was found.
    typename SNode<T>::Ref last;
    T new_t;

    list->_head = nullptr;
    if(token == "["){
        in >> token;
        std::istringstream iss(token);
        iss >> new_t;
        if(iss){

            list->_head = SNode<T>::create(new_t);
            last = list->_head;
            in >> token;

            while(in && token != "]"){
                std::istringstream iss(token);
                iss >> new_t;
                if(iss){
                    last->set_next(SNode<T>::create(new_t));
                    (list->_size)++;
                    last = last->next();
                    in >> token;
                } else {
                    throw std::runtime_error("Wrong input format.");
                }
            }

        }

        if(token != "]"){
            throw std::runtime_error("Wrong input format.");
        }

    }else if(token != "[]"){
        throw std::runtime_error("Wrong input format.");
    }

    if(!(list->is_empty())){
        (list->_size)++;
    }

    //
    return list;
}

template<class T>
bool SList<T>::is_empty () const
{
    bool ret_val = true;
    //TODO
    if(_size != 0)
        ret_val = false;
    //
    return ret_val;
}

template<class T>
size_t SList<T>::size () const
{
    size_t ret_val = 0;
    //TODO
    ret_val = _size;
    //
    return ret_val;
}

template<class T>
T SList<T>::front() const
{
    assert(!is_empty());
    T f;
    //TODO
    f = _head->item();
    //
    return f;
}

template<class T>
T SList<T>::current() const
{    
    assert(! is_empty());
    T c;
    //TODO
    c = _current->item();
    //
    return c;
}

template<class T>
bool SList<T>::has_next() const
{
    assert(!is_empty());
    bool ret_val = false;
    //TODO
    ret_val = _current->has_next();
    //
    return ret_val;
}

template<class T>
T SList<T>::next() const
{
    assert(has_next());
    T ret_val = false;
    //TODO
    typename SNode<T>::Ref next = _current->next();
    ret_val = next->item();
    //
    return ret_val;
}


template<class T>
bool SList<T>::has(T const& it) const
{
    bool found = false;
    //TODO
    //Hint: you can reuse SList::find() but you must remember to restore 
    // the old the cursor position. In this way we assure not modify the state of the list.
    //Hint: use const_cast<> to remove constness of this.

    typename SNode<T>::Ref old_current = const_cast<SList<T>&>(*this)._current;

    found = const_cast<SList<T>&>(*this).find(it);

    const_cast<SList<T>&>(*this)._current = old_current;

    //
    return found;
}

template<class T>
void SList<T>::fold(std::ostream& out) const
{
    //TODO

    typename SNode<T>::Ref node;

    if(is_empty()){

        out << "[]";

    }else{

        out << "[ ";
        node = _head;
        out << node->item();
        while(node->has_next()){
            node = node->next();
            out << " " << node->item();
        }
        out << " ]";

    }
    //
}

template<class T>
void SList<T>::set_current(T const& new_v)
{
    assert(!is_empty());
    //TODO
    _current->set_item(new_v);
    //
    assert(current()==new_v);
}


template<class T>
void SList<T>::push_front(T const& new_it)
{
#ifndef NDEBUG
    size_t old_size = size();
#endif
    //TODO
    //Remeber to update current if current is in the head.
    typename SNode<T>::Ref node = SNode<T>::create(new_it, _head);
    _size++;

    if(_current == _head || _current == nullptr)
        _current = node;

    _head = node;

    //
    assert(front()==new_it);
    assert(size() == (old_size+1));
}

template<class T>
void SList<T>::insert(T const& new_it)
{
#ifndef NDEBUG
    bool old_is_empty = is_empty();
    size_t old_size = size();
    T old_item;
    if (!old_is_empty)
        old_item = current();
#endif
    //TODO

    _size++;
    if(is_empty()){
        _head = SNode<T>::create(new_it, _head);
        _current = _head;
    }else{
        _current->set_next(SNode<T>::create(new_it, _current->next()));
    }

    //
    assert(!old_is_empty || (front()==new_it && current()==new_it));
    assert(old_is_empty || (old_item == current() && has_next() && next()==new_it));
    assert(size()==(old_size+1));
}

template<class T>
void SList<T>::pop_front()
{
    assert(!is_empty());
#ifndef NDEBUG
    size_t old_size = size();
    auto old_head_next = head()->next();
#endif
    //TODO
    if(_current == _head)
        _current = _head->next();

    _head = _head->next();
    _size--;

    //
    assert(is_empty() || head() == old_head_next);
    assert(size() == (old_size-1));
}


template<class T>
void SList<T>::remove()
{
    assert(!is_empty());
#ifndef NDEBUG
    size_t old_size = size();
    bool old_has_next = has_next();
    T old_next;
    if (has_next())
        old_next=next();
#endif
    //TODO
    //Case 1: current is the head.

    //Case 2: remove in a middle position.

    //Case 3: remove the last element.
    //Remenber to locate previous of prev_.

    if(_current == _head){

        pop_front();

    }else{
        locatePrev();

        if(has_next()){

            goto_next();
            _prev->set_next(_current);

        }else{

            _current = _prev;
            locatePrev();
            _current->set_next(nullptr);

        }

        _size--;
    }

    //
    assert(!old_has_next || current()==old_next);
    assert(size() == (old_size-1));
}

template<class T>
void SList<T>::locatePrev()
{
    _prev = _head;

    while(_prev->next() != _current && _current != _head)
        _prev = _prev->next();

}

template<class T>
void SList<T>::goto_next()
{
    assert(has_next());
#ifndef NDEBUG
    auto old_next = next();
#endif
    //TODO
    _current = _current->next();
    //
    assert(current()==old_next);
}

template<class T>
void SList<T>::goto_first()
{
    assert(!is_empty());
    //TODO
    _current = _head;
    //
    assert(current()==front());
}

template<class T>
bool SList<T>::find(T const& it)
{
    assert(!is_empty());
    bool found = false;
    //TODO
    goto_first();

    if(_head->item() == it)
        found = true;

    while(has_next() && !found){
        if(_current->item() == it){
            found = true;
        }else{
            goto_next();
        }
    }

    if(_current->item() == it && !has_next())
        found = true;

    //
    assert(!found || current()==it);
    assert(found || !has_next());
    return found;
}

template<class T>
bool SList<T>::find_next(T const& it)
{
    assert(has_next());
    bool found = false;
    //TODO
    goto_next();
    while(has_next() && !found){
        if(_current->item() == it){
            found = true;
        }else{
            goto_next();
        }
    }

    if(_current->item() == it && !has_next())
        found = true;

    //
    assert(!found || current()==it);
    assert(found || !has_next());
    return found;
}

