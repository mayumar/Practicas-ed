/**
 * @file trie.cpp
 *
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */

#include <cassert>
#include <sstream>
#include "trie.hpp"

Trie::Trie()
{
    //TODO
    root_ = nullptr;
    prefix_ = "";
    current_ = nullptr;
    //
    assert(is_empty());
}

Trie::Ref Trie::create()
{    
    return std::make_shared<Trie>();
}

Trie::Trie(TrieNode::Ref root_node, std::string const& pref)
{
    //TODO
    root_ = root_node;
    prefix_ = pref;
    current_ = nullptr;
    //
    assert(prefix() == pref);
}

Trie::Ref Trie::create(TrieNode::Ref root_node, std::string const& prefix)
{
    //We cannot use std::make_shared here
    //because the constructor is protected.
    typename Trie::Ref trie ( new Trie(root_node, prefix));
    return trie;
}

Trie::Ref Trie::create(std::istream& in) noexcept(false)
{
    Trie::Ref trie = nullptr;
    //TODO


    //
    return trie;
}

bool
Trie::is_empty() const
{
    bool ret_v=true;
    //TODO
    if(root_ != nullptr){
        ret_v = false;
    }
    //
    return ret_v;
}

std::string
Trie::prefix() const
{
    std::string ret_val = "";
    //TODO
    ret_val = prefix_;
    //
    return ret_val;
}

bool
Trie::is_key() const
{
    assert(!is_empty());
    bool ret_val = true;
    //TODO
    ret_val = root_->is_key();
    //
    return ret_val;
}


TrieNode::Ref
Trie::root() const
{
    TrieNode::Ref node = nullptr;
    //TODO
    node = root_;
    //
    return node;
}

bool
Trie::has(std::string const& k) const
{
    assert(!is_empty());
    bool found = false;
    //TODO
    //Hint: use find_node() to do this.
    //Remember: The Trie can have a prefix==k but does not store the key k.    
    auto node = find_node(k);
    found = (node!=nullptr && node->is_key());
    //
    return found;
}

static void
preorder_traversal(TrieNode::Ref node, std::string prefix,
                   std::vector<std::string> & keys)
{
    //TODO
    //Remember: node->is_key() means the prefix is a key too.

    //
}


void
Trie::retrieve(std::vector<std::string>& keys) const
{
    assert(!is_empty());
    //TODO
    //Remember add the subtrie's prefix to the retrieve keys.

    //
}

Trie::Ref
Trie::child(std::string const& pref) const
{
    assert(!is_empty());
    Trie::Ref ret_v = Trie::create();
    //TODO
    //Hint: use find_node() to do this.
    ret_v->root_ = find_node(prefix_+pref);

    if(ret_v->root_ != nullptr){
        ret_v->prefix_ = prefix_+pref;
    }

    //
    assert(ret_v != nullptr);
    return ret_v;
}

bool
Trie::current_exists() const
{
    assert(!is_empty());
    bool ret_val = false;
    //TODO
    if(current_ != nullptr){
        ret_val = true;
    }
    //
    return ret_val;
}

Trie::Ref
Trie::current() const
{
    assert(current_exists());
    Trie::Ref trie = nullptr;
    //TODO
    trie = current_;
    //
    return trie;
}

char
Trie::current_symbol() const
{
    assert(current_exists());
    char symbol = 0;
    //TODO

    symbol = current_->prefix_[prefix_.size()-1];

    //
    return symbol;
}

void
Trie::insert(std::string const& k)
{
    assert(k != "");
    //TODO

    if(is_empty()){
        root_ = TrieNode::create(false);
    }

    auto node = root_;

    for(int i = 0; i < k.size(); i++){
        if(node->has(k[i])){
            node = node->child(k[i]);
        }else{
            auto newNode = TrieNode::create(false);
            node->set_child(k[i], newNode);
            node = newNode;
        }
    }

    node->set_is_key_state(true);

    //
    assert(!is_empty());
    assert(has(k));
}

TrieNode::Ref
Trie::find_node(std::string const& pref) const
{
    assert(!is_empty());
    TrieNode::Ref node;
    //TODO
    //Remember: the prefix "" must return the trie's root node.
    node = root_;
    int i = 0;
    while(i<pref.size() && node!=nullptr){
        if(node->has(pref[i])){
            node = node->child(pref[i]);
            i++;
        }else{
            node = nullptr;
        }
    }
    //
    return node;
}

std::ostream&
Trie::fold(std::ostream& out) const
{
    //TODO



    //
    return out;
}

bool
Trie::find_symbol(char symbol)
{
    assert(!is_empty());
    bool found = false;
    //TODO
    auto node = find_node(prefix_+symbol);

    if(node != nullptr){
        found = true;
        current_->root_ = node;
        current_->prefix_ = prefix_+symbol;
    }

    //
    assert(!found || current_exists());
    assert(found || !current_exists());
    assert(!current_exists() || current_symbol()==symbol);
    return found;
}

void
Trie::goto_first_symbol()
{
    assert(!is_empty());
    //TODO
    root_->goto_first_child();
    if(root_->current_exists()){
        current_ = Trie::create(root_->current_node(), prefix_+root_->current_symbol());
    }
    //
    assert(!current_exists() ||
           current()->prefix()==prefix()+current_symbol());
}

void
Trie::goto_next_symbol()
{
    assert(current_exists());
    //TODO

    //
}
