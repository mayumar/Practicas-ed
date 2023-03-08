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

    //
    assert(!has_next());
}

template <class T>
SNode<T>::SNode (T const& it, SNode<T>::Ref& next)
{
    //TODO

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

    //
    return it;
}

template <class T>
bool SNode<T>::has_next() const
{
    bool has = false;
    //TODO

    //
    return has;
}

template <class T>
typename SNode<T>::Ref SNode<T>::next() const
{
    SNode<T>::Ref n;
    //TODO

    //
    return n;
}

template <class T>
void SNode<T>::set_item(const T& new_it)
{
    //TODO

    //
    assert(item()==new_it);
}

template <class T>
void SNode<T>::set_next(SNode<T>::Ref n)
{
    //TODO

    //
    assert(n == next());
}

template<class T>
SList<T>::SList ()
{
    //TODO



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

    //TODO
    //Hint: use std::istringstream to convert from "string" to template
    // parameter T type.
    // Throw std::runtime_error("Wrong input format.") exception when an input
    // format error was found.



    //
    return list;
}

template<class T>
bool SList<T>::is_empty () const
{
    bool ret_val = true;
    //TODO

    //
    return ret_val;
}

template<class T>
size_t SList<T>::size () const
{
    size_t ret_val = 0;
    //TODO

    //
    return ret_val;
}

template<class T>
T SList<T>::front() const
{
    assert(!is_empty());
    T f;
    //TODO

    //
    return f;
}

template<class T>
T SList<T>::current() const
{    
    assert(! is_empty());
    T c;
    //TODO

    //
    return c;
}

template<class T>
bool SList<T>::has_next() const
{
    assert(!is_empty());
    bool ret_val = false;
    //TODO

    //
    return ret_val;
}

template<class T>
T SList<T>::next() const
{
    assert(has_next());
    T ret_val = false;
    //TODO

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

    //
    return found;
}

template<class T>
void SList<T>::fold(std::ostream& out) const
{
    //TODO

    //
}

template<class T>
void SList<T>::set_current(T const& new_v)
{
    assert(!is_empty());
    //TODO

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



    //
    assert(!old_has_next || current()==old_next);
    assert(size() == (old_size-1));
}

template<class T>
void SList<T>::goto_next()
{
    assert(has_next());
#ifndef NDEBUG
    auto old_next = next();
#endif
    //TODO

    //
    assert(current()==old_next);
}

template<class T>
void SList<T>::goto_first()
{
    assert(!is_empty());
    //TODO

    //
    assert(current()==front());
}

template<class T>
bool SList<T>::find(T const& it)
{
    assert(!is_empty());
    bool found = false;
    //TODO

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

    //
    assert(!found || current()==it);
    assert(found || !has_next());
    return found;
}

