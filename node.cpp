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
   if(m_prev != nullptr)
   {
      delete m_prev;
   }

   if(m_next != nullptr)
   {
      delete m_next;
   }
}

int
Node::getValue() const
{
   return m_value;
}

void
Node::setNext(Node* node)
{
   m_next = node;
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

void
Node::setValue(int value)
{
   value = value;
}
