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
    if(s->size>=s->capacity){
        s->capacity*=2;
        int *temp=malloc(s->capacity*sizeof(int));
        for(int i=0;i<s->size;i++){
            temp[i]=s->arr[i];
        }
        s->arr=temp;
    }
    s->arr[s->size++]=x;
}
int pop(struct Stack *s){
    if(isEmpty(s)) return -1;
    return s->arr[s->size--];
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
    return s->arr[s->size-1];
}
int max(int a,int b){
    if(a>b) return a;
    return b;
}
int longestValidParentheses(char* s) {
    struct Stack *stack=malloc(sizeof(struct Stack));
  
    int n=strlen(s);
      int *arr=calloc(n,sizeof(int));
    initialize(stack);
    for(int i=0;i<n;i++){
        if(s[i]=='('){
             push(stack,i);
        }
        else{
            if(!isEmpty(stack)){
            if(s[top(stack)]=='('){
                pop(stack);
            }
            else{
                push(stack,i);
            }
            }
            else{
                push(stack,i);
            }
        }
    }
    int ans=0;
    int a=0;
    int b=n-1;
    if(isEmpty(stack)) return n;
    while(!isEmpty(stack)){
        a=top(stack);
        ans=max(b-a,ans);
        pop(stack);
        b=a-1;
    }
    a=-1;
    ans=max(b-a,ans);
    return ans;
}
