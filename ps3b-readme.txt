/**********************************************************************
 *                                                  
 *  PS3b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Michael Zogin

Hours to complete assignment : ~5

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes I did complete the whole assignment. I wrote a test file with boost
test cases to make sure that my StringSound class was implemented properly
with no errors. When I run my KSGuitarSim program all the right buttons
seem to be playing the right notes. 

/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  As a pair, or individually?
 **********************************************************************/
no

/**********************************************************************
 *  Did you implement exseptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes, I implemented the bad_alloc exception in my StringSound constructors
to make sure that they allocate the new CircularBuffer successfully.
(using try and catch block)

/*********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
sfml-dev.org for guidance on prudicing the sounds
cppreference.com for help with exceptions

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Had a segmentation fault problem which took a while to solve but ended up
being a simple fix in the makeSample function to pass the parameter by 
reference instead of by value. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
