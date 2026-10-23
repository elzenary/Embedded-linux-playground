#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/i2c-dev.h>
//#include <i2c/smbus.h>
#include<sys/ioctl.h>

#define I2C_DEVICE "/dev/i2c-1"
#define MPU6050_SLAVE_ADD 0x68
#define MPU6050_WHO_I_AM_REG_ADD 0x75
#define MPU6050_WHO_I_AM_REG_VALUE 0x68
#define MPU6050_INT_ENABLE_REG_ADD 0x75

/*
Help:
Kernel Documentation inside: Documentation/i2c/dev-interface.rst
*/
int i2c_Write_Reg(int fd, uint8_t reg, uint8_t value){
    int buf[2];
    buf[0]= reg;
    buf[1]=value;
    write(fd, buf, 2/*size*/);

}

/*
Docuemntation kernel bootlin link
https://elixir.bootlin.com/linux/v7.3/source/Documentation/i2c/dev-interface.rst
*/
/*read register, to be checked*/


int i2c_Read_Reg(int fd, uint8_t reg, uint8_t *value){

  /*
   * Using I2C Write, equivalent of
   * i2c_smbus_write_word_data(file, reg, 0x6543)
   */
  uint8_t buf[3] = {reg, 0, 0};

  /* Using I2C Read, equivalent of i2c_smbus_read_byte(file) */
  if (read(fd, buf, 1) != 1) {
    /* ERROR HANDLING: I2C transaction failed */
    return -1;
  } 
  else 
  {
    /* buf[0] contains the read byte */
    *value = buf[0];
    return 0;
  }
}


int main(){

    /*open i2c dev with R/W mode*/
    int file = open(I2C_DEVICE, O_RDWR);

    uint8_t value = 2;

    /*check if the fd is open correctly*/
    if (file < 0) {
    /* ERROR HANDLING; you can check errno to see what went wrong */
    exit(1);
    }

    /*check if slave is available using ioctl system call*/
    if (ioctl(file, I2C_SLAVE, MPU6050_SLAVE_ADD) < 0) {
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }

    
    i2c_Write_Reg(file, MPU6050_INT_ENABLE_REG_ADD, 0x01);

    /*usleep to be checked*/
    usleep(80000);

    i2c_Read_Reg(file, MPU6050_INT_ENABLE_REG_ADD, &value);



    close(file);


    return 0;
}