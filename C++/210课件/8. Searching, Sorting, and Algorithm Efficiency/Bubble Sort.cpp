void sortArray(int array_size, int  arr[])
{
int pass =1, temp;
bool swap  =  true;
while ( pass < array_size && swap == true)
{
swap= false;
for ( int i = 0; i< array_size ¨C 1; i ++ )
  {
  if  ( arr [i]  >  arr[ i+1])
    {
           temp  = arr[i];
           arr[i]  =  arr[i+1];
           arr[i+1]  =  temp;
           swap= true;
                      }
         }
pass = pass + 1;
  }
}
