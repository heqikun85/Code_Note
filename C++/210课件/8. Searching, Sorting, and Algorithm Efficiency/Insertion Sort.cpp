/***************************************/
/* InsertSort()                        */
/*                                     */
/* Sorts integer keys using   */
/*  an insertion sort.                 */
/***************************************/
void InsertSort(int DataArray[], int count)
{
    int            i, j;
    int            temp;
    int            NotDone;
    int            Key;

    for(i=1; i<count; i++)
    {
        Key = DataArray[i];
        j = i;
        NotDone = (DataArray[j-1] > Key);

        temp = DataArray[j]; /* Remove and hold the one to be moved */

        while(NotDone)
        {
            /* Slide all others to the right */
            DataArray[j] = DataArray[j-1];
            j--;
            if(j > 0)
                NotDone = (DataArray[j - 1] > Key);
            else
                NotDone = FALSE;
        }

        /* Put the removed record into it's correct slot */
        DataArray[j] = temp;
    }
}
