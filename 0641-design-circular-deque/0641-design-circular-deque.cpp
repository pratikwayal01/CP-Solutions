class MyCircularDeque {
private:
    int *deque;       
    int front, rear;  
    int size;         
    int capacity;     

public:
    
    MyCircularDeque(int k) {
        capacity = k;
        deque = new int[k];  
        front = 0;           
        rear = 0;            
        size = 0;            
    }

    
    bool insertFront(int value) {
        if (isFull()) return false;  
        front = (front - 1 + capacity) % capacity;  
        deque[front] = value;  
        size++;
        return true;
    }

    
    bool insertLast(int value) {
        if (isFull()) return false;  
        deque[rear] = value;  
        rear = (rear + 1) % capacity;  
        size++;
        return true;
    }

    
    bool deleteFront() {
        if (isEmpty()) return false;  
        front = (front + 1) % capacity;  
        size--;
        return true;
    }

    
    bool deleteLast() {
        if (isEmpty()) return false;  
        rear = (rear - 1 + capacity) % capacity;  
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];  
    }


    int getRear() {
        if (isEmpty()) return -1;
        return deque[(rear - 1 + capacity) % capacity];  
    }

    
    bool isEmpty() {
        return size == 0;
    }

    
    bool isFull() {
        return size == capacity;
    }
};
