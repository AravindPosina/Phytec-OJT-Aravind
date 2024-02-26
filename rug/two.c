#include <sys/types.h>                                                          
#include <sys/stat.h>                                                           
#include <fcntl.h>                                                              
#include <unistd.h>                                                             
#include <stdio.h>                                                              
#include <string.h>                                                             
#include <stdlib.h>                                                             
                                                                                
#define GPIO_EN  "/sys/class/gpio/export"                                       
#define GPIO_DIR "/sys/class/gpio/PC17/direction"                               
#define GPIO_Val "/sys/class/gpio/PC17/value"                                   
#define SWITCH_Val "/sys/class/gpio/PC12/value"                                 
                                                                                
int main()                                                                      
{                                                                               
    int gpio_fd, switch_fd;                                                     
    char gpio_buf[30], switch_val;                                              
    int gpio_num = 17; // GPIO pin for LED (PC17)                               
                                                                                
    // Export GPIO pin for LED                                                  
    gpio_fd = open(GPIO_EN, O_WRONLY);                                          
    if (gpio_fd < 0) {                                                          
        printf("Unable to open the file %s\n", GPIO_EN);                        
        exit(1);                                                                
    }                                                                           
    sprintf(gpio_buf, "%d", gpio_num);                                          
    write(gpio_fd, gpio_buf, strlen(gpio_buf));                                 
    close(gpio_fd);                                                             
                                                                                
    // Set direction of GPIO pin to out                                         
    gpio_fd = open(GPIO_DIR, O_WRONLY);                                         
    if (gpio_fd < 0) {                                                          
        printf("Unable to open the file %s\n", GPIO_DIR);                       
        exit(1);                                                                
    }                                                                           
    write(gpio_fd, "out", 3);                                                   
    close(gpio_fd);                                                             
                                                                                
    // Open GPIO pin for switch (PC12)                                          
    switch_fd = open(SWITCH_Val, O_RDONLY);                                     
    if (switch_fd < 0) {                                                        
        printf("Unable to open the file %s\n", SWITCH_Val);                     
        exit(1);                                                                
    }                                                                           
                                                                                
    // Main loop to toggle LED based on switch state                            
    int led_state = 0; // LED initially off                                     
    while (1) {                                                                 
        // Read switch state                                                    
        lseek(switch_fd, 0, SEEK_SET); // Reset file pointer                    
        read(switch_fd, &switch_val, 1);                                        
                                                                                
        if (switch_val == '0') { // Switch pressed                              
            // Toggle LED state                                                 
            led_state = !led_state;                                             
                                                                                
            // Write LED state                                                  
            gpio_fd = open(GPIO_Val, O_WRONLY);                                 
            if (gpio_fd < 0) {                                                  
                printf("Unable to open the file %s\n", GPIO_Val);               
                exit(1);                                                        
            }                                                                   
            if (led_state)                                                      
                write(gpio_fd, "1", 1); // Turn LED on                          
            else                                                                
                write(gpio_fd, "0", 1); // Turn LED off                         
            close(gpio_fd);                                                     
                                                                                
            // Wait for switch release                                          
            while (switch_val == '0') {                                         
                lseek(switch_fd, 0, SEEK_SET); // Reset file pointer            
                read(switch_fd, &switch_val, 1);                                
            }                                                                   
        }                                                                       
    }                                                                           
                                                                                
    // Close file descriptors                                                   
    close(switch_fd);                                                           
                                                                                
    return 0;                                                                   
}
