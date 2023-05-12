/**
 * @file graph_utils_imp.hpp
 *
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once

#include <string>

#include "wgraph.hpp"

/** GraphNode implementation **/

template<class T>
WNode<T>::WNode(size_t label, T const& v)
{
    //TODO

    //
    assert(item()==v);
    assert(!is_visited());
}

template<class T>
T WNode<T>::item() const
{
    T ret_v;
    //TODO

    //
    return ret_v;
}

template<class T>
size_t  WNode<T>::label() const
{
    size_t ret_v = 0;
    //TODO

    //
    return ret_v;
}

template<class T>
bool  WNode<T>::is_visited() const
{
    bool ret_v = false;
    //TODO

    //
    return ret_v;
}

template<class T>
void WNode<T>::set_item(T const& v)
{
    //TODO

    //
    assert(item()==v);
}


template<class T>
void WNode<T>::set_visited(bool new_st)
{
    //TODO

    //
    assert(new_st || !is_visited());
    assert(!new_st || is_visited());
}

/** GraphEdge implementation **/

template<class T, class E>
WEdge<T,E>::WEdge(NodeRef u, NodeRef v, FMatrix::Ref wmat)
{
    //TODO

    //
}

template<class T, class E>
E WEdge<T,E>::weight() const
{
    E ret_val=std::numeric_limits<float>::infinity();
    //TODO

    //
    return ret_val;
}

template<class T, class E>
bool WEdge<T,E>::has(NodeRef const& n) const
{
    bool ret_val = false;
    //TODO

    //
    return ret_val;
}

template<class T, class E>
typename WEdge<T,E>::NodeRef WEdge<T,E>::other(NodeRef const& n) const
{
    assert(has(n));
    NodeRef ret_val;
    //TODO


    //
    return ret_val;
}

template<class T, class E>
typename WEdge<T,E>::NodeRef WEdge<T,E>::first() const
{
    NodeRef ret_val;
    //TODO

    //
    return ret_val;
}

template<class T, class E>
typename WEdge<T,E>::NodeRef WEdge<T,E>::second() const
{
    NodeRef ret_val;
    //TODO

    //
    return ret_val;
}

template<class T, class E>
void WEdge<T,E>::set_weight(E const& v)
{
    //TODO

    //
    assert(weight()==v);
}


/** WGraph implementation **/
template<class T>
WGraph<T>::WGraph (size_t capacity, float default_weight)
{
    assert(capacity>0);

    //TODO
    //Remember: this a weighted graph, so all the nodes are connected with
    //          infinite weight by default.

    //

    assert(is_empty());
    assert(!has_current_node());
    assert(!has_current_edge());
}

template<class T>
bool WGraph<T>::is_empty() const
{
    bool ret_v = true;
    //TODO
    
    //
    assert(!ret_v || size()==0);
    return ret_v;
}

template<class T>
bool WGraph<T>::is_full() const
{
    bool ret_v = true;
    //TODO

    //
    assert(!ret_v || size()==capacity());
    return ret_v;
}

template<class T>
size_t WGraph<T>::size() const
{
    size_t ret_v = 0;
    //TODO

    //
    return ret_v;
}

template<class T>
size_t WGraph<T>::capacity() const
{
    size_t ret_v = 0;
    //TODO

    //
    return ret_v;
}

template<class T>
bool WGraph<T>::has(NodeRef u) const
{
    assert (u != nullptr);
    bool ret_v = true;
    //TODO

    //
    assert(!ret_v || (u->label()<capacity() && node(u->label())==u));
    return ret_v;
}

template<class T>
bool WGraph<T>::are_adjacent (NodeRef u, NodeRef v) const
{
    assert( has(u) && has(v) );
    bool ret_v = false;
    //TODO
    //Remember: this a Weighted graph so a node u is adjacent to v if the
    //          edge's weight is less than infinite.
    // Hint: use std::numeric_limits<float> facet to get infinite as float value.

    //
    return ret_v;
}

template<class T>
bool WGraph<T>::has_current_node () const
{
    bool ret_v = false;
    //TODO
    //Hint: use attribute _size to mark "end".

    //
    return ret_v;
}

template<class T>
typename WGraph<T>::NodeRef WGraph<T>::current_node () const
{
    assert(has_current_node());
    NodeRef ret_v;
    //TODO

    //
    return ret_v;
}

template<class T>
bool WGraph<T>::has_current_edge () const
{
    bool ret_v = false;    
    //TODO
    //Remember: first it must exist a current node.
    //Hint: use value size() to mark "end".

    //
    assert(!ret_v || has_current_node());
    return ret_v;
}

