#ifndef NODE_H
#define NODE_H

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
