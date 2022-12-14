template<typename S>
class queue{
    S *data;
    int nextIndex;
    int firstIndex;
    int capacity;
    int count;
public:
stackArray(){
    capacity = 4;
    data= new S[capacity];
    nextIndex=0;
    firstIndex=-1;
    count =0;
    
}
int size(){
    return count;
}
bool is_empty(){
    return count==0;
}
void enqueue(S element){
    if (nextIndex==capacity)
    {
        S *new_data = S int[2*capacity];
        int k=0;
        for (int i = firstIndex; i <capacity; i++)
        {
            new_data [k] = data[i];
            k++; 
        }
        for (int j = 0; j < nextIndex; j++)
        {
            new_data[k]=data[j];
            k++;
        }
        firstIndex=0;
        nextIndex=capacity;
        capacity = capacity*2;
        delete [] data;
        data=new_data;
    }
    
    data[nextIndex]=element;
    nextIndex=(nextIndex+1)%capacity;
    if (firstIndex==-1)
    {
        firstIndex++;
    }
    
    count++;
}
S dequeue(){
    if (is_empty){
        cout<<"The Stack is Empty"<<endl;
        return 0;
    }
    nextIndex--;
    firstIndex=(firstIndex-1)%capacity;
    count--;
    if (count==0)
    {
        firstIndex=-1;
        nextIndex=0;
    }
    
    return data[nextIndex]
}
S front(){
    if (is_empty){
        cout<<"The Stack is Empty"<<endl;
        return 0;
    }
    return data[firstIndex];
}

};