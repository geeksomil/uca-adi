typedef struct {
    int size;
    int capacity;
    int *arr;
    int start;
    int end;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj=malloc(sizeof(MyCircularQueue));
    obj->size=0;
    obj->capacity=k;
    obj->start=0;
    obj->end=-1;
    obj->arr=malloc(sizeof(int)*k);
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->size<obj->capacity){
        obj->arr[(obj->end+1)%(obj->capacity)]=value;
        obj->size++;
        obj->end=(obj->end+1)%obj->capacity;
        return true;
    }
    return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->size==0) return false;
    obj->start=(obj->start+1)%obj->capacity;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
     if(obj->size==0) return -1;
    return obj->arr[obj->start];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->size==0) return -1;
    return obj->arr[obj->end];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
   
    return obj->size==0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size==obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
