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
    item_ = v;
    label_ = label;
    visited_ = false;
    //
    assert(item()==v);
    assert(!is_visited());
}

template<class T>
T WNode<T>::item() const
{
    T ret_v;
    //TODO
    ret_v = item_;
    //
    return ret_v;
}

template<class T>
size_t  WNode<T>::label() const
{
    size_t ret_v = 0;
    //TODO
    ret_v = label_;
    //
    return ret_v;
}

template<class T>
bool  WNode<T>::is_visited() const
{
    bool ret_v = false;
    //TODO
    ret_v = visited_;
    //
    return ret_v;
}

template<class T>
void WNode<T>::set_item(T const& v)
{
    //TODO
    item_ = v;
    //
    assert(item()==v);
}


template<class T>
void WNode<T>::set_visited(bool new_st)
{
    //TODO
    visited_ = new_st;
    //
    assert(new_st || !is_visited());
    assert(!new_st || is_visited());
}

/** GraphEdge implementation **/

template<class T, class E>
WEdge<T,E>::WEdge(NodeRef u, NodeRef v, FMatrix::Ref wmat)
{
    //TODO
    first_ = u;
    second_ = v;
    wmatrix_ = wmat;
    weight_ = std::numeric_limits<float>::infinity();
    //
}

template<class T, class E>
E WEdge<T,E>::weight() const
{
    E ret_val=std::numeric_limits<float>::infinity();
    //TODO
    ret_val = weight_;
    //
    return ret_val;
}

template<class T, class E>
bool WEdge<T,E>::has(NodeRef const& n) const
{
    bool ret_val = false;
    //TODO

    if(n == first_){
        return true;
    }else if(n == second_){
        return true;
    }

    //
    return ret_val;
}

template<class T, class E>
typename WEdge<T,E>::NodeRef WEdge<T,E>::other(NodeRef const& n) const
{
    assert(has(n));
    NodeRef ret_val;
    //TODO

    (n == first_) ? ret_val = second_ : ret_val = first_;

    //
    return ret_val;
}

template<class T, class E>
typename WEdge<T,E>::NodeRef WEdge<T,E>::first() const
{
    NodeRef ret_val;
    //TODO
    ret_val = first_;
    //
    return ret_val;
}

template<class T, class E>
typename WEdge<T,E>::NodeRef WEdge<T,E>::second() const
{
    NodeRef ret_val;
    //TODO
    ret_val = second_;
    //
    return ret_val;
}

template<class T, class E>
void WEdge<T,E>::set_weight(E const& v)
{
    //TODO
    weight_ = v;
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

    edges_ = FMatrix::create(capacity,capacity,default_weight);
    nodes_ = std::vector<NodeRef>();
    currnode_ = capacity;
    curredge_ = capacity;
    capacity_ = capacity;

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
    ret_v = nodes_.empty();
    //
    assert(!ret_v || size()==0);
    return ret_v;
}

template<class T>
bool WGraph<T>::is_full() const
{
    bool ret_v = true;
    //TODO

    ret_v = (nodes_.size() == capacity_);

    //
    assert(!ret_v || size()==capacity());
    return ret_v;
}

template<class T>
size_t WGraph<T>::size() const
{
    size_t ret_v = 0;
    //TODO

    ret_v = nodes_.size();

    //
    return ret_v;
}

template<class T>
size_t WGraph<T>::capacity() const
{
    size_t ret_v = 0;
    //TODO
    ret_v = capacity_;
    //
    return ret_v;
}

template<class T>
bool WGraph<T>::has(NodeRef u) const
{
    assert (u != nullptr);
    bool ret_v = true;
    //TODO

    ret_v = (std::find(nodes_.begin(), nodes_.end(), u) != nodes_.end());

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

    if(edges_->get(u, v) < std::numeric_limits<float>::infinity()){
        return true;
    }else if(edges_->get(v, u) < std::numeric_limits<float>::infinity()){
        return true;
    }

    //
    return ret_v;
}

template<class T>
bool WGraph<T>::has_current_node () const
{
    bool ret_v = false;
    //TODO
    //Hint: use attribute _size to mark "end".
    ret_v = !(currnode_ == capacity_);
    //
    return ret_v;
}

template<class T>
typename WGraph<T>::NodeRef WGraph<T>::current_node () const
{
    assert(has_current_node());
    NodeRef ret_v;
    //TODO
    ret_v = nodes_[currnode_];
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
    if(has_current_node()){
        ret_v = !(curredge_ == capacity_);
    }
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
    ret_v = edges_->get(currnode_,curredge_);
    //
    assert(ret_v<std::numeric_limits<float>::infinity());
    return ret_v;
}

template<class T>
FMatrix::Ref WGraph<T>::weight_matrix() const
{
    FMatrix::Ref mat;
    //TODO
    mat = edges_;
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
    ret_v = edges_->get(u_label, v_label);
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
    ret_v = edges_->get(u->label(), v->label());
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

    ret_v = WEdge<T,float>::create(u, v, edges_);

    ret_v->set_weight(weight(u, v));

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

    ret_v = WEdge<T,float>::create(nodes_[u_label], nodes_[v_label], edges_);

    ret_v->set_weight(weight(u_label, v_label))

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

    ret_v = WEdge<T,float>::create(nodes_[currnode_], nodes_[curredge_], edges_);

    ret_v->set_weight(current_weight());

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
    n = nodes_[label];
    //
    return n;
}

template<class T>
void WGraph<T>::set_visited(bool state)
{
    //TODO
    // Remember: we only have visited flag in nodes, no one in edges.
    for(size_t i = 0; i < nodes_.size(); i++){
        nodes_[i]->set_visited(state);
    }
    //
}

template<class T>
void WGraph<T>::goto_first_node()
{
    assert(!is_empty());
    //TODO
    //Remember: the edge's cursor must be initialized too.

    currnode_ = 0;
    curredge_ = 0;

    while(curredge_<capacity_ && !(edges_->get(currnode_,curredge_)<std::numeric_limits<float>::infinity())){
        curredge_++;
    }

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

    curredge_ = 0;

    while(curredge_<capacity_ && !(edges_->get(currnode_,curredge_)<std::numeric_limits<float>::infinity())){
        curredge_++;
    }

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
    
    currnode_++;

    curredge_ = 0;

    if(has_current_node()){
        while(curredge_<capacity_ && !(edges_->get(currnode_,curredge_)<std::numeric_limits<float>::infinity())){
            curredge_++;
        }
    }else{
        curredge_ = capacity_;
    }

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

    curredge_++;

    while(curredge_<capacity_ && !(edges_->get(currnode_,curredge_)<std::numeric_limits<float>::infinity())){
        curredge_++;
    }

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

    currnode_ = u->label();

    curredge_ = 0;

    while(curredge_<capacity_ && !(edges_->get(currnode_,curredge_)<std::numeric_limits<float>::infinity())){
        curredge_++;
    }

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

    currnode_ = u->label();
    curredge_ = v->label();

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

    currnode_ = e->first()->label();
    curredge_ = e->second()->label();

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

    bool stop = false;

    currnode_ = 0;

    while(currnode_ < nodes_.size() && !stop){
        if(nodes_[currnode_]->item().key() == key){
            stop = true;
            ret_v = current_node();
        }else{
            currnode_++;
        }
    }

    goto_first_edge();

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

    bool stop = false;

    while(currnode_ < nodes_.size() && !stop){
        if(nodes_[currnode_]->item() == key){
            stop = true;
            ret_v = current_node();
        }else{
            currnode_++;
        }
    }

    goto_first_edge();

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
    edges_->set(currnode_, curredge_, new_w);
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
    edges_->set(u_label, v_label, new_w);
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
    edges_->set(u->label(), v->label(), new_w);
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

    NodeRef node = WNode<T>::create(nodes_.size(), v);

    nodes_.push_back(node);

    currnode_ = node->label();

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

    if(is_empty()){
        out << "[]";
    }else{
        out << "[ ";
        out << capacity_;
        out << " ";
        out << nodes_.size();
        out << " ";

        for(size_t i = 0; i < nodes_.size(); i++){
            out << nodes_[i]->item() << " ";
        }

        edges_->fold(out);

        out << " ]";
    }

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

    std::string token;

    input >> token;

    if(token == "["){
        input >> token;

        capacity_ = std::stoi(token);

        currnode_ = capacity_;
        curredge_ = capacity_;

        input >> token;

        size_t size = std::stoi(token);

        nodes_ = std::vector<NodeRef>();

        for(size_t i = 0; i < size; i++){
            input >> token;

            std::istringstream convert(token);

            T new_t;

            convert >> new_t;

            NodeRef node = WNode<T>::create(nodes_.size(), new_t);

            nodes_.push_back(node);

        }

        edges_ = FMatrix::create(input);

        input >> token;

    }

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

    std::string token;

    //TODO
    //First: Determine if it is directed or undirected.

    in >> token;

    std::string dir = token;

    //

    //TODO
    //Second: get the number of nodes and create a wgraph with this capacity.

    in >> token;

    size_t capacity = std::stoi(token);

    graph = WGraph<T>::create(capacity);

    //

    //TODO
    //Third: load the N T data items and adding the nodes.

    T new_t;

    in.get();
    for(size_t i = 0; i < capacity; i++){
        getline(in, token);

        std::istringstream convert(token);
        convert >> new_t;

        graph->add_node(new_t);
    }

    //

    //TODO
    //Fourth: load the number of edges.

    getline(in, token);

    size_t nedges = std::stoi(token);

    //

    //TODO
    //Fifth: load the N edges.
    //Remember: Use T::key_t type to load the edge's ends.
    //Remember: if the input graph is UNDIRECTED we simulated this with a WGraph
    //          duplicating each input edge (u,v) making too the (v,u) edge with same weight
    //          with the same weight.

    if(dir == "DIRECTED"){

        for(size_t i = 0; i < nedges; i++){
            T new_t;
            typename WNode<T>::Ref u;
            typename WNode<T>::Ref v;
            size_t w;

            in >> token;

            std::istringstream convert1(token);
            convert1 >> new_t;

            u = graph->find_node(new_t.key());

            in >> token;

            std::istringstream convert2(token);
            convert2 >> new_t;

            v = graph->find_node(new_t.key());

            in >> token;

            w = std::stoi(token);

            graph->set_weight(u,v,w);
        }

    }else if(dir == "UNDIRECTED"){

        for(size_t i = 0; i < nedges; i++){
            T new_t;
            typename WNode<T>::Ref u;
            typename WNode<T>::Ref v;
            size_t w;

            in >> token;

            std::istringstream convert1(token);
            convert1 >> new_t;

            u = graph->find_node(new_t.key());

            in >> token;

            std::istringstream convert2(token);
            convert2 >> new_t;

            v = graph->find_node(new_t.key());

            in >> token;

            w = std::stoi(token);

            graph->set_weight(u,v,w);
            graph->set_weight(v,u,w);
        }

    }else{
        throw std::runtime_error("Wrong graph");
    }

    //

    return graph;
}

