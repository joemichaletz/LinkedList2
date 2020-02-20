#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    this->count = 0;
}

void LinkedList::addFront(int payload)
{
    Node* n = new Node(payload); //Node n = new Node(payload); in Java

    //if list is currently empty
    if(!this->head) //tests the pointer count of this->head (boils down to 0 if nothing points here)
                        //Java: this.head == null
    {
        this->head = n;
    }
    else //list has at least 1 thing in it
    {
        n->setNextNode(this->head);
        this->head = n;
    }
    this->count++;
}

int LinkedList::getFront()
{
    return this->head->getPayload();
}

int LinkedList::removeFront()
{
    Node* nodeToReturn = this->head;
    this->head = this->head->getNextNode();
    int val = nodeToReturn->getPayload();
    delete nodeToReturn;
    this->count--;
    return val;
}

Node* LinkedList::runToEndOfList()
{
    Node* currNode = this->head;
    while(currNode->getNextNode()) //returns true when currNode has a next node
    {
        currNode = currNode->getNextNode(); // (*currNode).getNextNode()
    }
    return currNode;
}

void LinkedList::addEnd(int payload)
{
    if(!this->head)
    {
        this->addFront(payload);
    }
    else
    {
        //we have at least one thing in our list
        //traverse to end of list and connect new node

        Node* n = new Node(payload);
        Node* currNode = this->runToEndOfList();
        //currNode now points to the end of our list (ie the last Node)
        currNode->setNextNode(n);
        this->count++;

    } 
}

int LinkedList::getEnd()
{
    Node* currNode = this->runToEndOfList();
    //currnode points to the end of the list
    return currNode->getPayload();
}


int LinkedList::removeEnd()
{
    //we are assuming the list has at least one element in it for now
    //is this a list with a single element in it?
    if(!this->head->getNextNode())
    {
        return this->removeFront();
    }
    else
    {
        //we have at least two elements in our list
        Node* theLastGuy = this->runToEndOfList();
        Node* theGuyBeforeTheLastGuy = this->head;
        while(theGuyBeforeTheLastGuy->getNextNode() != theLastGuy)
        {
            theGuyBeforeTheLastGuy = theGuyBeforeTheLastGuy->getNextNode();
        }
        //theGuyBeforeTheLastGuy now points to the Node right before theLastGuy
        theGuyBeforeTheLastGuy->setNextNode(0);
        int valueToReturn = theLastGuy->getPayload();
        delete theLastGuy;
        this->count--;
        return valueToReturn;
    }
    
}

 void LinkedList::addAtIndex(int index, int payload)
 {
     if(index == 0)
     {
         this->addFront(payload);
     }
     else if(index == this->count)
     {
         this->addEnd(payload);
     }
     else
     {
         //we are placing somewhere in the middle
         Node* n = new Node(payload);
         Node* currNode = this->head;
         for(int i = 0; i < index-1; i++)
         {
             currNode = currNode -> getNextNode();
         }
         //currNode points to the node right before where N should be inserted
         n->setNextNode(currNode->getNextNode());
         currNode->setNextNode(n);
         this->count++;
     }
     
 }
    
int LinkedList::getIndex(int index)
{
    if(index == 0)
    {
        return this->getFront();
    }
    else if(index == this->count-1)
    {
        return this->getEnd();
    }
    else
    {
        Node* currNode = this->head; //gives us a second pointers to the front of the list
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode->getPayload();
    }
}
 
int LinkedList::removeIndex(int index)
{
    if(index == 0)
    {
        return this->removeFront();
    }
    else if(index == this->count-1)
    {
        return this->removeEnd();
    }
    else
    {
        Node* currNode = this->head;
        for(int i = 0; i < index-1; i++)
        {
            currNode = currNode->getNextNode();
        }
        Node* guy2Remove = currNode->getNextNode();
        currNode->setNextNode(guy2Remove->getNextNode());
        guy2Remove->setNextNode(0); //sets his next node to null
        
        int val2Return = guy2Remove->getPayload();
        delete guy2Remove;
        this->count--;
        return val2Return;
    }
    
}

void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode->getPayload() << "\n";
        currNode = currNode->getNextNode();
    }
}

void LinkedList::displayPointers()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode << "\n";
        currNode = currNode->getNextNode();
    }
}

void LinkedList::sort()
{
    Node* prevNode = this->head;
    Node* firstNode = prevNode->getNextNode();
    Node* secondNode = firstNode->getNextNode();
    for(int j = 0; j < this->count - j; j++)
        
        for(int i = 0; i < this->count - 1; i++)
        {
            if(!secondNode->getNextNode())
            {
                prevNode = this->head;
                firstNode = prevNode->getNextNode();
                secondNode = firstNode->getNextNode();
            }
            else if (firstNode->getPayload() > secondNode->getPayload())
            {
                Node* hold = 0;
                if(prevNode == this->head)
                {
                    hold = this->head->getNextNode();
                    prevNode->setNextNode(firstNode->getNextNode());
                    firstNode->setNextNode(secondNode->getNextNode());
                    secondNode->setNextNode(hold);
                }
                else
                {
                    hold = prevNode->getNextNode();
                    prevNode->setNextNode(firstNode->getNextNode());
                    firstNode->setNextNode(secondNode->getNextNode());
                    secondNode->setNextNode(hold);
                }
                prevNode = prevNode->getNextNode();
                firstNode = firstNode->getNextNode();
                secondNode = secondNode->getNextNode();
            }
            else
            {
                prevNode = prevNode->getNextNode();
                firstNode = firstNode->getNextNode();
                secondNode = secondNode->getNextNode();
            }
        }
}
