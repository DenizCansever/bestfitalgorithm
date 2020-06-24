

#include <stdio.h>

/* Raşit Deniz Cansever    */
   
   
int main()  /*I make an best fit algorithm below. In this algorithm I need to use arrays for processes to be allocated 
and empty blocks and size of these arrays. That's why in the main, firstly I initialize them. Then I just call the algorithm in the main to see outputs.*/
{
    int processes[] = {322,178,278,92,157};             //Initializing the array for processes to be allocated by given inputs as size in the question.
    int emptyBlocks[] = {300,200,200,100,650,150};      //Initializing the array for empty blocks by given inputs as size in the question.
    //With using that I keep the IDs and size of the processes and empty blocks easily. Processes and blocks' IDs are the same numbers which is given in the question. 
    
    
    int p = sizeof(processes)/sizeof(processes[0]);     //Initializing the length of processes array.
    int b = sizeof(emptyBlocks)/sizeof(emptyBlocks[0]); //Initializing the length of emptyBlocks array.
    
    int allocationId[p];  //Storing the id of block which allocated to a process.
    
    bestFitalgorithm(emptyBlocks, processes,allocationId, p, b); //Calling the best fit algorithm.
    
    return 0;
}


void bestFitalgorithm(int emptyBlocks[], int processes[], int allocationId[], int p, int b){  //This is for the making best fit algorithm to allocate memory to blocks.
    
    
    
    
    
    
    for(int i=0; i<p; i++){  //Picking each processes one by one.
        
        int savingId = -1; //Initializing best id as "-1". It is important to set like this to change later when algorithm find a best block to keep.
        for(int j=0; j<b; j++) { //Picking each blocks one by one to check for current process.
            if(emptyBlocks[j] >= processes[i]) { //Checking the size of current block. If this block's size bigger or equal than current process's, it keep that.
                if(savingId == -1)
                    savingId = j;
                else if(emptyBlocks[savingId] > emptyBlocks[j]) //Then checking for better block than block which was kept. If other block is better, it keep the new block.
                    savingId = j;
            }
        }
        if(savingId != -1){  //When Algorithm find a block for current process, It pass below. This is about checking the situation. It means best ID can not be "-1" in this part.
            
            allocationId[i] = savingId; //Allocating the block as j to p[i] of processes.
            
            emptyBlocks[savingId] = emptyBlocks[savingId] - processes[i]; //Calculating the available memory in this block with reducing by using process.
        }
    }
    printf("\n Allocations: \n"); //Printing outputs of allocations below.
    for (int i = 0; i < p; i++)
    {
        printf("Process %d fit to Block %d \n", i, allocationId[i]); // Printing all processes to show their fit to which blocks in order.
    }
    printf("Remaining Blocks:\n"); //Printing outputs of remaining sizes of blocks below.
    for (int i = 0; i < b; i++)
    {
        printf("Block %d remaining size: %d \n", i, emptyBlocks[i]); //Printing all blocks' remaininz size in order.
    }
}
    
    
    
