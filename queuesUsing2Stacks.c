struct Stack{
    int *arr;
    int size;
    int capacity;
};
bool isEmpty(struct Stack* s){
    if(s->size==0) return true;
    return false; 
}
void push(struct Stack* s,int x){
    if(s->size >= s->capacity){
        s->capacity*=2;
        int *temp=malloc(s->capacity*sizeof(int));
        for(int i=0;i<s->size;i++){
            temp[i]=s->arr[i];
        }
        free(s->arr);
        s->arr=temp;
    }
    s->arr[s->size++]=x;
}
int pop(struct Stack *s){
    if(isEmpty(s)) return -1;
    return s->arr[--s->size];
}
void initialize(struct Stack *s){
    s->size=0;
    s->capacity=1;
    s->arr=malloc(sizeof(int));
}
void empty(struct Stack * s){
    s->size=0;
}
int top(struct Stack * s){
    if(s->size==0) return -1;
    return s->arr[s->size-1];
}


typedef struct {
    struct Stack *s1;
    struct Stack *s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue * q=malloc(sizeof(MyQueue));
    q->s1=malloc(sizeof(struct Stack));
    q->s2=malloc(sizeof(struct Stack));
    initialize(q->s1);
    initialize(q->s2);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    push(obj->s1,x);
}

int myQueuePop(MyQueue* obj) {
    while(!isEmpty(obj->s1)){
        push(obj->s2,pop(obj->s1));
    }
    int ans=pop(obj->s2);
    while(!isEmpty(obj->s2)){
        push(obj->s1,pop(obj->s2));
    }
    return ans;
}

int myQueuePeek(MyQueue* obj) {
    while(!isEmpty(obj->s1)){
        push(obj->s2,pop(obj->s1));
    }
    int ans=top(obj->s2);
    while(!isEmpty(obj->s2)){
        push(obj->s1,pop(obj->s2));
    }
    return ans;
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
