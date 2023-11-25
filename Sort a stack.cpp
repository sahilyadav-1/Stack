

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void insertSorted(stack<int>& s, int element){
    if(s.empty() || s.top()<element){
        s.push(element);
       return;
    }
    
    int top = s.top();
    s.pop();
    
    insertSorted(s,element);
    
    s.push(top);
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   if(s.empty()){
       return;
   }
   
   int element = s.top();
   s.pop();
   
   sort();
   
   insertSorted(s,element);
}
