/*
    What are the min. number of squares we can cut from 
    a given paper of width 'W' and height 'H'.
*/

#include <stdio.h>

int cutPaper(int w, int h)
{
    int squaresCount = 0, reminder = 0;
    while (h != 0)
    {
        /* 
            get coefficient and that's the number of possible square we can cut
            from the given width and height
         */
        squaresCount += w / h; 
        
        /* 
            get remainder and now width*remainder(height) is the remaining paper 
            to cut squares
         */
        reminder = w % h;

        // Now replace widht with height and height with remainder.
        w = h;
        h = reminder;
    }
    
    return squaresCount;
}

int main()
{
    int width, height;
    printf("Enter paper width and height : ");
    scanf("%d%d", &width, &height);

    /* 
        Swap values so that width always holds higher value than height 
        inorder to avoid "Divide error".
    */
    if (width > height)
    {
        width = width + height;
        height = width - height;
        width = width - height;
    }

    printf("No. of possible squares we can cut from the given paper are: %d. \n", cutPaper(width, height));
    return 0;
}
