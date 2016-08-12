/*
There are 32 rooms. Need to check what's room is switched On.need to 
turn On/off a specific room. Also need to count how rooms are turned ON.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Global variables
volatile int Rooms;
unsigned int LookUpTable[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
					 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
					 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
					 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
					 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
					 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
					 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
					 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
					 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
					 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
					 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
					 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
					 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
					 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
					 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
					 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};


void ResetRooms(void);
void FlipRoom(int room);
void TurnOnRoom(int room);
void TurnOffRoom(int room);
int isRoomTurned(int room);
int RoomCounts(void); //It counts how much rooms are turned ON
void CreateLookUp(int num);
int RoomCounts256(void);
void Simulations(void);


int main(int argc, char *argv[])
{
	int room = 0, function;	
	ResetRooms();
	CreateLookUp(256);
	printf("Enter room number from 0 to 31 (-1 to end) and then press\n");
	printf("1 - Turn ON\n");
	printf("2 - Turn OFF\n");
	printf("3 - Flip room\n");
	printf("4 - Counting rooms\n");
	printf("5 - Turn Off all rooms\n");
	printf("6 - Turning simulation\n");
	scanf("%d%d", &room, &function);
	while(room != -1){
		switch(function){
			case 1:	{
				TurnOnRoom(room);
				break;
			}
			case 2:	{
				TurnOffRoom(room);
				break;
			}
			case 3:	{
				FlipRoom(room);
				break;
			}
			case 4:	{
				printf("There are %d rooms are turned ON\n", RoomCounts()) ;
				break;
			}
			case 5:	{
				printf("There are all rooms are turned Off\n");
				ResetRooms();
				break;
			}
			case 6:	{
				printf("Simulation are turned ON\n");
				ResetRooms();
				Simulations();
				break;
			}
			default: {
				printf("No this function.\n");
				break;
			}	
		}
		printf("Enter room number from 0 to 31 (-1 to end) and then press\n");
		printf("1 - Turn ON\n");
		printf("2 - Turn OFF\n");
		printf("3 - Flip room\n");
		printf("4 - Counting rooms\n");
		printf("5 - Turn Off all rooms\n");
		printf("6 - Turning simulation\n");
		scanf("%d%d", &room, &function);
		
	}
	
	printf("Good Bye!\n");
	return 0;
}

void ResetRooms(void)
{
	Rooms = 0;
}

void TurnOnRoom(int room)
{
	Rooms = Rooms | (1 << room);
	printf("Room number %d is turned On\n", room);
}

void TurnOffRoom(int room)
{
	Rooms = Rooms & (~(1 << room));
	printf("Room number %d is turned Off\n", room);
}

int isRoomTurned(int room)
{
	return (Rooms & (1 << room));
}

void FlipRoom(int room)
{
	Rooms = Rooms ^ (1 << room);
	if (isRoomTurned(room))		
		printf("Room number %d is turned On\n", room);
	else
		printf("Room number %d is turned Off\n", room);
}

int RoomCounts(void)
{
	int count = 0, i;
	for (i = 0; i < 32; i++){
		if(isRoomTurned(i))
			count++;
	}
	return count;
}

void CreateLookUp(int num)
{
	int i;
	printf("Look Up table:\n{");
	for (i=0; i < num; i++){
		Rooms = i;
		printf("%d, ", RoomCounts());
	}
	printf("}\n");
	ResetRooms();
}

int RoomCounts256(void)
{
	unsigned char *roomptr = (unsigned char *)&Rooms;
	int count;
	printf("roomptr[0] = 0x%X, roomptr[1] = 0x%X\n", roomptr[0], roomptr[1]);
	printf("roomptr[2] = 0x%X, roomptr[3] = 0x%X\n", roomptr[2], roomptr[3]);
	
	count = LookUpTable[roomptr[0]] + LookUpTable[roomptr[1]] +
			LookUpTable[roomptr[2]] + LookUpTable[roomptr[3]];
	
	return count;	
}

void Simulations(void)
{
	time_t t;
	srand((unsigned) time(&t));
	Rooms = rand() % 0xffffffff;
	printf("Rooms = 0x%X\n", Rooms);
	printf("Using simle counting:%d rooms\n", RoomCounts());
	printf("Using Look Up Table:%d rooms\n", RoomCounts256());
}