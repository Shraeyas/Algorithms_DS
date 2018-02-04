Take an example
111010 to 111100

All the numbers between them:
	111010, 111011 and 111100
	
	Now if we manually find their bitwise and:
		
		111010
	   &111011
	   &111100
	   --------
	    111000
	   --------
	   
Taking one more example:
	100 to 111
	
All the numbers between them:
	100, 101, 110 and 111
	
	
	Now if we manually find their bitwise and:
		
		100
	   &101
	   &110
	   &111
	   -----
	    100
	   -----
	   
Now if we look carefully there is a pattern:
	
	1)Starting from the leftmost digit, we will find the position
	  upto which the given numbers are same.
	
	2)Now in our answer we will take the position till where the 
	  digits are same and then append 0 for the rest of the digits.
	
