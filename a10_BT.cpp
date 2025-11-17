#include<bits/stdc++.h>
using namespace std;


class BT_Node{
   public :
       char name[20];
       BT_Node* left;
       BT_Node* right;


       BT_Node(){
           left = NULL;
           right = NULL;
           strcpy(name," ");
       }
};


class BT_Operations{
   private :
       BT_Node* root;
   public:
       BT_Operations(){
           root = NULL;
       }


       BT_Node* create_BT(){
           queue<BT_Node*> q;
           char value[20];
           cout<<"Enter root node name (or '-1' for empty tree): ";
           cin>>value;


           if(strcmp(value,"-1")==0){
               return NULL;
           }


           root = new BT_Node;
           strcpy(root->name, value);
           q.push(root);


           while(!q.empty()){
               BT_Node* current = q.front();
               q.pop();
               cout<<"Enter the left child of "<<current->name<<" (or '-1' for NULL): ";
               cin>>value;
               if(strcmp(value, "-1")!=0){
                   current->left = new BT_Node();
                   strcpy(current->left->name, value);
                   q.push(current->left);
               }


               cout<<"Enter the right child of "<<current->name<<" (or '-1' for NULL): ";
               cin>>value;


               if(strcmp(value, "-1")!=0){
                   current->right = new BT_Node();
                   strcpy(current->right->name, value);
                   q.push(current->right);
               }
           }


           return root;
       }


       void display_Preorder(BT_Node* node){
           if(node==NULL){
               return;
           }
           cout<<node->name<<" ";
           display_Preorder(node->left);
           display_Preorder(node->right);
       }


       void display_Inorder(BT_Node* node){
           if(node==NULL){
               return;
           }
           display_Inorder(node->left);
           cout<<node->name<<" ";
           display_Inorder(node->right);
       }
      
       void display_Postorder(BT_Node* node){
           if(node == NULL){
               return;
           }
           display_Postorder(node->left);
           display_Postorder(node->right);
           cout<<node->name<<" ";
       }


       BT_Node* getRoot(){
           return root;
       }
};


int main() {
   BT_Operations bt;
   int choice;
   BT_Node* root = NULL;
   do {
       cout << "\n---- MENU ----\n";
       cout << "1. Create Binary Tree\n";
       cout << "2. Preorder Traversal\n";
       cout << "3. Inorder Traversal\n";
       cout << "4. Postorder Traversal\n";
       cout << "5. Exit\n";
       cout << "Enter your choice: ";
       cin >> choice;
       switch(choice) {
           case 1:
               root = bt.create_BT();
               cout << "Binary Tree created!\n";
               break;
           case 2:
               cout << "Preorder: ";
               bt.display_Preorder(root);
               cout << endl;
               break;
           case 3:
               cout << "Inorder: ";
               bt.display_Inorder(root);
               cout << endl;
               break;
           case 4:
               cout << "Postorder: ";
               bt.display_Postorder(root);
               cout << endl;
               break;
           case 5:
               cout << "Exiting...\n";
               break;
           default:
               cout << "Invalid choice! Try again.\n";
       }
   } while(choice != 5);
   return 0;
}

/*
/** OUTPUT:

1.] Creating a Binary Tree
ENTER DATA OF THE NEW NODE: FOLDER
ENTER DATA OF THE NEW NODE: FOLDER1
ENTER DATA OF THE NEW NODE: FOLDER2
ENTER DATA OF THE NEW NODE: FILE1
ENTER DATA OF THE NEW NODE: FILE2
ENTER DATA OF THE NEW NODE: FILE3
ENTER DATA OF THE NEW NODE: FILE4

Binary Tree Created Successfully!!

2.] PREORDER DISPLAY
FOLDER FOLDER1 FILE1 FILE2 FOLDER2 FILE3 FILE4

3.] INORDER DISPLAY
FILE1 FOLDER1 FILE2 FOLDER FILE3 FOLDER2 FILE4

4.] POSTORDER DISPLAY
FILE1 FILE2 FOLDER1 FILE3 FILE4 FOLDER2 FOLDER

*/

