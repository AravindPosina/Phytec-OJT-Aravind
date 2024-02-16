

#include <stdio.h> 
#include <stdlib.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <string.h>


// EEPROM path
char const EEPROM_FILE_BOARD[] = "/sys/class/i2c-adapter/i2c-0/0-0050/eeprom";


// EEPROM content format
typedef struct _cBoardEEPROM
{

  char ModuleID[16];
  char SerialNo[16];
  char data[512];
  
}cBoardEEPROM;



// Read board EEPROM
int ReadBoardEEPROM(cBoardEEPROM* boardEEPROM)
{

	int Fd  = 0;
	int ReadBytes = 0;
	memset(boardEEPROM, 0, sizeof(boardEEPROM));

	if ((Fd = open(EEPROM_FILE_BOARD,O_RDONLY)) < 0)
	{
		printf("EEPROM_FILE_BOARD open error: %s\n", strerror(errno));
		return -1;
	}

	ReadBytes = read(Fd, (void*)boardEEPROM, sizeof(cBoardEEPROM));
	if( ReadBytes < 0 )
	{
		printf("EEPROM_FILE_SOM read error: %s\n", strerror(errno));
		close(Fd);
		return -1;
	}
	close(Fd);

}  // ReadBoardEEPROM


// Write board EEPROM 
void WriteBoardEEPROM(cBoardEEPROM* boardEEPROM)
{

	int Fd  = 0;
	int WriteBytes = 0;

	if ((Fd = open(EEPROM_FILE_BOARD,O_WRONLY)) < 0)
	{
		printf("EEPROM_FILE_BOARD open error: %s\n", strerror(errno));
		return;
	}

	WriteBytes = write(Fd, (void*)boardEEPROM, sizeof(cBoardEEPROM));
	if( WriteBytes < sizeof(cBoardEEPROM) )
	{

		if (WriteBytes < 0)
			printf("EEPROM_FILE_BOARD write error : %s\n", strerror(errno));

		else
			printf("EEPROM_FILE_BOARD write error : Partial write to EEPROM (%d)\n", WriteBytes);

	}

	close(Fd);

} // WriteBoardEEPROM



// main routine
int main(int argc, char *argv[])
{
	int Result = 0;

	cBoardEEPROM boardEEPROM ,board;
	strcpy(boardEEPROM.ModuleID,"RBEEPROM1234");
	strcpy(boardEEPROM.SerialNo,"112233445566");
	strcpy(boardEEPROM.data,"Phytec Embedded Pvt Ltd");
	
	WriteBoardEEPROM (&boardEEPROM);

	memset(&board, 0x00, sizeof(board));

	// Read EEPROM 
	Result = ReadBoardEEPROM(&board);

	printf("[EEPROM content]=============================\n");
	printf("Module ID : %s\n", board.ModuleID);
	printf("Serial NO : %s\n", board.SerialNo);
	printf("Data      : %s\n", board.data);
	
	return 0;
} 

