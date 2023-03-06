#include<stdio.h>  	
#include<stdlib.h>  	

struct node  	
{  	
	int key;  	
    	struct node *left;  
	struct node *right;  
};  
	
struct node *getnode(int val)  
{  
	struct node *newnode;  
	newnode = malloc(sizeof(struct node));  
	newnode->key = val;  
	newnode->left = NULL;
    	newnode->right = NULL;  
   	return newnode;
} 
	
struct node *insertnode(struct node *root, int val)  
{  
	if(root == NULL)  
		return getnode(val);  
	if(root->key < val)  
		root->right = insertnode(root->right,val);  
	if(root->key > val)  
    		root->left = insertnode(root->left,val);  
	return root;
}
	
void inorder(struct node *root)
{
	if(root == NULL)  
	    return;    
    	inorder(root->left);  	        //traverse the left subtree 
    	printf("%d  ",root->key);  	//visit the root   
    	inorder(root->right);           //traverse the right subtree
}

void preorder(struct node *root) 
{  
    	if(root == NULL)  
        	return; 
	printf("%d  ",root->key); 
	preorder(root->left);  
	preorder(root->right); 
}

void postorder(struct node *root)  
{
	if(root == NULL)  
		return;  
	postorder(root->left); 
    	postorder(root->right);
    	printf("%d  ",root->key);
}  

int main()  
{
	int choice;
	struct node *root = NULL;  
	while(1)      
    	{  
        	printf("\nSelect the operation\n");
        	printf("---------------------\n"); 
        	printf("1. Insert new node in Binary Tree\n2. Display nodes of Binary Tree(via Inorder Traversal)\n3. Display nodes of Binary Tree(via Preorder Traversal)\n4. Display nodes of Binary Tree(via Postorder Traversal)\n5. Exit\n");  
	    	scanf("%d", &choice);              
	    	switch(choice)  
	    	{  
	        	case 1:   
	            		int data;
				printf("Enter the value to be inserted\n");  
	        		scanf("%d",&data);  
	            		root = insertnode(root,data);                    
	            		break;                            
            		case 2:
			    	printf ("Inorder Traversal of the Binary Tree:\n");  
	            		inorder(root);  
	            		break;
            		case 3:
			    	printf ("Preorder Traversal of the Binary Tree:\n");  
	            		preorder(root);  
	            		break;
            		case 4:
			    	printf ("Postorder Traversal of the Binary Tree:\n");  
	            		postorder(root);  
	            		break;
            		case 5:
                		exit(0);
	        	default:
	            		printf("Wrong Entry\n");
                		break;
        	}                          
    	}  
 	return 0;  
}
