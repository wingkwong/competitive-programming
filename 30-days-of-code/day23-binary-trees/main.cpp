#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

	void levelOrder(Node * root){
      //Write your code here
      queue<Node*> q;
      Node* node = root;
      while(node){
          cout << node->data << " ";
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
          if(!q.empty()){
              node = q.front();
              q.pop();
          } else {
              node = NULL;
          }
      }
	}

};//End of Solution