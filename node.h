#ifndef NODE_H
#define NODE_H

/// <summary>
/// Node class, self-referential.
/// Contains Data and pointers to next and previous.
/// </summary>
class Node
{
   public:
      Node();
      Node(int value);
      ~Node();

      void setValue(int value);
      void setNext(Node* node);
      void setPrev(Node* node);

      int getValue() const;
      Node* getNext();
      Node* getPrev();

   private:
      Node* m_prev;
      Node* m_next;
      int m_value;
};

#endif
