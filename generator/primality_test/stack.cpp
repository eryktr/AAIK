struct Node
{
	int value;
	Node* next;
};

void push(Node **root_ref, int value)
{
	Node *newNode = new Node();
	newNode -> value = value;
	newNode -> next = *(root_ref);
	*(root_ref) = newNode;
}

int pop(Node **root_ref)
{
	Node *tmp = *(root_ref);
	*(root_ref) = tmp -> next;
	int val = tmp -> value;
	delete(tmp);
	return val;
}