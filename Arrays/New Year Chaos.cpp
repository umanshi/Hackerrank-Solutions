/*

In the given solution we are finding the number of times each element has been bribed and summing it up.

Starting from the rightmost element you know that all the elements that have bribed the ith element were
> 1.Greater than it (explaination in italics below)
> 
> 2. Now present on the left hand side of it. (As they simply bribed the ith element and got ahead)

Here's some brute force solution




>void minimumBribes(vector  < int >  q) {
>
> int ans = 0;
> 
> for (int i = q.size() ; i >= 1 ; i--)
>
>{
>
> if (q[i-1] - (i) > 2) {
>  
> cout << "Too chaotic" << endl;  
>  
>  return;
>  
> }
>
> for (int j=1; j < i; j++)    
> 
> if (q[j-1] > q[i-1])
>  {
> ans++;
>            
>   }
>            
> cout < < ans < < endl;
>            
> }

	
The j value ranges from 1 to i-1. This solution gives TLE as we are checking all possible values. This range of j can be further reduced.

Optimization:

> 	 1 2 3 **4** 5 6 7 8  ( The original positions)
> 	 
> 	 1 2 5 3 7 8 6 **4**  ( Final Positions)
> 	 
>
>    1 2 3 4 ***5 6 7 8***
>    

	
Only the elements present at the locations 5,6,7,8 could have bribed the element 4.
The element at location 5 can at max be shifted to 2 places left, that is, 5-2 = 3.
	So we search from 3rd position.
	
 	
 	
 	void minimumBribes(vector <  int  >  q) { 	
 	
     int ans = 0;     
     for (int i = q.size() ; i >= 1 ; i--){     
         if (q[i-1] - (i) > 2) {         
             cout << "Too chaotic" << endl;             
             return;    
         }         
         for (int j = max(1,q[i-1]-1) ; j < i; j++)          
             if (q[j-1] > q[i-1])          
             ans++;             
     }     
     cout << ans << endl;
     
}


So, q[i-1] gives the original position of the ith element. (If you start counting form 1 as done here)

The element at the minimum index (our chosen j) that has an element greater than it is at the position q[i-1]+1  (Again starting grom 1)

This greater element can at max be shifted two postions back.
So we subtract 2 and get

q[i-1]-1 as the starting location of j. It goes till i-1. 

We are using the max function to ensure that value of j doesn't become negative.

PS.
*Also, an element can't bribe the element that's larger than it as doing so would result in an arrangement that has occured previously *

*/


// Complete the minimumBribes function below.

void minimumBribes(vector<int> q) {
int ans = 0;
for (int i = q.size() ; i >= 1 ; i--)
{
    if (q[i-1] - (i) > 2) 
    {
        cout << "Too chaotic" << endl;
        return;
    }
    for (int j = max(1,q[i-1]-1) ; j < i; j++)  
    if (q[j-1] > q[i-1]) 
            ans++;
}
    cout << ans << endl;
}