template<class T>
float WGraph<T>::current_weight () const
{
    assert(has_current_edge());
    float ret_v = 0.0;
    //TODO

    //
    assert(ret_v<std::numeric_limits<float>::infinity());
    return ret_v;
}

template<class T>
FMatrix::Ref WGraph<T>::weight_matrix() const
{
    FMatrix::Ref mat;
    //TODO

    //
    return mat;
}

template<class T>
float WGraph<T>::weight(size_t u_label, size_t v_label) const
{
    assert(u_label<size());
    assert(v_label<size());
    float ret_v = 0.0;
    //TODO

    //
    assert(ret_v == weight(node(u_label), node(v_label)));
    return ret_v;
}

template<class T>
float WGraph<T>::weight (NodeRef u, NodeRef v) const
{
    assert(has(u));
    assert(has(v));
    float ret_v = 0.0;
    //TODO

    //
    return ret_v;
}

template<class T>
typename WGraph<T>::EdgeRef WGraph<T>::edge(NodeRef u, NodeRef v) const
{
    assert(has(u));
    assert(has(v));
    EdgeRef ret_v=nullptr;
    //TODO

    //
    assert(ret_v->first()==u);
    assert(ret_v->second()==v);
    assert(ret_v->weight()==weight(u, v));
    return ret_v;
}

template<class T>
typename WGraph<T>::EdgeRef WGraph<T>::edge(size_t u_label, size_t v_label) const
{
    assert(u_label<size());
    assert(v_label<size());
    EdgeRef ret_v=nullptr;
    //TODO
    //Hint: use the static method WEdge::create().

    //
    assert(ret_v->first()->label()==u_label);
    assert(ret_v->second()->label()==v_label);
    assert(ret_v->weight()==weight(u_label, v_label));
    return ret_v;
}

template<class T>
typename WGraph<T>::EdgeRef WGraph<T>::current_edge() const
{
    assert(has_current_edge());
    EdgeRef ret_v = nullptr;
    //TODO
    //Hint: use the static method WEdge::create().

    //
    assert(ret_v->first()==current_node() && ret_v->weight()<std::numeric_limits<float>::infinity());
    return ret_v;
}

template<class T>
typename WGraph<T>::NodeRef WGraph<T>::node(size_t label) const
{
    assert(label<size());
    NodeRef n;
    //TODO

    //
    return n;
}

template<class T>
void WGraph<T>::set_visited(bool state)
{
    //TODO
    // Remember: we only have visited flag in nodes, no one in edges.

    //
}

template<class T>
void WGraph<T>::goto_first_node()
{
    assert(!is_empty());
    //TODO
    //Remember: the edge's cursor must be initialized too.

    //
    assert(!has_current_edge()||current_edge()->first() == current_node());
    assert(!has_current_edge() ||
           current_weight()<std::numeric_limits<float>::infinity());
}

template<class T>
void WGraph<T>::goto_first_edge()
{
    assert(has_current_node());
    //TODO
    // Remember: we consider here edges with weight < infinite.
    

    //
    assert(!has_current_edge()||current_edge()->first() == current_node());
    assert(!has_current_edge() ||
           current_weight()<std::numeric_limits<float>::infinity());
}

template<class T>
void WGraph<T>::goto_next_node()
{
    assert(has_current_node());
    //TODO
    // Remember: you must update the edge cursor too.
    
    //
    assert(has_current_node() || !has_current_edge());
    assert(!has_current_edge() || (current_edge()->first() == current_node()));
    assert(!has_current_edge() ||
           current_weight()<std::numeric_limits<float>::infinity());
}

template<class T>
void WGraph<T>::goto_next_edge()
{
    assert(has_current_edge());
    //TODO
    // Remember: we consider here edges with weight < infinite.


    //
    assert(!has_current_edge() || current_edge()->first() == current_node());
    assert(!has_current_edge() ||
           current_weight()<std::numeric_limits<float>::infinity());
}

template<class T>
void WGraph<T>::goto_node(NodeRef u)
{
    assert(has(u));
    //TODO
    // Remember: update edge cursor too.

    //
    assert(!has_current_edge() || current_edge()->first()==u);
    assert(!has_current_edge() ||
           current_weight()<std::numeric_limits<float>::infinity());
}

template<class T>
void WGraph<T>::goto_edge(NodeRef u, NodeRef v)
{
    assert(has(u));
    assert(has(v));
    assert(weight(u, v) < std::numeric_limits<float>::infinity());
    //TODO
    //Remember: node and edge cursors must be initialized too.


    //
    assert(current_node()==u);
    assert(current_edge()->first()==u);
    assert(current_edge()->second()==v);
    assert(current_weight()==weight(u,v));
}

