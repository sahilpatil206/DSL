#include<bits/stdc++.h>
using namespace std;
#define MAX 5

// Class representing the Pizza Parlor order system using a circular deque
class Pizza_Parlor{

   public :
       string order_id[MAX]; // Array to store order IDs
       int front;            // Points to the front order
       int rear;             // Points to the rear order
      
       // Constructor initializes an empty queue
       Pizza_Parlor(){
           front = -1;
           rear = -1;
       }

       // Insert new order at the rear end
       void Insert_At_Rear(string order){
           // Check for queue full conditions (circular)
           if((front==0&&rear==MAX-1)||(rear+1==front)){
               cout<<"We are full! Cannot accept more orders.";
               return;
           }
          
           // Queue is empty
           if(front==-1){
               front = rear = 0;
           }
           // Rear reaches end and space available at front (wrap around)
           else if(rear==MAX-1 && front!=0){
               rear = 0;
           }
           else{
               rear++;
           }

           order_id[rear] = order; // Store order at rear
           cout<<"Order information : "<<order<<" is accepted."<<endl;
       }

       // Insert new order at the front end (for priority or special handling)
       void Insert_At_Front(string order){
           // Check for queue full conditions (circular)
           if(front==0 && rear==MAX-1||rear+1==front){
               cout<<"We are full! Cannot accept orders."<<endl;
               return;
           }
           // Queue is empty
           if(front==-1){
               front = rear = 0;
           }else if(front==0){
               front = MAX-1;     // Wrap front to end
           }else{
               front--;
           }
          
           order_id[front] = order; // Store order at front
           cout<<"Order information : "<<endl;
       }

       // Process (remove) the frontmost order
       void Process_From_Front(){
           if(front==-1){
               cout<<"Currently we have no orders."<<endl;
               return;
           }
           cout<<"Order "<<order_id[front]<<" completed."<<endl;

           // Only one order left
           if(front==rear){
               front = rear = -1;
           }else if(front == MAX-1){
               front = 0;        // Wrap front to start
           }else{
               front++;
           }
       }

       // Process (remove) the rearmost order
       void Process_From_Rear(){
           if(rear==-1){
               cout<<"Currently we do not have any orders."<<endl;
               return;
           }
           cout<<"Order "<<order_id[rear]<<" completed."<<endl;

           // Only one order left
           if(front==rear){
               front = rear = -1;
           }else if(rear==0){
               rear = MAX-1;     // Wrap rear to end
           }
           else{
               rear--;
           }
       }

       // Display all pending orders (from front to rear, circularly)
       void Display(){
           if(front==-1){
               cout<<"No pending orders."<<endl;
               return;
           }
           cout<<"Pending orders :  ";
           int i = front;
           while(true){
               cout<<order_id[i]<<" ";
               if(i==rear) break;
               i = (i+1)%MAX; // Move circularly
           }
           cout<<endl;
       }

};

int main(){
   Pizza_Parlor p;   // Object for managing orders
   int choice;
   string order;

   do{
       // Display menu
       cout<<"\n--- Pizza Parlor ---\n";
       cout<<"1. Accept order at rear.\n";
       cout<<"2. Accept order at front.\n";
       cout<<"3. Process orders at front.\n";
       cout<<"4. Process orders at rear.\n";
       cout<<"5. Display Pending Orders.\n";
       cout<<"6. Exit";
       cout<<"\nEnter choice : ";
       cin>>choice;

       switch (choice)
       {
       case 1:
           cout<<"Enter order_id : ";
           cin>>order;
           p.Insert_At_Rear(order);      // Add at rear
           break;
       case 2:
           cout<<"Enter order_id : ";
           cin>>order;
           p.Insert_At_Front(order);     // Add at front
           break;
       case 3:
           p.Process_From_Front();       // Remove from front
           break;
       case 4:
           p.Process_From_Rear();        // Remove from rear
           break;
       case 5:
           p.Display();                  // Show all orders
           break;
       default:
           cout<<"Invalid choice has been entered.\n";
           break;
       }
   }while(choice!=6);        // Keep running until exit

   return 0;
}
