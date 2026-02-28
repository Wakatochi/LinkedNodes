#include "Node.h"

Node::Node()
 : m_prev(nullptr)
 , m_next(nullptr)
 , m_value(0)
{
}

Node::Node(int value)
 : m_prev(nullptr)
 , m_next(nullptr)
 , m_value(value)
{
}

Node::~Node()
{
   m_prev = nullptr;
   m_next = nullptr;
}

void
Node::setValue(int value)
{
   value = value;
}

void
Node::setNext(Node* node)
{
   m_next = node;
}

void Node::setPrev(Node* node)
{
   m_prev = node;
}

int
Node::getValue() const
{
   return m_value;
}

Node*
Node::getNext()
{
   return m_next;
}

Node*
Node::getPrev()
{
   return m_prev;
}
