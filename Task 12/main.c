#include <stdio.h>
#include <string.h>

char spaces_delete(char *buffer) {
    
    size_t size = strlen(buffer);
    
    for(size_t i = 0; i < size; i++) {
        
        if(buffer[i] == ' ' && buffer[i+1] == ' ') {
            
            for(size_t j = i; j < size; j++) {
                
                buffer[j] = buffer[j+1];
            }
            --i;
        }
    }
    
    if (buffer[0] == ' ') {
        
        for(size_t i = 0; i < size; i++) {
            
            buffer[i] = buffer[i+1];
        }
    }
}

int main(int argc, char* argv[])
{
    system("clear");
    
    char buffer[256];
    
    gets(buffer);
    
    spaces_delete(buffer);
    
    puts(buffer);
    
    return 0;
}
