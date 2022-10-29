# Python3 implementation of the approach

# Node creation
class Node:

	# Constructor
	def __init__(self, data):
		
		self.val = data
		
		# Since n children are possible for a root.
		# A list created to store all the children.
		self.child = []


# Function to insert
def insert(root, parent, node):
	
	# Root is empty then the node will become the root
	if root is None:
		root = node			

	else:
		if root.val == parent:
			root.child.append(node)			
		else:

			# Recursive approach to
			# insert the child
			l = len(root.child)
			
			for i in range(l):
				if root.child[i].val == parent:
					insert(root.child[i], parent, node)
				else:
					insert(root.child[i], parent, node)

# Function that calls levelorder method to
# perform level order traversal
def levelorder_root(root):
	if root:
		level = []
		level.append(root)
		print(root.val)
		levelorder(level)

# Function to perform level order traversal
def levelorder(prev_level):

	cur_level = []
	print_data = []
	l = len(prev_level)

	if l == 0:
		exit()

	for i in range(l):
		prev_level_len = len(prev_level[i].child)

		for j in range(prev_level_len):
			
			# enqueue all the children
			# into cur_level list
			cur_level.append(
				prev_level[i].child[j])

			# Copies the entire cur_level
			# list into prev_level
			print_data.append(
				prev_level[i].child[j].val)

	prev_level = cur_level[:]				
	print(*print_data)
	levelorder(prev_level)


# Driver code

# -1 is the root element
arr = [-1, -1, -1, -1, -1]
root = Node(-1)
l = len(arr)
que = []

# Inserting root element to the queue
que.append(-1)

while 1:
	temp = []
	for i in range(l):
		if arr[i] in que:
			
			# Insert elements into the tree
			insert(root, arr[i], Node(i))
			temp.append(i)

	# Append child nodes into the queue
	# and insert the child
	que = temp[:]					
	
	if len(que)== 0:
		break

levelorder_root(root)
