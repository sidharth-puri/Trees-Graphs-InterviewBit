int getMaxWidth(Node* root)
{
    queue<Node *> q1, q2; 

	if (root == NULL) 
		return 0; 

	q1.push(root); 
    int count=0;
   int max=-999999;

	while (!q1.empty() || !q2.empty()) 
	{ 
		while (!q1.empty()) 
		{ 
		
			if (q1.front()->left != NULL) 
				q2.push(q1.front()->left); 

		
			if (q1.front()->right != NULL) 
				q2.push(q1.front()->right); 

		
           count++;
			q1.pop(); 
		} 
     // cout<<"current count :"<< count<<endl;
          if(count>max) {
                max=count;
            }
            count=0;
	

		while (!q2.empty()) 
		{ 
			
			if (q2.front()->left != NULL) 
				q1.push(q2.front()->left); 

		
			if (q2.front()->right != NULL) 
				q1.push(q2.front()->right); 

			
			q2.pop(); 
          count++;
		} 
       // cout<<"current count :"<< count << endl;
 if(count>max) {
                max=count;
            }
            count=0;
	
		
	} 
	return max;
}

