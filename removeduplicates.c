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
bool cmp(const char *a,const char *b){
    return a[0]-b[0];
}
char* removeDuplicateLetters(char* s) {
    int n=strlen(s);
    struct Stack *stack=malloc(sizeof(struct Stack));
    initialize(stack);
    int *f=calloc(26,sizeof(int));
    bool *boolean=calloc(26,sizeof(bool));
    for(int i=0;i<n;i++){
        f[s[i]-'a']++;
    }
    for(int i=0;i<n;i++){
        if(isEmpty(stack)){
            boolean[s[i]-'a']=true;
            push(stack,s[i]);
        }
        else
          {
            if(boolean[s[i]-'a']==true) {f[s[i]-'a']--;continue;}
            char t=top(stack);
            while(f[t-'a']!=0 && t>s[i] )
            {   pop(stack);
                boolean[t-'a']=false;
                if(isEmpty(stack)) break;
                t=top(stack);
            }
            push(stack,s[i]);
            boolean[s[i]-'a']=true;
           }
        f[s[i]-'a']--;
    }
    int elements=stack->size;
    char *res=malloc(sizeof(char)*(elements+1));
    int i=elements-1;
    res[elements]='\0';
    while(!isEmpty(stack)){
        res[i]=top(stack);
        pop(stack);
        i--;
    }
    return res;
}
