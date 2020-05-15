void printKdistance(struct Node *root, int k)
{
   queue<Node *> q1, q2; 

	if (root == NULL) 
		cout<<0; 

	q1.push(root); 
    int count=0;
 

	while (!q1.empty() || !q2.empty()) 
	{ 
		while (!q1.empty()) 
		{ 
		
			if (q1.front()->left != NULL) 
				q2.push(q1.front()->left); 

		
			if (q1.front()->right != NULL) 
				q2.push(q1.front()->right); 

		 if(count==k){
          cout<<q1.front()->data<<" ";
        }
            
			q1.pop(); 
		} 
    
	count++;
    
    
		while (!q2.empty()) 
		{ 
			
			if (q2.front()->left != NULL) 
				q1.push(q2.front()->left); 

		
			if (q2.front()->right != NULL) 
				q1.push(q2.front()->right); 

			 if(count==k){
          cout<<q2.front()->data<<" ";
        }
			q2.pop(); 
         
		} 
      count++;
		
        
    
	} 
	
}
