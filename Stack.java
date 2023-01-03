// circular Queue
class Queue 
{
    int queue[]=new int[5];
    int front=0;
    int rear=0;
    
    public void enqueue(int data)
    {
        queue[rear]=data;
        rear=(rear+1)%5;
    }
    public void dequeue()
    {
        
    int data;
    data=queue[front];
    //queue[front]=0;
    front=(front+1)%5;
    
        
    }
public void show(){
        for(int i=0;i<5;i++)
        {
            System.out.println(queue[(front+i)%5]);
        }
    }
    
}
 class Main 
 {
     public static void main(String[] args)
     {
         Queue o=new Queue();
         o.enqueue(23);
         o.enqueue(67);
         o.enqueue(56);
         o.enqueue(89);
         o.enqueue(79);
         o.dequeue();
         o.dequeue();
         o.enqueue(1);
         o.enqueue(2);
         o.show();
     }
     
 }
