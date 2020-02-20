#ifndef Node_hpp
#define Node_hpp

class Node 
{
private:
    int payload;
    Node* nextNode; //Node nextNode - java treats this as a Node* automatically
    
public:
    Node(int payload);
    int getPayload();
    Node* getNextNode();
    void setNextNode(Node* n);
    
};
#endif /* Node_hpp */