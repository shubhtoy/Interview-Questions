struct stack
{
    int size;
    int top;
    char *arr;
};
int is_empty(struct stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
    
}
int is_full(struct stack *s)
{
    if(s->top==s->size-1)
        return 1;
    else
        return 0;
    
}
void push(struct stack *s,char a)
{
    if(is_full(s))
        printf("Stack overflow");
    else
    {
        s->top++;
        s->arr[s->top]=a;
        
    }
}
char pop(struct stack *s)
{
    if(is_empty(s))
      return;
    
        char val=s->arr[s->top];
        s->top--;
        return val;
    
    
}
int match(char a,char b)
{
    if(a=='(' && b==')')
        return 1;
    else if(a=='[' && b==']')
        return 1;
    else if(a=='{' && b=='}')
        return 1;

        return 0;
    
}
int is_balance(char *p)
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=strlen(p);
    s->arr=(char *)malloc(sizeof(char)*s->size);
    for(int i=0;i<strlen(p);i++)
    {
        if(p[i]=='(' || p[i]=='[' || p[i]=='{')
            push(s,p[i]);
        else if(p[i]==')' || p[i]==']' || p[i]=='}')
        {   if(is_empty(s))
            return 0;
            char popped_ch=pop(s);
            if(!match(popped_ch,p[i]))
                return 0;
            
        }
    }
    if(is_empty(s))
        return 1;
 return 0;
    
}
    

bool isValid(char * s){
if(is_balance(s))
    return 1;
    else
    return 0;
    
    
}
