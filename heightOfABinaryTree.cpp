int height(Node* root)
{
  if(node==NULL)
  {
      return -1;  
  }

  queue<Node*> q;
  
  q.push(node);
  
  int height = 0;
  while(!q.empty())
  {
      height++;
      int sz = q.size();
      for(int i=0;i<sz;i++)
      {
          Node* temp = q.front();
          q.pop();
          
          if(temp->left)
              q.push(temp->left);
              
          if(temp->right)
              q.push(temp->right);
      }
    return height;
}

// Another Technique

int height(struct Node* root)
{
    if(root == NULL)
        return 0;
        
    int lheight = height(root->left);
    int rheight = height(root->right);
    
    return max(lheight,rheight)+1;
}

