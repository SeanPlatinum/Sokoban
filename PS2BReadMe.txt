/**********************************************************************
 *                                                  
 *  PS2b: Sokoban
 **********************************************************************/

Name: Sean Diaz

Hours to complete assignment : 
1 WEEK
/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I Think ive finished everything that this assignment is asking for...
The character moves by updating the matrix and redrawing (took me forever to figure this out)
I had to originally put a bunch of coordinates with cout statments because I mistakenly read the 
columns and rows backwards so my change in position messed up. 
After I finally got it working, moving the character wasn't super hard, the boxes moving was tricky. its still kind of janky
but it works !
The matrix moving part was super interesting to me. Thinking about how we could use symbols to move things in a 2d space 
is awesome!

/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  
 **********************************************************************/

    My program does play audio, a little hooray. this was easy to implement
    I tried to get the character to rotate but editing my draw function seemed super 
    daunting. I just figured id better leave it but hey at least I got something extra.

/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
yes it does but I am not going to lie, i had to use no lint on the include directives. I just 
dont know what is wrong. But yes it works.

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Google, my friends in Daly's class explaining verbally the concept of how I 
should approach the problem and figure out how to move the player. This saved me days.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I could not figure out for the life of me at first, how to get the player to stop
if there were two boxes in the way. Or if the box was next to a wall. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 overall its pretty late. But this one was a challenge for me. Im pretty smart with the switch statement
 I was talking to my friends about how they did theirs and a lot of people ended up using a bunch of if statements
 practically the same thing, but its probably much nicer to do it this way.