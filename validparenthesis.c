struct Stack{
    int *arr;
    int size;
    int capacity;
};
void push(struct Stack* s, int x){
        if(s->size<s->capacity){
            s->arr[s->size]=x;
            s->size++;
        }
        else{
            s->capacity=2*s->capacity;
            int *temp=malloc(s->capacity*sizeof(*temp));
            for(int i=0;i<s->size;i++){
                temp[i]=s->arr[i];
            }
            temp[s->size]=x;
            s->arr=temp;
            s->size++;
        }
}
int empty(struct Stack* s){
    return s->size==0;
}
void pop(struct Stack* s){
    if(!empty(s)){
        s->size--;
    }
}
int top(struct Stack* s){
    return s->arr[s->size-1];
}
void print(struct Stack* s){
      for(int i=0;i<s->size;i++) printf("%d",s->arr[i]);
}
bool isValid(char* s) {
    struct Stack *st=malloc(sizeof(*st));
    st->size=0;
    st->capacity=1;
    st->arr=malloc(sizeof(int));
    int n=strlen(s);
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c=='(' || c=='[' || c=='{') push(st,c);
        else{
            if(empty(st)) return false;
            char t=top(st);
            if(c==')') {
                if(t!='(') return false;
            }
            if(c=='}'){
                if(t!='{') return false;
            }
            if(c==']'){
                if(t!='[') return false;
            }
            pop(st);
        }
    }
    if(st->size) return false;
    return true;
}
