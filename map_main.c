#include "header.h"

void    map(char *filename)
{
    if (check_map_path(filename) == 1 && is_file_exists_empty(filename) == 1)
    {
        read_map_from_file(filename);
    }
}