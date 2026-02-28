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

      int getValue() const;

      void setNext(Node* node);
      Node* getNext();
      Node* getPrev();

      void setValue(int value);

   private:
      Node* m_prev;
      Node* m_next;
      int m_value;
};

#endif
