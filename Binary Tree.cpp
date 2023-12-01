/*
    1.Inorder Traversal -Iterative
    Time Complexity: O(n)
    Space Complexity: O(n)

vector<int> inorderTraversal(TreeNode* root) 
{
    //iterative______________tc:o(n);sc:0(n)_______
    /*
    vector<int>ans;
    stack<TreeNode*>store;
    if(!root)
    {
        return ans;
    }
    TreeNode*curr=root->left;
    
    store.push(root);
    while(!store.empty() || curr)
    {
        while(curr)
        {
            store.push(curr);
            curr=curr->left;
        }
        TreeNode*temp=store.top();
        ans.push_back(temp->val);
        store.pop();
        curr=temp->right;
    }
    return ans;
}

-Recursive
    //TC;SC: Same as Iterative

void inorder(TreeNode* root, vector<int>& nodes) 
{
    if (!root) 
    {
        return;
    }
    inorder(root -> left, nodes);
    nodes.push_back(root -> val);
    inorder(root -> right, nodes);
}

-Morris Traversal

    Time Complexity: O(n)
    Space Complexity: O(1)

vector<int> inorderTraversal(TreeNode* root)
{ 
    vector<int>ans;
    if(!root)
    {
        return ans;
    }
    TreeNode*curr=root;
    while(curr)
    {
        if(!curr->left)
        {
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else
        {
            TreeNode*prev=curr->left;
            while(prev->right && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(!prev->right)
            {
                prev->right=curr;
                curr=curr->left;
            }
            else
            {
                prev->right=NULL;
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return ans;
}


    2. Preorder
    TC & SC same for all..

-iterative

vector<int> preorderTraversal(TreeNode* root) 
{
    vector<int> nodes;
    stack<TreeNode*> todo;
    while (root || !todo.empty()) 
    {
        if (root)
        {
            nodes.push_back(root -> val);
            if (root -> right) 
            {
                todo.push(root -> right);
            }
            root = root -> left;
        } 
        else 
         {
            root = todo.top();
            todo.pop();
        }
    }
    return nodes;
}

-recursive

void preorder(TreeNode* root, vector<int>& nodes) 
{
    if (!root)
    {
        return;
    }
    nodes.push_back(root -> val);
    preorder(root -> left, nodes);
    preorder(root -> right, nodes);
}

-Morris Traversal

vector<int> preorderTraversal(TreeNode* root) 
{
    //Morris Traversal...
    vector<int>ans;
    if(!root)
    {
        return ans;
    }
    TreeNode*curr=root;
    while(curr)
    {
        if(!curr->left)
        {
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else
        {
            TreeNode*prev=curr->left;
            while(prev->right && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(!prev->right)
            {
                prev->right=curr;
                ans.push_back(curr->val);
                curr=curr->left;
            }
            else
            {
                prev->right=NULL;
                
                curr=curr->right;
            }
        }
    }
    return ans;    
}

    3. Postorder
    //TC & SC same correspondingly

-iterative:

vector<int> postorderTraversal(TreeNode* root) 
{
    //_______postorder is left, right, root. tc:o(n);sc: o(n)
    vector<int>ans;
    if(!root)
    {
        return ans;
    }
    stack<TreeNode*>st;
    TreeNode*temp,*last=NULL;//last pointer points to the last node. no need to traverse after this node
    while(root || !st.empty())
    {
        if(root)
        {
        st.push(root);
        root=root->left;//goes directly to leftmost node
        
        }
        else
        {
        temp=st.top();
        if(temp->right && last!=temp->right)
        {
            root=temp->right;
        }
        else//if there is no right, it's the last node, we add it and mark it as last
        {
            ans.push_back(temp->val);
            last=temp;
            st.pop();
        }
        }
    }
    return ans;        
}

-recursive:

void postorder(TreeNode* root, vector<int>& nodes) 
{
    if (!root) 
    {
        return;
    }
    postorder(root -> left, nodes);
    postorder(root -> right, nodes);
    nodes.push_back(root -> val);
}

-Morris

vector<int> postorderTraversal(TreeNode* root) 
{
        vector<int> nodes;
        TreeNode* dummy = new TreeNode(0);
        dummy -> left = root;
        TreeNode* cur = dummy;
        while (cur) 
        {
            if (cur -> left) 
            {
                TreeNode* pre = cur -> left;
                while (pre -> right && (pre -> right != cur)) 
                {
                    pre = pre -> right;
                }
                if (!(pre -> right)) 
                {
                    pre -> right = cur;
                    cur = cur -> left;
                } 
                else
                {
                    reverseAddNodes(cur -> left, pre, nodes);
                    pre -> right = NULL;
                    cur = cur -> right;
                }
            } 
            else 
            {
                cur = cur -> right;
            }
        }
        return nodes;
    }
private:
void reverseNodes(TreeNode* start, TreeNode* end) 
{
    if (start == end) 
    {
        return;
    }
    TreeNode* x = start;
    TreeNode* y = start -> right;
    TreeNode* z;
    while (x != end)
    {
        z = y -> right;
        y -> right = x;
        x = y;
        y = z;
    }
}
void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& nodes) 
{
    reverseNodes(start, end);
    TreeNode* node = end;
    while (true) {
        nodes.push_back(node -> val);
        if (node == start) {
            break;
        }
        node = node -> right;
    }
    reverseNodes(end, start);
}

    4. Level Order Traversal
    Time Complexity: O(N)
    Space Complexity: O(N)

vector<vector<int>> levelOrder(TreeNode* root) 
{
    vector<vector<int>>ans;//to store ans;
    if(!root)//base case
    {
        return ans;
    }
    queue<TreeNode*>q;//to store the elements
    vector<int>temp;//to store temp ans;
    int i,n;
    q.push(root);
    while(!q.empty())
    {
        n=q.size();
        for(i=0;i<n;i++)
        {
            TreeNode*curr=q.front();
            q.pop();
            temp.push_back(curr->val);
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
}

*/