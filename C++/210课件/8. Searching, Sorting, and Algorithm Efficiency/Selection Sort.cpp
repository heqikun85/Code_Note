void SelectSort(int DataArray[])
{
    int            NextIdx;    /* Next open position in sorted section */
    int            LargestKey;    /* INdex of largest key in unsorted section */
    int            i;
   int    temp;

    NextIdx = SIZE - 1;

    while(NextIdx > 0)
    {
        LargestKey = NextIdx;  /* Initialize the search by assuming the  */
                               /* entry in the next open position in the */
                               /* sorted section has the largest key.    */
        /* Find next largest key in unsorted section */
        for(i=0; i<NextIdx; i++)
            if(DataArray[i] > DataArray[LargestKey])
                LargestKey = i;

        /* Swap the largest key with the one at the top of the Priority Queue */
        temp = DataArray[LargestKey];
        DataArray[LargestKey] = DataArray[NextIdx];
        DataArray[NextIdx] = temp;

        /* Set NextIdx to next position up */
        NextIdx--;
    }
}
