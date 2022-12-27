template<typename S>
class stack{
    S *data;
    int nextIndex;
    int capacity;
public:
stack(){
    capacity = 4;
    data= new S[capacity];
    nextIndex=0;
    
}
int size(){
    return nextIndex;
}
bool is_empty(){
    return nextIndex==0;
}
void push(S element){
    if (nextIndex==capacity)
    {
        S *new_data = S int[2*capacity];
        for (int i = 0; i <capacity; i++)
        {
            new_data [i] = data[i]; 
        }
        capacity = capacity*2;
        delete [] data;
        data=new_data;
    }
    
    data[nextIndex]=element;
    nextIndex++;
}
void pop(){
    if (is_empty){
        cout<<"The Stack is Empty"<<endl;
        return 0;
    }
    nextIndex--;
}
S top(){
    if (is_empty){
        cout<<"The Stack is Empty"<<endl;
        return 0;
    }
    return data[nextIndex-1];
}

};