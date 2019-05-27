struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};


int checksequence(int d1, int d2)
{
	return (d1 ==  d2 - 1) ? 1 : 0;
}

int longest_sequesnce_from_node(struct s_node *node)
{
	int left_len = 1;
	int right_len = 1; 
	if (node)
	{
		if (node->left)
		{
			if (checksequence(node->value, node->left->value))
			{
				left_len = 1 + longest_sequesnce_from_node(node->left);
			}
		}

		if (node->right)
		{
			if (checksequence(node->value, node->right->value))
			{
				right_len = 1 + longest_sequesnce_from_node(node->right);
			}
		}

		return (left_len > right_len ? left_len : right_len); 
	}
	else 
		return 0; 

}

int	longest_sequence(struct s_node *node)
{
	int max = 1; 
	int cur; 


//traverse tree and for each node count longest sequence 

//if max < cur.longest_sequence -> max = cur ;
//return max 

	if (node)
	{

			if (node->left)
			{
				cur = checksequence(node->value, node->left->value) + longest_sequesnce_from_node(node->left);
				if (cur > max)
					max = cur;
				longest_sequence(node->left);
			}
			if (node->right)
			{
				cur = checksequence(node->value, node->right->value) + longest_sequesnce_from_node(node->right);
				if (cur > max)
					max = cur;
				longest_sequence(node->right);
 
			}
			return max;
	}
	else 
		return 0;
}







