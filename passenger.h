//#define CMNDMAX 15
//#define FIRSTNAME 10
//#define LASTNAME 30
//
//
////string mess;
//
//struct Passenger
//{
//	char id[CMNDMAX];
//	char firstName[FIRSTNAME], lastName[LASTNAME];
//	//1 la nam, 0 la nu
//	int  sex;
//	//bool isBook = false;
//};
//typedef struct Passenger p;
//
//p psg;
//int soluonghanhkhach = 0;
//
//struct NodePassenger
//{
//	Passenger key; 
//	NodePassenger* left;
//	NodePassenger* right;
//	int height;
//};
//typedef NodePassenger* Tree;
//
//Tree root = NULL;
struct SeachCharacterPassenger{
	int n;
	Tree *ds = new Tree[300]; 
	SeachCharacterPassenger(){
		n = 0;
	}
	~SeachCharacterPassenger(){
		delete[] ds;
	}
	void clear(){
		n = 0;
	}
};
typedef struct SeachCharacterPassenger SCP;

SCP spsg;

Tree newNode(p &key) {
	Tree node = new NodePassenger();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

int height(Tree &H) {
  	if (H == NULL)
    	return 0;
  	return H->height;
}

int max(int a, int b) {
  	return (a > b) ? a : b;
}
Tree rightRotate(Tree y) {
	Tree x = y->left;
	Tree r = x->right;
	x->right = y;
	y->left = r;
	y->height = max(height(y->left),
	    height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;
	  return x;
}
Tree leftRotate(Tree x) {
	Tree y = x->right;
	Tree l = y->left;
	y->left = x;
	x->right = l;
	x->height = max(height(x->left),
	    height(x->right)) + 1;
	y->height = max(height(y->left),
	    height(y->right)) + 1;
	  return y;
}

// Get the balance factor of each node
int getBalanceFactor(Tree &H) {
	if (H == NULL){
		return 0;
	}
	return height(H->left) - height(H->right);
}
bool CheckIdIsExisted(Tree &node, char id[]){
	if (node != NULL)
	{
		if (strcmp(node->key.id, id) == 0){
			return true;
		}	
		if (strcmp(node->key.id, id) > 0)
			return CheckIdIsExisted(node->left, id);
		else
			return CheckIdIsExisted(node->right, id);
	}
	mess = "Hanh khach khong co trong danh sach";
	return false;
}
//int CheckIdIsIndex(Node &n, char id[]){
//	if (n != NULL)
//	{
//		if (strcmp(n->key.id, id) == 0){
//			//return i;
//		}	
//		if (strcmp(n->key.id, id) > 0)
//			CheckIdIsExisted(n->left, id);
//		else
//			CheckIdIsExisted(n->right, id);
//	}
//	return -1;
//}
 //Insert a node
Tree insertNode(Tree &node, p &key) {
	//printf("key id: %s \n", key.id);
  // Find the correct postion and insert the node
	if (node == NULL){
		node = newNode(key);
	  	return node;
	}
//    return (newNode(key));
	if (strcmp(key.id, node->key.id) < 0)
	    node->left = insertNode(node->left, key);
	else if (strcmp(key.id, node->key.id) > 0)
	    node->right = insertNode(node->right, key);
	else
	    return node;

  // Update the balance factor of each node and
  // balance the tree
	node->height = 1 + max(height(node->left), height(node->right));
	
	int balanceFactor = getBalanceFactor(node);
	
	if (balanceFactor > 1) {
	    if (strcmp(key.id, node->left->key.id) < 0) {
	    	return rightRotate(node);
	    } else if (strcmp(key.id, node->left->key.id) > 0) {
	      	node->left = leftRotate(node->left);
	      	return rightRotate(node);
	    }
	}
	if (balanceFactor < -1) {
	    if (strcmp(key.id, node->right->key.id) > 0) {
	      	return leftRotate(node);
	    } else if (strcmp(key.id, node->right->key.id) < 0) {
	      	//node->left = rightRotate(node->left);
	      	node->right = rightRotate(node->right);
	      	return leftRotate(node);
	    }
	}
	return node;
}
Tree nodeWithMimumValue(Tree &node) {
	Tree current = node;
	while (current->left != NULL)
	    current = current->left;
	return current;
}
int count(Tree &t){
	if(t == NULL){
		return 0;
	}else{
		return (count(t->right) + count(t->left)) + 1;
	}
}
Tree FindPassenger(Tree &t, char idPassenger[])
{
	if (t != NULL)
	{
		Tree p = t;
		while (p != NULL)
		{
			if (strcmp(p->key.id, idPassenger) == 0)
				return p;
			else if (strcmp(p->key.id, idPassenger) > 0)
				p = p->left;
			else
				p = p->right;
		}
	}
	return NULL;
}

int FindPassengerint(Tree &t, char idPassenger[])
{
	if (t != NULL)
	{
		Tree p = t;
		while (p != NULL)
		{
			if (strcmp(p->key.id, idPassenger) == 0)
				return 1;
			else if (strcmp(p->key.id, idPassenger) > 0)
				p = p->left;
			else
				p = p->right;
		}
	}
	return 0;
}

Tree deleteNode(Tree &root, p &key) {
  // Find the node and delete it
	if (root == NULL)
	    return root;
	    
	if (strcmp(key.id, root->key.id) < 0)
	    root->left = deleteNode(root->left, key);
	else if (strcmp(key.id, root->key.id) > 0)
	    root->right = deleteNode(root->right, key);
	else {
	    if ((root->left == NULL) || (root->right == NULL)) {
	      	Tree temp = root->left ? root->left : root->right;
	      	if (temp == NULL) {
	        	temp = root;
	        	root = NULL;
	      	} else
	        	*root = *temp;
	      		free(temp);
	    } else {
	      	Tree temp = nodeWithMimumValue(root->right);
	      	root->key = temp->key;
	     	root->right = deleteNode(root->right, temp->key);
	    }
	}
	
	if (root == NULL)
	    return root;
	
	  // Update the balance factor of each node and
	  // balance the tree
	
	root->height = 1 + max(height(root->left), height(root->right));
	
	int balanceFactor = getBalanceFactor(root);
	
	if (balanceFactor > 1) {
	    if (getBalanceFactor(root->left) >= 0) {
	      	return rightRotate(root);
	    } else {
	      	root->left = leftRotate(root->left);
	      	return rightRotate(root);
	    }
	}
	if (balanceFactor < -1) {
	    if (getBalanceFactor(root->right) <= 0) {
	      	return leftRotate(root);
	    } else {
	      	root->right = rightRotate(root->right);
	      	return leftRotate(root);
	    }
	}
	return root;
}
bool InsertPassenger(Tree &node, p &key){
//	if(CheckIdIsExisted(node, key.id) == true){
//			mess = "So CMND bi trung";
//			return false;
//	}
	soluonghanhkhach++;
	node = insertNode(node, key);
	mess = "Luu thanh cong";
	return true;
}

bool DeletePassenger(Tree &node, char id[]){
	Tree t = FindPassenger(node, id);
	if(t->key.booktimes > 0){
		return false;
	}
	if(CheckIdIsExisted(node, id) == true){
		soluonghanhkhach--;
		node = deleteNode(node, t->key);
		mess = "Xoa thanh cong";
		return true;
	}
	mess = "Khong tim thay hanh khach can xoa";
	return false;
}
//bool EditPassenger(Node &node, p &key){
//	i = CheckIdIsIndex(node, key);
//	if(CheckIdIsExisted(node, key.id) == -1){
//		mess = "Khong tim thay so CMND";
//		return false;
//	}
//	mess = "Khong duoc thay doi CMND";
//	return true;
//}
bool EditPassenger(Tree &node, p &key){
	Tree t = newNode(key);
	t = FindPassenger(node, key.id);
	if(t == NULL){
		mess = "Khong tim thay hanh khach muon hieu chinh";
		return false;
	}
	mess = "Nhap ho muon doi";
	strcpy(node->key.lastName, key.lastName);
	mess = "Nhap ten muon doi";
	strcpy(node->key.firstName, key.firstName);
	mess = "Nhap gioi tinh muon doi";
	node->key.sex = key.sex;
	return true;
}
int indexOutPassenger = 0;
//void OutputListPassenger(Tree &t)
//{
//		if(t == NULL) {
//			return;
//		}
//		OutputListPassenger(t->left);
//		output(t->key, ++indexOutPassenger);
//		OutputListPassenger(t->right);
//}
void LNR(Tree &t, SCP &k, char *id){
    if(t != NULL)
    {
        LNR(t->left, k, id);
        if(strncmp(t->key.id, id, strlen(id)) == 0){
        	k.ds[k.n++] = t;
		}
        LNR(t->right, k, id);
    }
}
void WritePassengerToFile(Tree &n, fstream &file)
{
	if (n != NULL)
	{
		WritePassengerToFile(n->left, file);
		file << n->key.id << endl;
		file << n->key.firstName << endl;
		file << n->key.lastName << endl;
		file << n->key.sex << endl;
		file << n->key.booktimes << endl;
		file << n->key.count << endl;
		for(int i = 0; i < n->key.count; i++){
			file << n->key.MaFlight[i] << endl;
		}
		WritePassengerToFile(n->right, file);
	}
}
void SavePassenger(Tree &t)
{
	fstream file("passenger.txt", ios::out);
	file << count(t) << endl;
	if(count(t) != 0){
		WritePassengerToFile(t, file);
	}
	file.close();
}
void LoadPassenger(Tree &t)
{
	int n;
	fstream file("passenger.txt", ios::in);
	file >> n;
	file.ignore();
	for (int i = 0; i < n; i++)
	{
		p key;
		file.getline(key.id, 15);
		file.getline(key.firstName, 10);
		file.getline(key.lastName, 30);
		file >> key.sex;
		file >> key.booktimes;
		file >> key.count;
		file.ignore();
		for(int i = 0; i < key.count; i++){
			file.getline(key.MaFlight[i], 15);
		}
		t = insertNode(t, key);
	}
	mess = "loadppp";
	file.close();
}
void ClearListPassenger(Tree &root) {
	if (root == NULL) {
		return;
	}
	if (root->left) {
		ClearListPassenger(root->left);
	}
	else if (root->right) {
		ClearListPassenger(root->right);
	}
	else delete root;
}

