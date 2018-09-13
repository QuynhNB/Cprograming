/*http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html*/
#if 0
#include <stdio.h>
#include <stdlib.h> /* Windows only, use for system("pause"); */
#include <dirent.h>

int main()
{
    struct dirent *dir_entry = NULL;
    struct dirent *dir_entry_tmp = NULL;
    DIR *dir = NULL;
    int total_entries = 0;

    /* Open current directory */
    dir = opendir("D:\\WORK\\");//OK
    if (dir == NULL)
    {
        printf("Failed to open current directory\n");
        return -1;
    }
    /* Browse all members in current directory */
    while ((dir_entry = readdir(dir)) != NULL)
    {
        if(isdir(dir_entry->d_name))
        total_entries++;
        printf("%s\n", dir_entry->d_name);
    }
    /* Close directory after browsing finished */
    closedir(dir);
    printf("\nTotal entries = %d\n", total_entries);
    /* Stop screen to see the result */
    system("pause");

    return 0;
}

#else
/* CELEBO01

   This example opens a directory.

 */
#define _POSIX_SOURCE
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void traverse(char *fn, int indent) {
  DIR *dir;
  struct dirent *entry;
  int count;
  char path[1025];
  struct stat info;

  for (count = 0; count < indent; count++) printf("  ");
  printf("%s\n", fn);

  if ((dir = opendir(fn)) == NULL)
    perror("opendir() error");
  else {
    while ((entry = readdir(dir)) != NULL) {
      if (entry->d_name[0] != '.') {
        strcpy(path, fn);
        strcat(path, "\\");
        strcat(path, entry->d_name);
        if (stat(path, &info) != 0)
          fprintf(stderr, "stat() error on %s: %s\n", path,
                  strerror(errno));
        else if (S_ISDIR(info.st_mode))
               traverse(path, indent+1);
        else
            printf("%s\n", path); /*print files in current directory*/
      }
    }
    closedir(dir);
  }
}

int main()
{
  puts("Directory structure:");
  traverse("D:\\WORK\\CodeBlock", 0);

  system("pause");
  return 0;
}
#endif
