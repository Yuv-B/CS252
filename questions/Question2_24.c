/*
    CS252
    Operating systems
    Assignment
    2.24

    Yuvasankar B
    191ME197
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  // file pointers and file names
  int choice;
  FILE *fptr1, *fptr2;
  char f_source[100], f_dest[100], c;

  // Input file name to be read
  printf("\n Please enter the file name to open for reading: ");
  scanf("%s", f_source);

  // Open Source file for reading
  if(fptr1 = fopen(f_source,"r"))
  {
    // File 1 exists

    // Get the name of the file to copy the data into from the user.
    printf("\n Please enter file name to open for writing: ");
    scanf("%s", f_dest);

    // Open Destination file for writing
    if(fptr2 = fopen(f_dest, "r"))
    {
      // The file already exists, copying will overwrite the already existing content.
      printf("The file already exists.\n Do you want to overwrite the existing content?\n press 1 for yes \n press 2 for no \n");
      scanf("%d",&choice);
      if(choice==1)
      {
           fptr2 = fopen(f_dest,"w");
          goto cpy;
      }
      else
        exit(0);
    }
    else
    {
      // The Destination file does not exist.
      // Create the destination file.
      fptr2 = fopen(f_dest,"w");
      if(fptr2 == NULL)
      {
        // File can not be created. ERROR
        printf("\n Can not open the file %s\n", f_dest);
        exit(0);
      }

      // Destination file is successfully created to write
      // Read content from source file and write them to destination file character wise
      cpy:
      c = fgetc(fptr1);
      while(c!=EOF)
      {
        fputc(c, fptr2);
        c = fgetc(fptr1);
      }

      // Close both the files
      fclose(fptr1);
      fclose(fptr2);
      printf("The contents of the file are copied to %s \n",f_dest);
    }
  }
  else
  {
    // The source file does not exist
    printf("The file does not exist.\n");
    exit(0);
  }
  return 0;
}
