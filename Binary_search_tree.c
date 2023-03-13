#include<stdio.h>
#include<stdlib.h>
 
struct tree
{
  int key;
  struct tree* left;
  struct tree* right;
};

void print_tree (struct tree *root, int space);
void find_range (struct tree *root, int t1, int t2);
void enter_elements_of_treee (struct tree **p, int x);

int main()
{
  struct tree* root = NULL;
  int t1, t2, x;

  system("cls");
  printf("\t///Binary Search Tree keys in the given range///\n");
  printf("_________________________________________________\n");
  enter_elements_of_treee(&root, x);
  printf("_________________________________________________\n");
  printf("\t\tPRINTED TREE\n");
  printf("_________________________________________________\n");
  print_tree(root, 1);
  printf("_________________________________________________\n");
  printf("\nEnter range t1 to t2 (t1 < t2): ");
  scanf("%d %d",&t1, &t2);
  printf("_________________________________________________\n");

  if(t1 > t2)
    printf("\nERROR !!!! t1 > t2");
  else
  printf("\nThe keys in given range %d to %d are: ", t1, t2);
  find_range(root, t1, t2);
  printf("\n_________________________________________________\n");
 
  return 0;
}

void find_range (struct tree *root, int t1, int t2) // Min O(1), Max O(N), Average O(N)
{
  if (root == NULL)
  return;
 
  if ( t1 < root->key )
   find_range(root->left, t1, t2);

  if ( t1 <= root->key && t2 >= root->key )
   printf("%d ", root->key );

  find_range(root->right, t1, t2);
}
 
void enter_elements_of_treee (struct tree ** p, int x)  // min O(N), max O(N)
{
	int right, left;
	struct tree *q1, *q2;

	if (*p == NULL)  
	{
		printf("Enter a root: ");
		scanf("%d", &x);
 
		(*p) = (struct tree *)malloc(sizeof(struct tree));
		(*p)->key = x;
	}	


	printf("Enter the left heir of %d: ", x);
	scanf("%d", &left);
	

	printf("Enter the right heir of %d: ", x);
	scanf("%d", &right);

	if (left != 0)
	{
		q1 = (struct tree *)malloc(sizeof(struct tree));
		q1->key = left;
		(*p)->left = q1;
 
		enter_elements_of_treee(&q1, left);
	}
	else
		(*p)->left = NULL;

	if (right != 0)
	{
		q2 = (struct tree *)malloc(sizeof(struct tree));
 
		q2->key = right;
		(*p)->right = q2;
		enter_elements_of_treee(&q2, right);
	}
	else
		(*p)->right = NULL;
}

void print_tree (struct tree *root, int space) // min 0(1), max O(N * space )
{
  if (root == NULL) 
    return;
 
    print_tree(root->right, space+1);
 
    printf("\n");
    for (int i = 1; i <= space; i++)
    printf("\t");
    printf("%d", root->key);
    printf("\n");
 
    print_tree(root->left, space+1);
}