template<class T>
void WGraph<T>::goto_edge(EdgeRef e)
{
    assert(has(e->first()));
    assert(has(e->second()));
    assert(e->weight() < std::numeric_limits<float>::infinity());
    //TODO
    //Remember: node and edge cursors must be initialized too.


    //
    assert(current_node()==e->first());
    assert(current_edge()->second()==e->second());
    assert(current_weight()==e->weight());
}

template<class T>
typename WGraph<T>::NodeRef WGraph<T>::find_node(typename T::key_t const& key)
{
    assert(!is_empty());
    NodeRef ret_v = nullptr;
    //TODO
    // Remember: update node and edge cursors.
    // Remember: The item.key() is used to look for.
    

    //
    assert((ret_v==nullptr) || (has_current_node() && current_node()==ret_v));
    assert(!has_current_node() || current_node()->item()==key);
    assert(!has_current_edge() || current_edge()->first()==current_node());
    return ret_v;
}

template<class T>
typename WGraph<T>::NodeRef WGraph<T>::find_next_node(typename T::key_t const& key)
{
    assert(!is_empty());
    NodeRef ret_v = nullptr;
    //TODO
    // Remember: update node and edge cursors.
    // Remember: The item.key() is used to look for.

    //
    assert((ret_v==nullptr) || (has_current_node() && current_node()==ret_v));
    assert(!has_current_node() || current_node()->item()==key);
    assert(!has_current_edge() || current_edge()->first()==current_node());
    return ret_v;
}

template<class T>
void WGraph<T>::set_current_weight(float new_w)
{
    assert(has_current_edge());
    //TODO
    // Remember: set infinite as new weight invalidates edge_cursor.

    //
    assert(new_w < std::numeric_limits<float>::infinity() || !has_current_edge());
}

template<class T>
void WGraph<T>::set_weight(size_t u_label, size_t v_label, float new_w)
{
    assert(u_label<size());
    assert(v_label<size());
    // TODO
    // Remember: set infinite as new weight could invalidate the edge cursor if it is currently points to this edge.

    //
    assert(new_w == weight(u_label, v_label));
    assert(!has_current_edge() || current_weight()<std::numeric_limits<float>::infinity());
}

template<class T>
void WGraph<T>::set_weight(NodeRef u, NodeRef v, float new_w)
{
    assert(has(u));
    assert(has(v));
    //TODO
    // Remember: set infinite as new weight could invalidate the edge cursor if it is currently points to this edge.

    //
    assert(weight(u, v)==new_w);
    assert(!has_current_edge() || current_weight()<std::numeric_limits<float>::infinity());
}

template<class T>
void WGraph<T>::add_node(T const& v)
{
    assert(! is_full());
    //TODO
    // Remember: update node and edge cursors.

    //
    assert(has_current_node());
    assert(!has_current_edge());
}

template <class T>
std::ostream&
WGraph<T>::fold(std::ostream& out) const
{
    //TODO
    //Hint: the Matrix template has a fold method.

    //
    return out;
}

template <class T>
WGraph<T>::WGraph (std::istream& input) noexcept(false)
{
    //TODO
    //Remember: capacity is the max number of nodes that the graph could have.
    //          size is the current number of nodes (size <= capacity).
    //Hint: The Matrix template has a unfold method.

    //
    assert(!has_current_node());
    assert(!has_current_edge());
}

template <class T>
typename WGraph<T>::Ref WGraph<T>::create (std::istream & input)
{
    return std::make_shared<WGraph<T>>(input);

}

template<class T>
typename WGraph<T>::Ref create_wgraph(std::istream &in) noexcept(false)
{
    assert(in);
    typename WGraph<T>::Ref graph = nullptr; //The returned graph.

    //TODO    
    //Remember: Throw std::runtime_error("Wrong graph") when detecting a wrong
    //          input format.
    //Remember: key_t type is used to give the edge's ends.

    //TODO
    //First: Determine if it is directed or undirected.

    //

    //TODO
    //Second: get the number of nodes and create a wgraph with this capacity.

    //

    //TODO
    //Third: load the N T data items and adding the nodes.

    //

    //TODO
    //Fourth: load the number of edges.

    //

    //TODO
    //Fifth: load the N edges.
    //Remember: Use T::key_t type to load the edge's ends.
    //Remember: if the input graph is UNDIRECTED we simulated this with a WGraph
    //          duplicating each input edge (u,v) making too the (v,u) edge with same weight
    //          with the same weight.


    //

    return graph;
}

