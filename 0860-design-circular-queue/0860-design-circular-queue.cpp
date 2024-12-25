class MyCircularQueue {
public:
    int f; // front back size
    int b;
    int s;
    int c ; // capacity
    vector<int> arr;
    MyCircularQueue(int k) {
        // int k = size of which user wants to create queue of
        f=0;
        b=0;
        s=0;
        c=k;
        vector<int> v(k);
        arr=v;
    }
    
    bool enQueue(int val) { // push back
        if(s==c) return false;
        arr[b]= val;
        b++;
        if(b==c) b=0;
        s++;
        return true;
    }
    
    bool deQueue() { //pop front
        if(s==0) return false;
        f++;
        if(f==c) f=0;
        s--;
        return true;
    }
    
    int Front() {
        if(s==0) return -1;
        return arr[f];
    }
    
    int Rear() { // back
        if(s==0) return -1;
        if(b==0) return arr[c-1] ; // last element
        return arr[b-1];
    }
    
    bool isEmpty() {
        if(s==0) return true;
        else return false;
    }
    
    bool isFull() { // overflow condition
        if(s==c) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */