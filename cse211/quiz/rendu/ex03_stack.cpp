


#include <ctime>
class Stack {
    public:
        Stack();
        Stack(const Stack& other);     // deep copy
        ~Stack();                      // free every node
        Stack& operator=(const Stack&) = delete;

        bool isEmpty() const;
        int  size() const;
        void push(int value);
        bool pop();                    // false if empty
        bool pop(int& value);          // false if empty, value unchanged
        bool getTop(int& value) const; // false if empty, value unchanged
    private:
            struct StackNode {
                int item;
                StackNode* next;
            };
            StackNode* topPtr;   // listenin başı = stack'in tepesi
    };


    bool Stack::isEmpty() const
    {
    	if(topPtr == nullptr)
     		return true;
     	return false;
    }

    int Stack::size() const
    {
		StackNode *it = topPtr;
		int counter = 0;
		while(it != nullptr)
		{
			counter++;
			it = it->next;
		}
		return counter;
    }

    void Stack::push(int value)
    {
    	StackNode *n = new StackNode;
		n->next = topPtr->next;		
     	topPtr->next = n;
      	n->item = value;
    }

    bool Stack::pop()
    {
		if(isEmpty())
			return false;
     	StackNode *temp = topPtr;
      	topPtr = topPtr->next;
       	delete temp;
        return true;
    }

    bool Stack::pop(int &value)
    {
		if(isEmpty())
			return false;
		value = topPtr->item;
		return pop();
    }

    bool Stack::getTop(int &value) const
    {
    	if(isEmpty())
     		return false;
     	value = this->topPtr->item;
     	return true;
    }