#include<abhinav.h>

struct tree
{
	int data;
	struct tree *left,*right;
};

struct tree* create_tree(int val)
{
	struct tree* node=new tree;
	node->left=NULL;
	node->right=NULL;
	node->data=val;
	return node;
}

int cnt=0,in[100],pre[100];

int inorder(struct tree *root)
{
	//struct tree *node=root;
	if(root!=NULL)
	{
		inorder(root->left);
		in[cnt]=root->data;
		cnt++;
		inorder(root->right);
	}
}

int cnt1=0;

int preorder(struct tree *root)
{
	//struct tree *node=root;
	if(root!=NULL)
	{
		pre[cnt1]=root->data;
		cnt1++;
		preorder(root->left);
		preorder(root->right);
	}
}

struct tree* create_temp()
{
	struct tree *root=create_tree(7);
	root->left=create_tree(3);
	root->right=create_tree(11);
	
	root->left->left=create_tree(1);
	root->left->right=create_tree(5);
	
	root->left->left->left=create_tree(0);
	root->left->left->right=create_tree(2);

	root->left->right->left=create_tree(4);
	root->left->right->right=create_tree(6);
	
	root->right->left=create_tree(9);
	root->right->right=create_tree(13);
	
	root->right->left->left=create_tree(8);
	root->right->left->right=create_tree(10);
	
	root->right->right->left=create_tree(12);
	root->right->right->right=create_tree(14);

	return root;
}

int main()
{
	struct tree *root=create_temp();
	int a,b;
	cin>>a>>b;
	inorder(root);
	preorder(root);
	
	int left,right;
	
	for(int i=0;i<cnt;i++)
	{
		if(in[i]==a)
			left=a;
		if(in[i]==b)
			right=b;
	}
				
	for(int i=0;i<cnt;i++)
	{
		for(int j=left;j<=right;j++)
		{
			if(pre[i]==in[j])
			{
				cout<<pre[i];
				return 2;
			}
		}
	}
}
